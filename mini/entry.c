#include "minicrt.h"

extern int main(int argc, char *argv[]);
void exit(int);

void mini_crt_entry(void)
{
	int ret;
	int argc;
	char **argv;

	char *ebp_reg = 0;
	asm(
		"movl %%ebp, %0"
		:"=r"(ebp_reg)
	);

	argc = *(int *)(ebp_reg + 4);
	argv = (char **)(ebp_reg + 8);

	ret = main(argc, argv);

	exit(ret);
}

void exit(int exitCode)
{
	asm(
		"movl %0, %%ebx\n"
		"movl $1, %%eax\n"
		"int $0x80"
		::"m"(exitCode)
	);
}
