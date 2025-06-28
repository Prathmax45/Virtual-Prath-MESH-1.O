#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "cpu.h"
#include "shared_memory.h"


void* run_cpu1(void* arg)
{
    cpu_1("cpu_1.bin");
    return NULL;
}

void* run_cpu2(void* arg)
{
    cpu_2("cpu_2.bin");
    return NULL;
}


int main()
{
    pthread_t thread1 , thread2;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&thread1,NULL,run_cpu1,NULL);
    pthread_create(&thread2,NULL,run_cpu2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_mutex_destroy(&lock);



    return 0;
}

