#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
typedef long long  ll;
ll mm[1011];
void f(int i){
	if(mm[i]!=0)return;
	mm[i]=1;
	for(int k=1;k<=i/2;k++){
		f(k);
		mm[i]+=mm[k];
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	memset(mm,0,sizeof mm);
	cin>>n;
	f(n);
		//cout<<n;
	//printf("%lld",n);
	cout<<mm[n];
	
	return 0;
}
