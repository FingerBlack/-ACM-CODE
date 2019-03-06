#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	
	int n,m;
	while(cin>>n>>m){
		int first=1;
		if(n==0&&m==0){
			break;
		}
		if(n<m){
			int tem=n;
			n=m;
			m=tem;
			//n^=m^=n^=m;
		}
		if((n/m)>=2){
			cout<<"win"<<endl;
		}else{
			while(n/m==1){
				int tem=n;
				n=m;
				m=tem-m;
				first=-first;
			}
			if(first>0){
				cout<<"win"<<endl;
			}else{
				cout<<"lose"<<endl;
			}
		}
	}
	return 0;
}
