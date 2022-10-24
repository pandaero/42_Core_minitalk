// Tests for the functions in client.c
#include "../../minitalk.h"
#include <stdlib.h>
#include <stdio.h>

/* Test for end_signal. Use receiver.c to check.
// run: (comment out main) cc client_main.c ../client.c
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Input Error.\n");
		return (0);
	}
	end_signal(atoi(argv[1]));
	return (0);
}
//*/

/* Test for char_signal. Use receiver.c to check.
// run: (comment out main) cc client_main.c ../client.c
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Input Error.\n");
		return (0);
	}
	char_signal('A', atoi(argv[1]));
	return (0);
}
//*/
