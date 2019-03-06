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
const int N=1e7;
char a[N],b[N];
int k=1,ans,d,m,n,flag=0;
struct Node
{
	int num;
	int l,r;
	
};
Node node[10000];
void travel(int Root){
	
	if(node[Root].l!=0&&!flag){
		travel(node[Root].l);
	}
	if(node[Root].num==m&&!flag){
		flag=1;
		cout<<k<<endl;
	}
//	cout<<k<<' '<<node[Root].l<<' '<<Root<<endl;
	k++;
	if(node[Root].r!=0&&!flag){
		travel(node[Root].r);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x,l,r; 
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&l,&r);
		node[i].l=l;
		node[i].r=r;
		node[i].num=x;
	//	cout<<node[i].l<<endl;
	}
	travel(1);
	return 0;
}
