#ifndef CANLIB_DEVICE_H
#define CANLIB_DEVICE_H

#include <stddef.h>
#include <stdlib.h>

typedef struct {
    void* message;
    void* _converted;
    void* _raw;
    int _size_raw;
    int _size_converted;
} device_t;
void device_init(device_t *device);
void device_preallocate(device_t *device, int bytes);
void device_free(device_t *device);
void device_set_address(device_t *device, void* raw, size_t raw_size, void *converted, size_t converted_size);

#endif // CANLIB_DEVICE_H
