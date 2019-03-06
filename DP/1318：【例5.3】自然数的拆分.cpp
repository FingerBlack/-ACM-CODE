#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int sum=0;
int m;
int a[N];
void f(int start,int n,int l){
	if(n==0){
		cout<<m<<'='<<a[0];
		for(int i=1;i<l;i++){
			cout<<'+'<<a[i];
		}
		cout<<endl;
		return;
	}
	for(int i=start;i<=n;i++){
		a[l]=i;
		if(i!=m)
		f(i,n-i,l+1);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	
	cin>>m;
	f(1,m,0);
	return 0;
}
