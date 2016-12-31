/**
 *顺序表例程
 *
 *By Spacebody
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef  _SequenceList_h

typedef struct list seqList; 
typedef int eleType;

#define MAXSIZE 10  //初始分配量
#define LISTINCREMENT 10  //存储空间的分配增量
#define FINISHED 1 //执行成功
#define ERROR 0 //错误
#define OVERFLOW -2 //溢出

//函数声明
int initList(seqList *se); //初始化顺序表
int currSize(seqList *se); //顺序表当前长度
int claerList(seqList *se); //清空顺序表
bool isEmpty(seqList se);  //顺序表是否为空
eleType getElemAt(seqList se,int i); //返回第 i 个数据
int deleteElem(seqList *se, int i); //删除第 i 个元素，i+1 之后的元素前移一位
int insertElement(seqList *se,eleType e); //末尾添加一个元素
int locateElem( seqList se, eleType e); //查找顺序表中第一个与所给数据匹配的数据元素的位置
int printList(seqList se); //打印顺序表
int maxSize(void); //返回顺序表容量
int insertElementAT(seqList *se, int i, eleType e); //第 i 个位置插入元素
int destList(seqList *se); //销毁顺序表

#endif   /* Sequence.h */

struct list //定义一个结构体
{
    eleType *elem;  //存储空间基地址
    int listSize;   //当前分配的内存
    int length;   //当前顺序表的长度
};


//主函数
int main(void)
{
    seqList *pL=(seqList *)malloc(sizeof(seqList)); //申请存储空间
    initList(pL); //初始化顺序表
    
    int a,i;
    eleType data;  //int 型数据
    while(1)
    {   //打印菜单
        printf("\n/**********顺序表功能实现示例**********/\n");
        printf("\n1.创建顺序表\n");
        printf("\n2.打印顺序表\n");
        printf("\n3.查询顺序表中某个位置的数据\n");
        printf("\n4.查询与数据匹配的元素的位置\n");
        printf("\n5.向顺序表中某个位置插入数据\n");
        printf("\n6.向顺序表添加数据\n");
        printf("\n7.删除顺序表中的数据\n");
        printf("\n8.返回顺序表当前长度\n");
        printf("\n9.返回顺序表容量\n");
        printf("\n10.查询顺序表是否为空\n");
        printf("\n11.清空顺序表\n");
        printf("\n12.销毁顺序表\n");
        printf("\n0.退出\n");
        printf("\n输入1-12，选择您需要的功能:\n");
        scanf("%d",&a);
        printf("\n您选择的功能号为：%d\n",a);
        
        switch(a)
        {
            case 1:   //创建顺序表
                initList(pL);
                printf("\n创建成功\n");
                break;
            case 2:    //打印顺序表
                printList(*pL);
                break;
            case 3:    //查询顺序表中某个位置的数据
                printf("\n请输入您需要查询的元素的编号1-%d:",pL->length);
                scanf("%d",&i);
                data=getElemAt(*pL,i);
                printf("\n您查询的数据为%d\n",data);
                break;
            case 4:    //查询与数据匹配的元素的位置
                printf("\n请输入您需要查询的数据元素:\n");
                scanf("%d",&data);
                if(locateElem(*pL,data))
                {
                    printf("\n您查询的元素的位置是:%d\n",locateElem(*pL,data));
                }
                else
                {
                    printf("\n没有查询到您输入的数据\n");
                }
                break;
            case 5:    //向顺序表中某个位置插入数据
                printf("\n请输入您需要插入的数据以及它的位置:");
                scanf("%d%d",&data,&i);
                printf("\n您需要插入的数据是%d\n您要插入的位置是:%d\n",data,i);
                if(insertElementAT(pL,i,data))
                {
                    printf("\n插入成功\n");
                }
                printf("插入后的链表排序为:\n");
                printList(*pL);
                break;
            case 6:  //向顺序表添加数据
                printf("\n请输入要添加的数据:\n");
                scanf("%d",&i);
                printf("您要添加的是:%d\n",i);
                if(insertElement(pL,i))
                {
                    printf("\n添加成功\n");
                }
                else
                {
                    printf("\n列表已满，添加失败\n");
                }
                printf("添加后的顺序表排序为:\n");
                printList(*pL);
                break;
            case 7:    //删除顺序表中的数据
                printf("\n请输入您需要删除元素的位置:");
                scanf("%d",&i);
                printf("您要删除的位置是:%d\n",i);
                if(deleteElem(pL,i))
                {
                    printf("删除成功\n");
                }
                printf("删除后的链表为：\n");
                printList(*pL);
                break;
            case 8:  //返回顺序表当前长度
                printf("\n当前顺序表长度:%d", currSize(pL));
                break;
            case 9:  //返回顺序表容量
                printf("\n顺序表容量:%d",maxSize());
                break;
            case 10: //查询顺序表是否为空
                if(isEmpty(*pL))
                {
                    printf("\n顺序表为空\n");
                }
                else
                {
                    printf("\n顺序表非空\n");
                }
                break;
            case 11:  //清空顺序表
                claerList(pL);
                printf("\n清空成功\n");
                break;
            case 12: //销毁顺序表
                if(destList(pL))
                {
                    printf("\n销毁成功\n");
                }
                else
                {
                    printf("\n顺序表未存在\n");
                }
                break;
            case 0:    //退出
                return FINISHED;
            default:
                printf("无该选项，请重新选择（1~12，输入 0 退出）\n");
                break;
        }
    }
    return 0;
}

