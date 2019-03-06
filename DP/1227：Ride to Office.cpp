#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace  std;
#define local
const int N=101;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;

	//	cout<<1;
	while(cin>>n&&n){
		double t,v;
		int minn=1e6;
		//cout<<minn;
		for(int i=0;i<n;i++){
			cin>>v>>t;
			if(t<0)continue;
			//cout<<t<<" "<<v<<endl;
			int s=t+4.5/v*3600;
			//cout<<s<<endl;
			if((t+4.5/v*3600)-s){
				s++;
			}
			//cout<<s<<endl;
			if(s<minn){
				minn=s;
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
