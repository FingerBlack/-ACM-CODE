#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
typedef long long ll;
const int N=10001;
ll b,p,k;
ll f(ll n){
	if(n==1){
		return b%k; 
	}
	if(n==0){
		return 1;
	}
	ll tem=f(n/2)%k;
	tem=(tem*tem)%k;
	if(n%2){
		return (tem*b)%k;
	}else{
		return tem;
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<" mod "<<k<<"="<<f(p)<<endl;
	return 0;
}
