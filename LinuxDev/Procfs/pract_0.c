//Get CPU model name
#include <stdio.h>
#include <string.h>

void getCPUInfo()
{
	FILE* fp;
	char buffer[1024];
	size_t bytesRead;
	char* match;
	char modelName[100];

	//load file /proc/cpuinfo to buffer
	fp = fopen("/proc/cpuinfo", "r");
	bytesRead = fread(buffer, 1, sizeof(buffer), fp);
	fclose(fp);

	if(bytesRead == 0 /*|| bytesRead == sizeof(buffer)*/){
		printf("UPS\n");
		printf("%lu bytes\n",bytesRead);
	}

	buffer[bytesRead] = '\0';
	
	match = strstr(buffer, "model name");
	sscanf(match, "model name : %[^\n]", modelName);
	printf("%s\n", modelName);
}

int main()
{
	getCPUInfo();
	return 0;
}
