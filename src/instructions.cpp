#include <stdint.h>

#include "config.h"

#include "types.h"
#include "cpu_model.h"
#include "memory.h"

void dec_r_direct(uint8_t arg) {
    r[arg]--;
    ic++;
}



void dec_r_indirect(uint8_t arg) {

    data_memory[r[arg]]--;

    ic++;

}



void dec_direct(uint8_t arg) {

    data_memory[arg]--;

    ic++;

}

void anl_c_bit(uint8_t arg) {

    psw.carry &= bit_memory[arg];

    ic++;

}

void anl_c_not_bit(uint8_t arg) {

    psw.carry &= !bit_memory[arg];

    ic++;

}

void mov_r_n_immediate(uint8_t r_i, uint8_t value) {

    r[r_i] = value;

    ic++;

}

void mov_r_indirect(uint8_t arg) {

    acc = data_memory[r[arg]];

    psw.parity = (acc % 2) == 0;

    ic++;

}

void mov_direct(uint8_t arg) {

    acc = arg;

    psw.parity = (acc % 2) == 0;

    ic++;

}

void jz_rel(uint8_t arg) {

    if (acc == 0)

        ic += arg;

    else

        ic++;

}