#include "canlib_device.h"

void device_init(device_t *device) {
    device->message = NULL;
    device->_converted = NULL;
    device->_raw = NULL;
    device->_size_raw = 0;
    device->_size_converted = 0;
}
void device_preallocate(device_t *device, int bytes){
    if(device->_size_raw > 0)
        free(device->_raw);
    if(device->_size_converted > 0)
        free(device->_converted);
    device->_raw = malloc(bytes);
    device->_converted = malloc(bytes);
    device->_size_converted = device->_size_raw = bytes;
}
void device_free(device_t *device) {
    free(device->_raw);
    free(device->_converted);
    device->message = NULL;
    device->_raw = NULL;
    device->_converted = NULL;
    device->_size_raw = 0;
    device->_size_converted = 0;
}
void device_set_address(device_t *device, void* raw, size_t raw_size, void *converted, size_t converted_size) {
    device->_raw = raw;
    device->_converted = converted;
    device->_size_raw = raw_size;
    device->_size_converted = converted_size;
}
