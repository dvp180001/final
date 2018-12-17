 #include <stdio.h>

 int main()
 {
     int x,i,n,temp; // Variables


       printf("Enter a number: ");
	   scanf("%d", &n); 
	   for(i=1;i<=n;i++)
{	                   temp =i;
		              x=i;
			      while (x%2==0)
			     { x = x/2; }
			      while (x%3==0) 
			      {x = x/3;}
			        while (x%5==0)
			       {x = x/5;}
			      
			      
	//printf("ugly numbers are :");      
	
	if(x == 1)

 {
 printf("%d\n",temp);
 }
                                                                    
									 
                                                                           
 }//for
 return 0;
 }

