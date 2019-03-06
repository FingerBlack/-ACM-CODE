#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
typedef long long ll;

ll f(int i,int j){
	if(i<j)return 0;
	if(j==1||j==i) return 1;
	return f(i-1,j-1)+j*f(i-1,j);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,k;
	cin>>n>>k;
	cout<<f(n,k)<<endl;
	return 0;
}
