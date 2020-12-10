#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

void usr_sig(int signo, siginfo_t *info, void* no_use);

int main()
{
	struct sigaction act; // declare act
	
	act.sa_sigaction = usr_sig; // set handler to sa_sigaction
	sigemptyset(&act.sa_mask); // emty &act.sa_mask
	sigaddset(&act.sa_mask, SIGQUIT); // dont block SIGQUIT while handler
	act.sa_flags = SA_SIGINFO; // use sa_sigaction instead of sa_handler
	
	if (sigaction(SIGTSTP, &act, 0) == -1) // did SIG handler work?
	{
		printf("signal error"); // no
		return -1;
	}
	
	printf("pid: %d\n", getpid()); // print pid of this process
	
	while(1) // something this program do
	{
		printf(".");
		sleep(3);
	}
}

void usr_sig(int signo, siginfo_t *info, void* no_use) // printf signo and si_val
{
	int received_signo;
	int received_sigval;
	
	printf("\nsigno: %d\nsigval: %d\n", signo, info->si_value.sival_int);
}

