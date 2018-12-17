   /*--------------------------------------------------------------------*/
   #include "mytools.h"
   #include <assert.h>
   #include <math.h>
   #include <stdio.h>
   /* ------------------------------------------------
        *   * ------------------------------------------------*/
   int main()
   {
     int i;
     // varible x and y for distance
     double x=0;
     double y=0;
     // intitialize to find variable
     double deviation=0; 
     //intialize to find error
     double error=0;
     // sum
     double s, sum, p=0;
     //variable inside and outside of circle
     double inside=0;
     double outside=0;
     //to find distance 
     double dist_origin=0;
     //to estimate pie
     double estpi=0;
     double e=0;
    double  NUM_ITERS=10;
double pie = 3.14;

 const gsl_rng_type * t;
 double squreroot;
   gsl_rng * r1;
   gsl_rng * r2;
	   gsl_rng_env_setup();
t= gsl_rng_default;
r1= gsl_rng_alloc(t);
r2= gsl_rng_alloc(t);
         /* Step 1: initialize tool */

//	   assert( init_mytool() == 0);

	     /* Step 2: use tool to get sequence of random numbers */
 gsl_rng_set(r1, time(NULL));
	       for(i=0;i<NUM_ITERS;i++)
	         {  //printf("Random number = %f\n",get_random_number());
                 x=gsl_rng_uniform(r1);
		 printf("x variable = %f\n",x);
		 y=gsl_rng_uniform(r2);
		 printf("y variable=%f\n",y);
                 s=x*x;
                 p=y*y;
/* Step 3: clean up tool */
dist_origin = (s+p);
squreroot = sqrt(dist_origin);
if (squreroot < 1);
inside +=1;
outside++;
sum += squreroot;
//inside++;
//outside ++;
//s += dist_origin;
}
//finalize_mytool();
estpi = (sum/NUM_ITERS)*4.0;

printf("estimate value of pie = %.3f\n",estpi);
deviation = pie - estpi;
error = abs(((pie-estpi)/estpi)*100);
//printf("estimated value of pie = %.4f\n",estpi);
printf("percent error = %.4f\n",error);
printf("deviation = %.4f\n",deviation);
//finalize_mytool();

		         return 0;
}