//1初始化顺序表
int initList(seqList *se)
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

//2打印顺序表
int printList(seqList se)
{ //传入参数为结构体 se
    int i;
    printf("顺序表 se: ");
    //输出顺序表元素
    for(i = 1;i<=se.length;i++)
    {
        printf("%d\t",se.elem[i-1]);
    }
    printf("\n"); //换行
    return FINISHED;
}

//3返回第 i 个数据
eleType getElemAt(seqList se,int i)
{
    //检查 i 的合法性
    if(i<1||i>se.length)
    {
        return ERROR; //不合法则报错
    }
    else
    {
        return se.elem[i-1]; //返回第 i 个上数据
    }
}

//4查找顺序表中第一个与所给数据匹配的数据元素的位置
int locateElem( seqList se, eleType e)
{
    int i=1;
    eleType *p=se.elem;
    //寻找数据
    while(*p != e && i<=se.length)
    {
        i++;
        p++;
    }  //p指向下一个元素
    
    //检查 i 是否合法
    if(i>se.length)
    {
        return 0;   //没有找到数据,返回0
    }
    else
    {
        return i;  //找到返回位置i
    }
}

//5第 i 个位置插入元素
int insertElementAT(seqList *se, int i, eleType e)
{
    eleType *p;
    eleType *q;
    if(i<1||i>(se->length+1))
    {
        return ERROR;
    }
    if(se->length >= se->listSize)
    {
        printf("列表已满，插入失败");
        return ERROR;
    }
    else
    {
        q=&(se->elem[i-1]);
        p=se->elem+se->length-1;
        for(;p>=q;p--)
        { //对于插入位置之后的元素，从最后一位元素开始依次后移一个位置
            *(p+1)=*(p);
        }
        *q = e; //插入元素
        ++se->length; //表长增加 1
        return FINISHED;
    }
}

//6末尾添加一个元素
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

//7删除第 i 个元素，i+1 之后的元素前移一位
int deleteElem(seqList *se, int i)
{
    eleType *p, *q;
    p=&(se->elem[i-1]);   //确定要删除的位置
    q=se->elem+se->length-1;    //将 q 指向最后一个元素
    
    //将后继元全部前移一位
    while(p<q)
    { //从删除位置开始，之后的后继元全部前移一个位置
        *p=*(p+1);
        p++;
    }
    --se->length;//表长减小 1
    return FINISHED;
}


//8顺序表当前长度
int currSize(seqList *se)
{
    return se->length; //返回顺序表长度
}

//9返回顺序表容量
int maxSize(void)
{
    return MAXSIZE;
}

//10顺序表是否为空
bool isEmpty(seqList se)
{
    //判断顺序表是否为空
    if(se.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//11清空顺序表，默认置为 0
int claerList(seqList *se)
{
    se->length = 0;
    return FINISHED;
}

//12销毁顺序表
int destList(seqList *se)
{
    if(se->elem)
    {  //释放存储空间
        free(se->elem);
        return FINISHED;
    }
    else
    {
        return ERROR;
    }
}

