#include <stdio.h>
#include "lib.h"
#include "cpu.h"
#include <stdlib.h>
#include "shared_memory.h"
int A2  = 0 , B2 = 0;
int cnt_2 = 0;
int cpu_id_2 = 2;

char memory_cpu_2[MEMORY_SIZE];

void cpu_2(char* filename)
{
     FILE *file2 = fopen(filename,"rb");
     if(!file2)
     {
        printf("Unable to open the bin file");
        exit(0);
     }

    int i = 0;
    while(!feof(file2) && i < MEMORY_SIZE)
    {
        fread(&memory_cpu_2[i], 1, 1, file2);
        i++;
    }
    fclose(file2);

    while (1)
    {
        if (cpu_2_alive == 1)
            exe(cnt_2,memory_cpu_2[cnt_2++],&A2,&B2,cpu_id_2);
        else
        return;
    }
}
