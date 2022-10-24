// Program decodes a fake signal to a character output.

#include <stdio.h>

int	main(void)
{
	unsigned int	sig[] = {0, 1, 0, 0, 0, 0, 0, 1};;
	unsigned int	num;
	int				i;

	i = 0;
	while (i < 8)
	{
		num = num * 2 + sig[i];
		i++;
	}
	printf("Num: %d, Char: %c\n", num, num);
	return (0);
}
