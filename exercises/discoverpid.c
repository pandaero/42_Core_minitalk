// Program is an executable that displays its own PID and terminates.

#include <unistd.h>		//Standard Unix functions
#include <stdio.h>		//Standard input/output
#include <signal.h>		//Signal functions and name macros

int	main(void)
{
	pid_t	pid;

	// Get own PID from system
	pid = getpid();
	// Display PID
	printf("PID: %d. Goodbye\n", pid);
	// Send stop signal to self
	kill(pid, SIGSTOP);
	return (0);
} 