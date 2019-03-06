#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=1e5;
int sum=1;
int mm[N];
void f(int a,int b){
	for(int i=a;i*i<=b;i++){
		if(b%i==0){
			sum++;
			f(i,b/i);
		}
	}
}	
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	int n;
	while(t--){
		sum=1;
		cin>>n;
		f(2,n);
		cout<<sum<<endl;
	}
	return 0;
}
