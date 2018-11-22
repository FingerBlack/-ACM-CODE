#include<iostream>
//#include<vector>
using namespace  std;
#define local;
const int maxn =0xffffff;
int n,m,w,k;
int dis[100000];
struct edge
{
	int f,t,val;
	edge(){

	}
	edge(int a,int b,int c){
		f=a,t=b,val=c;
	}
}edges[10000];
bool Bellman_ford(){
	//设原点为0，目的是为了证明从原点出发；
	//如果大家初始化一样，意味着，从任意一点出发；
	//
	for(int i=0;i<n ;i++){
		dis[i]=maxn;
	}
	dis[0]=-11;
	//init the distance array
	for (int i = 0; i < n-1; ++i)
	{	
		int flag=0;
		for(int j=0;j<k;j++){
			if(dis[edges[j].f]+edges[j].val<dis[edges[j].t]){
				dis[edges[j].t]=dis[edges[j].f]+edges[j].val;
				flag=1;
			}
			/*
			cout<<"case "<<j<<endl;
			for(int s=0;s<k;s++){
				printf("%d %d %d %d\n",edges[s].f,edges[s].t,dis[edges[s].f],dis[edges[s].t]);
			}
			*/
			
		}
		if(!flag){
			break;
		}
		/* code */
	}
	//debug
	/*for(int j=0;j<k;j++){
		printf("%d %d %d %d\n",edges[j].f,edges[j].t,dis[edges[j].f],dis[edges[j].t]);
	}
	*/
	for(int j=0;j<k;j++){
		if(dis[edges[j].f]+edges[j].val<dis[edges[j].t]){
			return true;		
		}
	}
	return false;
	//
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out1","wt+",stdout);
#endif
	int count;
	cin>>count;
	while(count--){
		cin>>n>>m>>w;
		int f,t,val;
		k=0;
		for(int i=0;i<m;i++){
			cin>>f>>t>>val;
			edges[k++]=edge(f-1,t-1,val);
			edges[k++]=edge(t-1,f-1,val);
		}
		for(int i=0;i<w;i++){
			cin>>f>>t>>val;
			edges[k++]=edge(f-1,t-1,-val);
		}
		//一些题的节点不一定是0开头
		//cout<<k<<endl;
		if(Bellman_ford()){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		//Build the map
	}
	return 0;
}
