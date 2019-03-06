#include<iostream>
#include<string>
using namespace  std;
#define local
typedef long long ll;
const int N=1000;
ll f1[N];
ll f2[N];
const int mod=12345;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	f1[1]=1;// odd
	f2[1]=9;// even
	int n;
	cin>>n;
	int x=9;
	for(int i=2;i<=n;i++){
		if(i==n) x=8;
		f2[i]=(f2[i-1]*x+f1[i-1])%mod;
		f1[i]=(f1[i-1]*x+f2[i-1])%mod;
	}
/*	for(int i=1;i<=n;i++){
		cout<<f1[i]<<" "<<f2[i]<<endl;
	}
*/	
	cout<<f2[n]%mod<<endl;
	return 0;
}
