#include<iostream>
using namespace std;
# define MAXSIZE  10


// 链表是一种数据结构 包括指针域和数据域
struct LinkNode{
    int data;
    struct LinkNode* next;
};

// 线性表顺序存储  
typedef struct LNode*List;
struct LNode{
    int Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;

int main()
{
    {
        // 1.定义静态链表
        struct LinkNode node1={10,NULL};
        struct LinkNode node2={20,NULL};
        struct LinkNode node3={30,NULL};
        struct LinkNode node4={40,NULL};
        struct LinkNode node5={50,NULL};
        struct LinkNode node6={60,NULL};
        
        // 数据域指向下一个节点的地址
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node5;
        node5.next = &node6;

        // 如何遍历链表？

        // 先定义一个辅助指针变量
        struct LinkNode*pCurrent = &node1;
        while (pCurrent != NULL)
        {
            cout<<pCurrent->data<<" ";

            // 指针移动到下一个元素的首地址
            pCurrent = pCurrent->next;
        }
        
        

        
    }
}
     