#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
#define local
const int N=10001;
int f[N],w[N],c[N],sum[N]={0};
struct node
{
	int k,num;
	node(int a,int b){
		k=a;
		num=b;
	}
	bool operator <(const node&n)const{
		return k<n.k;
	}
};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&f[i]);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);

	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		sum[i]=sum[i-1]+c[i];
	}
	scanf("%d",&t);
	int maxn=0;
	for(int i=0;i<n;i++){
		int ans=0;
		int T=t;
		T-=sum[i-1];
		if(T<=0){
			break;
		}
		priority_queue< node > qq;
		for(int j=0;j<i;j++){
			qq.push(node(f[i],i));
		}
		while(T){
			int kk=qq.top().k;
	 		qq.top()
			T--;
		}
		qq.push()
		
		if(maxn>0){

		}
	}
	return 0;
}
