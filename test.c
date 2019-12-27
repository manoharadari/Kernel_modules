#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd;

	fd = open("/dev/helloC" , O_RDWR );

	if(fd == -1 )
	{
		perror("open error");
		return -1;
	}

	sleep(100);

	close(fd);
}
