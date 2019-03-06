#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f(int m,int n){
	if(m<n){
		return f(m,m);
	}
	if(m==0)return 1;
	if(m==1||n==1){
		return 1; 
	}
	return f(m,n-1)+f(m-n,n);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<f(m,n)<<endl;
	}
	return 0;
}
