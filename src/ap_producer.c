/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

#include "global.h"

/* Thread A Prime (AP) Producer: Produces a signal every 1.00 seconds */

void* ap_producer(void * producer_thread_id) {
	int upper_bound = 300, lower_bound = 1;										// Boundary ranges to avoid negative integers

    /* psudo-code: do_forever() */
	while(1) {
		sem_wait(&empty);                               						// Decrement Semaphore
        
        /* psudo-code: wait_delay_time() */
		pthread_mutex_lock(&mutex_ap_ar);               						// Lock mutex object (buffer) from the other threads
		sleep(1);                                       						// Produce signal every 1.00 seconds
		
		/* psudo-code: data = gen_new_data() */
		int data_point = (rand()%(upper_bound-lower_bound+1))+lower_bound;		// Create random data for buffer

		/* psudo-code: write_data(data, isPrime) */
		buffer_ap_ar[0] = data_point;                   						// Add data point to the buffer
		printf("Channel AP added %3.2f into buffer\n", sin(data_point));
		pthread_mutex_unlock(&mutex_ap_ar);             						// Unlock mutex object (buffer) for other thread access
		sem_post(&not_empty);
	}
}