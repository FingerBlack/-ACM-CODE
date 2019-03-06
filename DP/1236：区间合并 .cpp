#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=1e5+10;
struct node
{
	int l,r;
	bool operator<(const node &n)const{
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
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&f[i].l,&f[i].r);
	}
	sort(f,f+n);
	int flag=0;
	int l=f[0].l,r=f[0].r;

	for(int i=1;i<n;i++){
		if(f[i].l>r){
			flag=1;
		}else{
			if(f[i].r>r)
				r=f[i].r;
		}
	}
	if(flag){
		cout<<"no"<<endl;
	}else
	cout<<l<<" "<<r<<endl;
	return 0;
}
