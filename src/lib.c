#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "../include/lib.h"
#include "../include/cpu.h"
#include "../include/shared_memory.h"

char memory[MEMORY_SIZE];

void exe (int* cnt , char opcode , CPU * self)
{
    switch(opcode)        
    {
        case HLT:
        printf("CPU%d: Halted\n", self->cpuid);
            pthread_mutex_lock(&lock);
            
            cpu_alive[self->cpuid - 1] = 0;
            ready_bus[self->cpuid - 1] = 0;
            int cnt_flag = 0;
            int tmp_id = self->cpuid;
            while ( tmp_id <= 10 && cnt_flag < 2)
            {
                if(cpu_alive[tmp_id] == 1)
                {
                    ready_bus[tmp_id] = 1;
                    break;
                }
                else
                {  
                    (tmp_id)++;
                    if (tmp_id == 10)
                    {
                        tmp_id = 1;
                        cnt_flag++;
                    }
                }

                
        
                

            }
            
            pthread_mutex_unlock(&lock);
        break;

        case LA:
        self->data[0] = self->memory[(*cnt)++];
        break;

        case LB:
        self->data[1] = self->memory[(*cnt)++];
        break;

        case ADD:
        printf("Addition operation performed..! \n");
        self->data[0] = self->data[0] + self->data[1];
        break;

        case SUB:
        printf("Substraction operation performed ..! \n");
        self->data[0] = self->data[0] - self->data[1];
        break;

        case MUL:
        printf("Multiplication operation performed ..! \n");
        self->data[0] = self->data[0] * self->data[1];
        break;

        case JMP:
        *cnt = memory[(*cnt)];
        break;

        case JZ:
        if(self->data[0] == 1)
            *cnt = memory[(*cnt)];
        else
            (*cnt)++;
        break;

        case INP_A:
        printf("Enter the A : ");
        scanf("%d",&self->data[0]);
        break;

        case INP_B:
        printf("Enter the B : ");
        scanf("%d",&self->data[1]);
        break;

        case PRN:
        printf("Result : %d\n",self->data[0]);
        break;

        case TRF :
        int id = self->memory[(*cnt)++];
        printf("Transmitting Data from CPU%d to CPU%d\n",self->cpuid,id);
        pthread_mutex_lock(&lock);
        common = self->data[0];
        ready_bus[id - 1] = 1;
        ready_bus[self->cpuid - 1] = 0;
        pthread_mutex_unlock(&lock);
        printf("Transferred Successfully !!\n");
        break;

        case RCV :
        while(!(ready_bus[self->cpuid - 1]));
        sleep(1);
        pthread_mutex_lock(&lock);
        self->data[0] = common;
        ready_bus[self->cpuid - 1] = 0;
        pthread_mutex_unlock(&lock);
        printf("Data Recieved by CPU%d\n",self->cpuid );
        break;

        case PAU:
        printf("CPU%d is Paused\n",self->cpuid);
        while(!(ready_bus[self->cpuid - 1]));
        if ((ready_bus[self->cpuid - 1]))
            {
                sleep(2);
                printf("The CPU%d is resumed!!\n", self->cpuid);
                break;
            }  
        
        break;


        case CMP :
        if (self->data[0] == self->data[1])
            printf("Both are equal\n");
        else
            printf("They are not equal\n");
        break;

        default:{
        printf("Unknown instruction");
        exit(1);}
        

    }
}


