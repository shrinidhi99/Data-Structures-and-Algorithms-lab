#include<stdio.h>
#include<stdlib.h>
#define inf 1e9

struct edges
{
	int from;
	int to;
	int weight;
};

struct edges tree[1000];
int adj[100][100],dis[1001];

void bellman(int s,int m,int n)
{
	dis[s]=0;// source vertex distance set to zero and all other distances are now counted wrt this 
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<=m;j++)
		{
			int u=tree[j].from;
			int v=tree[j].to;
			int w=tree[j].weight;
			if(dis[u]+w<dis[v])
				dis[v]=dis[u]+w;
			else if(dis[v]+w<dis[u])
				dis[u]=dis[v]+w;
		}
	}
	return;
}

int main()
{
	int n,m,i,s;
	printf("Enter the num of nodes and edges \n");
	scanf("%d%d",&n,&m);
	printf("Enter the edges with their weights: \n");
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tree[i].from,&tree[i].to,&tree[i].weight);
	}
	printf("Enter the source vertex\n");
	scanf("%d",&s);
	for(i=1;i<=n;i++) 
	dis[i]=inf;
	bellman(s,m,n);
	for(i=1;i<=n;i++) 
		printf("%d - %d\n",i,dis[i]);
	return 0;
}
/*

void bellman(int s ,int m,int n)
{
	dis[s] = 0;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<=m;j++)
		{
			int u = tree[j].from;
			int v = tree[j].to;
			int w = tree[j].weight;
			if(dis[u] + w < dis[v])
			dis[v]  = dis[u] + w;// relaxation 
			else if(dis[v] + w < dis[u])
			dis[u] = dis[v] + w;// relaxation
		}
	}
	return;
}
*/
