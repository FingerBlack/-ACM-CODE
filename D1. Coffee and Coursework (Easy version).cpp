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
const int N=1000;
int dp[101][10001],n,m;
long long sum=0;
const int inf=1e8;
int a[N],b[N],c[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=150;i++){
		b[i]=b[i-1]+i;
		c[i]=i+1;
	}
	if(sum<m){
		cout<<-1<<endl;
	}else{
		int x=sum-m;
	//   	cout<<n<<endl;
		for(int i=1;i<=150;i++){
			for(int k=c[i];k<=n;k++){
				for(int j=b[i];j<=x;j++){
					dp[k][j]=max(dp[k][j],dp[k-c[i]][j-b[i]]+i);
				}
			}
		}
		sort(a+1,a+n+1);
		int minn=inf,summ=0;
		for(int i=0;i<=n;i++){
			summ+=a[i];
			//cout<<summ<<' '<<x-summ<<' '<<dp[n-i][x-summ]<<endl;
			if(summ>x){
				break;
			}
			minn=min(minn,n-i-dp[n-i][x-summ]);
		}
		cout<<minn<<endl;
		
	}
	return 0;
}
