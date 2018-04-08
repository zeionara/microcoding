#include <stdint.h>
#include <stdio.h>

#include "config.h"

#include "types.h"
#include "instructions.h"
#include "memory.h"
#include "cpu_model.h"

void print_registers_state() {

    printf("REGISTERS\n");
    printf("accumulator: %#04x\n", acc);
    printf("process status word: carry = %d | parity = %d\n", psw.carry, psw.parity);
    printf("instructions counter:  %d\n", ic);

}

void print_r_registers_state() {

    printf("R REGISTERS\n");

    for (int i = 0; i < R_COUNT; i++) {
        printf("r%-2u: %#04x \n", i, r[i]);

    }

    printf("\n");

}

void print_bit_memory_state() {

    printf("BIT MEMORY\n");

    for (int i = 0; i < BIT_MEMORY_SIZE; i++) {

        printf("%-2u: %u\n", i, bit_memory[i]);

    }

    printf("\n");

}

void print_data_memory_state(int row_display_count) {

    printf("MEMORY\n");

    int columns = DATA_MEMORY_SIZE / row_display_count;

    for (int i = 0; i < row_display_count; i++) {

        for (int j = 0; j < columns; j++) {

            printf("%#04x  ", data_memory[i * columns + j]);

        }

        printf("\n");

    }

}

void print_state() {

    printf("\n====== COMPUTER STATE ====== \n");

    printf("\n");
    print_registers_state();

    printf("\n");
    print_r_registers_state();

    printf("\n");
    print_bit_memory_state();

    printf("\n");
    print_data_memory_state(4);

    printf("====== END OF COMPUTER STATE ====== \n\n\n");
}

void print_instruction(Instruction instruction) {

   printf(">>>> ");

   switch(instruction.name) {

        case DEC_R_DIRECT:
            printf("%-3i %-5s R%u\n", ic, "DEC", instruction.arg1);
        break;

        case DEC_R_INDIRECT:
            printf("%-3i %-5s @R%u\n", ic, "DEC", instruction.arg1);
        break;

        case DEC_DIRECT:
            printf("%-3i %-5s %Xh\n", ic, "DEC", instruction.arg1);
        break;

        case ANL_C_BIT:
            printf("%-3i %-5s C, %Xh\n", ic, "ANL", instruction.arg1);
        break;

        case ANL_C_NOT_BIT:
            printf("%-3i %-5s C, /%Xh\n", ic, "ANL", instruction.arg1);
        break;

        case MOV_R_N_IMMEDIATE:
            printf("%-3i %-5s R%u, #%Xh\n", ic, "MOV", instruction.arg1, instruction.arg2);
        break;

        case MOV_R_INDIRECT:
            printf("%-3i %-5s A, @R%u\n", ic, "MOV", instruction.arg1);
        break;

        case MOV_DIRECT:
            printf("%-3i %-5s A, #%Xh\n", ic, "MOV", instruction.arg1);
        break;

        case JZ_REL:
            printf("%-3i %-5s %u\n", ic, "JZ", instruction.arg1);
        break;

        default:
            printf("====== FAIL ====== \n");

    }

}

void print_program() {

    int program_length = sizeof(program_memory) / sizeof(Instruction);

    for (int i = 0; i < program_length; i++) {
        printf("%3d | ", i);
        print_instruction(program_memory[i]);
        printf("\n");
    }

    printf("\n");

}