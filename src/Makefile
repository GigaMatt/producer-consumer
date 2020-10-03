# \
CS 170 - Theory of Operating Systems\
Author: Matthew S Montoya\
Author: Matthew Iglesias\
Purpose: Model a NASA spacecraft antenna controller that needs the signal from multiple antennas at the same time as producer-consumer\

lab5.o: consumer.c ap_producer.c bp_producer.c br_producer.c ar_producer.c main.c
	gcc -pthread consumer.c ap_producer.c bp_producer.c br_producer.c ar_producer.c main.c -lm -o lab5.o
clean:
	rm -f *.o
