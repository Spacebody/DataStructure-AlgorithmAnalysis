
//  
//  PolynomialAddition.c
//  By Spacebody 

#ifndef _PolynomialAddition_h

#include <stdio.h>
#include <stdlib.h>

//使用结构体构建多项式的每一项
typedef struct Polynomial term;

term *Create(void); //创建多项式
int FindMaxExp(term *headA,term *headB); //寻找最高次幂
term *PolyAdd(term *headA,term *headB);//多项式相加
term *PolySub(term *headA,term *headB);//多项式相减
term *PolyMult(term *headA,term *headB); //多项式乘法
term *PolyDiff(term *head); //多项式求导
term *AddItem(term *head, int coeff, int exp);//插入项
term *SortItem(term *head); //多项式冒泡排序
term *DeleteZero(term *head);//删除系数为 0 的多项式
void PrintList(term *head);//打印多项式

#endif /* PolynomialAddition.h */

struct Polynomial
{
    int coeff; //系数
    int exp; //指数
    struct Polynomial *next; //下一个节点位置
};

int main(void)
{
    term *headA,*headB,*Poly;
    headA = headB = Poly = NULL;
    printf("请输入多项式 A 的各项的次数和系数（使用“ ，”隔开）,输入 “0,0” 结束:\n");
    headA = Create(); //创建链表
    PrintList(headA); //打印结果
    printf("请输入多项式 B 的各项的次数和系数（使用“ ，”隔开）,输入 “0,0” 结束:\n");
    headB = Create();
    PrintList(headB);
    
    printf("最高次幂是 %d\n\n",FindMaxExp(headA,headB)); //寻找最高次幂
    
    Poly = PolyAdd(headA,headB); //多项式加法
    Poly = DeleteZero(Poly);//删除系数为 0 的多项式
    Poly = SortItem(Poly); //降幂排序
    printf("求和后:\n");
    PrintList(Poly);//输出结果

    Poly = PolySub(headA,headB);//多项式相减
    Poly = DeleteZero(Poly);//删除系数为 0 的多项式
    Poly = SortItem(Poly); //降幂排序
    printf("作差后:\n");
    PrintList(Poly);//输出结果

    Poly = PolyMult(headA,headB); //多项式乘法
    Poly = DeleteZero(Poly);//删除系数为 0 的多项式
    printf("相乘后:\n");
    PrintList(Poly);//输出结果
    
    Poly = PolyDiff(headA); //多项式求导
    Poly = DeleteZero(Poly);//删除系数为 0 的多项式
    Poly = SortItem(Poly); //降幂排序
    PrintList(Poly);//输出结果
    
    return 0;
}

//创建链表
term *Create()
{
    int coeff,exp;
    term *head, *current, *p;
    head = (term *)malloc(sizeof(term));
    p = head;
    scanf("%d,%d",&exp,&coeff);
    if (coeff != 0)
    {
        p->coeff = coeff;
        p->exp = exp;
    }
    else
    {
        head->next = NULL; //只有头结点的情况
        return head;
    }
    while (1)
    {
        scanf("%d,%d",&exp,&coeff);
        if (coeff == 0 )
        {
            printf("输入结束\n");
            break;
        }
        current = (term *)malloc(sizeof(term));
        current->coeff = coeff;
        current->exp = exp;
        p->next = current;
        p = p->next;
    }
    p->next = NULL;
    return head;
}

//打印链表
void PrintList(term *head)
{
    term *p = head;
    if (p == NULL)
    {
        printf("当前无数据，请创建!\n");
    }
    else
    {
        printf("当前多项式为<次数，系数>:\n");
    }
    while (p != NULL)
    {
        printf("<%d, %d>\n", p->exp,p->coeff);
        p = p->next;
    }
    printf("\n");
}

//寻找多项式次数
int FindMaxExp(term *headA,term *headB)
{
    term *p;
    p = headA;
    int Max = p->exp;
    p = p->next;
    while(p != NULL)
    {
        if(p->exp > Max)
        {
            Max = p->exp;
        }
        p = p->next;
    }
    
    p = headB;
    while(p!=NULL)
    {
        if(p->exp >= Max )
        {
            Max = p->exp;
        }
        p = p->next;
    }
    
    return Max;
}

