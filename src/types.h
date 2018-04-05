#ifndef TYPES_H_
#define TYPES_H_

typedef enum { 

    DEC_R_DIRECT,
    DEC_R_INDIRECT,
    DEC_DIRECT,

    ANL_C_BIT,
    ANL_C_NOT_BIT,


    MOV_R_N_IMMEDIATE,
    MOV_R_INDIRECT,
    MOV_DIRECT,

    JZ_REL

} InstructionName;

typedef struct {

    InstructionName name;

    uint8_t arg1;

    uint8_t arg2;

} Instruction;

struct {

    uint8_t carry;
    uint8_t parity;

} psw;

#endif