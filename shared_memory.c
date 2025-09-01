#include "shared_memory.h"

int common = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int cpu_alive[10] = {1,1,1,0,0,0,0,0,0,0};
int ready_bus[10] = {0,0,0,0,0,0,0,0,0,0};
