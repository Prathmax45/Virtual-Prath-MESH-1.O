#include "lib.h"
#include <stdio.h>
#include <pthread.h>
#include "shared_memory.h"

char memory[MEMORY_SIZE];


void exe (int cnt ,char opcode ,int* regA , int* regB,int cpuid)
{
    switch(opcode)        
    {
        case HLT:
        printf("CPU%d: Halted\n", cpuid);
        pthread_exit(NULL);  // Terminate only the current thread, not the whole program
        break;;

        case LA:
        *regA = memory[cnt++];
        break;

        case LB:
        *regB = memory[cnt++];
        break;

        case ADD:
        printf("Addition operation performed ..! \n");
        *regA = *regA + *regB;
        break;

        case SUB:
        printf("Substraction operation performed ..! \n");
        *regA = *regA - *regB;
        break;

        case MUL:
        printf("Multiplication operation performed ..! \n");
        *regA = (*regA) * (*regB);
        break;

        case JMP:
        cnt = memory[cnt];
        break;

        case JZ:
        if(*regA == 1)
            cnt = memory[cnt];
        else
            cnt++;
        break;

        case INP_A:
        printf("Enter the A : ");
        scanf("%d",regA);
        break;

        case INP_B:
        printf("Enter the B : ");
        scanf("%d",regB);
        break;

        case PRN:
        printf("Result : %d\n",*regA);
        break;

        case TRF :
        if(cpuid == 1)
        {
            pthread_mutex_lock(&lock);
            common = *regA;
            ready = 1;
            printf("Data transmitted from CPU%d = %d\n",cpuid,*regA);
            pthread_mutex_unlock(&lock);
        }
        else if(cpuid == 2)
        {
            pthread_mutex_lock(&lock);
            common = *regA;
            ready = 1;
            printf("Data transmitted from CPU%d = %d\n",cpuid,*regA);
            pthread_mutex_unlock(&lock);
        }
        break;

        case RCV :
        if(cpuid == 1)
        {
            while(ready != 1);
            pthread_mutex_lock(&lock);
            *regA = common;
            printf("Data received by CPU%d = %d\n",cpuid,*regA);
            ready = 0;
            pthread_mutex_unlock(&lock);
        }
        else if(cpuid == 2)
        {
            while(ready != 1);
            pthread_mutex_lock(&lock);
            *regA = common;
            printf("Data received by CPU%d = %d\n",cpuid,*regA);
            ready = 0;
            pthread_mutex_unlock(&lock);
        }
        break;

        case CMP :
        if (*regA == *regB)
            printf("Both are equal\n");
        else
            printf("They are not equal\n");
        break;

        default:
         printf("Unknown instruction");
        exit(1);
        

    }
}