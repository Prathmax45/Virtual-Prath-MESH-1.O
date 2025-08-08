#include <stdio.h>
#include "lib.h"
#include "cpu.h"
#include "shared_memory.h"
#include <stdlib.h>
int A1 = 0 , B1 = 0;
int cnt_1 = 0;
int cpu_id_1 = 1;

char memory_cpu_1[MEMORY_SIZE];

void cpu_1(char* filename)
{
     FILE *file1 = fopen(filename,"rb");
     if(!file1)
     {
        printf("Unable to open the bin file");
        exit(0);
     }

    int i = 0;
    while(!feof(file1) && i < MEMORY_SIZE)
    {
        fread(&memory_cpu_1[i], 1, 1, file1);
        i++;
    }
    fclose(file1);

    while (1)
    {
        if (cpu_1_alive == 1)
            exe(cnt_1,memory_cpu_1[cnt_1++],&A1,&B1,cpu_id_1);
        else
            return;
    }
}
