#include<iostream>
using namespace std;
int e[111][111];
int n,m,u,v,l;
const int inf=999999;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			e[i][j]=0;
			else
			e[i][j]=inf;
		}
	}
}
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(e[i][k]<inf&&e[k][j]<inf&&e[i][j]>e[i][k]+e[k][j])
				e[i][j]=e[i][k]+e[k][j];
			}
		}
	}
}
int main()
{
	int i,j;
	cin>>n>>m;
	init();
	//读入边 
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>l;
		e[u][v]=l;
	}
	floyd();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<e[i][j]<<endl;
		}
	}
	return 0;
}

