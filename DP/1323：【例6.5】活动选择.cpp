#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace  std;
#define local
const int N=10001;
struct nn
{
	int l,r;
	bool operator < (const nn &n)const{
		return l<n.l;
	}	
}f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	scanf("%d",&n);
	//ios::sync_with_stdio(false);
	for(int i=0;i<n;i++){
		scanf("%d%d",&f[i].l,&f[i].r);
	}
	sort(f,f+n);
	int r=f[0].r;
	int count=1;
	for(int i=1;i<n;i++){
		if(f[i].r<r){
			r=f[i].r;
		}
		if(f[i].l>=r){
			count++;
			r=f[i].r;
		}
	}
	cout<<count<<endl;
	return 0;
}
