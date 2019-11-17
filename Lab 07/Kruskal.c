#include <stdio.h>    
#include<limits.h>
#include<stdlib.h>

int V;
int* parent;
int find(int i) { 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
 
void union1(int i, int j) { 

    int a = find(i); 
    int b = find(j); 
    parent[a] = b; 

} 

void kruskalMST(int cost[][V]) {

    int mincost = 0; 
 
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int edge_count = 0; 
    while (edge_count < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (find(i) != find(j) && cost[i][j] < min) { 
                    min = cost[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
        union1(a, b); 
        printf("Edge %d:(%d, %d) cost:%d \n", 
               edge_count++, a, b, min); 
        mincost += min; 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 

int main() { 

    printf("Enter Vertices: ");
    scanf("%d",&V);

    int graph[V][V];

    for(int i = 0; i < V; i ++)
        for(int j =0; j < V; j++)
            graph[i][j] = INT_MAX;
    
    int i =0;

    while(i < V){

        int node, weight;
        printf("Enter connected node and weight for node %d (Enter \"-1 -1\"  to move onto next node): ", i);
        scanf("%d %d",&node,&weight);

        if(node == -1)
            i++;
        else
            graph[i][node] = weight;

    } 

    parent = (int*)malloc(V * sizeof(int));

    kruskalMST(graph); 
  
    return 0; 
}