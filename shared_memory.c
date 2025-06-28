#include "shared_memory.h"

int common = 0;
int ready = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

