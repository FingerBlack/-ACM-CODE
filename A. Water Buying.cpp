#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
#define local
const int N=10001;
int f[N],n,m;
long long sum;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		cin>>sum>>n>>m;
		double x1=n;
		double x2=m/2.0;
		if(x2<x1){
			if(sum%2==1){
				cout<<(sum-1)/2*m+n<<endl;
			}else if(sum%2==0){
				cout<<sum/2*m<<endl;
			}
		}else{
			cout<<sum*n<<endl;
		}
	}
	return 0;
}
