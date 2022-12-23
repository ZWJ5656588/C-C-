#include "3.2 dynamic linked list.h"

// 初始化链表
struct LinkNode *Init_LinkList()
{
    // 创建头结点
    struct LinkNode *header = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    header->data = -1;  // 不用头结点数据
    header->next = NULL;

    // 尾部指针,保持指针始终指向尾部
    struct LinkNode *pReal = header;

    int val = -1;
    while (true)
    {
        cout << "请输入插入的数据" << endl;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        

    // 先创建新节点
    struct LinkNode *newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    newnode->data = val;
    newnode->next = NULL;

    // 新节点插入到链表
    pReal->next = newnode;
    newnode->next = NULL;

    // 更新尾部指针指向
    pReal = newnode;
    
    }
    
    return header; //返回头结点即可
}




// 在值oldval 后面插入新的数据newval
void InsertByValue_LinkList(struct LinkNode * header, int oldval, int newval)
{
    ;
}
// 删除值为val的节点
void RemoveByValue_LinkList(struct LinkNode * header, int delval);
// 遍历
void Foreach_LinkList(struct LinkNode * header)
{
    // 定义辅助指针,不遍历头结点
    if (NULL == header)
    {
        return ;
    }

    // 辅助指针变量
    struct LinkNode *pCurrent = header->next;

    while (pCurrent != NULL)
    {
        cout<<pCurrent->data<<" ";
        pCurrent = pCurrent->next;
    }       
}
// 销毁
void Destroy_LinkList(struct LinkNode * header);
// 清空
void Clear_LinkList(struct LinkNode * header);
