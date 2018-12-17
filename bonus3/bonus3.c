#include <stdio.h>
#include <string.h>
int main()
{
int sum, num;
 int x,i,n,temp; // Variables


        printf("Enter a number: ");
	           scanf("%d", &n);
		   for(i=1; i<=num; i++)
		   {
		   if(num%i == 0)
		   sum+=i;
		   }
		   n=2*num;
		   if(sum<n)
		   printf("its deficient number");
		   else if(sum=n)
		   printf("its perfect num");
		   else if(sum>n)
		   printf("its abudent");
		   return 0;
		   }
