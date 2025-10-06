#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/lib.h"
#include "../include/cpu.h"
#include "../include/shared_memory.h"

void cpu_2(char* filename)
{
    CPU cpu;
    int cnt = 0;
    cpu.cpuid = 2;
    
     FILE *file2 = fopen(filename,"rb");
     if(!file2)
     {
        printf("Unable to open the bin file");
        exit(0);
     }

    int i = 0;
    while(!feof(file2) && i < MEMORY_SIZE)
    {
        fread(&cpu.memory[i], 1, 1, file2);
        i++;
    }
    fclose(file2);

    while (1)
    {
        
        if (cpu_alive[1] == 1)
        {
            exe(&cnt , cpu.memory[cnt++], &cpu);
            sleep(1);  // sleep time = 1 sec
        }
        else
            return;
    }
}
