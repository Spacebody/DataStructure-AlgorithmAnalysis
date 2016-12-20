//
//Dijkstra.c
//
//Use adjacency list to store the relation of vertex
//Ues matrix to represent the graph
//!!! The vertex number is larger than its index by 1 
//
//By Spacebody
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _Dijkstra_h

#define NotAVertex -1   //define the no vertex to be -1
#define NumVertex 7 //define the number of vertex
#define Infinity 65535  //use the maxima of 16-bit integer to define the infinity
typedef int Vertex;
typedef int DistType;
typedef int* List;

struct TableEntry
{
    List Header;  //the adjacency list
    bool Known;   //mark the vertex whether it has been visited
    DistType Dist; //the distance
    Vertex Path;  //the path
};

struct GraphRecord
{
    Vertex V[NumVertex]; // set of vertex
    int VexNum;	 // number of vertex
    int EdgNum;	 // number of edge
    int matrix[NumVertex][NumVertex];  //adjacency matrix
};

typedef struct TableEntry Table[NumVertex];
typedef struct GraphRecord Graph;
typedef struct EdgeRecord Edge;

void InitTable(Vertex Start, Graph *G, Table T, const int matrix[][NumVertex]); //initialize the table
void PrintPath(Vertex V, const Table T, const Graph G); //print the path
void Dijkstra(const Graph G, Table T); //Dijkstra algorithm to reset the table 
void ReadGraph(Graph *G, Table T, const int matrix[][NumVertex]); //read graph for initializing the table
Vertex SmallestUnknownDistanceVertex(const Table T, const Graph G); //find the smallest unknown distance vertex
void Decrease(DistType *OriginalDist, DistType *ShortenDist); //refresh the distance 

#endif  /* Dijkstra.h */


int main(void)
{   //initialize the graph by using matrix
    Graph G;
    Table T;
    //graph, specify initialization which is supported in C99
    int matrix[NumVertex][NumVertex] = {
        [0][1] = 2, [0][3] = 1,
        [1][3] = 3, [1][4] = 10,
        [2][0] = 4, [2][5] = 5,
        [3][2] = 2, [3][4] = 2, [3][5] = 8, [3][6] = 4,
        [4][6] = 6,
        [6][5] = 1
    };
    InitTable(0, &G, T, matrix);
    //print the table and graph
    printf("The graph(number 1 to 7, path diredction is from row to column):\n");
    int i,j;
    for(i = 0; i < NumVertex; i++)
    {
        for(j = 0; j < NumVertex; j++)
        {
            printf("%4d\t", G.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nThe table:\n");
    for(i = 0; i < NumVertex; i++)
    {
        printf("%4d\t", T[i].Known);
        printf("%4d\t", T[i].Dist);
        printf("%4d\t", T[i].Path);
        for( j = 0;j < NumVertex; j++)
        {
            printf("%6d", T[i].Header[j]);
        }
        printf("\n");
    }
    Dijkstra(G, T);
    printf("\n");
    for(i = 0; i < NumVertex; i++)
    {
        printf("%4d\t", T[i].Known);
        printf("%4d\t", T[i].Dist);
        printf("%4d\t", T[i].Path);
        for( j = 0; j < NumVertex; j++)
        {
            printf("%6d", T[i].Header[j]);
        }
        printf("\n");
    }
    int n = 6; //vertex which to go
    printf("\nThe path to %d is ", n);
    PrintPath(n, T, G);
    printf("\n");
    return 0;
}

void InitTable(Vertex Start, Graph *G, Table T, const int matrix[][NumVertex])
{
    int i;
    ReadGraph(G, T, matrix); //read graph
    for(i = 0; i < NumVertex; i++)
    {
        T[i].Known = false; //default to be unknown
        T[i].Dist = Infinity; //default to be infinity
        T[i].Path = NotAVertex; //default to be no vertex
    }
    T[Start].Dist = 0; //set the distance of start vertex to be 0
    T[Start].Path = 0; //set the path to start vertex to be its self
}

void ReadGraph(Graph *G, Table T, const int matrix[][NumVertex])
{
    int i, j, EdgNum = 0;
    G->VexNum = NumVertex; 
    for(i = 0;i < NumVertex; i++)
    {
        G->V[i] = i+1; //for every vertex, use number 1 to 7 to represent it
        T[i].Header = (List)malloc(sizeof(int)*NumVertex); 
        for(j = 0;j < NumVertex; j++)
        {
            G->matrix[i][j] = matrix[i][j]; //read the matrix
            if(G->matrix[i][j] != 0)
            {   //if two vertex has connected, number of edge increase
                EdgNum++;
                T[i].Header[j] = j; //mark two vertex have connection
            }
            else
            {
                T[i].Header[j] = NotAVertex; //if no connection, mark as not a vertex
            }
        }
    }
    G->EdgNum = EdgNum; //assign the value
}

void Dijkstra(const Graph G, Table T)
{
    Vertex V, W; //V is the beginnning vertex, W is the end vertex
    for(; ;)
    {
        V = SmallestUnknownDistanceVertex(T, G); //find the smallest unknown distance vertex then assign to V
        if(V == NotAVertex)
        {
            break; //stop loop if not a vertex
        }
        T[V].Known = true; //mark the vertex visited
        for(W = 0; W < NumVertex; W++)
        {  //for every vertex W adjacent to V
            if(T[V].Header[W] != NotAVertex)
            {
                if(!T[W].Known)
                {
                    if(T[V].Dist + G.matrix[V][W] < T[W].Dist)
                    {   //if the distance is smaller than before, renew it
                        DistType ShortenDist = T[V].Dist +  G.matrix[V][W];
                        Decrease(&T[W].Dist, &ShortenDist);
                        T[W].Path = G.V[V]; //record the path
                    }
                }
            }
        }
    }
}

Vertex SmallestUnknownDistanceVertex(const Table T, const Graph G)
{
    int i, Tmp = NotAVertex;
    DistType dist = Infinity; 
    for(i = 0; i < NumVertex; i++)
    {
        if(T[i].Known == 1)
        {
            continue; //if vertex is ever visited, mark as known
        }
        else
        {
            if(T[i].Dist < dist)
            {
                dist = T[i].Dist; //assign the value
                Tmp = i; //assign the index
            }
        }
    }
    if(Tmp == NotAVertex)
    {
        return NotAVertex; //not found, return not a vertex
    }
    else
    {
        return G.V[Tmp]-1; //if found, return the vertex but need to modified to equal its index in the vertex set
    }
}

void Decrease(DistType *OriginalDist, DistType *ShortenDist)
{
    *OriginalDist = *ShortenDist;
}

void PrintPath(Vertex V, const Table T, const Graph G)
{  //print out the path in recursion
    V--;
    if(T[V].Path == 0)
    {
        printf("%d",G.V[V]);
        return;
    }
    if(T[V].Path != NotAVertex)
    {
        PrintPath(T[V].Path, T, G);
        printf(" to  ");
    }
    printf("%d", G.V[V]);
}