//多项式加法
term *PolyAdd(term *headA, term *headB)
{
    term *Poly,*current,*p,*q;
    
    Poly = (term *)malloc(sizeof(term));
    p = Poly;
    p->coeff = headA->coeff;
    p->exp = headA->exp;
    q = headA->next;
    while(q!=NULL)
    {
        current = (term *)malloc(sizeof(term));
        current->coeff = q->coeff;
        current->exp = q->exp;
        p->next = current;
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    //合并同类项
    q = headB;
    while(q!=NULL)
    {
        p=Poly;
        do
        {
            if(p->exp == q->exp)
            {
                p->coeff += q->coeff;
                break;
            }
            p=p->next; //指向下一个节点
        }while(p!=NULL);
        q=q->next;
    }
    
    q = headB;
    while (q!=NULL)
    {
        p=Poly;
        do
        {
            if(p->exp == q->exp)
            {
                break;
            }
            if(p->exp!= q->exp && p->next == NULL)
            {
                Poly = AddItem(Poly, q->coeff,q->exp); //添加多项式 Poly 中不存在的项
            }
            p=p->next;
        }while(p!=NULL);
        q=q->next;
    }
    return Poly;
}



//多项式减法
term *PolySub(term *headA, term *headB)
{
    term *Poly,*current,*p,*q;
    
    Poly = (term *)malloc(sizeof(term));
    p = Poly;
    p->coeff = headA->coeff;
    p->exp = headA->exp;
    q = headA->next;
    while(q!=NULL)
    {
        current = (term *)malloc(sizeof(term));
        current->coeff = q->coeff;
        current->exp = q->exp;
        p->next = current;
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    //合并同类项
    q = headB;
    while(q!=NULL)
    {
        p=Poly;
        do
        {
            if(p->exp == q->exp)
            {
                p->coeff -= q->coeff;
                break;
            }
            p=p->next; //指向下一个节点
        }while(p!=NULL);
        q=q->next;
    }
    
    q = headB;
    while (q!=NULL)
    {
        p=Poly;
        do
        {
            if(p->exp == q->exp)
            {
                break;
            }
            if(p->exp!= q->exp && p->next == NULL)
            {
                Poly = AddItem(Poly, -q->coeff,q->exp); //添加多项式 Poly 中不存在的项
            }
            p=p->next;
        }while(p!=NULL);
        q=q->next;
    }
    return Poly;
}

//多项式相乘
term *PolyMult(term *headA,term *headB)
{
    term *Poly,*p,*q,*PolyHead,*tmp;
    p = headA;
    PolyHead = Poly = (term *)malloc(sizeof(term));
    while(p!=NULL)
    {
        q = headB;
        while(q!=NULL)
        {
            Poly->coeff = p->coeff * q->coeff;
            Poly->exp = p->exp + q->exp;
            Poly->next = (term *)malloc(sizeof(term));
            Poly = Poly->next;
            q = q->next;
        }
        p = p->next;
    }
    Poly->next=NULL;
    PolyHead = SortItem(PolyHead); //降幂排序
    p = PolyHead;
    while(p->next->next!=NULL)
    {
        if(p->exp == p->next->exp)
        {
            p->coeff += p->next->coeff;
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            tmp = NULL;
        }
        p = p->next;
    }
    return PolyHead;
}

//多项式求导
term *PolyDiff(term *head)
{
    term *Poly;
    Poly = head;
    while(Poly!=NULL)
    {
        if(Poly->exp == 0 )
        {
            Poly->coeff=0;
        }
        else
        {
            Poly->coeff = Poly->coeff*Poly->exp;
            Poly->exp -= 1;
        }
        Poly = Poly->next;
    }
    return head;
}

//末尾插入不存在的多项式
term *AddItem(term *head, int coeff, int exp)
{
    term *current, *p;
    current = head;
    while (current->next != NULL)
    {
        //寻找末尾节点
        current = current->next;
    }
    p = (term *)malloc(sizeof(term)); //申请空间
    p->coeff = coeff;
    p->exp = exp;
    p->next = current->next;
    current->next = p;
    return head;
}

//删除系数为 0 的项
term *DeleteZero(term *head)
{
    term *p = head;
    term *temp;
    int flag = 0; //记录便表中 0 的个数
    while (1)
    {
        if (head->coeff == 0) //删除头结点的情况
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
        if (p->next->coeff == 0 )
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
    return head;
}


//多项式排序
term *SortItem(term *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    term *p = head->next;
    term *pre= head;
    
    while(pre->next!= NULL)
    {
        while (p)
        {
            if(pre->exp >= p->exp)
            {
                p = p->next;
                continue;
            }
            else
            { //交换节点内值
                int tmpExp,tmpCoeff;
                tmpExp = p->exp;
                tmpCoeff = p->coeff;
                p->exp = pre->exp;
                p->coeff = pre->coeff;
                pre->exp = tmpExp;
                pre->coeff = tmpCoeff;
                p = p->next;
            }
        }
        pre = pre->next;
        p = pre;
    }
    return head;
}


