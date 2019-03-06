#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
//#define local
const int N=100001;
int f[N];
int n,m,k,x,l,r,y;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d",&x);
	l=x;
	y=x;
	for(int i=0;i<n-2;i++){
		scanf("%d",&x);
		f[i]=x-y-1;
		y=x;
	}
	scanf("%d",&x);
	r=x;
	f[n-2]=x-y-1;
	int sum=r-l+1; 
	sort(f,f+n-1,cmp);
	for(int i=0;i<k-1;i++){
		sum-=f[i];
	}
	cout<<sum<<endl;
	return 0;
}
