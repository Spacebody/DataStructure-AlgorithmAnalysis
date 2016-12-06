//
//Binary search tree 
//
//Test example "35(17(15, 18(, 22)),60(51, 88(, 93)))"
//
//By Spacebody
//
//
//

#ifndef _BinarySearchTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinarySearchTree *Tree;
typedef int ElemType;

//funcions about bianry search tree
Tree BinarySearchTree(Tree T, int tree[], int length); //create a binary search tree
bool SearchValue(ElemType X, Tree T); //exam whether there is such value on the tree
Tree Find(ElemType X, Tree T); //search the value the same to the given value
Tree Insert(ElemType X, Tree T); //insert value into the tree
Tree FindMin(Tree T); //find the max on the tree
Tree FindMax(Tree T); //find the min on the tree
Tree Delete(ElemType X, Tree T); //delete the value appointed
Tree MakeEmpty(Tree T); //make an empty tree
ElemType Retrieve(Tree T); //retrieve the value according to the address
void InOrder(Tree T); //traverse the tree in inorder

#endif /* BinarySearchTree.h */

struct BinarySearchTree
{
	ElemType elem;
	Tree Left;
	Tree Right;
};

//Driving function
int main(void)
{
	int data[]={35,17,18,15,22,60,51,88,93};
	int length = sizeof(data)/sizeof(data[0]);
	Tree T = NULL;
	T = MakeEmpty(T);
	T = BinarySearchTree(T, data, length);
	InOrder(T);
    printf("\n");
    printf("%d\n", Retrieve(FindMin(T)));
    printf("%d\n", Retrieve(FindMax(T)));
    printf("%p\n", Find(17, T)); //use %p to print out the address
    T = Delete(60, T);
    InOrder(T);
    printf("\n");
    if(SearchValue(88, T))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
	return 0;
}


Tree MakeEmpty(Tree T)
{
	if(T)
	{
		MakeEmpty(T->Left); //make the left child empty
		MakeEmpty(T->Right);
		free(T); //free the root
	}
	return NULL;
}

Tree BinarySearchTree(Tree T, int tree[], int length)
{  
    int i;        
    for(i = 0; i < length; i++)
    {  
        T = Insert(tree[i], T); //for elements in the array, insert each of them into the tree
    }  
    return T;  
}  

void InOrder(Tree T)
{    
    if(T)
    {
        InOrder(T->Left); 
        printf("%d\t",T->elem);
        InOrder(T->Right);
    }
}


Tree Insert(ElemType X, Tree T)
{
    if(T == NULL)
    {  //if no such value on the tree, create a node
       	T = (Tree)malloc(sizeof(struct BinarySearchTree));  
        if(T == NULL)
        {
        	printf("Out of Space!\n");
        }
        else
        {
        	T->elem = X;  
        	T->Left = T->Right = NULL;  
    	}
	}  
    else if(X < T->elem)
    {   //if the given value is smaller than the node, turn to its left child
        T->Left = Insert(X, T->Left); 
    } 
    else if(X > T->elem)
    {  //if the given value is larger than the node, turn to its right child
        T->Right = Insert(X, T->Right);
    }  
    return T;  
}  

bool SearchValue(ElemType X, Tree T)
{   
     if(T == NULL)
    { //if not found, return false
        return false;
    }
    if(X < T->elem)
    { //if it is smaller than the node, turn to left
        return SearchValue(X, T->Left);
    }
    else if(X > T->elem)
    {  //if it is larger than the node, turn to right
        return SearchValue(X, T->Right);
    }
    else
    {  //otherwise, wo found it and return true
        return true;
    }

} 

Tree Find(ElemType X, Tree T)
{   //like the funciton before, but return the node rather than true or false
    if(T == NULL)
    {
        return NULL;
    }
    if(X < T->elem)
    {
        return Find(X, T->Left);
    }
    else if(X > T->elem)
    {
        return Find(X, T->Right);
    }
    else
    {
        return T;
    }

}

Tree FindMin(Tree T)
{   //just go for left until we fonud the value
     if(T == NULL)
     {
        return NULL;
     }
     else if(T->Left == NULL)
     {
        return T;
     }
     else
     {
        return FindMin(T->Left);
     }
}

Tree FindMax(Tree T)
{  //go right unless we fonud it
     if(T == NULL)
     {
        return NULL;
     }
     else if(T->Right == NULL)
     {
        return T;
     }
     else
     {
        return FindMax(T->Right);
     }
}

Tree Delete(ElemType X, Tree T)
{
    Tree Tmp;
    if( T == NULL)
    {   //no such value we do nothing and return error
        printf("Element Not Found!\n");
    }
    else if(X < T->elem)
    {   //go left if smaller than node 
        T->Left = Delete(X, T->Left);
    }
    else if(X > T->elem)
    {   //go right uf larger than node 
        T->Right = Delete(X, T->Right);
    }
    else if(T->Left && T->Right)
    {  //if has children
        Tmp = FindMin(T->Right); //assign the min on the right child to temp variable
        T->elem = Tmp->elem; //assign the temp value to the node we want to delete
        T->Right = Delete(T->elem, T->Right); //assign the right child to the parent node
    }
    else
    {   //if only has one child
        Tmp = T;
        if(T->Left == NULL)
        {
            T = T->Right; //no left child, go to right
        }
        else if(T->Right == NULL)
        {
            T = T->Left; //no right child, go to left
        }
        free(Tmp); //free the node to delete
    }
    return T;
}

ElemType Retrieve(Tree T)
{
    return T->elem;  //return the value of the given address
}







