
#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f(int a,int b){
	return b==0?a:f(b,a%b);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x,y;
	cin>>x>>y;
	cout<<f(x,y)<<endl;
	return 0;
}
