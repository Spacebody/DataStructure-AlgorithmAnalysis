//
//  LinkedList.c
//  链表实现
//
//目前已知 BUG: 逆置之后的链表无法正常使用其他功能
//  Created by Jerry on 16/9/27.
//  Copyright © 2016年 Spacebody. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef _LinkedList_h

typedef struct Node node;
#define FINISHED 1
#define ERROR 0
//使用结构体构建链表节点
struct Node
{
    int data; //链表内数据
    struct Node *next; //下一个节点位置
};

#endif  /*LinkedList.h*/


//函数声明
int printLen();  //打印链表长度
int printNext();  //打印下一个节点
int setValue();  //设置元素值
int getValue();  //获取元素值
int findElemAt(node *head,int elem); //寻找与给定数据匹配的节点位置
void printList(node *head); //打印链表
void destroyList(node* head); //销毁链表
node *create();  //创建链表
node *insertNode(node *head,int elem,int position);  //插入节点
node *deleteNode(node *head,int elem);  //删除节点
node *reverseList(node *head);  //逆置顺序
node *addNode(); //末尾添加节点

//主函数
int main(void)
{
    node *head;
    head = NULL;
    int elem ,position,a;
    
    while(1)
    {   //打印菜单
        printf("\n/*********链表功能实现示例**********/\n");
        printf("\n1.创建链表\n");
        printf("\n2.打印链表\n");
        printf("\n3.查询链表中指定节点内的数据\n");
        printf("\n4.查询链表中指定节点的下一个节点内的数据\n");
        printf("\n5.查询与数据匹配的元素的节点\n");
        printf("\n6.向链表中指定位置之后插入节点\n");
        printf("\n7.向链表末尾添加节点\n");
        printf("\n8.删除链表中指定位置的节点\n");
        printf("\n9.返回链表长度\n");
        printf("\n10.设置指定节点内数据\n");
        printf("\n11.逆置链表\n");
        printf("\n12.销毁链表\n");
        printf("\n0.退出\n");
        printf("\n输入1-12，选择您需要的功能:\n");
        scanf("%d",&a);
        printf("\n您选择的功能号为：%d\n",a);
        
        switch(a)
        {
            case 1:   //创建链表
                head = create();
                printf("创建成功，创建链表为: ");
                printList(head); //输出创建的链表
                break;
            case 2:    //打印链表
                printf("当前链表为: ");
                if(head ==NULL )
                {   //无链表则提示创建
                    printf("当前无链表，请创建。\n");
                }
                else
                {   //链表存在则打印
                     printList(head);
                }
                break;
            case 3: //查询链表中指定节点内的数据
                if(head == NULL)
                {
                    printf("当前无链表，请创建。\n");
                }
                else
                {
                    int position;
                    printf("请输入要查询的节点: ");
                    scanf("%d",&position);
                    printf("查询结果: %d\n",getValue(head, position));
                }
                break;
            case 4:    //查询链表中指定节点的下一个节点内的数据
                if(head == NULL)
                {
                    printf("查询失败，当前无链表。\n");
                }
                else
                {
                    int position;
                    printf("请输入节点位置: ");
                    scanf("%d",&position);
                    printf("查询结果: %d",printNext(head, position));
                    
                }
                break;
            case 5:    //查询与数据匹配的元素的节点
                if(head == NULL)
                {
                    printf("当前无链表，请创建。\n");
                }
                else
                {
                    int elem;
                    printf("请输入要匹配的数据: ");
                    scanf("%d",&elem);
                    if(findElemAt(head,elem)==0)
                    {
                        printf("未找到匹配的数据。\n");
                    }
                    else
                    {
                        printf("匹配的数据在第 %d 节点。\n",findElemAt(head,elem));
                    }
                }
                                break;
            case 6:    //向链表中插入节点
                printf("请输入要插入的数据和节点位置: \n");
                scanf("%d %d", &elem, &position);
                if(head ==NULL )
                {   //无链表则提示创建
                    printf("当前无链表，请创建。\n");
                }
                else
                {   //插入节点并打印
                    insertNode(head,elem,position);
                    printf("插入成功，当前链表为:");
                    printList(head);
                }
                break;
            case 7:  //向链表添加数据
                if(head ==NULL )
                {   //无链表则提示创建
                    printf("当前无链表，请创建。\n");
                }
                else
                {   //插入节点并打印
                    printf("请输入要插入的元素: ");
                    scanf("%d",&elem);
                    addNode(head,elem);
                    printf("添加成功，当前链表为:");
                    printList(head);
                }
                break;
            case 8:    //删除链表中的数据
                if(head ==NULL )
                {   //无链表则提示创建
                    printf("当前无链表，请创建。\n");
                }
                else
                {   //删除节点
                    printf("输入你要删除的节点内的元素: \n");
                    scanf("%d",&elem);
                    deleteNode(head,elem);
                    printf("删除成功，当前链表为:" );
                    printList(head);
                }
                break;
            case 9:  //返回当前链表长度
                if(printLen(head)==0)
                {
                    printf("当前链表不存在，请先创建。\n");
                }
                else
                {
                    printf("当前链表长度: %d",printLen(head));
                }
                break;
            case 10: //设置指定节点内数据
                if(head == NULL)
                {
                    printf("当前无链表，请创建。\n");
                }
                else
                {
                    int position,elem;
                    printf("请输入要设置的节点和数据: ");
                    scanf("%d %d",&position,&elem);
                    setValue(head,position,elem);
                    printf("设置成功，当前链表为: ");
                    printList(head);
                }
                                break;
            case 11:  //逆置链表
                if(head ==NULL )
                {   //无链表则提示创建
                    printf("当前无链表，请创建。\n");
                }
                else
                {   //逆置链表并打印
                    node *pre = reverseList(head);
                    printf("逆置成功，当前链表为:");
                    printList(pre);
                }
                break;
            case 12: //销毁链表
                if(head == NULL)
                {
                    printf("销毁失败，当前无链表\n");
                }
                else
                {
                    destroyList(head);
                    printf("销毁成功\n");
                    head =NULL; //去掉此行才是真的销毁链表
                }
                break;
            case 0:    //退出
                printf("程序已结束。\n");
                return FINISHED;
                break;
            default:
                printf("无该选项，请重新选择（1~12，输入 0 退出）\n");
                break;
        }
    }
    return 0;
}

