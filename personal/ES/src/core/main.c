#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "core/test.h"

pthread_t				threadID;
pthread_mutex_t lock;

int running(int i) {
	static int r = 1;
	if (i == 2)
		r = 0;
	else if (i == 1)
		r = 1;
	return r;
}

void*	loop(void* arg) {
	int run = 1;
	int count = 0;
	while (run) {
		if (pthread_mutex_trylock(&lock)) {
			int r = running(0);
			pthread_mutex_unlock(&lock);
			if (!r)
				run = 0;
			else
				write(2, "toto is back\n", strlen("toto is back\n"));
			sleep(1);
		}
	}
	return NULL;
}

int	launch(void) {
	running(1);
	if (pthread_mutex_init(&lock, NULL) != 0)
		return 1;

	pthread_create(&threadID, NULL, &loop, NULL);	
	return 0;
}

void	stop(void) {
	int x = 0;
	pthread_mutex_lock(&lock);
	running(2);
	pthread_mutex_unlock(&lock);
	pthread_join(threadID, NULL);
	x++;
}
