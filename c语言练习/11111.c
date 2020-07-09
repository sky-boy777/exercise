#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node {
    DataType member;
    struct node *next;
}*LinkList, *pNode;

// ��ʼ������
LinkList GetEmptyList() {
    LinkList head = (pNode)malloc(sizeof(struct node));
    head->member = 0;
    head->next = NULL;
    return head;
}


// �ڷ��������в�����
void InsertNode(LinkList head, DataType x) {
    pNode p,q;
    for(p = head; p->next != NULL; p = p->next) {
        if(p->next->member <= x) {
            q = (pNode)malloc(sizeof(struct node));
            q->member = x;
            q->next = p->next;
            p->next = q;
            return;
        }
    }
    q = (pNode)malloc(sizeof(struct node));
    q->member = x;
    q->next = p->next;
    p->next = q;
}

// �½�����Ϊ�׽��
void PushNode(LinkList head, DataType x) {
    pNode p = (pNode)malloc(sizeof(struct node));
    p->member = x;
    p->next = head->next;
    head->next = p;
}

// ɾ�����
int DeleteNode(LinkList head, DataType x) {
    pNode p,q;
    for(p = head; p != NULL; p = p->next) {
        if(p->next->member == x) {
            q = p->next;
            p->next = q->next;
            free(q);
            return 1; // �ɹ�ɾ��member(��һ��)Ϊx�Ľ��
        }
    }
    return 0; // û���ҵ�memberΪx�Ľ��
}

// ���ҽ��
int FindNode(LinkList head, DataType x) {
    pNode p;
    for(p = head->next; p != NULL; p = p->next) {
        if(p->member == x) return 1; // �ҵ���
    }
    return 0; // û���ҵ�
}

// ��������
void DestroyList(LinkList head) {
    pNode q,p = head;
    while(p) {
        q = p;
        p = q->next;
        free(q);
    }
    head = NULL;
}

// ��������
void ShowList(LinkList head) {
    pNode p = head->next;
    while(p != NULL) {
        printf("%d ",p->member);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DataType x,res;
    LinkList head = GetEmptyList();
    printf("����һ������('q' to quit): ");
    while(scanf("%d",&x) == 1) {
        InsertNode(head, x); // ������������
        printf("����һ������('q' to quit): ");
    }
    fflush(stdin);
    ShowList(head);
    printf("��������ҵ�����: ");
    scanf("%d",&x);
    res = FindNode(head, x);
    if(res) printf("�ҵ��ˡ�\n");
    else printf("û�ҵ���\n");
    printf("�����ɾ��������: ");
    scanf("%d",&x);
    res = DeleteNode(head, x);
    if(res) printf("�ɹ�ɾ����\n");
    else printf("û�ҵ�����Ϊ:%d�Ľ�㣡\n",x);
    ShowList(head);
    DestroyList(head);
    return 0;
}
