// fifo-write

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define FIFO_NAME1 "FIFO_1"
#define FIFO_NAME2 "FIFO_2"

int main()
{
	char buf[100];
	int num, fd1,fd2;
	int i=0;
	
	// making a FD for FIFO
	if(mknod(FIFO_NAME1, S_IFIFO | 0666, 0)==-1)
	{
		perror("mknod error");
	}
	
	if(mknod(FIFO_NAME2, S_IFIFO | 0666, 0) ==-1)
	{
		perror("mknod error");
	}
	
	// we are waiting for a reader
	// we open the FD, when the reader opens the FD
	fd1 = open(FIFO_NAME1, O_RDWR);
	fd2 = open(FIFO_NAME2, O_RDWR);
	
	//send the user input data to the reader via FIFO
	while(sprintf(buf, "%d", i), !feof(stdin))
	{
		if ((num=write(fd1, buf, strlen(buf))) ==-1)
			perror("write error");
		else
		{
			printf("%d\n", i); // delete later
			i++;
			sleep(1);
			
			if((num = read(fd2, buf, 100)) == -1)
				perror("read error");
			else
			{
				buf[num] = '\0';
				printf("%d+1 = %d", i, atoi(buf));
			}
		}
	}
	
	return 0;
}
