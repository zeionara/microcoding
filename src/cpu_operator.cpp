#include <stdint.h>
#include <stdio.h>

#include "config.h"

#include "types.h"
#include "instructions.h"
#include "memory.h"
#include "cpu_model.h"
#include "loggers.h"

void execute_instruction(Instruction instruction) {

    if (VERBOSE) {
        print_instruction(instruction);
    }

    switch(instruction.name) {

        case DEC_R_DIRECT:

        dec_r_direct(instruction.arg1);

        break;



        case DEC_R_INDIRECT:

        dec_r_indirect(instruction.arg1);

        break;



        case DEC_DIRECT:

        dec_direct(instruction.arg1);

        break;



        case ANL_C_BIT:

        anl_c_bit(instruction.arg1);

        break;



        case ANL_C_NOT_BIT:

        anl_c_not_bit(instruction.arg1);

        break;



        case MOV_R_N_IMMEDIATE:

        mov_r_n_immediate(instruction.arg1, instruction.arg2);

        break;



        case MOV_R_INDIRECT:

        mov_r_indirect(instruction.arg1);

        break;



        case MOV_DIRECT:

        mov_direct(instruction.arg1);

        break;



        case JZ_REL:

        jz_rel(instruction.arg1);

        break;



        default:

        printf("Unknown instruction");

    }

}

void init_control_unit() {

    ic  = 0;

    acc = 0;

    psw.carry = 1;

    for (int i = 0; i < DATA_MEMORY_SIZE; i++) {

        data_memory[i] = 0x00;

    }

    for (int i = 0; i < R_COUNT; i++) {

        r[i] = 0x00;

    }

    for (int i = 0; i < BIT_MEMORY_SIZE; i++) {

        bit_memory[i] = 0;

    }

}

void execute_next_instruction() {

    Instruction instruction = program_memory[ic];

    execute_instruction(instruction);

}

void execute_program() {

    int program_length = sizeof(program_memory) / sizeof(Instruction);

    while (ic < program_length) {

        //printf("%i\n", ic);

        execute_next_instruction();

    }

}