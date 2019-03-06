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
int dp[N]={0},w[N],c[N],num[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m,ww,cc,numm;
	cin>>m>>n;
	int l=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&ww,&cc,&numm);
		
		if(numm){
			int k=1;
			while(numm>k){
				numm-=k;
				w[l]=k*ww;
				c[l]=k*cc;
				num[l]=k;
				k<<=1;
				l++;
			}
			w[l]=numm*ww;
			c[l]=numm*cc;
			num[l++]=numm;
		}else{
			w[l]=ww;
			c[l]=cc;
			num[l++]=0;
		}
	}
	for(int i=0;i<l;i++){
		if(!num[i]){
			for(int j=w[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
			}
		}
		else{
			for(int j=m;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//
//		cout<<dp[i]<<" " ;
//	}
	cout<<dp[m]<<endl;
	return 0;
}
