#include<stdio.h>
#define MAX 100
#define INF 99999
int graph [MAX][MAX];
int residual [MAX][MAX];
int parent[MAX];
int visited[MAX];
int n;
int bfs(int sourse,int sink){
    int queue[MAX];
    int froent = 0,rear = 0;
    int u,v;
    for (int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    queue[rear++]=source;
    visited[source]=1;
    while(froent<rear){
        u=queue[froent++];
        for(v=0;v<n;v++){
            if(!visited[v] && residual[u][v]>0){
                visited[v]=1;
                parent[v]=u;
                if(v==sink){
                    return 1;
                }
                queue[rear++]=v;
            }
        }
    }
    return 0;
}