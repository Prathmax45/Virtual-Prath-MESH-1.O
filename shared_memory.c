#include "shared_memory.h"

int common = 0;
int ready = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int cpu_1_alive = 1;
int cpu_2_alive = 1;
