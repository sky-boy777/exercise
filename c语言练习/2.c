typedef int DataType;

//����
typedef struct Node
{
  DataType *data;
  struct Node *next;
}Node, *pNode, *pList;
void InitLinkList(pList *pplist);//��ʼ������
pNode BuyNode(DataType d);//��������ڵ�
void PushBack(pList *pplist, DataType d);//β��
void PopBack(pList *pplist);//βɾ
void PushFront(pList *pplist, DataType d);//ͷ��
void PopFront(pList *pplist);//ͷɾ
void PrintList(pList plist);//��ӡ����
pNode Find(pList plist, DataType d);//����ָ��Ԫ��
void Remove(pList *pplist, DataType d);//ɾ��ָ����һ��Ԫ��
void RemoveAll(pList *pplist, DataType d);//ɾ��ָ��������Ԫ��
void Insert(pList *pplist, pNode pos, DataType d);//ָ��λ�õĺ������
void Erase(pList *pplist, pNode pos);//ָ��λ��ɾ��
void DestroyList(pList *pplist);//��������
pNode BuyNode(DataType d)

{
  pNode newNode = (pNode)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  newNode->data = d;
  newNode->next = NULL;
  return newNode;
}
void InitLinkList(pList *pplist)
{
  assert(pplist);
  *pplist = NULL;
}
void PushBack(pList *pplist, DataType d)
{
  assert(pplist);
  pNode newNode = BuyNode(d);
  pNode cur = *pplist;
  //����û�нڵ�
  if (*pplist == NULL)
  {
    *pplist = newNode;
    return;
  }
  //�����нڵ�
  while (cur->next != NULL)
  {
    cur = cur->next;
  }
  cur->next = newNode;
}
void PopBack(pList *pplist)
{
  pNode cur = *pplist;
  pNode prev = NULL;
  assert(pplist);
  //����û�нڵ�
  if (*pplist == NULL)
  {
    return;
  }
  //������һ���ڵ�
  if (cur->next == NULL)
  {
    free(*pplist);
    *pplist = NULL;
    return;
  }
  //�������������������Ͻڵ�
  while (cur->next != NULL)
  {
    prev = cur;//prev�б������cur֮ǰ���Ǹ��ڵ�
    cur = cur->next;
  }
  prev->next = NULL;
  free(cur);
}
void PushFront(pList *pplist, DataType d)
{
  pNode newNode = BuyNode(d);
  //pNode cur = *pplist;
  assert(pplist);
  ////����û�нڵ�
  //if (*pplist == NULL)
  //{
  // *pplist = newNode;
  //}
  ////�����нڵ�
  newNode->next = *pplist;
  *pplist = newNode;

}
void PopFront(pList *pplist)
{
  pNode cur = *pplist;
  assert(pplist);
  //����Ϊ��
  if (*pplist == NULL)
  {
    return;
  }
  *pplist = cur->next;
  free(cur);
  cur = NULL;
}
void PrintList(pList plist)
{
  pNode cur = plist;
  while (cur)
  {
    printf("%d-->", cur->data);
    cur = cur->next;
  }
  printf("NULL\n");
}
pNode Find(pList plist, DataType d)
{
  pNode cur = plist;
  while (cur)
  {
    if (cur->data == d)
    {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}
void Remove(pList *pplist, DataType d)
{
  pNode cur = *pplist;
  pNode prev = NULL;
  assert(pplist);
  if (cur == NULL)
  {
    return;
  }
  while (cur)
  {
    if (cur->data == d)
    {
      pNode del = cur;
      if (cur == *pplist)
      {
        *pplist = cur->next;
      }
      prev->next = cur->next;
      free(del);
      del = NULL;
      return;
    }
    else
    {
      prev = cur;
      cur = cur->next;
    }
  }
}
void RemoveAll(pList *pplist, DataType d)
{
  pNode cur = *pplist;
  pNode prev = NULL;
  assert(pplist);
  if (*pplist == NULL)
  {
    return;
  }
  while (cur)
  {
    if (cur->data == d)
    {
      pNode del = cur;
      if (cur == *pplist)
      {
        *pplist = cur->next;
      }
      else
      {
        prev->next = cur->next;
      }
      cur = cur->next;
      free(del);
      del = NULL;
    }
    else
    {
      prev = cur;
      cur = cur->next;
    }
  }

}
//��pos�������һ��Ԫ��
void Insert(pList *pplist, pNode pos, DataType d)
{
  pNode newNode = BuyNode(d);
  assert(pplist);
  assert(pos);
  if (*pplist == NULL)
  {
    PushFront(pplist, d);
    return;
  }
  newNode->next = pos->next;
  pos->next = newNode;
}
void Erase(pList *pplist, pNode pos)
{
  assert(pplist);
  assert(pos);
  //Ҫɾ������β�ڵ�
  if (pos->next == NULL)
  {
    PopBack(pplist);
  }
  //ɾ�����Ƿ�β�ڵ�
  else
  {
    pNode del = pos->next;
    pos->data = pos->next->data;
    pos->next = pos->next->next;
    free(del);
    del = NULL;
  }
}
void DestroyList(pList *pplist)
{
  assert(pplist);
  pNode cur = *pplist;
  while (cur)
  {
    pNode del = cur;
    cur = cur->next;
    printf("del:%d\n", del->data);
    free(del);
    del = NULL;
  }
}
