#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include <stack>
using namespace  std;
#define local
const int N=511,inf=1e8;
int  dp[N][N],n,m,x,y,z;
int sum[N]={0},pos[N][N],a[N];
void print(int i,int j)
{
    int x,t;
    if(i==0) return;
    if(i==1)
    {
        cout<<1<<" "<<j<<endl;
        return ;
    }
    x=a[j];
    t=j;
    while(x+a[t-1]<=dp[m][n])
    {
        x+=a[t-1];
        t--;
    }
    print(i-1,t-1);           
    cout<<t<<" "<<j<<endl;   
}
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	memset(dp,0x3f3f,sizeof dp);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		dp[1][i]=sum[i];
	}
	
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
		//	dp[i][j]=inf;	
			for(int k=i-1;k<j;k++){
				if(max(dp[i-1][k],sum[j]-sum[k])<dp[i][j]){
					dp[i][j]=max(dp[i-1][k],sum[j]-sum[k]);
					pos[i][j]=k;
				}
				//dp[i][j]=min(dp[i][j],max(dp[i-1][k],sum[j]-sum[k]));
			//	cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
	}
	print(m,n);
	cout<<dp[m][n]<<endl;
	return 0;
}
