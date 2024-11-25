
#ifndef secondary_PROTO_INTERFACE_H
#define secondary_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "secondary.pb.h"

#ifdef secondary_IMPLEMENTATION
#undef secondary_IMPLEMENTATION
#define __secondary_IMPLEMENTATION
#endif

#include "../../lib/secondary/secondary_network.h"

#ifdef __secondary_IMPLEMENTATION
#undef __secondary_IMPLEMENTATION
#define secondary_IMPLEMENTATION
#endif

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#ifndef CANLIB_CIRCULAR_BUFFER
#define CANLIB_CIRCULAR_BUFFER
namespace Helper {
template <bool FITS8, bool FITS16>
struct Index {
  using Type = uint32_t;
};

template <>
struct Index<false, true> {
  using Type = uint16_t;
};

template <>
struct Index<true, true> {
  using Type = uint8_t;
};
}  // namespace Helper

template <typename T, size_t S,
          typename IT =
              typename Helper::Index<(S <= UINT8_MAX), (S <= UINT16_MAX)>::Type>
class canlib_circular_buffer {
 public:
  static constexpr IT capacity = static_cast<IT>(S);

  using index_t = IT;

  constexpr canlib_circular_buffer();
  canlib_circular_buffer(const canlib_circular_buffer &) = delete;
  canlib_circular_buffer(canlib_circular_buffer &&) = delete;
  canlib_circular_buffer &operator=(const canlib_circular_buffer &) = delete;
  canlib_circular_buffer &operator=(canlib_circular_buffer &&) = delete;

  bool unshift(T value);
  bool push(T value);
  T shift();
  T pop();
  const T& start() const;
  T inline first() const;
  T inline last() const;
  T& operator[](IT index);
  const T& operator[](IT index) const;
  IT inline size() const;
  IT inline available() const;
  bool inline empty() const;
  bool inline full() const;
  void inline clear();
  size_t inline offset() const;


 private:
  T buffer[S];
  T *head;
  T *tail;
  size_t _offset;
#ifndef CIRCULAR_BUFFER_INT_SAFE
  IT count;
#else
  volatile IT count;
#endif
};

template <typename T, size_t S, typename IT>
constexpr canlib_circular_buffer<T, S, IT>::canlib_circular_buffer()
    : head(buffer), tail(buffer), count(0), _offset(0) {}

template <typename T, size_t S, typename IT>
bool canlib_circular_buffer<T, S, IT>::unshift(T value) {
  if (head == buffer) {
    head = buffer + capacity;
  }
  *--head = value;
  if (count == capacity) {
    if (tail-- == buffer) {
      tail = buffer + capacity - 1;
    }
    return false;
  } else {
    if (count++ == 0) {
      tail = head;
    }
    return true;
  }
}

template <typename T, size_t S, typename IT>
bool canlib_circular_buffer<T, S, IT>::push(T value) {
  if (++tail == buffer + capacity) {
    tail = buffer;
  }
  *tail = value;
  if (count == capacity) {
    if (++head == buffer + capacity) {
      head = buffer;
    }
    _offset = (_offset + 1) % capacity;
    return false;
  } else {
    if (count++ == 0) {
      head = tail;
    }
    return true;
  }
}

template <typename T, size_t S, typename IT>
T canlib_circular_buffer<T, S, IT>::shift() {
  if (count == 0) return *head;
  T result = *head++;
  if (head >= buffer + capacity) {
    head = buffer;
  }
  count--;
  return result;
}

template <typename T, size_t S, typename IT>
T canlib_circular_buffer<T, S, IT>::pop() {
  if (count == 0) return *tail;
  T result = *tail--;
  if (tail < buffer) {
    tail = buffer + capacity - 1;
  }
  count--;
  return result;
}

template <typename T, size_t S, typename IT>
T inline canlib_circular_buffer<T, S, IT>::first() const {
  return *head;
}

template <typename T, size_t S, typename IT>
T inline canlib_circular_buffer<T, S, IT>::last() const {
  return *tail;
}

template <typename T, size_t S, typename IT>
const T& canlib_circular_buffer<T, S, IT>::start() const {
  return buffer[1];
}

template <typename T, size_t S, typename IT>
T& canlib_circular_buffer<T, S, IT>::operator[](IT index) {
  if (index >= count) return *tail;
  return *(buffer + ((head - buffer + index) % capacity));
}

template <typename T, size_t S, typename IT>
const T& canlib_circular_buffer<T, S, IT>::operator[](IT index) const {
  if (index >= count) return *tail;
  return *(buffer + ((head - buffer + index) % capacity));
}

template <typename T, size_t S, typename IT>
IT inline canlib_circular_buffer<T, S, IT>::size() const {
  return count;
}

template <typename T, size_t S, typename IT>
IT inline canlib_circular_buffer<T, S, IT>::available() const {
  return capacity - count;
}

template <typename T, size_t S, typename IT>
bool inline canlib_circular_buffer<T, S, IT>::empty() const {
  return count == 0;
}

template <typename T, size_t S, typename IT>
bool inline canlib_circular_buffer<T, S, IT>::full() const {
  return count == capacity;
}

template <typename T, size_t S, typename IT>
void inline canlib_circular_buffer<T, S, IT>::clear() {
  head = tail = buffer;
  count = 0;
  _offset = 0;
}

template <typename T, size_t S, typename IT>
size_t inline canlib_circular_buffer<T, S, IT>::offset() const {
  return _offset;
}

#endif // CANLIB_CIRCULAR_BUFFER

#ifndef CANLIB_CIRCULAR_BUFFER_SIZE
#define CANLIB_CIRCULAR_BUFFER_SIZE 2000
#endif // CANLIB_CIRCULAR_BUFFER_SIZE


#ifndef CANLIB_PROTO_INTERFACE_TYPES
#define CANLIB_PROTO_INTERFACE_TYPES

/**
*  Use network_<> to get all the values from the protobuffer.
*  Every network can be consensed into one network_<> as all the
*  messages names are unique.
**/

typedef std::string field_name;
typedef std::string messages_name;
typedef canlib_circular_buffer<double,      CANLIB_CIRCULAR_BUFFER_SIZE> double_buffer;
typedef canlib_circular_buffer<uint64_t,    CANLIB_CIRCULAR_BUFFER_SIZE> uint64_buffer;
typedef canlib_circular_buffer<std::string, CANLIB_CIRCULAR_BUFFER_SIZE> string_buffer;

// structure contains all the messages with a enum value associated
// the type is unified to uint64_t
typedef std::unordered_map<field_name,    uint64_buffer> message_enums;
typedef std::unordered_map<messages_name, message_enums> network_enums;

// structure contains all the messages with a signal associated
// the type is unified to double
typedef std::unordered_map<field_name,    double_buffer>   message_signals;
typedef std::unordered_map<messages_name, message_signals> network_signals;

// structure contains all the messages with a string associated
// the type is unified to string
typedef std::unordered_map<field_name,    string_buffer>   message_strings;
typedef std::unordered_map<messages_name, message_strings> network_strings;

