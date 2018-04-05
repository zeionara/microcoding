#include <stdint.h>

#include "config.h"

#include "types.h"
#include "cpu_model.h"


Instruction program_memory[] = {

    // MOV_DIRECT test
    { MOV_DIRECT,        0x0A       }, // 0

    // MOV_R_N_IMMEDIATE and DEC_R_DIRECT test
    { MOV_R_N_IMMEDIATE, 0x00, 0xFF }, // 1
    { DEC_R_DIRECT,      0x00       }, // 2

    // MOV_R_N_IMMEDIATE and DEC_R_INDIRECT test
    { MOV_R_N_IMMEDIATE, 0x01, 0x00 }, // 3
    { DEC_R_INDIRECT,    0x01       }, // 4
    { DEC_R_INDIRECT,    0x01       }, // 5

    // ANL_C_NOT_BIT_TEST
    { ANL_C_NOT_BIT,     0x00       }, // 6

    // ANL_C_BIT_TEST
    { ANL_C_BIT,         0x00       }, // 7

    // JZ test
    { MOV_DIRECT,        0x00       }, // 8
    { JZ_REL,            0x02       }, // 9
    { MOV_R_N_IMMEDIATE, 0x02, 0x01 }, // 10
    { MOV_R_N_IMMEDIATE, 0x03, 0x01 }  // 11

};

uint8_t data_memory[DATA_MEMORY_SIZE];
uint8_t bit_memory[BIT_MEMORY_SIZE];
uint8_t r[R_COUNT];
uint8_t ic;
uint8_t acc;