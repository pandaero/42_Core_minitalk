// Program writes a unicode character to standard output

#include <unistd.h>

int	main(void)
{
	unsigned int	ch;
	char			happy[] = {0xE2, 0x98, 0xBA};

	ch = 0;
	// Display smiley together
	write(1, happy, 3);
	// Give space in output
	write(1, " ", 2);	
	// Display smiley by serial output
	ch = 0xE2;
	write(1, &ch, 1);
	ch = 0x98;
	write(1, &ch, 1);
	ch = 0xBA;
	write(1, &ch, 1);
	write(1, "\n", 2);
	return (0);
}
