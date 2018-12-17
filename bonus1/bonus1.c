 #include <stdio.h>
 #include <math.h>
 int main()
 {
 int x;
 double f;
 double lnfactorial( int a);
 int main(void)
 {
 printf("enter an integer:%d\n", x);
 f = lnfactorial(x);
 printf(" ln in factor d is %f\n",f);
 return 0;
 }
 }
double lnfactorial(int a)
{ 
 //int a;
 int y;
 double z;
 if(a == 1)
 return 1;
 else
 {
  z=0;
  for(y=2; y<=a; y++)
  z = Lnfactorial(y)+z;
  return (z);
  }
  }

