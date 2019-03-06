#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace  std;
#define local
const int N=20001;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int i=0,sum=0;
	for(;i<n;i++){
		if(sum<m){
			sum+=a[i];
		}else{
			break;
		}
	}
	cout<<i<<endl;
	return 0;
}
