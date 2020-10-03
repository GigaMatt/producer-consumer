/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

#include "global.h"

/* 5 threads to complete the assignment */
int thread_id[MAX_THREADS] = {0,1,2,3,4};

/* Location identifier for (pthread_join) */
int position = 0;

int main(int argc, char *argv[]){

    /* Create Semaphores & Send in Buffer */
	pthread_t thread[MAX_THREADS];
	pthread_mutex_init(&mutex_ap_ar, NULL);
	pthread_mutex_init(&mutex_bp_br, NULL);
	sem_init(&not_empty, 0, 0);
    sem_init(&empty, 0, 1);

	/* Create the threads for producer-consumer */
	pthread_create(&thread[0], NULL, (void *)ap_producer,(void *) &thread_id[0]);
	pthread_create(&thread[1], NULL, (void *)bp_producer,(void *) &thread_id[1]);
	pthread_create(&thread[2], NULL, (void *)ar_producer, (void *) &thread_id[2]);
	pthread_create(&thread[3], NULL, (void *)br_producer,(void *) &thread_id[3]);
	pthread_create(&thread[4], NULL, (void *)consumer,(void*) &thread_id[4]);
    
    /* Join the threads we just created */
    while(position < MAX_THREADS){
        pthread_join(thread[position], NULL);
        position++;
    }

	/* Close the Mutex */
	pthread_mutex_destroy(&mutex_ap_ar);
	pthread_mutex_destroy(&mutex_bp_br);

    /* Close the Semaphores */
	sem_destroy(&empty);
	sem_destroy(&not_empty);

	return 0;
}