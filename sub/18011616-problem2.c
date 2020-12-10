#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

void usr_sig(int signo);

int main()
{
	int i=0;
	int signo;
	
	struct sigaction act; // declare sigaction struct
	
	act.sa_handler = usr_sig; // set handler as my function usr_sig
	sigemptyset(&act.sa_mask); // emty mask 
	sigaddset(&act.sa_mask, SIGQUIT); // add SIGQUIT to the set
	act.sa_flags = 0; // flag is NULL
	
	if(sigaction(SIGINT, &act, 0) == -1) // sig action when SIGINt is received
	{
		perror("sigaction error");
		return -1;
	}
	
	if(sigaction(SIGTSTP, &act, 0) == -1) // sig action when SIGTSPT is received
	{
		perror("sigaction error");
		return -1;
	}
	
	while(1) // something the progam do == wait for signal
	{
		printf("Waiting for siganl to be received! Count:%d\n", i);
		sleep(1);
		i++;
	}
	
	return 0;
}

void usr_sig(int signo) //  my handler
{
	psignal(signo, "Received Signal:"); // printf info about signal that was received
	return;
}
