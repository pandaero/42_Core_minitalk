// Program broadcasts PID to listen for signals.

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sigone(int sig)
{
	printf("Received SIGUSR1.\n");
}

void	sigtwo(int sig)
{
	printf("Received SIGUSR2.\n");
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	printf("PID: %d. Receiving.\n", pid);
	signal(SIGUSR1, sigone);
	signal(SIGUSR2, sigtwo);
	while (1);
	return (0);
}
