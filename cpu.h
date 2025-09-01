#ifndef CPU_H
#define CPU_H

#include <pthread.h>
#define MEMORY_SIZE 256


void cpu_1(char* filename);
void cpu_2(char* filename);
void cpu_3(char* filename);

typedef struct 
{
    int data[10];
    int from_cpu;
    int to_cpu;

}Message;

typedef struct CPU
{
    int cpuid;
    char memory[MEMORY_SIZE];
    int data[10];
    int head, tail;
    pthread_mutex_t lock;
    int ready;
    int alive;
    
}CPU;







#endif