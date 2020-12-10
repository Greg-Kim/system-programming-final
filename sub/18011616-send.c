#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid;
	int signo;
	union sigval sig_value;
	
	scanf("%d %d", &pid, &sig_value.sival_int); // get target pid and value
	
	if(sigqueue(pid, SIGTSTP, sig_value) < 0) // send SIGTSTP and sig_value to pid
	{
		perror("error\n");
		exit(-1);
	}
	
	return 0;
}


