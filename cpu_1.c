#include <stdio.h>
#include "lib.h"
#include "cpu.h"
#include "shared_memory.h"
#include <stdlib.h>

void cpu_1(char* filename)
{
    CPU cpu;
    int cnt = 0;
    cpu.cpuid = 1;

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
        if (cpu_alive[0] == 1)
            exe(cnt , cpu.memory[cnt++], &cpu);
        else
            return;
    }
}

