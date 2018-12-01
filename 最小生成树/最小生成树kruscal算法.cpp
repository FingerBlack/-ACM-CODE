#include<iostream>
#include<algorithm>
using namespace  std;
#define local;
const int maxn=1e5;
const int inf=0x3f3f3f3f;
int n,m;
int f[maxn];

struct edge
{
	int f,t,dis;
	edge(int a,int b, int c){
		f=a;
		t=b;
		dis=c;
	}
	edge(){
	}
	bool operator <(const edge &a)const{
		return dis<a.dis;
	}
}Edge[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int kruscal(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int sum=0;
	for(int i=0;i<m;i++){
		int x=Edge[i].f;
		int y=Edge[i].t;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			sum+=Edge[i].dis;
		}
	}
	
	return sum;
}

int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	while(cin>>n>>m){
		int f,t,val;
		for(int i=0;i<m;i++){
			cin>>f>>t>>val;
			Edge[i]=edge(f,t,val);		
		}
		sort(Edge,Edge+m);
		cout<<kruscal()<<endl;
	}
	return 0;
}
