// Program converts a character to a bit string

#include <stdio.h>

int	main(void)
{
	char			ch;
	unsigned int	num;
	int				i;
	unsigned int	arr[8];

	// Hexadecimal A is 41, 01000001
	ch = 'A';
	printf("Char: %c, Value: %d\n", ch, ch);
	num = (unsigned int) ch;
	i = 0;
	while (i < 8)
	{
		arr[i] = num % 2;
		num /= 2;
		i++;
	}
	printf("Raw output:  %d %d %d %d | %d %d %d %d\n", arr[0], arr[1], arr[2],
								arr[3],	arr[4], arr[5], arr[6], arr[7]);
	printf("Good output: %d %d %d %d | %d %d %d %d\n", arr[7], arr[6], arr[5],
								arr[4],	arr[3], arr[2], arr[1], arr[0]);
	return (0);
}