#endif // CANLIB_PROTO_INTERFACE_TYPES

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, device_t* device);
void secondary_proto_interface_deserialize(secondary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef secondary_PROTO_INTERAFCE_IMPLEMENTATION

void secondary_proto_interface_deserialize(secondary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->acquisinator_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_JMP_TO_BLT"]["_timestamp"].push(pack->acquisinator_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ACQUISINATOR_JMP_TO_BLT"]["acquisinatore_id"].push(pack->acquisinator_jmp_to_blt(i).acquisinatore_id());

    }

    for(int i = 0; i < pack->acquisinator_flash_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_0_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_0_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_0_TX"]["_timestamp"].push(pack->acquisinator_flash_0_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_0_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_0_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_0_RX"]["_timestamp"].push(pack->acquisinator_flash_0_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_1_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_1_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_1_TX"]["_timestamp"].push(pack->acquisinator_flash_1_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_1_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_1_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_1_RX"]["_timestamp"].push(pack->acquisinator_flash_1_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_2_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_2_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_2_TX"]["_timestamp"].push(pack->acquisinator_flash_2_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_2_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_2_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_2_RX"]["_timestamp"].push(pack->acquisinator_flash_2_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_3_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_3_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_3_TX"]["_timestamp"].push(pack->acquisinator_flash_3_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_3_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_3_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_3_RX"]["_timestamp"].push(pack->acquisinator_flash_3_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_4_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_4_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_4_TX"]["_timestamp"].push(pack->acquisinator_flash_4_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_4_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_4_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_4_RX"]["_timestamp"].push(pack->acquisinator_flash_4_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_5_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_5_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_5_TX"]["_timestamp"].push(pack->acquisinator_flash_5_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_5_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_5_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_5_RX"]["_timestamp"].push(pack->acquisinator_flash_5_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_6_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_6_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_6_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_6_TX"]["_timestamp"].push(pack->acquisinator_flash_6_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_6_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_6_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_6_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_6_RX"]["_timestamp"].push(pack->acquisinator_flash_6_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_7_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_7_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_7_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_7_TX"]["_timestamp"].push(pack->acquisinator_flash_7_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_7_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_7_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_7_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_7_RX"]["_timestamp"].push(pack->acquisinator_flash_7_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_8_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_8_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_8_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_8_TX"]["_timestamp"].push(pack->acquisinator_flash_8_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_8_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_8_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_8_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_8_RX"]["_timestamp"].push(pack->acquisinator_flash_8_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_9_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_9_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_9_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_9_TX"]["_timestamp"].push(pack->acquisinator_flash_9_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_9_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_9_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_9_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_9_RX"]["_timestamp"].push(pack->acquisinator_flash_9_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_10_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_10_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_10_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_10_TX"]["_timestamp"].push(pack->acquisinator_flash_10_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_10_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_10_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_10_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_10_RX"]["_timestamp"].push(pack->acquisinator_flash_10_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_11_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_11_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_11_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_11_TX"]["_timestamp"].push(pack->acquisinator_flash_11_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_11_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_11_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_11_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_11_RX"]["_timestamp"].push(pack->acquisinator_flash_11_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_12_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_12_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_12_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_12_TX"]["_timestamp"].push(pack->acquisinator_flash_12_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_12_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_12_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_12_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_12_RX"]["_timestamp"].push(pack->acquisinator_flash_12_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_13_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_13_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_13_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_13_TX"]["_timestamp"].push(pack->acquisinator_flash_13_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_13_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_13_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_13_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_13_RX"]["_timestamp"].push(pack->acquisinator_flash_13_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_14_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_14_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_14_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_14_TX"]["_timestamp"].push(pack->acquisinator_flash_14_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_14_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_14_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_14_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_14_RX"]["_timestamp"].push(pack->acquisinator_flash_14_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_15_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_15_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_15_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_15_TX"]["_timestamp"].push(pack->acquisinator_flash_15_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_15_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_15_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_15_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_15_RX"]["_timestamp"].push(pack->acquisinator_flash_15_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_16_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_16_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_16_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_16_TX"]["_timestamp"].push(pack->acquisinator_flash_16_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_16_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_16_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_16_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_16_RX"]["_timestamp"].push(pack->acquisinator_flash_16_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_17_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_17_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_17_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_17_TX"]["_timestamp"].push(pack->acquisinator_flash_17_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_17_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_17_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_17_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_17_RX"]["_timestamp"].push(pack->acquisinator_flash_17_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_18_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_18_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_18_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_18_TX"]["_timestamp"].push(pack->acquisinator_flash_18_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_18_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_18_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_18_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_18_RX"]["_timestamp"].push(pack->acquisinator_flash_18_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_19_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_19_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_19_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_19_TX"]["_timestamp"].push(pack->acquisinator_flash_19_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_19_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_19_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_19_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_19_RX"]["_timestamp"].push(pack->acquisinator_flash_19_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_20_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_20_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_20_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_20_TX"]["_timestamp"].push(pack->acquisinator_flash_20_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_20_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_20_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_20_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_20_RX"]["_timestamp"].push(pack->acquisinator_flash_20_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_21_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_21_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_21_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_21_TX"]["_timestamp"].push(pack->acquisinator_flash_21_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_21_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_21_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_21_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_21_RX"]["_timestamp"].push(pack->acquisinator_flash_21_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_22_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_22_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_22_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_22_TX"]["_timestamp"].push(pack->acquisinator_flash_22_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_22_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_22_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_22_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_22_RX"]["_timestamp"].push(pack->acquisinator_flash_22_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_23_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_23_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_23_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_23_TX"]["_timestamp"].push(pack->acquisinator_flash_23_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_23_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_23_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_23_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_23_RX"]["_timestamp"].push(pack->acquisinator_flash_23_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_24_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_24_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_24_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_24_TX"]["_timestamp"].push(pack->acquisinator_flash_24_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_24_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_24_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_24_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_24_RX"]["_timestamp"].push(pack->acquisinator_flash_24_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_25_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_25_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_25_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_25_TX"]["_timestamp"].push(pack->acquisinator_flash_25_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_25_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_25_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_25_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_25_RX"]["_timestamp"].push(pack->acquisinator_flash_25_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_26_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_26_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_26_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_26_TX"]["_timestamp"].push(pack->acquisinator_flash_26_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_26_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_26_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_26_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_26_RX"]["_timestamp"].push(pack->acquisinator_flash_26_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_27_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_27_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_27_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_27_TX"]["_timestamp"].push(pack->acquisinator_flash_27_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_27_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_27_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_27_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_27_RX"]["_timestamp"].push(pack->acquisinator_flash_27_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_28_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_28_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_28_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_28_TX"]["_timestamp"].push(pack->acquisinator_flash_28_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_28_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_28_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_28_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_28_RX"]["_timestamp"].push(pack->acquisinator_flash_28_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_29_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_29_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_29_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_29_TX"]["_timestamp"].push(pack->acquisinator_flash_29_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_29_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_29_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_29_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_29_RX"]["_timestamp"].push(pack->acquisinator_flash_29_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_30_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_30_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_30_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_30_TX"]["_timestamp"].push(pack->acquisinator_flash_30_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_30_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_30_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_30_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_30_RX"]["_timestamp"].push(pack->acquisinator_flash_30_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_31_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_31_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_31_tx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_31_TX"]["_timestamp"].push(pack->acquisinator_flash_31_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_flash_31_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_flash_31_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_flash_31_rx(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_FLASH_31_RX"]["_timestamp"].push(pack->acquisinator_flash_31_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->acquisinator_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_version(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_VERSION"]["_timestamp"].push(pack->acquisinator_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ACQUISINATOR_VERSION"]["acquisinator_id"].push(pack->acquisinator_version(i).acquisinator_id());
		(*net_signals)["ACQUISINATOR_VERSION"]["canlib_build_time"].push(pack->acquisinator_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->imu_angular_rate_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->imu_angular_rate(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->imu_angular_rate(i)._inner_timestamp();
        (*net_signals)["IMU_ANGULAR_RATE"]["_timestamp"].push(pack->imu_angular_rate(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IMU_ANGULAR_RATE"]["x"].push(pack->imu_angular_rate(i).x());
		(*net_signals)["IMU_ANGULAR_RATE"]["y"].push(pack->imu_angular_rate(i).y());
		(*net_signals)["IMU_ANGULAR_RATE"]["z"].push(pack->imu_angular_rate(i).z());

    }

    for(int i = 0; i < pack->imu_acceleration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->imu_acceleration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->imu_acceleration(i)._inner_timestamp();
        (*net_signals)["IMU_ACCELERATION"]["_timestamp"].push(pack->imu_acceleration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IMU_ACCELERATION"]["x"].push(pack->imu_acceleration(i).x());
		(*net_signals)["IMU_ACCELERATION"]["y"].push(pack->imu_acceleration(i).y());
		(*net_signals)["IMU_ACCELERATION"]["z"].push(pack->imu_acceleration(i).z());
		(*net_signals)["IMU_ACCELERATION"]["imu_temperature"].push(pack->imu_acceleration(i).imu_temperature());

    }

    for(int i = 0; i < pack->irts_fl_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_0(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_0"]["_timestamp"].push(pack->irts_fl_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_0"]["channel1"].push(pack->irts_fl_0(i).channel1());
		(*net_signals)["IRTS_FL_0"]["channel2"].push(pack->irts_fl_0(i).channel2());
		(*net_signals)["IRTS_FL_0"]["channel3"].push(pack->irts_fl_0(i).channel3());
		(*net_signals)["IRTS_FL_0"]["channel4"].push(pack->irts_fl_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_fl_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_1(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_1"]["_timestamp"].push(pack->irts_fl_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_1"]["channel5"].push(pack->irts_fl_1(i).channel5());
		(*net_signals)["IRTS_FL_1"]["channel6"].push(pack->irts_fl_1(i).channel6());
		(*net_signals)["IRTS_FL_1"]["channel7"].push(pack->irts_fl_1(i).channel7());
		(*net_signals)["IRTS_FL_1"]["channel8"].push(pack->irts_fl_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_fl_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_2(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_2"]["_timestamp"].push(pack->irts_fl_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_2"]["channel9"].push(pack->irts_fl_2(i).channel9());
		(*net_signals)["IRTS_FL_2"]["channel10"].push(pack->irts_fl_2(i).channel10());
		(*net_signals)["IRTS_FL_2"]["channel11"].push(pack->irts_fl_2(i).channel11());
		(*net_signals)["IRTS_FL_2"]["channel12"].push(pack->irts_fl_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_fl_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_3(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_3"]["_timestamp"].push(pack->irts_fl_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_3"]["channel13"].push(pack->irts_fl_3(i).channel13());
		(*net_signals)["IRTS_FL_3"]["channel14"].push(pack->irts_fl_3(i).channel14());
		(*net_signals)["IRTS_FL_3"]["channel15"].push(pack->irts_fl_3(i).channel15());
		(*net_signals)["IRTS_FL_3"]["channel16"].push(pack->irts_fl_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_fr_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_0(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_0"]["_timestamp"].push(pack->irts_fr_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_0"]["channel1"].push(pack->irts_fr_0(i).channel1());
		(*net_signals)["IRTS_FR_0"]["channel2"].push(pack->irts_fr_0(i).channel2());
		(*net_signals)["IRTS_FR_0"]["channel3"].push(pack->irts_fr_0(i).channel3());
		(*net_signals)["IRTS_FR_0"]["channel4"].push(pack->irts_fr_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_fr_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_1(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_1"]["_timestamp"].push(pack->irts_fr_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_1"]["channel5"].push(pack->irts_fr_1(i).channel5());
		(*net_signals)["IRTS_FR_1"]["channel6"].push(pack->irts_fr_1(i).channel6());
		(*net_signals)["IRTS_FR_1"]["channel7"].push(pack->irts_fr_1(i).channel7());
		(*net_signals)["IRTS_FR_1"]["channel8"].push(pack->irts_fr_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_fr_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_2(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_2"]["_timestamp"].push(pack->irts_fr_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_2"]["channel9"].push(pack->irts_fr_2(i).channel9());
		(*net_signals)["IRTS_FR_2"]["channel10"].push(pack->irts_fr_2(i).channel10());
		(*net_signals)["IRTS_FR_2"]["channel11"].push(pack->irts_fr_2(i).channel11());
		(*net_signals)["IRTS_FR_2"]["channel12"].push(pack->irts_fr_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_fr_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_3(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_3"]["_timestamp"].push(pack->irts_fr_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_3"]["channel13"].push(pack->irts_fr_3(i).channel13());
		(*net_signals)["IRTS_FR_3"]["channel14"].push(pack->irts_fr_3(i).channel14());
		(*net_signals)["IRTS_FR_3"]["channel15"].push(pack->irts_fr_3(i).channel15());
		(*net_signals)["IRTS_FR_3"]["channel16"].push(pack->irts_fr_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_rl_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_0(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_0"]["_timestamp"].push(pack->irts_rl_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_0"]["channel1"].push(pack->irts_rl_0(i).channel1());
		(*net_signals)["IRTS_RL_0"]["channel2"].push(pack->irts_rl_0(i).channel2());
		(*net_signals)["IRTS_RL_0"]["channel3"].push(pack->irts_rl_0(i).channel3());
		(*net_signals)["IRTS_RL_0"]["channel4"].push(pack->irts_rl_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_rl_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_1(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_1"]["_timestamp"].push(pack->irts_rl_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_1"]["channel5"].push(pack->irts_rl_1(i).channel5());
		(*net_signals)["IRTS_RL_1"]["channel6"].push(pack->irts_rl_1(i).channel6());
		(*net_signals)["IRTS_RL_1"]["channel7"].push(pack->irts_rl_1(i).channel7());
		(*net_signals)["IRTS_RL_1"]["channel8"].push(pack->irts_rl_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_rl_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_2(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_2"]["_timestamp"].push(pack->irts_rl_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_2"]["channel9"].push(pack->irts_rl_2(i).channel9());
		(*net_signals)["IRTS_RL_2"]["channel10"].push(pack->irts_rl_2(i).channel10());
		(*net_signals)["IRTS_RL_2"]["channel11"].push(pack->irts_rl_2(i).channel11());
		(*net_signals)["IRTS_RL_2"]["channel12"].push(pack->irts_rl_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_rl_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_3(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_3"]["_timestamp"].push(pack->irts_rl_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_3"]["channel13"].push(pack->irts_rl_3(i).channel13());
		(*net_signals)["IRTS_RL_3"]["channel14"].push(pack->irts_rl_3(i).channel14());
		(*net_signals)["IRTS_RL_3"]["channel15"].push(pack->irts_rl_3(i).channel15());
		(*net_signals)["IRTS_RL_3"]["channel16"].push(pack->irts_rl_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_rr_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_0(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_0"]["_timestamp"].push(pack->irts_rr_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_0"]["channel1"].push(pack->irts_rr_0(i).channel1());
		(*net_signals)["IRTS_RR_0"]["channel2"].push(pack->irts_rr_0(i).channel2());
		(*net_signals)["IRTS_RR_0"]["channel3"].push(pack->irts_rr_0(i).channel3());
		(*net_signals)["IRTS_RR_0"]["channel4"].push(pack->irts_rr_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_rr_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_1(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_1"]["_timestamp"].push(pack->irts_rr_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_1"]["channel5"].push(pack->irts_rr_1(i).channel5());
		(*net_signals)["IRTS_RR_1"]["channel6"].push(pack->irts_rr_1(i).channel6());
		(*net_signals)["IRTS_RR_1"]["channel7"].push(pack->irts_rr_1(i).channel7());
		(*net_signals)["IRTS_RR_1"]["channel8"].push(pack->irts_rr_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_rr_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_2(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_2"]["_timestamp"].push(pack->irts_rr_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_2"]["channel9"].push(pack->irts_rr_2(i).channel9());
		(*net_signals)["IRTS_RR_2"]["channel10"].push(pack->irts_rr_2(i).channel10());
		(*net_signals)["IRTS_RR_2"]["channel11"].push(pack->irts_rr_2(i).channel11());
		(*net_signals)["IRTS_RR_2"]["channel12"].push(pack->irts_rr_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_rr_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_3(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_3"]["_timestamp"].push(pack->irts_rr_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_3"]["channel13"].push(pack->irts_rr_3(i).channel13());
		(*net_signals)["IRTS_RR_3"]["channel14"].push(pack->irts_rr_3(i).channel14());
		(*net_signals)["IRTS_RR_3"]["channel15"].push(pack->irts_rr_3(i).channel15());
		(*net_signals)["IRTS_RR_3"]["channel16"].push(pack->irts_rr_3(i).channel16());

    }

    for(int i = 0; i < pack->vehicle_position_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->vehicle_position(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->vehicle_position(i)._inner_timestamp();
        (*net_signals)["VEHICLE_POSITION"]["_timestamp"].push(pack->vehicle_position(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VEHICLE_POSITION"]["x"].push(pack->vehicle_position(i).x());
		(*net_signals)["VEHICLE_POSITION"]["y"].push(pack->vehicle_position(i).y());
		(*net_signals)["VEHICLE_POSITION"]["heading"].push(pack->vehicle_position(i).heading());

    }

    for(int i = 0; i < pack->vehicle_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->vehicle_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->vehicle_speed(i)._inner_timestamp();
        (*net_signals)["VEHICLE_SPEED"]["_timestamp"].push(pack->vehicle_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VEHICLE_SPEED"]["u"].push(pack->vehicle_speed(i).u());
		(*net_signals)["VEHICLE_SPEED"]["v"].push(pack->vehicle_speed(i).v());

    }

    for(int i = 0; i < pack->vehicle_curvilinear_coordinates_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->vehicle_curvilinear_coordinates(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->vehicle_curvilinear_coordinates(i)._inner_timestamp();
        (*net_signals)["VEHICLE_CURVILINEAR_COORDINATES"]["_timestamp"].push(pack->vehicle_curvilinear_coordinates(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VEHICLE_CURVILINEAR_COORDINATES"]["s"].push(pack->vehicle_curvilinear_coordinates(i).s());
		(*net_signals)["VEHICLE_CURVILINEAR_COORDINATES"]["n"].push(pack->vehicle_curvilinear_coordinates(i).n());

    }

    for(int i = 0; i < pack->front_angular_velocity_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->front_angular_velocity(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->front_angular_velocity(i)._inner_timestamp();
        (*net_signals)["FRONT_ANGULAR_VELOCITY"]["_timestamp"].push(pack->front_angular_velocity(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["FRONT_ANGULAR_VELOCITY"]["fl"].push(pack->front_angular_velocity(i).fl());
		(*net_signals)["FRONT_ANGULAR_VELOCITY"]["fr"].push(pack->front_angular_velocity(i).fr());

    }

    for(int i = 0; i < pack->rear_angular_velocity_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->rear_angular_velocity(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->rear_angular_velocity(i)._inner_timestamp();
        (*net_signals)["REAR_ANGULAR_VELOCITY"]["_timestamp"].push(pack->rear_angular_velocity(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["REAR_ANGULAR_VELOCITY"]["rl"].push(pack->rear_angular_velocity(i).rl());
		(*net_signals)["REAR_ANGULAR_VELOCITY"]["rr"].push(pack->rear_angular_velocity(i).rr());

    }

    for(int i = 0; i < pack->hv_soc_estimation_state_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_soc_estimation_state(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_soc_estimation_state(i)._inner_timestamp();
        (*net_signals)["HV_SOC_ESTIMATION_STATE"]["_timestamp"].push(pack->hv_soc_estimation_state(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_SOC_ESTIMATION_STATE"]["soc"].push(pack->hv_soc_estimation_state(i).soc());
		(*net_signals)["HV_SOC_ESTIMATION_STATE"]["rc1"].push(pack->hv_soc_estimation_state(i).rc1());
		(*net_signals)["HV_SOC_ESTIMATION_STATE"]["rc2"].push(pack->hv_soc_estimation_state(i).rc2());

    }

    for(int i = 0; i < pack->hv_soc_estimation_covariance_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_soc_estimation_covariance(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_soc_estimation_covariance(i)._inner_timestamp();
        (*net_signals)["HV_SOC_ESTIMATION_COVARIANCE"]["_timestamp"].push(pack->hv_soc_estimation_covariance(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_SOC_ESTIMATION_COVARIANCE"]["soc"].push(pack->hv_soc_estimation_covariance(i).soc());
		(*net_signals)["HV_SOC_ESTIMATION_COVARIANCE"]["rc1"].push(pack->hv_soc_estimation_covariance(i).rc1());
		(*net_signals)["HV_SOC_ESTIMATION_COVARIANCE"]["rc2"].push(pack->hv_soc_estimation_covariance(i).rc2());

    }

    for(int i = 0; i < pack->lv_soc_estimation_state_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_soc_estimation_state(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_soc_estimation_state(i)._inner_timestamp();
        (*net_signals)["LV_SOC_ESTIMATION_STATE"]["_timestamp"].push(pack->lv_soc_estimation_state(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_SOC_ESTIMATION_STATE"]["soc"].push(pack->lv_soc_estimation_state(i).soc());
		(*net_signals)["LV_SOC_ESTIMATION_STATE"]["rc1"].push(pack->lv_soc_estimation_state(i).rc1());
		(*net_signals)["LV_SOC_ESTIMATION_STATE"]["rc2"].push(pack->lv_soc_estimation_state(i).rc2());

    }

    for(int i = 0; i < pack->lv_soc_estimation_covariance_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_soc_estimation_covariance(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_soc_estimation_covariance(i)._inner_timestamp();
        (*net_signals)["LV_SOC_ESTIMATION_COVARIANCE"]["_timestamp"].push(pack->lv_soc_estimation_covariance(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_SOC_ESTIMATION_COVARIANCE"]["soc"].push(pack->lv_soc_estimation_covariance(i).soc());
		(*net_signals)["LV_SOC_ESTIMATION_COVARIANCE"]["rc1"].push(pack->lv_soc_estimation_covariance(i).rc1());
		(*net_signals)["LV_SOC_ESTIMATION_COVARIANCE"]["rc2"].push(pack->lv_soc_estimation_covariance(i).rc2());

    }

    for(int i = 0; i < pack->pedal_throttle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedal_throttle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedal_throttle(i)._inner_timestamp();
        (*net_signals)["PEDAL_THROTTLE"]["_timestamp"].push(pack->pedal_throttle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDAL_THROTTLE"]["throttle"].push(pack->pedal_throttle(i).throttle());

    }

    for(int i = 0; i < pack->pedal_brakes_pressure_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedal_brakes_pressure(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedal_brakes_pressure(i)._inner_timestamp();
        (*net_signals)["PEDAL_BRAKES_PRESSURE"]["_timestamp"].push(pack->pedal_brakes_pressure(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDAL_BRAKES_PRESSURE"]["front"].push(pack->pedal_brakes_pressure(i).front());
		(*net_signals)["PEDAL_BRAKES_PRESSURE"]["rear"].push(pack->pedal_brakes_pressure(i).rear());

    }

    for(int i = 0; i < pack->steer_angle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steer_angle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steer_angle(i)._inner_timestamp();
        (*net_signals)["STEER_ANGLE"]["_timestamp"].push(pack->steer_angle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEER_ANGLE"]["angle"].push(pack->steer_angle(i).angle());

    }

    for(int i = 0; i < pack->odometer_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->odometer(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->odometer(i)._inner_timestamp();
        (*net_signals)["ODOMETER"]["_timestamp"].push(pack->odometer(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ODOMETER"]["kilometers"].push(pack->odometer(i).kilometers());

    }

    for(int i = 0; i < pack->tpms_pressure_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tpms_pressure(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tpms_pressure(i)._inner_timestamp();
        (*net_signals)["TPMS_PRESSURE"]["_timestamp"].push(pack->tpms_pressure(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TPMS_PRESSURE"]["fl"].push(pack->tpms_pressure(i).fl());
		(*net_signals)["TPMS_PRESSURE"]["fr"].push(pack->tpms_pressure(i).fr());
		(*net_signals)["TPMS_PRESSURE"]["rl"].push(pack->tpms_pressure(i).rl());
		(*net_signals)["TPMS_PRESSURE"]["rr"].push(pack->tpms_pressure(i).rr());

    }

    for(int i = 0; i < pack->tpms_temperature_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tpms_temperature(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tpms_temperature(i)._inner_timestamp();
        (*net_signals)["TPMS_TEMPERATURE"]["_timestamp"].push(pack->tpms_temperature(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TPMS_TEMPERATURE"]["fl"].push(pack->tpms_temperature(i).fl());
		(*net_signals)["TPMS_TEMPERATURE"]["fr"].push(pack->tpms_temperature(i).fr());
		(*net_signals)["TPMS_TEMPERATURE"]["rl"].push(pack->tpms_temperature(i).rl());
		(*net_signals)["TPMS_TEMPERATURE"]["rr"].push(pack->tpms_temperature(i).rr());

    }

    for(int i = 0; i < pack->tlm_unix_timestamp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_unix_timestamp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_unix_timestamp(i)._inner_timestamp();
        (*net_signals)["TLM_UNIX_TIMESTAMP"]["_timestamp"].push(pack->tlm_unix_timestamp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_UNIX_TIMESTAMP"]["timestamp"].push(pack->tlm_unix_timestamp(i).timestamp());

    }

    for(int i = 0; i < pack->tlm_lap_time_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_lap_time(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_lap_time(i)._inner_timestamp();
        (*net_signals)["TLM_LAP_TIME"]["_timestamp"].push(pack->tlm_lap_time(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_LAP_TIME"]["lap_count"].push(pack->tlm_lap_time(i).lap_count());
		(*net_signals)["TLM_LAP_TIME"]["lap_time"].push(pack->tlm_lap_time(i).lap_time());

    }

    for(int i = 0; i < pack->tlm_laps_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_laps_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_laps_stats(i)._inner_timestamp();
        (*net_signals)["TLM_LAPS_STATS"]["_timestamp"].push(pack->tlm_laps_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_LAPS_STATS"]["lap_number"].push(pack->tlm_laps_stats(i).lap_number());
		(*net_signals)["TLM_LAPS_STATS"]["best_time"].push(pack->tlm_laps_stats(i).best_time());
		(*net_signals)["TLM_LAPS_STATS"]["last_time"].push(pack->tlm_laps_stats(i).last_time());

    }

    for(int i = 0; i < pack->tlm_network_interface_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_network_interface(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_network_interface(i)._inner_timestamp();
        (*net_signals)["TLM_NETWORK_INTERFACE"]["_timestamp"].push(pack->tlm_network_interface(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_NETWORK_INTERFACE"]["iname_0"].push(pack->tlm_network_interface(i).iname_0());
		(*net_signals)["TLM_NETWORK_INTERFACE"]["iname_1"].push(pack->tlm_network_interface(i).iname_1());
		(*net_signals)["TLM_NETWORK_INTERFACE"]["iname_2"].push(pack->tlm_network_interface(i).iname_2());
		(*net_signals)["TLM_NETWORK_INTERFACE"]["iname_3"].push(pack->tlm_network_interface(i).iname_3());
		(*net_signals)["TLM_NETWORK_INTERFACE"]["ip_address"].push(pack->tlm_network_interface(i).ip_address());

    }

    for(int i = 0; i < pack->front_ammo_compression_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->front_ammo_compression(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->front_ammo_compression(i)._inner_timestamp();
        (*net_signals)["FRONT_AMMO_COMPRESSION"]["_timestamp"].push(pack->front_ammo_compression(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["FRONT_AMMO_COMPRESSION"]["fl"].push(pack->front_ammo_compression(i).fl());
		(*net_signals)["FRONT_AMMO_COMPRESSION"]["fr"].push(pack->front_ammo_compression(i).fr());

    }

    for(int i = 0; i < pack->rear_ammo_compression_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->rear_ammo_compression(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->rear_ammo_compression(i)._inner_timestamp();
        (*net_signals)["REAR_AMMO_COMPRESSION"]["_timestamp"].push(pack->rear_ammo_compression(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["REAR_AMMO_COMPRESSION"]["rl"].push(pack->rear_ammo_compression(i).rl());
		(*net_signals)["REAR_AMMO_COMPRESSION"]["rr"].push(pack->rear_ammo_compression(i).rr());

    }

    for(int i = 0; i < pack->acquisinator_calibrations_offsets_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_calibrations_offsets(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_calibrations_offsets(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_CALIBRATIONS_OFFSETS"]["_timestamp"].push(pack->acquisinator_calibrations_offsets(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ACQUISINATOR_CALIBRATIONS_OFFSETS"]["acquisinator_id"].push(pack->acquisinator_calibrations_offsets(i).acquisinator_id());
		(*net_signals)["ACQUISINATOR_CALIBRATIONS_OFFSETS"]["offset1"].push(pack->acquisinator_calibrations_offsets(i).offset1());
		(*net_signals)["ACQUISINATOR_CALIBRATIONS_OFFSETS"]["offset2"].push(pack->acquisinator_calibrations_offsets(i).offset2());

    }

    for(int i = 0; i < pack->acquisinator_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acquisinator_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acquisinator_errors(i)._inner_timestamp();
        (*net_signals)["ACQUISINATOR_ERRORS"]["_timestamp"].push(pack->acquisinator_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ACQUISINATOR_ERRORS"]["acquisinator_id"].push(pack->acquisinator_errors(i).acquisinator_id());
		(*net_enums)["ACQUISINATOR_ERRORS"]["acquisinator_errors_acquisinatore_led_code_can_not_working"].push(pack->acquisinator_errors(i).acquisinator_errors_acquisinatore_led_code_can_not_working());
		(*net_enums)["ACQUISINATOR_ERRORS"]["acquisinator_errors_acquisinatore_led_code_spi_error"].push(pack->acquisinator_errors(i).acquisinator_errors_acquisinatore_led_code_spi_error());
		(*net_enums)["ACQUISINATOR_ERRORS"]["acquisinator_errors_acquisinatore_led_code_read_write_flash"].push(pack->acquisinator_errors(i).acquisinator_errors_acquisinatore_led_code_read_write_flash());
		(*net_enums)["ACQUISINATOR_ERRORS"]["acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id"].push(pack->acquisinator_errors(i).acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id());

    }

    for(int i = 0; i < pack->link_deformation_debug_voltages_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_debug_voltages(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_debug_voltages(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["_timestamp"].push(pack->link_deformation_debug_voltages(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["wheel_id"].push(pack->link_deformation_debug_voltages(i).wheel_id());
		secondary_link_deformation_debug_voltages_wheel_id_enum_to_string((secondary_link_deformation_debug_voltages_wheel_id)pack->link_deformation_debug_voltages(i).wheel_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["wheel_id"].push(buffer);
		(*net_enums)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["rod_id"].push(pack->link_deformation_debug_voltages(i).rod_id());
		secondary_link_deformation_debug_voltages_rod_id_enum_to_string((secondary_link_deformation_debug_voltages_rod_id)pack->link_deformation_debug_voltages(i).rod_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["rod_id"].push(buffer);
		(*net_signals)["LINK_DEFORMATION_DEBUG_VOLTAGES"]["raw_voltage"].push(pack->link_deformation_debug_voltages(i).raw_voltage());

    }

    for(int i = 0; i < pack->link_deformation_fl_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_fl_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_fl_wheel(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_FL_WHEEL"]["_timestamp"].push(pack->link_deformation_fl_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LINK_DEFORMATION_FL_WHEEL"]["rod_id"].push(pack->link_deformation_fl_wheel(i).rod_id());
		secondary_link_deformation_fl_wheel_rod_id_enum_to_string((secondary_link_deformation_fl_wheel_rod_id)pack->link_deformation_fl_wheel(i).rod_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_FL_WHEEL"]["rod_id"].push(buffer);
		(*net_signals)["LINK_DEFORMATION_FL_WHEEL"]["deformation"].push(pack->link_deformation_fl_wheel(i).deformation());

    }

    for(int i = 0; i < pack->link_deformation_fr_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_fr_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_fr_wheel(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_FR_WHEEL"]["_timestamp"].push(pack->link_deformation_fr_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LINK_DEFORMATION_FR_WHEEL"]["rod_id"].push(pack->link_deformation_fr_wheel(i).rod_id());
		secondary_link_deformation_fr_wheel_rod_id_enum_to_string((secondary_link_deformation_fr_wheel_rod_id)pack->link_deformation_fr_wheel(i).rod_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_FR_WHEEL"]["rod_id"].push(buffer);
		(*net_signals)["LINK_DEFORMATION_FR_WHEEL"]["deformation"].push(pack->link_deformation_fr_wheel(i).deformation());

    }

    for(int i = 0; i < pack->link_deformation_rl_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_rl_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_rl_wheel(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_RL_WHEEL"]["_timestamp"].push(pack->link_deformation_rl_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LINK_DEFORMATION_RL_WHEEL"]["rod_id"].push(pack->link_deformation_rl_wheel(i).rod_id());
		secondary_link_deformation_rl_wheel_rod_id_enum_to_string((secondary_link_deformation_rl_wheel_rod_id)pack->link_deformation_rl_wheel(i).rod_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_RL_WHEEL"]["rod_id"].push(buffer);
		(*net_signals)["LINK_DEFORMATION_RL_WHEEL"]["deformation"].push(pack->link_deformation_rl_wheel(i).deformation());

    }

    for(int i = 0; i < pack->link_deformation_rr_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_rr_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_rr_wheel(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_RR_WHEEL"]["_timestamp"].push(pack->link_deformation_rr_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LINK_DEFORMATION_RR_WHEEL"]["rod_id"].push(pack->link_deformation_rr_wheel(i).rod_id());
		secondary_link_deformation_rr_wheel_rod_id_enum_to_string((secondary_link_deformation_rr_wheel_rod_id)pack->link_deformation_rr_wheel(i).rod_id(), buffer);
		(*net_strings)["LINK_DEFORMATION_RR_WHEEL"]["rod_id"].push(buffer);
		(*net_signals)["LINK_DEFORMATION_RR_WHEEL"]["deformation"].push(pack->link_deformation_rr_wheel(i).deformation());

    }

    for(int i = 0; i < pack->link_deformation_set_calibration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation_set_calibration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation_set_calibration(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION_SET_CALIBRATION"]["_timestamp"].push(pack->link_deformation_set_calibration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->ammo_compression_set_calibration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ammo_compression_set_calibration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ammo_compression_set_calibration(i)._inner_timestamp();
        (*net_signals)["AMMO_COMPRESSION_SET_CALIBRATION"]["_timestamp"].push(pack->ammo_compression_set_calibration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->debug_signal_5_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_5(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_5(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_5"]["_timestamp"].push(pack->debug_signal_5(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_5"]["device_id"].push(pack->debug_signal_5(i).device_id());
		secondary_debug_signal_5_device_id_enum_to_string((secondary_debug_signal_5_device_id)pack->debug_signal_5(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_5"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_5"]["field_1"].push(pack->debug_signal_5(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_5"]["field_2"].push(pack->debug_signal_5(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_5"]["field_3"].push(pack->debug_signal_5(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_6_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_6(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_6(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_6"]["_timestamp"].push(pack->debug_signal_6(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_6"]["device_id"].push(pack->debug_signal_6(i).device_id());
		secondary_debug_signal_6_device_id_enum_to_string((secondary_debug_signal_6_device_id)pack->debug_signal_6(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_6"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_6"]["field_1"].push(pack->debug_signal_6(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_6"]["field_2"].push(pack->debug_signal_6(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_6"]["field_3"].push(pack->debug_signal_6(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_7_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_7(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_7(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_7"]["_timestamp"].push(pack->debug_signal_7(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_7"]["device_id"].push(pack->debug_signal_7(i).device_id());
		secondary_debug_signal_7_device_id_enum_to_string((secondary_debug_signal_7_device_id)pack->debug_signal_7(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_7"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_7"]["field_1"].push(pack->debug_signal_7(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_7"]["field_2"].push(pack->debug_signal_7(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_7"]["field_3"].push(pack->debug_signal_7(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_8_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_8(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_8(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_8"]["_timestamp"].push(pack->debug_signal_8(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_8"]["device_id"].push(pack->debug_signal_8(i).device_id());
		secondary_debug_signal_8_device_id_enum_to_string((secondary_debug_signal_8_device_id)pack->debug_signal_8(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_8"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_8"]["field_1"].push(pack->debug_signal_8(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_8"]["field_2"].push(pack->debug_signal_8(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_8"]["field_3"].push(pack->debug_signal_8(i).field_3());

    }

    for(int i = 0; i < pack->cooling_temp_pumps_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->cooling_temp_pumps(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->cooling_temp_pumps(i)._inner_timestamp();
        (*net_signals)["COOLING_TEMP_PUMPS"]["_timestamp"].push(pack->cooling_temp_pumps(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["COOLING_TEMP_PUMPS"]["input"].push(pack->cooling_temp_pumps(i).input());
		(*net_signals)["COOLING_TEMP_PUMPS"]["output"].push(pack->cooling_temp_pumps(i).output());

    }

    for(int i = 0; i < pack->cooling_temp_radiators_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->cooling_temp_radiators(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->cooling_temp_radiators(i)._inner_timestamp();
        (*net_signals)["COOLING_TEMP_RADIATORS"]["_timestamp"].push(pack->cooling_temp_radiators(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["COOLING_TEMP_RADIATORS"]["air_temp"].push(pack->cooling_temp_radiators(i).air_temp());

    }

    for(int i = 0; i < pack->lateral_controller_preview_point_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lateral_controller_preview_point_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lateral_controller_preview_point_errors(i)._inner_timestamp();
        (*net_signals)["LATERAL_CONTROLLER_PREVIEW_POINT_ERRORS"]["_timestamp"].push(pack->lateral_controller_preview_point_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LATERAL_CONTROLLER_PREVIEW_POINT_ERRORS"]["heading"].push(pack->lateral_controller_preview_point_errors(i).heading());
		(*net_signals)["LATERAL_CONTROLLER_PREVIEW_POINT_ERRORS"]["distance"].push(pack->lateral_controller_preview_point_errors(i).distance());

    }

    for(int i = 0; i < pack->lateral_controller_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lateral_controller_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lateral_controller_errors(i)._inner_timestamp();
        (*net_signals)["LATERAL_CONTROLLER_ERRORS"]["_timestamp"].push(pack->lateral_controller_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LATERAL_CONTROLLER_ERRORS"]["com_distance"].push(pack->lateral_controller_errors(i).com_distance());

    }

}

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, device_t* device) {
    int index = secondary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 0: {
            secondary_acquisinator_jmp_to_blt_t* msg = (secondary_acquisinator_jmp_to_blt_t*)(device->message);
            secondary::ACQUISINATOR_JMP_TO_BLT* proto_msg = pack->add_acquisinator_jmp_to_blt();
			proto_msg->set_acquisinatore_id(msg->acquisinatore_id);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1: {
            secondary_acquisinator_flash_0_tx_t* msg = (secondary_acquisinator_flash_0_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_0_TX* proto_msg = pack->add_acquisinator_flash_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2: {
            secondary_acquisinator_flash_0_rx_t* msg = (secondary_acquisinator_flash_0_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_0_RX* proto_msg = pack->add_acquisinator_flash_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 3: {
            secondary_acquisinator_flash_1_tx_t* msg = (secondary_acquisinator_flash_1_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_1_TX* proto_msg = pack->add_acquisinator_flash_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            secondary_acquisinator_flash_1_rx_t* msg = (secondary_acquisinator_flash_1_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_1_RX* proto_msg = pack->add_acquisinator_flash_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            secondary_acquisinator_flash_2_tx_t* msg = (secondary_acquisinator_flash_2_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_2_TX* proto_msg = pack->add_acquisinator_flash_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            secondary_acquisinator_flash_2_rx_t* msg = (secondary_acquisinator_flash_2_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_2_RX* proto_msg = pack->add_acquisinator_flash_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            secondary_acquisinator_flash_3_tx_t* msg = (secondary_acquisinator_flash_3_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_3_TX* proto_msg = pack->add_acquisinator_flash_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            secondary_acquisinator_flash_3_rx_t* msg = (secondary_acquisinator_flash_3_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_3_RX* proto_msg = pack->add_acquisinator_flash_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            secondary_acquisinator_flash_4_tx_t* msg = (secondary_acquisinator_flash_4_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_4_TX* proto_msg = pack->add_acquisinator_flash_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            secondary_acquisinator_flash_4_rx_t* msg = (secondary_acquisinator_flash_4_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_4_RX* proto_msg = pack->add_acquisinator_flash_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 11: {
            secondary_acquisinator_flash_5_tx_t* msg = (secondary_acquisinator_flash_5_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_5_TX* proto_msg = pack->add_acquisinator_flash_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 12: {
            secondary_acquisinator_flash_5_rx_t* msg = (secondary_acquisinator_flash_5_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_5_RX* proto_msg = pack->add_acquisinator_flash_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 13: {
            secondary_acquisinator_flash_6_tx_t* msg = (secondary_acquisinator_flash_6_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_6_TX* proto_msg = pack->add_acquisinator_flash_6_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 14: {
            secondary_acquisinator_flash_6_rx_t* msg = (secondary_acquisinator_flash_6_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_6_RX* proto_msg = pack->add_acquisinator_flash_6_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 15: {
            secondary_acquisinator_flash_7_tx_t* msg = (secondary_acquisinator_flash_7_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_7_TX* proto_msg = pack->add_acquisinator_flash_7_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            secondary_acquisinator_flash_7_rx_t* msg = (secondary_acquisinator_flash_7_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_7_RX* proto_msg = pack->add_acquisinator_flash_7_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            secondary_acquisinator_flash_8_tx_t* msg = (secondary_acquisinator_flash_8_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_8_TX* proto_msg = pack->add_acquisinator_flash_8_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            secondary_acquisinator_flash_8_rx_t* msg = (secondary_acquisinator_flash_8_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_8_RX* proto_msg = pack->add_acquisinator_flash_8_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 19: {
            secondary_acquisinator_flash_9_tx_t* msg = (secondary_acquisinator_flash_9_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_9_TX* proto_msg = pack->add_acquisinator_flash_9_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 20: {
            secondary_acquisinator_flash_9_rx_t* msg = (secondary_acquisinator_flash_9_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_9_RX* proto_msg = pack->add_acquisinator_flash_9_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            secondary_acquisinator_flash_10_tx_t* msg = (secondary_acquisinator_flash_10_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_10_TX* proto_msg = pack->add_acquisinator_flash_10_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            secondary_acquisinator_flash_10_rx_t* msg = (secondary_acquisinator_flash_10_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_10_RX* proto_msg = pack->add_acquisinator_flash_10_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            secondary_acquisinator_flash_11_tx_t* msg = (secondary_acquisinator_flash_11_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_11_TX* proto_msg = pack->add_acquisinator_flash_11_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
            secondary_acquisinator_flash_11_rx_t* msg = (secondary_acquisinator_flash_11_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_11_RX* proto_msg = pack->add_acquisinator_flash_11_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 25: {
            secondary_acquisinator_flash_12_tx_t* msg = (secondary_acquisinator_flash_12_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_12_TX* proto_msg = pack->add_acquisinator_flash_12_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 26: {
            secondary_acquisinator_flash_12_rx_t* msg = (secondary_acquisinator_flash_12_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_12_RX* proto_msg = pack->add_acquisinator_flash_12_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 27: {
            secondary_acquisinator_flash_13_tx_t* msg = (secondary_acquisinator_flash_13_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_13_TX* proto_msg = pack->add_acquisinator_flash_13_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 28: {
            secondary_acquisinator_flash_13_rx_t* msg = (secondary_acquisinator_flash_13_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_13_RX* proto_msg = pack->add_acquisinator_flash_13_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 29: {
            secondary_acquisinator_flash_14_tx_t* msg = (secondary_acquisinator_flash_14_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_14_TX* proto_msg = pack->add_acquisinator_flash_14_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 30: {
            secondary_acquisinator_flash_14_rx_t* msg = (secondary_acquisinator_flash_14_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_14_RX* proto_msg = pack->add_acquisinator_flash_14_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 31: {
            secondary_acquisinator_flash_15_tx_t* msg = (secondary_acquisinator_flash_15_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_15_TX* proto_msg = pack->add_acquisinator_flash_15_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 32: {
            secondary_acquisinator_flash_15_rx_t* msg = (secondary_acquisinator_flash_15_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_15_RX* proto_msg = pack->add_acquisinator_flash_15_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 33: {
            secondary_acquisinator_flash_16_tx_t* msg = (secondary_acquisinator_flash_16_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_16_TX* proto_msg = pack->add_acquisinator_flash_16_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 34: {
            secondary_acquisinator_flash_16_rx_t* msg = (secondary_acquisinator_flash_16_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_16_RX* proto_msg = pack->add_acquisinator_flash_16_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 35: {
            secondary_acquisinator_flash_17_tx_t* msg = (secondary_acquisinator_flash_17_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_17_TX* proto_msg = pack->add_acquisinator_flash_17_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 36: {
            secondary_acquisinator_flash_17_rx_t* msg = (secondary_acquisinator_flash_17_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_17_RX* proto_msg = pack->add_acquisinator_flash_17_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 37: {
            secondary_acquisinator_flash_18_tx_t* msg = (secondary_acquisinator_flash_18_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_18_TX* proto_msg = pack->add_acquisinator_flash_18_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 38: {
            secondary_acquisinator_flash_18_rx_t* msg = (secondary_acquisinator_flash_18_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_18_RX* proto_msg = pack->add_acquisinator_flash_18_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 39: {
            secondary_acquisinator_flash_19_tx_t* msg = (secondary_acquisinator_flash_19_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_19_TX* proto_msg = pack->add_acquisinator_flash_19_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 40: {
            secondary_acquisinator_flash_19_rx_t* msg = (secondary_acquisinator_flash_19_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_19_RX* proto_msg = pack->add_acquisinator_flash_19_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 41: {
            secondary_acquisinator_flash_20_tx_t* msg = (secondary_acquisinator_flash_20_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_20_TX* proto_msg = pack->add_acquisinator_flash_20_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 42: {
            secondary_acquisinator_flash_20_rx_t* msg = (secondary_acquisinator_flash_20_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_20_RX* proto_msg = pack->add_acquisinator_flash_20_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 43: {
            secondary_acquisinator_flash_21_tx_t* msg = (secondary_acquisinator_flash_21_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_21_TX* proto_msg = pack->add_acquisinator_flash_21_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 44: {
            secondary_acquisinator_flash_21_rx_t* msg = (secondary_acquisinator_flash_21_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_21_RX* proto_msg = pack->add_acquisinator_flash_21_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 45: {
            secondary_acquisinator_flash_22_tx_t* msg = (secondary_acquisinator_flash_22_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_22_TX* proto_msg = pack->add_acquisinator_flash_22_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 46: {
            secondary_acquisinator_flash_22_rx_t* msg = (secondary_acquisinator_flash_22_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_22_RX* proto_msg = pack->add_acquisinator_flash_22_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 47: {
            secondary_acquisinator_flash_23_tx_t* msg = (secondary_acquisinator_flash_23_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_23_TX* proto_msg = pack->add_acquisinator_flash_23_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 48: {
            secondary_acquisinator_flash_23_rx_t* msg = (secondary_acquisinator_flash_23_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_23_RX* proto_msg = pack->add_acquisinator_flash_23_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 49: {
            secondary_acquisinator_flash_24_tx_t* msg = (secondary_acquisinator_flash_24_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_24_TX* proto_msg = pack->add_acquisinator_flash_24_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 50: {
            secondary_acquisinator_flash_24_rx_t* msg = (secondary_acquisinator_flash_24_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_24_RX* proto_msg = pack->add_acquisinator_flash_24_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 51: {
            secondary_acquisinator_flash_25_tx_t* msg = (secondary_acquisinator_flash_25_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_25_TX* proto_msg = pack->add_acquisinator_flash_25_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 52: {
            secondary_acquisinator_flash_25_rx_t* msg = (secondary_acquisinator_flash_25_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_25_RX* proto_msg = pack->add_acquisinator_flash_25_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 53: {
            secondary_acquisinator_flash_26_tx_t* msg = (secondary_acquisinator_flash_26_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_26_TX* proto_msg = pack->add_acquisinator_flash_26_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 54: {
            secondary_acquisinator_flash_26_rx_t* msg = (secondary_acquisinator_flash_26_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_26_RX* proto_msg = pack->add_acquisinator_flash_26_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 55: {
            secondary_acquisinator_flash_27_tx_t* msg = (secondary_acquisinator_flash_27_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_27_TX* proto_msg = pack->add_acquisinator_flash_27_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 56: {
            secondary_acquisinator_flash_27_rx_t* msg = (secondary_acquisinator_flash_27_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_27_RX* proto_msg = pack->add_acquisinator_flash_27_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 57: {
            secondary_acquisinator_flash_28_tx_t* msg = (secondary_acquisinator_flash_28_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_28_TX* proto_msg = pack->add_acquisinator_flash_28_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 58: {
            secondary_acquisinator_flash_28_rx_t* msg = (secondary_acquisinator_flash_28_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_28_RX* proto_msg = pack->add_acquisinator_flash_28_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 59: {
            secondary_acquisinator_flash_29_tx_t* msg = (secondary_acquisinator_flash_29_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_29_TX* proto_msg = pack->add_acquisinator_flash_29_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 60: {
            secondary_acquisinator_flash_29_rx_t* msg = (secondary_acquisinator_flash_29_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_29_RX* proto_msg = pack->add_acquisinator_flash_29_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 61: {
            secondary_acquisinator_flash_30_tx_t* msg = (secondary_acquisinator_flash_30_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_30_TX* proto_msg = pack->add_acquisinator_flash_30_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 62: {
            secondary_acquisinator_flash_30_rx_t* msg = (secondary_acquisinator_flash_30_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_30_RX* proto_msg = pack->add_acquisinator_flash_30_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 63: {
            secondary_acquisinator_flash_31_tx_t* msg = (secondary_acquisinator_flash_31_tx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_31_TX* proto_msg = pack->add_acquisinator_flash_31_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 64: {
            secondary_acquisinator_flash_31_rx_t* msg = (secondary_acquisinator_flash_31_rx_t*)(device->message);
            secondary::ACQUISINATOR_FLASH_31_RX* proto_msg = pack->add_acquisinator_flash_31_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 700: {
            secondary_acquisinator_version_t* msg = (secondary_acquisinator_version_t*)(device->message);
            secondary::ACQUISINATOR_VERSION* proto_msg = pack->add_acquisinator_version();
			proto_msg->set_acquisinator_id(msg->acquisinator_id);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1260: {
            secondary_imu_angular_rate_converted_t* msg = (secondary_imu_angular_rate_converted_t*)(device->message);
            secondary::IMU_ANGULAR_RATE* proto_msg = pack->add_imu_angular_rate();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            secondary_imu_acceleration_converted_t* msg = (secondary_imu_acceleration_converted_t*)(device->message);
            secondary::IMU_ACCELERATION* proto_msg = pack->add_imu_acceleration();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);
			proto_msg->set_imu_temperature(msg->imu_temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1456: {
            secondary_irts_fl_0_converted_t* msg = (secondary_irts_fl_0_converted_t*)(device->message);
            secondary::IRTS_FL_0* proto_msg = pack->add_irts_fl_0();
			proto_msg->set_channel1(msg->channel1);
			proto_msg->set_channel2(msg->channel2);
			proto_msg->set_channel3(msg->channel3);
			proto_msg->set_channel4(msg->channel4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1457: {
            secondary_irts_fl_1_converted_t* msg = (secondary_irts_fl_1_converted_t*)(device->message);
            secondary::IRTS_FL_1* proto_msg = pack->add_irts_fl_1();
			proto_msg->set_channel5(msg->channel5);
			proto_msg->set_channel6(msg->channel6);
			proto_msg->set_channel7(msg->channel7);
			proto_msg->set_channel8(msg->channel8);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1458: {
            secondary_irts_fl_2_converted_t* msg = (secondary_irts_fl_2_converted_t*)(device->message);
            secondary::IRTS_FL_2* proto_msg = pack->add_irts_fl_2();
			proto_msg->set_channel9(msg->channel9);
			proto_msg->set_channel10(msg->channel10);
			proto_msg->set_channel11(msg->channel11);
			proto_msg->set_channel12(msg->channel12);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1459: {
            secondary_irts_fl_3_converted_t* msg = (secondary_irts_fl_3_converted_t*)(device->message);
            secondary::IRTS_FL_3* proto_msg = pack->add_irts_fl_3();
			proto_msg->set_channel13(msg->channel13);
			proto_msg->set_channel14(msg->channel14);
			proto_msg->set_channel15(msg->channel15);
			proto_msg->set_channel16(msg->channel16);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1464: {
            secondary_irts_fr_0_converted_t* msg = (secondary_irts_fr_0_converted_t*)(device->message);
            secondary::IRTS_FR_0* proto_msg = pack->add_irts_fr_0();
			proto_msg->set_channel1(msg->channel1);
			proto_msg->set_channel2(msg->channel2);
			proto_msg->set_channel3(msg->channel3);
			proto_msg->set_channel4(msg->channel4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1465: {
            secondary_irts_fr_1_converted_t* msg = (secondary_irts_fr_1_converted_t*)(device->message);
            secondary::IRTS_FR_1* proto_msg = pack->add_irts_fr_1();
			proto_msg->set_channel5(msg->channel5);
			proto_msg->set_channel6(msg->channel6);
			proto_msg->set_channel7(msg->channel7);
			proto_msg->set_channel8(msg->channel8);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1466: {
            secondary_irts_fr_2_converted_t* msg = (secondary_irts_fr_2_converted_t*)(device->message);
            secondary::IRTS_FR_2* proto_msg = pack->add_irts_fr_2();
			proto_msg->set_channel9(msg->channel9);
			proto_msg->set_channel10(msg->channel10);
			proto_msg->set_channel11(msg->channel11);
			proto_msg->set_channel12(msg->channel12);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1467: {
            secondary_irts_fr_3_converted_t* msg = (secondary_irts_fr_3_converted_t*)(device->message);
            secondary::IRTS_FR_3* proto_msg = pack->add_irts_fr_3();
			proto_msg->set_channel13(msg->channel13);
			proto_msg->set_channel14(msg->channel14);
			proto_msg->set_channel15(msg->channel15);
			proto_msg->set_channel16(msg->channel16);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1468: {
            secondary_irts_rl_0_converted_t* msg = (secondary_irts_rl_0_converted_t*)(device->message);
            secondary::IRTS_RL_0* proto_msg = pack->add_irts_rl_0();
			proto_msg->set_channel1(msg->channel1);
			proto_msg->set_channel2(msg->channel2);
			proto_msg->set_channel3(msg->channel3);
			proto_msg->set_channel4(msg->channel4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1469: {
            secondary_irts_rl_1_converted_t* msg = (secondary_irts_rl_1_converted_t*)(device->message);
            secondary::IRTS_RL_1* proto_msg = pack->add_irts_rl_1();
			proto_msg->set_channel5(msg->channel5);
			proto_msg->set_channel6(msg->channel6);
			proto_msg->set_channel7(msg->channel7);
			proto_msg->set_channel8(msg->channel8);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1470: {
            secondary_irts_rl_2_converted_t* msg = (secondary_irts_rl_2_converted_t*)(device->message);
            secondary::IRTS_RL_2* proto_msg = pack->add_irts_rl_2();
			proto_msg->set_channel9(msg->channel9);
			proto_msg->set_channel10(msg->channel10);
			proto_msg->set_channel11(msg->channel11);
			proto_msg->set_channel12(msg->channel12);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1471: {
            secondary_irts_rl_3_converted_t* msg = (secondary_irts_rl_3_converted_t*)(device->message);
            secondary::IRTS_RL_3* proto_msg = pack->add_irts_rl_3();
			proto_msg->set_channel13(msg->channel13);
			proto_msg->set_channel14(msg->channel14);
			proto_msg->set_channel15(msg->channel15);
			proto_msg->set_channel16(msg->channel16);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1200: {
            secondary_irts_rr_0_converted_t* msg = (secondary_irts_rr_0_converted_t*)(device->message);
            secondary::IRTS_RR_0* proto_msg = pack->add_irts_rr_0();
			proto_msg->set_channel1(msg->channel1);
			proto_msg->set_channel2(msg->channel2);
			proto_msg->set_channel3(msg->channel3);
			proto_msg->set_channel4(msg->channel4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1201: {
            secondary_irts_rr_1_converted_t* msg = (secondary_irts_rr_1_converted_t*)(device->message);
            secondary::IRTS_RR_1* proto_msg = pack->add_irts_rr_1();
			proto_msg->set_channel5(msg->channel5);
			proto_msg->set_channel6(msg->channel6);
			proto_msg->set_channel7(msg->channel7);
			proto_msg->set_channel8(msg->channel8);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1202: {
            secondary_irts_rr_2_converted_t* msg = (secondary_irts_rr_2_converted_t*)(device->message);
            secondary::IRTS_RR_2* proto_msg = pack->add_irts_rr_2();
			proto_msg->set_channel9(msg->channel9);
			proto_msg->set_channel10(msg->channel10);
			proto_msg->set_channel11(msg->channel11);
			proto_msg->set_channel12(msg->channel12);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1203: {
            secondary_irts_rr_3_converted_t* msg = (secondary_irts_rr_3_converted_t*)(device->message);
            secondary::IRTS_RR_3* proto_msg = pack->add_irts_rr_3();
			proto_msg->set_channel13(msg->channel13);
			proto_msg->set_channel14(msg->channel14);
			proto_msg->set_channel15(msg->channel15);
			proto_msg->set_channel16(msg->channel16);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1536: {
            secondary_vehicle_position_converted_t* msg = (secondary_vehicle_position_converted_t*)(device->message);
            secondary::VEHICLE_POSITION* proto_msg = pack->add_vehicle_position();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_heading(msg->heading);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1544: {
            secondary_vehicle_speed_converted_t* msg = (secondary_vehicle_speed_converted_t*)(device->message);
            secondary::VEHICLE_SPEED* proto_msg = pack->add_vehicle_speed();
			proto_msg->set_u(msg->u);
			proto_msg->set_v(msg->v);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1552: {
            secondary_vehicle_curvilinear_coordinates_converted_t* msg = (secondary_vehicle_curvilinear_coordinates_converted_t*)(device->message);
            secondary::VEHICLE_CURVILINEAR_COORDINATES* proto_msg = pack->add_vehicle_curvilinear_coordinates();
			proto_msg->set_s(msg->s);
			proto_msg->set_n(msg->n);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1560: {
            secondary_front_angular_velocity_converted_t* msg = (secondary_front_angular_velocity_converted_t*)(device->message);
            secondary::FRONT_ANGULAR_VELOCITY* proto_msg = pack->add_front_angular_velocity();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            secondary_rear_angular_velocity_converted_t* msg = (secondary_rear_angular_velocity_converted_t*)(device->message);
            secondary::REAR_ANGULAR_VELOCITY* proto_msg = pack->add_rear_angular_velocity();
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1576: {
            secondary_hv_soc_estimation_state_converted_t* msg = (secondary_hv_soc_estimation_state_converted_t*)(device->message);
            secondary::HV_SOC_ESTIMATION_STATE* proto_msg = pack->add_hv_soc_estimation_state();
			proto_msg->set_soc(msg->soc);
			proto_msg->set_rc1(msg->rc1);
			proto_msg->set_rc2(msg->rc2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1584: {
            secondary_hv_soc_estimation_covariance_converted_t* msg = (secondary_hv_soc_estimation_covariance_converted_t*)(device->message);
            secondary::HV_SOC_ESTIMATION_COVARIANCE* proto_msg = pack->add_hv_soc_estimation_covariance();
			proto_msg->set_soc(msg->soc);
			proto_msg->set_rc1(msg->rc1);
			proto_msg->set_rc2(msg->rc2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1592: {
            secondary_lv_soc_estimation_state_converted_t* msg = (secondary_lv_soc_estimation_state_converted_t*)(device->message);
            secondary::LV_SOC_ESTIMATION_STATE* proto_msg = pack->add_lv_soc_estimation_state();
			proto_msg->set_soc(msg->soc);
			proto_msg->set_rc1(msg->rc1);
			proto_msg->set_rc2(msg->rc2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            secondary_lv_soc_estimation_covariance_converted_t* msg = (secondary_lv_soc_estimation_covariance_converted_t*)(device->message);
            secondary::LV_SOC_ESTIMATION_COVARIANCE* proto_msg = pack->add_lv_soc_estimation_covariance();
			proto_msg->set_soc(msg->soc);
			proto_msg->set_rc1(msg->rc1);
			proto_msg->set_rc2(msg->rc2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1608: {
            secondary_pedal_throttle_converted_t* msg = (secondary_pedal_throttle_converted_t*)(device->message);
            secondary::PEDAL_THROTTLE* proto_msg = pack->add_pedal_throttle();
			proto_msg->set_throttle(msg->throttle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1616: {
            secondary_pedal_brakes_pressure_converted_t* msg = (secondary_pedal_brakes_pressure_converted_t*)(device->message);
            secondary::PEDAL_BRAKES_PRESSURE* proto_msg = pack->add_pedal_brakes_pressure();
			proto_msg->set_front(msg->front);
			proto_msg->set_rear(msg->rear);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1624: {
            secondary_steer_angle_converted_t* msg = (secondary_steer_angle_converted_t*)(device->message);
            secondary::STEER_ANGLE* proto_msg = pack->add_steer_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
            secondary_odometer_converted_t* msg = (secondary_odometer_converted_t*)(device->message);
            secondary::ODOMETER* proto_msg = pack->add_odometer();
			proto_msg->set_kilometers(msg->kilometers);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1640: {
            secondary_tpms_pressure_t* msg = (secondary_tpms_pressure_t*)(device->message);
            secondary::TPMS_PRESSURE* proto_msg = pack->add_tpms_pressure();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1648: {
            secondary_tpms_temperature_t* msg = (secondary_tpms_temperature_t*)(device->message);
            secondary::TPMS_TEMPERATURE* proto_msg = pack->add_tpms_temperature();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1656: {
            secondary_tlm_unix_timestamp_t* msg = (secondary_tlm_unix_timestamp_t*)(device->message);
            secondary::TLM_UNIX_TIMESTAMP* proto_msg = pack->add_tlm_unix_timestamp();
			proto_msg->set_timestamp(msg->timestamp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1664: {
            secondary_tlm_lap_time_converted_t* msg = (secondary_tlm_lap_time_converted_t*)(device->message);
            secondary::TLM_LAP_TIME* proto_msg = pack->add_tlm_lap_time();
			proto_msg->set_lap_count(msg->lap_count);
			proto_msg->set_lap_time(msg->lap_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1672: {
            secondary_tlm_laps_stats_converted_t* msg = (secondary_tlm_laps_stats_converted_t*)(device->message);
            secondary::TLM_LAPS_STATS* proto_msg = pack->add_tlm_laps_stats();
			proto_msg->set_lap_number(msg->lap_number);
			proto_msg->set_best_time(msg->best_time);
			proto_msg->set_last_time(msg->last_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1680: {
            secondary_tlm_network_interface_t* msg = (secondary_tlm_network_interface_t*)(device->message);
            secondary::TLM_NETWORK_INTERFACE* proto_msg = pack->add_tlm_network_interface();
			proto_msg->set_iname_0(msg->iname_0);
			proto_msg->set_iname_1(msg->iname_1);
			proto_msg->set_iname_2(msg->iname_2);
			proto_msg->set_iname_3(msg->iname_3);
			proto_msg->set_ip_address(msg->ip_address);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1688: {
            secondary_front_ammo_compression_converted_t* msg = (secondary_front_ammo_compression_converted_t*)(device->message);
            secondary::FRONT_AMMO_COMPRESSION* proto_msg = pack->add_front_ammo_compression();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1696: {
            secondary_rear_ammo_compression_converted_t* msg = (secondary_rear_ammo_compression_converted_t*)(device->message);
            secondary::REAR_AMMO_COMPRESSION* proto_msg = pack->add_rear_ammo_compression();
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1704: {
            secondary_acquisinator_calibrations_offsets_converted_t* msg = (secondary_acquisinator_calibrations_offsets_converted_t*)(device->message);
            secondary::ACQUISINATOR_CALIBRATIONS_OFFSETS* proto_msg = pack->add_acquisinator_calibrations_offsets();
			proto_msg->set_acquisinator_id(msg->acquisinator_id);
			proto_msg->set_offset1(msg->offset1);
			proto_msg->set_offset2(msg->offset2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1712: {
            secondary_acquisinator_errors_t* msg = (secondary_acquisinator_errors_t*)(device->message);
            secondary::ACQUISINATOR_ERRORS* proto_msg = pack->add_acquisinator_errors();
			proto_msg->set_acquisinator_id(msg->acquisinator_id);
			proto_msg->set_acquisinator_errors_acquisinatore_led_code_can_not_working(msg->acquisinator_errors_acquisinatore_led_code_can_not_working);
			proto_msg->set_acquisinator_errors_acquisinatore_led_code_spi_error(msg->acquisinator_errors_acquisinatore_led_code_spi_error);
			proto_msg->set_acquisinator_errors_acquisinatore_led_code_read_write_flash(msg->acquisinator_errors_acquisinatore_led_code_read_write_flash);
			proto_msg->set_acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id(msg->acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1720: {
            secondary_link_deformation_debug_voltages_converted_t* msg = (secondary_link_deformation_debug_voltages_converted_t*)(device->message);
            secondary::LINK_DEFORMATION_DEBUG_VOLTAGES* proto_msg = pack->add_link_deformation_debug_voltages();
			proto_msg->set_wheel_id((secondary::secondary_link_deformation_debug_voltages_wheel_id)msg->wheel_id);
			proto_msg->set_rod_id((secondary::secondary_link_deformation_debug_voltages_rod_id)msg->rod_id);
			proto_msg->set_raw_voltage(msg->raw_voltage);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1728: {
            secondary_link_deformation_fl_wheel_converted_t* msg = (secondary_link_deformation_fl_wheel_converted_t*)(device->message);
            secondary::LINK_DEFORMATION_FL_WHEEL* proto_msg = pack->add_link_deformation_fl_wheel();
			proto_msg->set_rod_id((secondary::secondary_link_deformation_fl_wheel_rod_id)msg->rod_id);
			proto_msg->set_deformation(msg->deformation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1736: {
            secondary_link_deformation_fr_wheel_converted_t* msg = (secondary_link_deformation_fr_wheel_converted_t*)(device->message);
            secondary::LINK_DEFORMATION_FR_WHEEL* proto_msg = pack->add_link_deformation_fr_wheel();
			proto_msg->set_rod_id((secondary::secondary_link_deformation_fr_wheel_rod_id)msg->rod_id);
			proto_msg->set_deformation(msg->deformation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1744: {
            secondary_link_deformation_rl_wheel_converted_t* msg = (secondary_link_deformation_rl_wheel_converted_t*)(device->message);
            secondary::LINK_DEFORMATION_RL_WHEEL* proto_msg = pack->add_link_deformation_rl_wheel();
			proto_msg->set_rod_id((secondary::secondary_link_deformation_rl_wheel_rod_id)msg->rod_id);
			proto_msg->set_deformation(msg->deformation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1752: {
            secondary_link_deformation_rr_wheel_converted_t* msg = (secondary_link_deformation_rr_wheel_converted_t*)(device->message);
            secondary::LINK_DEFORMATION_RR_WHEEL* proto_msg = pack->add_link_deformation_rr_wheel();
			proto_msg->set_rod_id((secondary::secondary_link_deformation_rr_wheel_rod_id)msg->rod_id);
			proto_msg->set_deformation(msg->deformation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 72: {
            secondary_link_deformation_set_calibration_t* msg = (secondary_link_deformation_set_calibration_t*)(device->message);
            secondary::LINK_DEFORMATION_SET_CALIBRATION* proto_msg = pack->add_link_deformation_set_calibration();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 80: {
            secondary_ammo_compression_set_calibration_t* msg = (secondary_ammo_compression_set_calibration_t*)(device->message);
            secondary::AMMO_COMPRESSION_SET_CALIBRATION* proto_msg = pack->add_ammo_compression_set_calibration();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1760: {
            secondary_debug_signal_5_converted_t* msg = (secondary_debug_signal_5_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_5* proto_msg = pack->add_debug_signal_5();
			proto_msg->set_device_id((secondary::secondary_debug_signal_5_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1768: {
            secondary_debug_signal_6_converted_t* msg = (secondary_debug_signal_6_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_6* proto_msg = pack->add_debug_signal_6();
			proto_msg->set_device_id((secondary::secondary_debug_signal_6_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1776: {
            secondary_debug_signal_7_converted_t* msg = (secondary_debug_signal_7_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_7* proto_msg = pack->add_debug_signal_7();
			proto_msg->set_device_id((secondary::secondary_debug_signal_7_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1784: {
            secondary_debug_signal_8_converted_t* msg = (secondary_debug_signal_8_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_8* proto_msg = pack->add_debug_signal_8();
			proto_msg->set_device_id((secondary::secondary_debug_signal_8_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1792: {
            secondary_cooling_temp_pumps_converted_t* msg = (secondary_cooling_temp_pumps_converted_t*)(device->message);
            secondary::COOLING_TEMP_PUMPS* proto_msg = pack->add_cooling_temp_pumps();
			proto_msg->set_input(msg->input);
			proto_msg->set_output(msg->output);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1800: {
            secondary_cooling_temp_radiators_converted_t* msg = (secondary_cooling_temp_radiators_converted_t*)(device->message);
            secondary::COOLING_TEMP_RADIATORS* proto_msg = pack->add_cooling_temp_radiators();
			proto_msg->set_air_temp(msg->air_temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1808: {
            secondary_lateral_controller_preview_point_errors_converted_t* msg = (secondary_lateral_controller_preview_point_errors_converted_t*)(device->message);
            secondary::LATERAL_CONTROLLER_PREVIEW_POINT_ERRORS* proto_msg = pack->add_lateral_controller_preview_point_errors();
			proto_msg->set_heading(msg->heading);
			proto_msg->set_distance(msg->distance);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1816: {
            secondary_lateral_controller_errors_converted_t* msg = (secondary_lateral_controller_errors_converted_t*)(device->message);
            secondary::LATERAL_CONTROLLER_ERRORS* proto_msg = pack->add_lateral_controller_errors();
			proto_msg->set_com_distance(msg->com_distance);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // secondary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // secondary_PROTO_INTERFACE_H
