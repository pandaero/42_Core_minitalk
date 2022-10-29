// Program writes out unicode-compatible text

#include <stdio.h>

int	main(void)
{
	// \u escapes 16-bit Unicode chars
	char	obj[3] = "\u2C90";

	printf("Objects: %s%s%s%s%s\n", obj, obj, obj, obj, obj);
	return (0);
}
