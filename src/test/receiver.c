// Program to report received signals.

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sigrcv(int sig)
{
	printf("Received signal %d\n", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d. Receiving...\n", pid);
	signal(SIGUSR1, sigrcv);
	signal(SIGUSR2, sigrcv);
	while (1);
	return (0);
}
