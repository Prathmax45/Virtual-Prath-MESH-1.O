#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/lib.h"
#include "../include/cpu.h"
#include "../include/shared_memory.h"


void cpu_3(char* filename)
{
    CPU cpu;
    int cnt = 0;
    cpu.cpuid = 3;

     FILE *file = fopen(filename,"rb");
     if(!file)
     {
        printf("Unable to open the bin file");
        exit(0);
     }

    int i = 0;
    while(!feof(file) && i < MEMORY_SIZE)
    {
        fread(&cpu.memory[i], 1, 1, file);
        i++;
    }
    fclose(file);

    while (1)
    {
        
        if (cpu_alive[2] == 1)
        {
            exe(&cnt , cpu.memory[cnt++], &cpu);
            sleep(1); // sleep time = 1 sec
        }
        else
            return;
    }
}
