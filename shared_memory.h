#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <pthread.h>


extern int common;
extern int ready;
extern pthread_mutex_t lock;

#endif