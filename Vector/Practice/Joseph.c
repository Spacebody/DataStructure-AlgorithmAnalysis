/**
 *约瑟夫问题：
 *设有 n 个人围成一个圆圈坐下，从某个人开始对所有围坐的人依次编号为1，2，3，…，n，
 *从编号为1 的人开始沿围坐的圆圈顺序报数，报数为m的人即出列，于是第 m+1 个人就与第 m-1 个人紧挨着；
 *下一个人 (第 m+1 个) 又从1 开始沿围坐的圆圈顺序报数，再报数到 m 的人便是第二个出列的人。
 *如此重复下去，直到最后一个人出列为止，于是便得到一个出列的顺序。
 *
 *By Spacebody
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _Joseph_h

#define MAXSIZE 10  //初始分配量
#define LISTINCREMENT 10  //存储空间的分配增量
#define FINISHED 1
#define ERROR 0
#define OVERFLOW -2
typedef int eleType;
typedef struct list seqList;

//函数声明
int listInit(seqList *se); //初始化顺序表
int insertElement(seqList *se,eleType e); //插入元素
int josephElem(seqList *se,int m);//出列元素

#endif /* Joseph.h */

struct list //定义一个结构体
{
    eleType *elem;  //存储空间基地址
    int listSize;   //当前分配的内存
    int length;   //当前顺序表的长度
};

//主函数
int main(void)
{
    seqList *joList=(seqList *)malloc(sizeof(seqList)); //初始化列表
    listInit(joList);
    
    int n,m,i;
    printf("请输入总人数: ");
    scanf("%d",&n);
    printf("请输入每轮出列的人的报数: ");
    scanf("%d",&m);
    for(i = 1;i<=n;i++)
    {
        insertElement(joList,i);
    }
    josephElem(joList,m);

    return 0;
}

//初始化顺序表
int listInit(seqList *se)
{
    se->elem = (eleType *)malloc(sizeof(eleType)); //指定每个元素的内存大小为 int 型
    if(!se->elem)
    {   //存储空间分配失败
        exit(OVERFLOW);
    }
    se->length = 0; //置空白长度为 0
    se->listSize = MAXSIZE; //制定顺序表最大长度
    return FINISHED;
}

//插入元素
int insertElement(seqList *se,eleType e)
{
    eleType *p;
    if(se->length >= se->listSize)
    {   //检查列表是否已满
        return ERROR;
    }
    else
    {
        p = se->elem+se->length-1;  //指向最后一个元素
        *(p+1) = e;  //插入最后一个元素的后继元
        ++se->length; //列表增加一位
    }
    return  FINISHED;
}

//出列元素
int josephElem(seqList *se,int m)
{
    int t=0,j,k;
    if(m>se->length)
    { //超出已有人数则报错
        printf("并没有这么多人哦~~\n");
        return ERROR;
    }
    else
    {
        //确保在人数范围内查找出列元素
        for(j=se->length;j>=1;j--)
        {
            t=(t+m-1)%j; //查找出列元素
            printf("%d\t",se->elem[t]); //输出该元素
            for(k=t+1;k<=j-1;k++)
            {
                //从出列对象的后继元开始往前移动一位
                se->elem[k-1]=se->elem[k];
            }
        }
        printf("\n");
        return FINISHED;
    }
    
}



