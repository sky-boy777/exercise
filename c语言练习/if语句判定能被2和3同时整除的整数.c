#include<stdio.h>
void main()
{
    int n,flag=0;
    printf("��������:\n");
    scanf("%d",&n);
    if(n%2==0&&n%3==0)
    flag=1;
    if(flag==0)
        printf("%d����ͬʱ��2��3����\n",n);
    else
        printf("%d�ܱ�2��3ͬʱ����",n);
}