//创建链表
node *create()
{
    node *head, *current, *p;
    int data;
    head = (node *)malloc(sizeof(node));
    p = head;
    printf("请输入整数, 输入 -1 结束:\n");
    scanf("%d",&data);
    
    if (data != -1)
    {
        p->data = data;
    }
    else
    {
        head->next = NULL; //只有头结点的情况
        return head;
    }
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            printf("输入结束\n");
            break;
        }
        current = (node *)malloc(sizeof(node));
        current->data = data;
        p->next = current;
        p = p->next;
    }
    p->next = NULL;
    return head;
}

//末尾添加节点
node *addNode(node *head, int elem)
{
    node *current, *p;
    current = head;
    while (current->next != NULL)
    {
        //寻找末尾节点
        current = current->next;
    }
    p = (node *)malloc(sizeof(node)); //申请空间
    p->data = elem;
    p->next = current->next;
    current->next = p;
    return head;
}

//插入节点到指定位置之后
node *insertNode(node *head,int elem,int position)
{
    node *current, *p;
    int i = position - 1;
    current = head;
    
    while (i > 0 && current->next != NULL)
    {
        //在合法范围内插入节点
        current = current->next;
        i--;
    }
    if (i > 0) //节点数小于输入的位置position
    {
        printf("位置错误！\n");
        return head;
    }
    p = (node *)malloc(sizeof(node)); //申请空间
    p->data = elem;
    p->next = current->next;
    current->next = p;
    
    return head;
}

//删除节点
node *deleteNode(node *head,int elem)
{
    node *p = head;
    node *temp;
    int flag = 0; //记录便表中elem的个数
    while (1)
    {
        if (head->data == elem) //删除头结点的情况
        {
            flag++;
            head = head->next;
            free(p);
            p = head;
        }
        else
        {
            break;
        }
    }
    while (p->next != NULL)
    {
        if (p->next->data == elem )
        {
            flag++;
            temp = p->next;
            if (p->next->next != NULL)
            {
                p->next = p->next->next;
                free(temp);
                temp = NULL;
            }
            else //最后一个结点
            {
                free(temp);
                temp =NULL;
                p->next = NULL;
                break;
            }
        }
        else //没有删除结点时，查询下一个结点
        {
            p = p->next;
        }
    }
    printf("%d number '%d' was found and deleted.\n", flag, elem);
    return head;
}


//逆置链表
node *reverseList(node *head)
{
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node *pre = NULL;
    node *next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

//打印链表
void printList(node *head)
{
    node *p = head;
    if (p == NULL)
    {
        printf("当前无链表，请创建!\n");
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//打印链表长度
int printLen(node *head)
{
    int i = 0;
    node *p;
    p = head;
    if(p == NULL)
    {
        return ERROR;
    }
    else
    {
        while(p!= NULL)
        {
            i += 1;
            p = p->next;
        }
        return i;
    }
}


//获取下一个节点
int printNext(node *head,int position)
{
    int i,elem = 0;
    node *p= head;
    for(i = 0;i<position;i++)
    {
        p = p->next;  //指向下一个节点
        
    }
    elem = p->data; //指向节点内数据
    return elem; //返回数据
}


//设置指定节点内数据
int setValue(node *head,int position,int elem)
{
    int i;
    node *p = head;
    for(i = 0;i<position-1;i++)
    {
        p=p->next;
    }
    return p->data=elem;
}


//获取指定节点内数据
int getValue(node *head,int position)
{
    int i;
    node *p=head;
    for(i = 0;i<position-1;i++)
    {
        p=p->next;
    }
    return p->data;
}

//查询链表中与数据匹配的节点
int findElemAt(node *head,int elem)
{
    node *p=head;
    int i = 1;
    do
    {
        if(p->data == elem)
        {
            break;
        }
        else
        {
            if(p->next!=NULL)
            {
                p=p->next;
                i += 1;
            }
        }
    }while(p->next!=NULL);
    if(p->next ==NULL && p->data == elem)
    {
         i += 1;
    }
    else if(p->next == NULL && p->data != elem)
    {
        i = 0;
    }
    return i;
}

//销毁链表
void destroyList(node* head)
{
    node* temp = head->next;
    do {
        if (head != NULL) {
            free(head);
        }
        head = temp;
        if (temp != NULL)
        {
            temp = temp->next;
        }
    }while(head == NULL);
}


