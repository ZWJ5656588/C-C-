#pragma once
# include<iostream>
# include<stdlib.h>
# include<stdbool.h>
# include<errno.h>
# include<string.h>

using namespace std;


#ifdef __cplusplus
extern "C" {
#endif
    
    // 定义数据类型
    struct LinkNode
    {
        int data;
        struct LinkNode *next; 
    };

    // 初始化链表
    struct LinkNode*Init_LinkList();
    // 找到含有oldval的前驱元
    struct LinkNode*FindPrevious(int oldval,struct LinkNode*header);
    // 在值oldval 位置插入心的数据newval
    void InsertByValue_LinkList(struct LinkNode *header,int oldval,int newval);
    // 删除值为val的节点
    void RemoveByValue_LinkList(struct LinkNode *header,int delval);
    // 遍历
    void Foreach_LinkList(struct LinkNode *header);
    // 销毁
    void Destroy_LinkList(struct LinkNode *header);
    // 清空
    void Clear_LinkList(struct LinkNode *header);  
    







#ifdef __cplusplus
}
#endif