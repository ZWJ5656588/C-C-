#include "3.2 dynamic linked list.h"


// 1.初始化链表
struct LinkNode *Init_LinkList()
{
    // 创建头结点
    struct LinkNode *header = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    header->data = -1; // 不用头结点数据
    header->next = NULL;

    // 尾部指针,保持指针始终指向尾部
    struct LinkNode *pReal = header;

    int val = -1;
    while (true)
    {
        cout << "请输入插入的数据:" << endl;
        cin >> val;
        if (val == -1)
        {
            break;
        }

        // 先创建新节点
        struct LinkNode *newnode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        newnode->data = val;
        newnode->next = NULL;

        // 新节点插入到链表
        pReal->next = newnode;
        newnode->next = NULL;

        // 更新尾部指针指向
        pReal = newnode;
    }

    return header; // 返回头结点即可
}

// 2. 找到含有oldval的前驱元
struct LinkNode *FindPrevious(int oldval, struct LinkNode *header)
{
    struct LinkNode *p = header;
    while (p->next != NULL && p->next->data != oldval)
    {
        p = p->next;
    }
    // 以下步骤可以选择 如果要求没有找到oldval时插入到链表尾部 则注释掉以下代码即可
#if 0
    if (p->next == NULL)
    {
        p = NULL;
    }
#endif
    return p;
}

// 在值oldval 位置插入新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval)
{
    if (NULL == header)
    {
        return;
    }
    // 找到前驱元的指针p,没找到p == NULL
    struct LinkNode *p = FindPrevious(oldval, header);
    if (NULL == p)
    {
        cout<<"链表中不存在值"<<oldval<<endl;
        return;
    }
    // 创建临时节点tmpcell接收newval并进行插入操作
    struct LinkNode *tmpcell;
    tmpcell = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    // 不要忘记检测动态开辟内存是否成功
    if (tmpcell == NULL)
    {
        cout<<strerror(errno)<<endl;
    }
    tmpcell->data = newval;
    tmpcell->next = p->next;
    p->next = tmpcell; 
}

// 3. 删除值为val的节点
void RemoveByValue_LinkList(struct LinkNode *header, int delval)
{
    if (NULL == header)
    {
        return;
    }
    struct LinkNode *pprev = FindPrevious(header,delval);

    // 判断 pprev 是否为链表最后一个元素 如果是 则代表链表中没有deval
    if (pprev->next == NULL)
    {
        cout<<"链表中没有值"<<delval<<"无法执行删除操作"<<endl;
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

// 4. 遍历
void Foreach_LinkList(struct LinkNode *header)
{
    // 定义辅助指针,不遍历头结点
    if (NULL == header)
    {
        return;
    }

    // 辅助指针变量从头结点的下一个位置开始遍历
    struct LinkNode *pCurrent = header->next;

    while (pCurrent != NULL)
    {
        cout << pCurrent->data << " ";
        pCurrent = pCurrent->next;
    }
}
// 5. 销毁
void Destroy_LinkList(struct LinkNode *header)
{
    if (NULL == header)
    {
        return;
    }

    // 辅助指针变量
    struct LinkNode *pCurrent = header;

    while (pCurrent != NULL)
    {
        //先保存当前节点的下一个节点地址
        struct LinkNode* pNext = pCurrent->next;

        // 释放当前节点内存
        free(pCurrent);

        // 指针后移
        pCurrent = pNext;
    }
    
}
// 6. 清空
void Clear_LinkList(struct LinkNode *header)
{
    if(NULL == header)
    {
        return;
    }
    // 清空————仅保留头结点
    // 辅助指针变量,开始指向第二个节点，因为头结点不释放
    struct LinkNode *pCurrent = header->next;

    while (pCurrent != NULL)
    {
        // 先保存当前节点下一个节点的地址
        struct LinkNode *pNext = pCurrent->next;

        // 释放当前节点内存
        free(pCurrent);

        // pCurrent指向下一节点
        pCurrent = pNext;
    }
    header->next = NULL;
}








// 进行调试test
void text()
{
    // 初始化链表 100 200 666 300 400 500 600
    struct LinkNode *header1 = Init_LinkList();

    // 打印链表
    Foreach_LinkList(header1);

    // 插入数据
    InsertByValue_LinkList(header1,800,666);
    
    // 打印链表
    cout<<"\n"<<"---------------------"<<endl;
    Foreach_LinkList(header1);

    // 清空链表
    Clear_LinkList(header1);
    
    // 再次向空链表添加数据
    InsertByValue_LinkList(header1,1000,101);
    InsertByValue_LinkList(header1,1000,985);

    // 再次打印
    cout<<"\n"<<"---------------------"<<endl;
    Foreach_LinkList(header1);
}




int main()
{
    text();
}
