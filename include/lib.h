#ifndef LIB_H
#define LIB_H

#include "cpu.h"
// memory size of 256 byte
typedef struct CPU CPU;

# define HLT 0      // operation definitions 
# define LA  1       // predefinitons
# define LB  2
# define ADD 3
# define SUB 4
# define MUL 5
# define PRN 6
# define JMP 7
# define JZ  8
# define INP_A 9
# define INP_B 10
# define TRF 11
# define RCV 12
# define CMP 13
# define PAU 14
# define CPY 15

void exe (int* cnt , char opcode , CPU * self);



#endif