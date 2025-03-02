#ifndef ENCODER_H
#define ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"

uint16_t encoder_getcounter (uint8_t name);
void encoder_setcounter (uint8_t name, uint16_t value);

#ifdef __cplusplus
}
#endif

#endif //ENCODER_H
