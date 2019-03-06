#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int mm[N]={0};
int f(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	if(mm[n]!=0) return mm[n];
	return mm[n]=f(n-1)+f(n-2);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
	return 0;
}
