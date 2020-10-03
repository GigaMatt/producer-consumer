/*
 * CS 170 - Theory of Operating Systems
 * Author: Matthew S Montoya
 * Author: Matthew Iglesias
 * Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer
*/

#include "global.h"

/* Thread Consumer: Acquires data from channel A and channel B */

void* consumer(void *consumer_thread_id){
	
    /* Time stamp needs to print the seconds from the start of execution */
	struct timeval start_time, end_time;
	gettimeofday(&start_time, 0);

    /* psudo-code: do_forever() */
	while(1){
		sem_wait(&not_empty);                           // Hold for object object insertion into buffer (A)
		pthread_mutex_lock(&mutex_ap_ar);               // Lock mutex object (buffer_ap_ar) from the other threads
		usleep(1);
	
        /* psudo-code: a_val = read(a_buffer) */
		int data_point_ap_ar = buffer_ap_ar[0];
		buffer_ap_ar[0] = 0;                            // Clear data point in the buffer
		pthread_mutex_unlock(&mutex_ap_ar);             // Unlock mutex object (buffer_ap_ar) for other thread access
		sem_post(&empty);                               // Increment Semaphore
		sem_wait(&not_empty);                           // Hold for object object insertion into buffer (A)
		pthread_mutex_lock(&mutex_bp_br);               // Lock mutex object (buffer_bp_br) from the other threads

        /* psudo-code: b_val = read(b_buffer) */
		usleep(1);
		int data_point_bp_br = buffer_bp_br[0];

        /* psudo-code: printf(<time stamp> , a_val, b_val) */
		gettimeofday(&end_time, 0);
		double total_time = ((end_time.tv_sec)-(start_time.tv_sec))+(double)((end_time.tv_usec)-(start_time.tv_usec))/1000000L;
		printf("\nTime: Chanel Consumer took %6.3f.\nChanel A took %3.2f.\nChanel B took %3.2f\n",total_time,sin(data_point_ap_ar),sin(data_point_bp_br));
		buffer_bp_br[0] = 0;                            // Clear data point in the buffer
		pthread_mutex_unlock(&mutex_bp_br);             // Unlock mutex object (buffer_bp_br) for other thread access
		sem_post(&empty);                               // Increment Semaphore
	}	
}