// Program 

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Signal handler for SIGUSR1
void u1sighandler(int sig)
{
	if (sig == SIGUSR1)
		printf("SIGUSR1 Received\n");
}

//Signal handler for SIGUSR2
void u2sighandler(int sig)
{
	if (sig == SIGUSR2)
		printf("SIGUSR2 Received\n");
}

int	main(void)
{
	struct sigaction actusr1;
	struct sigaction actusr2;
	
	printf("This is PID %d\n", getpid());
	// Define signal action for first signal
	actusr1.sa_handler = &u1sighandler;
	sigemptyset(&actusr1.sa_mask);
	actusr1.sa_flags = SA_RESTART;
	// Define signal action for second signal
	actusr2.sa_handler = &u2sighandler;
	sigemptyset(&actusr2.sa_mask);
	actusr2.sa_flags = SA_RESTART;
	// Add signals to masks
	sigaddset(&actusr1.sa_mask, SIGINT);
	sigaddset(&actusr1.sa_mask, SIGUSR2);
	sigaddset(&actusr2.sa_mask, SIGINT);
	sigaddset(&actusr2.sa_mask, SIGUSR1);
	// Initialise sigaction and check for errors
	if (sigaction(SIGUSR1, &actusr1, 0) == -1 || \
		sigaction(SIGUSR2, &actusr2, 0) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
		usleep(10);
	return (0);
}
