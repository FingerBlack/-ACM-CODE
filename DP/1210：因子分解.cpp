#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
void f(int n){
	int flag=0;
	for(int i=2;i*i<=n;i++){
		//cout<<i<<endl;
		if(n%i==0){
			if(flag){
				cout<<'*';
			}
			flag++;
			cout<<i;
			int j=0;
			while(n%i==0){
				j++;
				n/=i;
			}
			if(j!=1){
				cout<<'^'<<j;
			}
		}
	}
	if(n!=1){	
		cout<<'*'<<n<<endl;
	}
}

int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	f(n);
	return 0;
}
