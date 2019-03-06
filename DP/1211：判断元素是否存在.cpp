#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int k,x;
bool f(int x){
	if(x==k)
		return true;
	if((x-1)%2==0&&(x-1)%3==0){
		return f((x-1)/2)||f((x-1)/3);
	}else if((x-1)%2==0&&(x-1)%3!=0){
		return f((x-1)/2);
	}else if((x-1)%2!=0&&(x-1)%3==0){
		return f((x-1)/3);
	}else{
		return false;
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	char c;
	cin>>k>>c>>x;
	if(f(x)){cout<<"YES"<<endl;}
	else  {cout<<"NO"<<endl;}
	return 0;
}
