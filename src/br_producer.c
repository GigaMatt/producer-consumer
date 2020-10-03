/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

/* Thread B Redundant (BR) Producer: Produces a signal every 1.15 seconds */

#include "global.h"

void* br_producer(void * producer_thread_id){
	int upper_bound = 300, lower_bound = 1;										// Boundary ranges to avoid negative integers

	/* psudo-code: do_forever() */
	while(1){
		sem_wait(&empty);														// Decrement semaphore

		/* psudo-code: wait_delay_time() */
		pthread_mutex_lock(&mutex_bp_br);										// Initiate lock
		sleep(1.15);															// Produce signal every 1.15 seconds

		/* psudo-code: data = gen_new_data() */
		int data_point = (rand()%(upper_bound-lower_bound+1))+lower_bound;		// Create random data for BR

		/* psudo-code: write_data(data, isPrime) */
		if(buffer_bp_br[0] == 0){												// Check if empty
			buffer_bp_br[0] = data_point;										// Range [lower_bound, upper_bound]
		}
		printf("Channel BR added %3.2f into buffer\n", sin(data_point));
		pthread_mutex_unlock(&mutex_bp_br);										// Unlock thread
		sem_post(&not_empty);	
	}	
}