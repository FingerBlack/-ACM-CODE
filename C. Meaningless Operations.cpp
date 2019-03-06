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
int x;
int a[N];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	scanf("%d",&n);
	int maxx=-1;
	/*for(int i=2;i<n;i++){
		//scanf("%d",&x);
		maxx=-1;
		for(int j=1;j<i;j++)
			maxx=max(maxx,gcd(i^j,i&j));
		cout<<i<<" "<<maxx<<endl;
	}*/
	int i=1;
	int k=25;
	cout<<"{1";
	while(k--){
		i=2*i+1;
		for(int j=1;j<i;j++)
			maxx=max(maxx,gcd(i^j,i&j));
		cout<<i<<" "<<maxx<<endl;
	}
	return 0;
}
//1 5
