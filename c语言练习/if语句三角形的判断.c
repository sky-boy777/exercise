#include<stdio.h>
void main()
{
    int a,b,c;
    printf("���������������ߵ�ֵa,b,c:(�ÿո�ֿ�)\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a==b&&b==c)
        printf("�ȱ�������\n");
    else if(a!=b&&a!=c&&b!=c)
        printf("һ��������\n");
    else
    printf("����������");

}
