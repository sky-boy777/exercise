#include<stdio.h>
void main()
{
   int x=35;
   char z='A';
   int b;
   b=((x&15)&&(z<'a'));
   printf("%d",b);/*���н��Ϊ1*/
}
