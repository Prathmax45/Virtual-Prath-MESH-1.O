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
        if(cpuid == 1)
        {
            pthread_mutex_lock(&lock);
            cpu_1_alive = 0;
            ready = 1;
            pthread_mutex_unlock(&lock);
        }
        if(cpuid == 2)
        {
            pthread_mutex_lock(&lock);
            cpu_2_alive = 0;
            ready = 2;
            pthread_mutex_unlock(&lock);
        }
        return;

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
            

        }
        else if(cpuid == 2)
        {
            pthread_mutex_lock(&lock);
            common = *regA;
            ready = 2;
            
            printf("Data transmitted from CPU%d = %d\n",cpuid,*regA);
            
        }
        break ;

        case RCV :
        if(cpuid == 1)
        {
            while(ready != 2);
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

        case PAU:
        if (cpuid == 1)
        {
            printf("the cpu %d is paused\n",cpuid);
            pthread_mutex_unlock(&lock);
            while (ready!= 2);  
            //     pthread_mutex_lock(&lock);    
            if (ready == 2)
            {
                printf("The cpu %d is resumed!!\n", cpuid);
                break;
            }
             break;
        }
        else if (cpuid == 2)
        {
            printf("the cpu %d is paused\n",cpuid);
            pthread_mutex_unlock(&lock);
            while (ready!= 1);    
            if (ready == 1)
            {
                printf("The cpu %d is resumed!!\n", cpuid);
                break;
            }  
             break;
        }
            
            


        default:
         printf("Unknown instruction");
        exit(1);
        

    }
}