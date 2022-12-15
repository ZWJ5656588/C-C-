# include<stdio.h>

int main()
{
    {
        // 1. 喝汽水问题，汽水1元一瓶，2隔空空瓶换一瓶汽水
        // 分为两部分 (1)买回来的汽水 (2)换的汽水
        //(1)
        int money=0;
        int total=0;
        int empty=0; //空瓶
        printf("请输入money:");
        scanf("%d",&money);
        total=money/1; //买回来的汽水
        empty=total;
        //(2)
        while(empty>=2)
        {
            total+=empty/2;   //加上某一次喝完以后空瓶能换的汽水瓶数
            // 喝完以后余下的空瓶
            empty=empty/2+empty%2;  //加上上一次余下的空瓶
        }
        printf("总共能买%d瓶\n", total);
        printf("手里还有%d个空瓶\n",empty);
    }   

}
