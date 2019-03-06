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
char a[N];
int k=0,ans,d,b[N]={0},n;
struct node
{
	char c;
	node *left,*right;
	node(){
		left=NULL;
		right=NULL;
	}
};
void find(int k){
	if(k>=pow(2,d-1)&&k<pow(2,d)){
		ans=k;
		return;
	}
	if(b[k]){
		b[k]=0;
		find(2*k+1);
	}else{
		b[k]=1;
		find(2*k);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&d,&n);
	for(int i=0;i<n;i++)
		find(1);
	cout<<ans<<endl;
	return 0;
}
