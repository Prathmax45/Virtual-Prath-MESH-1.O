#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "cpu.h"
#include "shared_memory.h"


void* run_cpu1(void* arg)
{
    printf("CPU1_Entry , Live_State = %d\n" ,cpu_alive[0]);

    while (cpu_alive[0] != 0)
        cpu_1("cpu_1.bin");

    printf("CPU1_returned, Live_State = %d\n", cpu_alive[0]);

    pthread_exit(NULL);
}

void* run_cpu2(void* arg)
{
    printf("CPU2_Entry , Live_State = %d\n", cpu_alive[1]);
    while(cpu_alive[1] != 0)
        cpu_2("cpu_2.bin"); 

    printf("CPU2_returned, Live_State = %d\n", cpu_alive[1]);
    pthread_exit(NULL);
}

void* run_cpu3(void* arg)
{
    printf("CPU3_Entry , Live_State = %d\n", cpu_alive[2]);
    while(cpu_alive[2] != 0)
        cpu_3("cpu_3.bin"); 

    printf("CPU3_returned, Live_State = %d\n", cpu_alive[2]);
    pthread_exit(NULL);
}


int main()
{
    printf("\n........Hello Pratham ! welcome to the PRATH-mesh..........\n\n");
    pthread_t thread1 , thread2, thread3;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&thread1,NULL,run_cpu1,NULL);
    pthread_create(&thread2,NULL,run_cpu2,NULL);
    pthread_create(&thread3,NULL,run_cpu3,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);

    pthread_mutex_destroy(&lock);

    printf("All CPUs Terminated ..... !!!\n");

    return 0;
}

