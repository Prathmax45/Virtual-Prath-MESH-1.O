#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "cpu.h"
#include "shared_memory.h"


void* run_cpu1(void* arg)
{
    printf("CPU1 Entry , cpu_1_alive = %d\n", cpu_1_alive);

    while (cpu_1_alive != 0)
        cpu_1("cpu_1.bin");

    printf("CPU1 returned, cpu_1_alive = %d\n", cpu_1_alive);

    pthread_exit(NULL);
}

void* run_cpu2(void* arg)
{
    printf("CPU2 Entry , cpu_2_alive = %d\n", cpu_2_alive);
    while(cpu_2_alive != 0)
        cpu_2("cpu_2.bin"); 

    printf("CPU2 returned, cpu_2_alive = %d\n", cpu_2_alive);
    pthread_exit(NULL);
}


int main()
{
    printf("\n........Hello Pratham ! welcome to the PRATH-mesh..........\n\n");
    pthread_t thread1 , thread2;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&thread1,NULL,run_cpu1,NULL);
    pthread_create(&thread2,NULL,run_cpu2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_mutex_destroy(&lock);

    printf("All CPUs Terminated ..... !!!\n");

    return 0;
}

