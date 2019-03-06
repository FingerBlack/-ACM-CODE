#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
const double pi=acos(-1.0);
#define local
const double Exp=1e-5;
const int N=50001;
//int l,n,m;
int a[N];
int l,n,m;
int judge(int x){
	int num=0;
	int dis=0;	
	for(int i=1;i<=n;i++){
		if(a[i]-dis<x){
			num++;
		}else{
			dis=a[i];
		}
	}
	if(l-dis<x){
		num++;
	}
	return num<=m;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ll=0,r=l;
	int mid;
	while(ll+1<r){
		mid=(ll+r)/2;
		if(judge(mid)){
			ll=mid;
		}else{
			r=mid;
		}
		//cout<<ll<<" "<<r<<endl;
	}
	//cout<<rr<<" "<<mid<<" "<<l2<<endl;
	printf("%d\n",ll);
	return 0;
}
//l1=r*a;
//l*l=r^2+r^2-2r^2cosa;
//r-1/2*r^2*sin(a)/l2;