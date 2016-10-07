//
//  PolynomialAddition.c
//  多项式加法，使用效率不高的冒泡排序仅对链表进行值交换
//  对于链表的排序方法有很多，这里只是简单地实现多项式降幂排序输出。
//  Created by Jerry on 16/10/2.
//  Copyright © 2016年 Spacebody. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//使用结构体构建多项式的每一项
typedef struct Polynomial
{
    int cff; //系数
    int exp; //指数
    struct Polynomial *next; //下一个节点位置
}poly;



poly *create(); //创建多项式
void printList(poly *head);//打印多项式
poly *addCff(poly *head);//多项式相加
poly *addItem(poly *head, int cff, int exp);//插入 A 中不存在的多项式
poly *sortItem(poly *head); //多项式冒泡排序


int main(void)
{
    poly *head;
    head = NULL;
    printf("请输入多项式 A 的各项的系数和幂次（使用“ ，”隔开）,输入 “0,0” 结束:\n");
    head = create(); //创建链表
    printList(head); //打印结果
    printf("请输入多项式 B 的各项的系数和幂次（使用“ ，”隔开）,输入 “0,0” 结束:\n");
    head = addCff(head); //合并同类项
    head = sortItem(head); //降幂排序
    printList(head);//输出结果
    return 0;
}

//创建链表
poly *create()
{
    int cff,exp;
    poly *head, *current, *p;
    head = (poly *)malloc(sizeof(poly));
    p = head;
    scanf("%d,%d",&cff,&exp);
    if (cff != 0)
    {
        p->cff = cff;
        p->exp = exp;
    }
    else
    {
        head->next = NULL; //只有头结点的情况
        return head;
    }
    while (1)
    {
        scanf("%d,%d",&cff,&exp);
        if (cff == 0 )
        {
            printf("输入结束\n");
            break;
        }
        current = (poly *)malloc(sizeof(poly));
        current->cff = cff;
        current->exp = exp;
        p->next = current;
        p = p->next;
    }
    p->next = NULL;
    return head;
}

//打印链表
void printList(poly *head)
{
    poly *p = head;
    if (p == NULL)
    {
        printf("当前无数据，请创建!\n");
    }
    else
    {
        printf("当前多项式为(系数，次数):\n");
    }
    while (p != NULL)
    {
        printf("%d, %d\n", p->cff,p->exp);
        p = p->next;
    }
    printf("\n");
}

//多项式加法
poly *addCff(poly *head)
{
    poly *p;
    int cff,exp;
    while(1)
    {
        scanf("%d,%d",&cff,&exp);
        if(exp == 0)
        { //系数为0则跳出循环
            break;
        }
        p=head;
        do
        {
            if(p->exp == exp)
            {
                p->cff += cff;
                break; //合并同列项后跳出循环
            }
            if(p->exp!=exp && p->next == NULL)
            {
                head = addItem(head, cff, exp); //添加 多项式 A 中不存在的项
            }
            p=p->next; //指向下一个节点
        }while(p!=NULL);
    }
    return head;
}


//末尾插入 A 中不存在的多项式
poly *addItem(poly *head, int cff, int exp)
{
    poly *current, *p;
    current = head;
    while (current->next != NULL)
    {
        //寻找末尾节点
        current = current->next;
    }
    p = (poly *)malloc(sizeof(poly)); //申请空间
    p->cff = cff;
    p->exp = exp;
    p->next = current->next;
    current->next = p;
    return head;
}

//多项式排序（冒泡排序）
poly *sortItem(poly *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    poly *p = head->next;
    poly *pre= head;
    bool flag = false;   //用于标记是否有交换，当数组有序的时候，提高判断效率
    
    while(pre->next != NULL)
    {
        int tempExp = pre->exp;
        while (p)
        {
            if(tempExp > p->exp)
            {
                p = p->next;
                continue;
            }
            else
            { //交换节点内值
                int tempExp,tempCff;
                tempExp = p->exp;
                tempCff = p->cff;
                p->exp = pre->exp;
                p->cff = pre->cff;
                pre->exp = tempExp;
                pre->cff = tempCff;
                p = p->next;
                flag = true;
            }
            if (flag == false)
            {
                return head;
            }
        }
        pre = pre->next;
        p = pre;
    }
    return head;
}


