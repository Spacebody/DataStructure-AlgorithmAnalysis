//
//double circular linkedlist
//
// by Spacebody 

#ifndef _DlinkedList_h_

#include <stdio.h>
#include <stdlib.h>
typedef struct DlinkedList List;
typedef int ElemType;

List *Create(void); //create empty list
void InsertLast(List *head, ElemType X); //insert element into the last of list
void InsertBefore(List *head, ElemType X, int key); //insert the element into the key before 
int Search(List *head, int key); //search the key we want 
void Remove(List *head);//remove the last element in the list
void Print(List *head);//print out the list

#endif /* DlinkedList.h */

struct DlinkedList
{	
	ElemType elem;
	struct DlinkedList *prior;
	struct DlinkedList *next;
};

int main(void)
{
	List *L;
	L = Create();
	InsertLast(L, 10);
	InsertLast(L, 20);
	InsertLast(L,2000);
	InsertBefore(L, 89, 20);
	InsertBefore(L, 1000,10);
	// InsertBefore(L, 30, 500);
	Print(L);
	printf("\n");
	Remove(L);
	Remove(L);
	Print(L);
	printf("\n");
	printf("The number of the node with value 20 is %d.\n", Search(L,20));
	printf("The number of the node with value 300 is %d.\n", Search(L, 300));
	return 0;
}


List *Create(void)
{
	List *head; //head node without any value assigned 
	head = (List *)malloc(sizeof(List));
	head->next = head;
	head->prior = head;
	return head;
}

void InsertLast(List *head, ElemType X)
{
	List *p,*newNode;
	p = head;
	while(p->next != head)
	{	
		p = p->next;
	}
	newNode =(List *)malloc(sizeof(List));
	newNode->elem = X;
	newNode->prior = p;
	newNode->next = head;
	p->next = newNode;
	head->prior = newNode;
}

void InsertBefore(List *head, ElemType X, int key)
{
	List *p,*newNode;
	p = head->next;
	while(p->elem != key && p != head)
	{
		p = p->next;
	}
	if(p->elem != key && p == head)
	{
		printf("There is no such value in the list.\n");
		exit(0);
	}
	else
	{
		newNode = (List *)malloc(sizeof(List));
		newNode->elem = X;
		newNode->next = p;
		newNode->prior = p->prior;
		p->prior->next = newNode;
		p->prior = newNode;
	}
}

int Search(List *head, int key)
{
	List *p;
	int i = 1;
	p = head->next;
	while(p->elem != key && p != head)
	{
		p = p->next;
		i++;	
	}
	if(p->elem != key && p == head)
	{
		printf("There is no such value in the list.\n");
		exit(0);
	}
	else
	{
		return i;
	}
}

void Remove(List *head)
{
	List *p;
	p = head->next;
	if(p == head)
	{
		printf("Empty List!\n");
		exit(0);
	}
	else
	{
		while(p->next != head)
		{
			p = p->next;
		}
		p->prior->next = head;
	 	head->prior = p->prior;
	 	free(p);
	}
	 
}


void Print(List *head)
{
	List *p;
	p = head->next;
	if(p == head)
	{
		printf("Empty List!\n");
		exit(0);
	}
	else
	{
		while(p != head)
		{
			printf("%d\n", p->elem);
			p = p->next;
		} 
		
	}
}



