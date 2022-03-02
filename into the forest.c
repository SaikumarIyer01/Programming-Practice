#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int n,m;
int adj[1000][1000],edgesInfo[1000];
int count,minSize=INT_MAX, maxSize=INT_MIN;    
void dfs(int head){
    edgesInfo[head]=1;
    for (int i=0;i<n;i++){
        if(adj[head][i]==1 && edgesInfo[i]==0){
            count++;
            dfs(i);
            
        }
    }
    if(count < minSize)
        minSize=count;
    if(count>maxSize)
        maxSize=count;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x-1][y-1]=1;
    adj[y-1][x-1]=1;}
    int treeCount=0;
    for(int i=0;i<n;i++){
        if(edgesInfo[i]==0){
            count=1;
            dfs(i);
            treeCount++;
        }
    }
    if(treeCount==1)
        minSize=maxSize;
    printf("%d %d %d",maxSize,minSize,treeCount);
    return 0;
}
