//
//Binary tree to recover the tree (A(B(E(K,L),F),C(G),D(H(M),I,J)))
//Call the functions in recursion
//By Spacebody
//
//



#ifndef _BinaryTree_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
typedef char ElemType;

#endif /* BinaryTree.h */

struct TreeNode
{
	ElemType elem;
	Tree Left;
	Tree Right;
};

Tree CreateTree(Tree T); //create the tree
void PreOrder(Tree T); //traversal in preorder
void InOrder(Tree T); //traversal in inorder
void PostOrder(Tree T); //traversal in postorder
int SumLeaf(Tree T); //count the sum of leaves
int Depth(Tree T); //count the depth of the binary tree

int main(void)
{
	Tree T;
	T = CreateTree(T);
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T);
	printf("\n");
	printf("%d\n", SumLeaf(T));
	printf("%d\n", Depth(T));
	return 0;
}


Tree CreateTree(Tree T)
{
	ElemType elem;
    elem = getchar(); //get the string "ABEK#L##F##CG##DHM##I#J####"
    if(elem == '#')
    {  //if the character is '#', the end the pointer
    	T = NULL; 
   	}
    else
    {
    	if(!(T=(Tree)malloc(sizeof(struct TreeNode))))
    	{ 
   			printf("Error!");
   			exit(0);
   		}
   		T->elem = elem;
   		T->Left = CreateTree(T->Left);  //Call the function in recursion
   		T->Right = CreateTree(T->Right); 
   	}
   	return T;
}


void PreOrder(Tree T)
{   
  	if(T)
  	{
   		printf("%c\t",T->elem);
   		PreOrder(T->Left); //Call the function in recursion
   		PreOrder(T->Right);
  	}
}

void InOrder(Tree T)
{    
   	if(T)
   	{
   		InOrder(T->Left); //Call the function in recursion
   		printf("%c\t",T->elem);
   		InOrder(T->Right);
   }
}

void PostOrder(Tree T)
{   
    if(T)
    { 
    	PostOrder(T->Left); //Call the function in recursion
    	PostOrder(T->Right);
    	printf("%c\t",T->elem);
    }
}

int SumLeaf(Tree T)
{                         
  	int Sum = 0, Left, Right;
  	if(T)
  	{
   		if((!T->Left) && (!T->Right))
   		{
   			Sum++;
   		}
   		Left = SumLeaf(T->Left);  //count the left leaves
   		Sum += Left;
   		Right = SumLeaf(T->Right);  //count the right leaves
   		Sum += Right;
  	}
	return Sum;
} 



int Depth(Tree T)  
{
	int depth = 0, DepthLeft, DepthRight;
	if(!T)
	{
		depth = 0;
	}
  	else
  	{
   		DepthLeft = Depth(T->Left); //conut the left depth 
   		DepthRight = Depth(T->Right); //count the right depth
   		depth = 1 + (DepthLeft > DepthRight ? DepthLeft : DepthRight); //choose the maximum
  	}
	return depth;
}
