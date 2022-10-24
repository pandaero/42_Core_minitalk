// Program sends two signals to determined PID.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Input Error.\n");
		return (0);
	}
	kill(atoi(argv[1]), SIGUSR1);
	usleep(10);
	printf("Sent SIGUSR1\n");
	kill(atoi(argv[1]), SIGUSR2);
	usleep(10);
	printf("Sent SIGUSR2\n");
	kill(atoi(argv[1]), SIGUSR1);
	usleep(10);
	printf("Sent SIGUSR1\n");
	kill(atoi(argv[1]), SIGUSR2);
	printf("Sent SIGUSR2\n");
	return (0);
}
