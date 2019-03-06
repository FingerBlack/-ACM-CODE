#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
typedef long long ll;
ll f[N];
ll b[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=1;i<=x;i++){
		f[i]=1;
		b[i]=0;
	}
	for(int i=x+1;i<=z+1;i++){
		b[i]=f[i-x]*y;
		f[i]=b[i-2]+f[i-1];
		//cout<<f[i]<<endl;
	}
	cout<<f[z+1]<<endl;
	return 0;
}
