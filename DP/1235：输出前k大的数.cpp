#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=1e5+10;
int f[N];
int cmp(int a,int b){
	return a>b;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&f[i]);
	}
	scanf("%d",&k);
	sort(f,f+n,cmp);
	for(int i=0;i<k;i++){
		printf("%d\n",f[i] );
	}
	return 0;
}
