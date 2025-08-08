#ifndef LIB_H
#define LIB_H

// memory size of 256 byte
#define MEMORY_SIZE 256

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

void exe(int cnt,char opcode,int* regA , int* regB, int cpuid);



#endif