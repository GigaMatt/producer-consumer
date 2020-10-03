/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

#ifndef _GLOBAL_
#define _GLOBAL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#define buffer_size 1
#define MAX_THREADS 5

/* Mutexes to (dis)allow threads to share the same resource */
pthread_mutex_t mutex_ap_ar, mutex_bp_br;

/* Semaphores to singal when a producer or consumer can access the buffers. */
sem_t empty, not_empty;

/* Define Buffers: One for AP/AR, One for BP/BR */
int buffer_ap_ar[buffer_size], buffer_bp_br[buffer_size];

/* Thread Consumer: Acquires data from channel A and channel B */
void* consumer(void *consumer_thread_id);

/* Thread A Prime (AP) Producer: Produces a signal every 1.00 seconds */
void* ap_producer(void *producer_thread_id);

/* Thread B Prime (BP) Producer: Produces a signal every 1.00 seconds (Not BP, the energy company) */
void* bp_producer(void *producer_thread_id);

/* Thread A Redundant (AR) Producer: Produces a signal every 1.15 seconds */
void* ar_producer(void *producer_thread_id);

/* Thread B Redundant (BR) Producer: Produces a signal every 1.15 seconds */
void* br_producer(void *producer_thread_id);

#endif