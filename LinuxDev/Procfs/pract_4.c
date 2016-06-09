//print process argument list

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void showProcArgs(pid_t pid)
{
	int fd;
	char filename[30];
	char argList[1024];
	size_t lenght;
	char* nextArg;
	
	snprintf(filename, sizeof(filename), "/proc/%d/cmdline", (int)pid);
	
	fd = open(filename, O_RDONLY);
	lenght = read(fd, argList, sizeof(argList));
	close(fd);

	argList[lenght] = '\0';
	nextArg = argList;
	while(nextArg < argList+lenght)
	{
		printf("%s\n", nextArg);
		nextArg += strlen (nextArg) + 1;
	} 	

}

int main(int argc, char** argv)
{
	pid_t pid = atoi(argv[1]);
	showProcArgs(pid);
	return 0;
}
