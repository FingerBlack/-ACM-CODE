#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<stack>
#include<queue>
using namespace  std;
#define local
const int N=511,inf=1e8;
int  dp[N]={0},n,m;
int a[N],b[N],pos[N][N]={0};
void print(int i,int j){
	if(i==1){
		cout<<b[j];
		return;
	}
	if(pos[i][j]!=0){
		print(i-1,pos[i][j]);
		cout<<' '<<b[j];
	}else{
		print(i-1,j);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}	
	int MAX=0;
	int pp=0;
	for(int i=1;i<=n;i++){
		MAX=0;
		for(int j=1;j<=m;j++){
			if(a[i] > b[j]){
				if(dp[j]>MAX){
					pp=j;
					MAX=dp[j];
				}
			} 
			if(a[i] == b[j]){ 
				dp[j] = MAX+1;
				pos[i][j]=pp;
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=m;i++){
		if(dp[i]>=maxx){
			maxx=dp[i];
			pp=i;
		}
	}
	//cout<<pp<<endl;
	cout<<maxx<<endl;
	print(n,pp);
	return 0;
}
