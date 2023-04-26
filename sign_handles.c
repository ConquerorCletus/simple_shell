#include "main.h"

/**
 * sign_handles - Signal handler
 * @signal
 */

void sign_handles(int signal)
{
	(void)signal;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
