int open(const char *pathname, int flags, int mode)
{
	int fd = 0;
	asm(
		"movl $5, %%eax\n"
		"movl %1, %%ebx\n"
		"movl %2, %%ecx\n"
		"movl %3, %%edx\n"
		"int $0x80\n"
		"movl %%eax, %0"
		:"=m"(fd)
		:"m"(pathname), "m"(flags), "m"(mode)
	);
	return fd;
}

int write(int fd, const void* buffer, unsigned size)
{
	int ret = 0;
	asm(
		"movl $4, %%eax\n"
		"movl %1, %%ebx\n"
		"movl %2, %%ecx\n"
		"movl %3, %%edx\n"
		"int $0x80\n"
		"movl %%eax, %0\n"
		:"=m"(ret)
		:"m"(fd), "m"(buffer), "m"(size)
	);
	return ret;
}
