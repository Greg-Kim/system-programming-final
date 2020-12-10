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
	char buf2[100];
	int num, fd1, fd2;
	int i=0;
	
	// make a fd as fifo
	if(mknod(FIFO_NAME1, S_IFIFO | 0666, 0) ==-1)
	{
		perror("mknod error");
	}
	
	if(mknod(FIFO_NAME2, S_IFIFO | 0666, 0) ==-1)
	{
		perror("mknod error");
	}
	
	// wait for writer
	// open FD, when writer opens FD
	fd1 = open(FIFO_NAME1, O_RDWR);
	fd2 = open(FIFO_NAME2, O_RDWR);
	
	do{
		if((num = read(fd1, buf, 100)) == -1)
			perror("read error");
		else
		{
			buf[num] = '\0';
			while(sprintf(buf2, "%d", atoi(buf)+1), !feof(stdin))
			{
				if ((num=write(fd2, buf2, strlen(buf2))) ==-1)
					perror("write error");
				else
				{
					printf("%d\n", atoi(buf)); // delete later
					i++;
					sleep(1);
				}
			}
		}
	}while(num >0);

	return 0;
}


