/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

/* Thread A Redundant (AR) Producer: Produces a signal every 1.15 seconds */

#include "global.h"

void* ar_producer(void * producer_thread_id){
	int upper_bound = 300, lower_bound = 1;										// Boundary ranges to avoid negative integers

	/* psudo-code: do_forever() */
	while(1){
		sem_wait(&empty);														// Decrement semaphore

		/* psudo-code: wait_delay_time() */
		pthread_mutex_lock(&mutex_ap_ar);										// Initiate lock
		sleep(1.15);															// Produce signal every 1.15 seconds

		/* psudo-code: data = gen_new_data() */
		int data_point = (rand()%(upper_bound-lower_bound+1))+lower_bound;		// Create random data for AR
		
		/* psudo-code: write_data(data, isPrime) */
		if(buffer_ap_ar[0] == 0){												// Check if empty
			buffer_ap_ar[0] = data_point;										// Range [lower_bound, upper_bound]
		}
		printf("Channel AR added %3.2f into buffer\n", sin(data_point));
		pthread_mutex_unlock(&mutex_ap_ar);										// Unlock thread
		sem_post(&not_empty);	
	}
}