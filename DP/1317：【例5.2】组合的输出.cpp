#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int n,r;
int a[N];
int b[N];
void f(int start,int l){

	if(l==r){
		//a[l]=start;
		for(int i=0;i<l;i++){
			cout<<"  "<<b[a[i]];
		}
		cout<<endl;
		return;
	}
	for(int i=start;i<n;i++){
		a[l]=i;
		f(i+1,l+1);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	 cin>>n>>r;
	 for(int i=0;i<n;i++){
	 	b[i]=i+1;
	 }
	 f(0,0);
	return 0;
}
