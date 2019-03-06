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
	int n;
	for(int i=3;i<=20;i++){
		f[i]=f[i-2]+f[i-1];
	}
	cin>>n;
	cout<<f[n]<<endl;
	return 0;
}
