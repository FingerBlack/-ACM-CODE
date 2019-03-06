#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=1000011;
const int mod=32767;
typedef long long ll;
ll f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	f[1]=1;
	f[2]=2;
	f[3]=4;
	int n;
	for(int i=4;i<=72;i++){
			f[i]=f[i-2]+f[i-3]+f[i-1];
	}
	while(cin>>n&&n){
		cout<<f[n]<<endl;
	}
	return 0;
}
