#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=1000011;
const int mod=32767;
int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	f[1]=1;
	f[2]=2;
	int t;
	cin>>t;
	int n;
	for(int i=3;i<=1000000;i++){
			f[i]=(2*f[i-1]+f[i-2])%mod;
	}
	while(t--){
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}
