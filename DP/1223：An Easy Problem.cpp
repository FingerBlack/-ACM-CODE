#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=10001;
int f(int n){
	int k=1;
	int h=1;
	int tem=n;
	while(!(tem&1)){
		tem>>=1;
		h<<=1;
	}
	while((tem&1)){
		tem>>=1;
		k<<=1;
		k++;
	}
	k>>=1;
	k>>=1;
	n+=h;
	n+=k;
	return n;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n; 
	while(cin>>n){
		if(!n){
			break;
		}
		cout<<f(n)<<endl;
	}
	return 0;
}
