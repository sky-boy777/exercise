#include<stdio.h>
void main()
{
    int s;
	printf("����һ��0��100������\n",s);
    scanf("%d",&s);
    switch(s/10)
    {
        case 10:
        case 9: printf("����\n"); break;
        case 8: printf("��");break;
        case 7: printf("��");break;
        case 6: printf("����");break;
        default: printf("������");
    }
}
