#include<iostream>
#include<string>
#include<string.h>
using namespace  std;
#define local
const int N=1e7;
int mm[N];
void f(int n){
	if(mm[n]!=0);
	f(n-1);
	f(n-2);
	mm[n]=(2*mm[n-1]+mm[n-2])%32767;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	memset(mm,0,sizeof mm);
	cin>>t;
	int n;
	mm[1]=1;
	mm[2]=2;
	while(t--){
		cin>>n;
		f(n);
		cout<<mm[n]<<endl;
	}
	return 0;
}
