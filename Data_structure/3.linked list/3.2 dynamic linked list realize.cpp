#include "3.2 dynamic linked list.h"


// 1.��ʼ������
struct LinkNode *Init_LinkList()
{
    // ����ͷ���
    struct LinkNode *header = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    header->data = -1; // ����ͷ�������
    header->next = NULL;

    // β��ָ��,����ָ��ʼ��ָ��β��
    struct LinkNode *pReal = header;

    int val = -1;
    while (true)
    {
        cout << "��������������:" << endl;
        cin >> val;
        if (val == -1)
        {
            break;
        }

        // �ȴ����½ڵ�
        struct LinkNode *newnode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        newnode->data = val;
        newnode->next = NULL;

        // �½ڵ���뵽����
        pReal->next = newnode;
        newnode->next = NULL;

        // ����β��ָ��ָ��
        pReal = newnode;
    }

    return header; // ����ͷ��㼴��
}

// 2. �ҵ�����oldval��ǰ��Ԫ
struct LinkNode *FindPrevious(int oldval, struct LinkNode *header)
{
    struct LinkNode *p = header;
    while (p->next != NULL && p->next->data != oldval)
    {
        p = p->next;
    }
    // ���²������ѡ�� ���Ҫ��û���ҵ�oldvalʱ���뵽����β�� ��ע�͵����´��뼴��
#if 0
    if (p->next == NULL)
    {
        p = NULL;
    }
#endif
    return p;
}

// ��ֵoldval λ�ò����µ�����newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval)
{
    if (NULL == header)
    {
        return;
    }
    // �ҵ�ǰ��Ԫ��ָ��p,û�ҵ�p == NULL
    struct LinkNode *p = FindPrevious(oldval, header);
    if (NULL == p)
    {
        cout<<"�����в�����ֵ"<<oldval<<endl;
        return;
    }
    // ������ʱ�ڵ�tmpcell����newval�����в������
    struct LinkNode *tmpcell;
    tmpcell = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    // ��Ҫ���Ǽ�⶯̬�����ڴ��Ƿ�ɹ�
    if (tmpcell == NULL)
    {
        cout<<strerror(errno)<<endl;
    }
    tmpcell->data = newval;
    tmpcell->next = p->next;
    p->next = tmpcell; 
}

// 3. ɾ��ֵΪval�Ľڵ�
void RemoveByValue_LinkList(struct LinkNode *header, int delval)
{
    if (NULL == header)
    {
        return;
    }
    struct LinkNode *pprev = FindPrevious(header,delval);

    // �ж� pprev �Ƿ�Ϊ�������һ��Ԫ�� ����� �����������û��deval
    if (pprev->next == NULL)
    {
        cout<<"������û��ֵ"<<delval<<"�޷�ִ��ɾ������"<<endl;
        return;
    }
    else
    {
        struct LinkNode * tmp = pprev->next;
        pprev->next = tmp->next;
        free(tmp);
        tmp = NULL;
    }

}

// 4. ����
void Foreach_LinkList(struct LinkNode *header)
{
    // ���帨��ָ��,������ͷ���
    if (NULL == header)
    {
        return;
    }

    // ����ָ�������ͷ������һ��λ�ÿ�ʼ����
    struct LinkNode *pCurrent = header->next;

    while (pCurrent != NULL)
    {
        cout << pCurrent->data << " ";
        pCurrent = pCurrent->next;
    }
}
// 5. ����
void Destroy_LinkList(struct LinkNode *header)
{
    if (NULL == header)
    {
        return;
    }

    // ����ָ�����
    struct LinkNode *pCurrent = header;

    while (pCurrent != NULL)
    {
        //�ȱ��浱ǰ�ڵ����һ���ڵ��ַ
        struct LinkNode* pNext = pCurrent->next;

        // �ͷŵ�ǰ�ڵ��ڴ�
        free(pCurrent);

        // ָ�����
        pCurrent = pNext;
    }
    
}
// 6. ���
void Clear_LinkList(struct LinkNode *header)
{
    if(NULL == header)
    {
        return;
    }
    // ��ա�������������ͷ���
    // ����ָ�����,��ʼָ��ڶ����ڵ㣬��Ϊͷ��㲻�ͷ�
    struct LinkNode *pCurrent = header->next;

    while (pCurrent != NULL)
    {
        // �ȱ��浱ǰ�ڵ���һ���ڵ�ĵ�ַ
        struct LinkNode *pNext = pCurrent->next;

        // �ͷŵ�ǰ�ڵ��ڴ�
        free(pCurrent);

        // pCurrentָ����һ�ڵ�
        pCurrent = pNext;
    }
    header->next = NULL;
}








// ���е���test
void text()
{
    // ��ʼ������ 100 200 666 300 400 500 600
    struct LinkNode *header1 = Init_LinkList();

    // ��ӡ����
    Foreach_LinkList(header1);

    // ��������
    InsertByValue_LinkList(header1,800,666);
    
    // ��ӡ����
    cout<<"\n"<<"---------------------"<<endl;
    Foreach_LinkList(header1);

    // �������
    Clear_LinkList(header1);
    
    // �ٴ���������������
    InsertByValue_LinkList(header1,1000,101);
    InsertByValue_LinkList(header1,1000,985);

    // �ٴδ�ӡ
    cout<<"\n"<<"---------------------"<<endl;
    Foreach_LinkList(header1);
}




int main()
{
    text();
}
