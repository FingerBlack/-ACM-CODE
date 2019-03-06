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
const int N=100001;
int a[N];
int n,kk;
const int inf=1e9;
bool f(int min){
	int sum=0;
	int month=1;
	for(int i=1;i<=n;i++){
		if(a[i]+sum>min){
			sum=a[i];
			month++;
		}else{
			sum+=a[i];
		}
	}
	//cout<<month<<endl;
	if(month>kk){
		return false;
	}else{
		return true;
	}
}
//int dp[N][N]; 
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif

	scanf("%d%d",&n,&kk);
	int x;
	int sum=0;
	int l,r;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		l=max(l,a[i]);
	}
	r=sum;
	//cout<<r;
	l--;
	r++;
	while(l+1<r){
		//cout<<l<<" "<<r<<endl;
		int mid=(l+r)/2;
		if(f(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<r<<endl;
	return 0;

}
