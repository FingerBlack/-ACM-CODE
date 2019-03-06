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
char s[N];
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
	int t;
	cin>>t;
	b=2011;
	k=10000;
//	int i,k=2011;
	//for(i=2;;i++)
//	{
//		k=k*2011%10000;
//		if(k==2011)
//		{
//			printf("%d",i-1);
//			return 0;
//		}
//	}

	while(t--){
		scanf("%s",s);
		int len =strlen(s);
		p=0;
		for(int i=len-4;i<len;i++){
			if(i>=0)
			p=10*p+s[i]-'0';
		}	
		cout<<f(p)<<endl;
	}
	return 0;
}
