#include<iostream>
#include<string>
#include<string.h>
using namespace  std;
#define local
const int N=1e7;
int mm[N];
int f(int n){
	if(n==1||n==2) return 1;
	return f(n-1)+f(n-2);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		cout<<f(n);
	}
	return 0;
}
