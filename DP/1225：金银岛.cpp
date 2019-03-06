#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace  std;
#define local
const int N=101;
int f[N];
int a[N];
struct node
{
	int w,v;
	bool operator<(const node &n)const{
		return (double)v/w>(double)n.v/n.w;
	}
};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		int w,k;
		cin>>w>>k;
		node nn[N];
		for(int i=0;i<k;i++){
			scanf("%d%d",&nn[i].w,&nn[i].v);
		}
		sort(nn,nn+k);
		double v=0;
		for(int i=0;i<k;i++){
			if(w>=nn[i].w){
				w-=nn[i].w;
				v+=nn[i].v;
			}else{
				v+=(double)w*(double)nn[i].v/(double)nn[i].w;
				w-=w;
			}
			if(!w){
				break;
			}
		}
		printf("%.2lf\n",v );
	}
	return 0;
}
