// Program 

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

volatile	sig_atomic_t unprocessedSig = 0;
void sighandler(int sig)
{
	if (sig == SIGINT)
		unprocessedSig = 1;
}

int	main(void)
{
	struct sigaction act;
	
	printf("This is PID %d\n", getpid());
	act.sa_handler = &sighandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &act, 0) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("Kill this process: Ctrl-Z\n");
	while (1)
	{
		if (unprocessedSig != 0)
		{
			unprocessedSig = 0;
			printf("SIGINT Received.\n");
		}
	}
}
