int main(int argc, char *argv[])
{
	int fd = open("txt", 0102, 0644);
	write(fd, "QOO\n", 4);
	exit(33);
}
