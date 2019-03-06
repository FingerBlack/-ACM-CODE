#include<iostream>
#include<string>
#include<algorithm>
using namespace  std;
#define local
const int N=10001;
const int inf=1e8;
int a[N][N];
int bb[N];
int maxsub(int a[],int n){
	int b=a[0];
	int maxx=b;
	for(int i=1;i<n;i++){
		b=max(b+a[i],a[i]);
		maxx=max(maxx,b);
	}
	return maxx;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int maxx=-inf;
	for(int i=1;i<=n;i++){
		memset(bb,0,sizeof bb);
		for(int j=i;j<=n;j++){
			for(int k=0;k<n;k++){
				bb[k]+=a[j][k+1];
			}
		//	cout<<1;
		//	cout<<maxsub(bb,n)<<endl;
			maxx=max(maxx,maxsub(bb,n));
		}
	}
	cout<<maxx<<endl;
	return 0;
}
