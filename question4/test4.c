#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "mytools.h"
#include <assert.h>
#include <math.h>
	   
void child(int);
   void parent(int);
	         int
		    main(void)
		      {
		      int  u,s, j;
		      int cn;
		      const gsl_rng_type *t;
		      gsl_rng *r;
		      gsl_rng_env_setup();
		      t= gsl_rng_default;
		      r = gsl_rng_alloc(t);
		      srand(time(NULL));
		      struct sigaction sig;
		      sig.sa_handler = child;
		      if (sigaction(SIGINT, &sig, NULL) <0)
		      {
		      perror("invalid argument");
		      exit(1);
		      }
		             pid_t pid;
			    // while (cn == 1)
			     //{
			     //int random = rand() % 31 +1;
			    // sleep(2);
			    // printf("parent sending signal to child%d\n",random);
			    if((pid = fork()) < 0)
			    {//error
			    perror("error in fork");
			    exit(1);
			    }
			    if(pid == 0)
			    {
			    //printf("i%d\n", rand());

			    //child
			    while(1)
			   {
			    printf("child waiting\n");
			    sleep(1);
			    }
			    }
			    else
			    {
			    //parent process
			    gsl_rng_set(r, time(NULL));
			    u = gsl_rng_get(r);
			    j = abs(u%31);
			    s = j+1;
			    sleep(1);
			    printf("parent sending signal %d\n", s);
			    kill(pid,SIGINT);
			    sleep(2);
			    printf("\nparent: sending sigkill\n", s);
			    kill(pid, SIGKILL);
			    sleep(2);
			    }
			return 0;
			}
			 void child(int sigi1)
			 {
			 signal(SIGINT, child);
			 printf("signal recived by child\n");
			 }
			 void parent(int sigi1)
			 {
			 printf("parent will exit now");
			 exit(0);
			 }
