#include <vector>
#include <iostream>
#include<stack>
#define M 0
#define N 0
#define INT_MAX 1e9
using namespace std;

typedef struct node
{
	vector<vector<int>> matrix;      //邻接矩阵 
	int n;                 //顶点数 
	int e;                 //边数 
}MGraph; 

struct cod{
	int x;
	int y;
};

void DijkstraPath(MGraph g,int *dist,int *path,int v0)   //v0表示源顶点 
{
	int i,j,k;
	bool *visited=(bool *)malloc(sizeof(bool)*g.n);
	for(i=0;i<g.n;i++)     //初始化 
	{
		if(g.matrix[v0][i]>0&&i!=v0)
		{
			dist[i]=g.matrix[v0][i];
			path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点 
		}
		else
		{
			dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大 
			path[i]=-1;
		}
		visited[i]=false;
		path[v0]=v0;
		dist[v0]=0;
	}
	visited[v0]=true;
	for(i=1;i<g.n;i++)     //循环扩展n-1次 
	{
		int min=INT_MAX;
		int u;
		for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点 
		{
			if(visited[j]==false&&dist[j]<min)
			{
				min=dist[j];
				u=j;        
			}
		} 
		visited[u]=true;
		for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值 
		{
			if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
			{
				dist[k]=min+g.matrix[u][k];
				path[k]=u; 
			}
		}        
	}    
}

void showPath(int *path,int v,int v0)   //打印最短路径上的各个顶点 
{
	stack<int> s;
	int u=v;
	while(v!=v0)
	{
		s.push(v);
		v=path[v];
	}
	s.push(v);
	while(!s.empty())
	{
		//cout<<s.top()<<" ";
		s.pop();
	}
} 

int countcost(vector<cod>& coordinates, int i, int j)
{
	return min(abs(coordinates[i].x - coordinates[j].x), abs(coordinates[i].y - coordinates[j].y));
}

int main(int argc, char *argv[])
{
	//int num;
	int n,e;     //表示输入的顶点数和边数 
	cin>>n;
	vector<cod> coooor;
	for (int i=0; i<n; ++i)
	{
		cod tmp;
		cin>>tmp.x>>tmp.y;
		coooor.push_back(tmp);
	}

	vector<vector<int>> edges(n, vector<int>(n, 0));
	for (int i=0; i<n; ++i)
	{
		for (int j=i; j<n; ++j)
		{
			edges[i][j] = countcost(coooor, i, j);
		}
	}

	int i,j;
	int s,t,w;      //表示存在一条边s->t,权值为w
	MGraph g;
	int v0;
	int *dist=(int *)malloc(sizeof(int)*n);
	int *path=(int *)malloc(sizeof(int)*n);
	
	g.matrix = edges;
	edges.clear();
	
	//for(i=0;i<N;i++)
	//	for(j=0;j<M;j++)
	//		g.matrix[i][j]=0;
	g.n=n;
	g.e=n*(n-1);

	//for (int ii = 0; ii<n; ++ii)
	//{
	//	for (int jj = 0; jj<n; ++jj)
	//	{
	//		g.matrix[ii][jj] = edges[ii][jj];
	//	}
	//}
 
	v0 = 0;
	DijkstraPath(g,dist,path,v0);

	int Cost = 0;
	for(i=0;i<n;i++)
	{
		if(i!=v0)
		{
			showPath(path,i,v0);
			Cost += dist[i];
			//cout<<dist[i]<<endl;
		}
	}
	cout<<Cost-1<<endl;

	
	return 0;
}