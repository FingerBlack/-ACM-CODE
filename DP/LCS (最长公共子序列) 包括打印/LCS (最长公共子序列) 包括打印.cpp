#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace  std;
#define local;
const int maxn =1e3;
int n,m;
int dp[maxn][maxn];
int path[maxn][maxn];
char a[maxn],b[maxn];
int lcs(){
	memset(dp,0,sizeof dp);
	memset(path,0,sizeof path);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				path[i][j]=1;
			}else {
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j];
					path[i][j]=2;
				}
				else{
					dp[i][j]=dp[i][j-1];
					path[i][j]=3;
				}
			}
		}
	}
	return dp[n][m];
}
void printlcs(int i,int j){
	if(i==0||j==0){
		return;
	}
	if(path[i][j]==1){
		printlcs(i-1,j-1);

		cout<<a[i];
	}else if(path[i][j]==2){
		printlcs(i-1,j);
	}else if(path[i][j]==3){
		printlcs(i,j-1);
	}

}
#define local
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	while(gets(a+1)){
		gets(b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		cout<<lcs()<<endl;
		printlcs(n,m);
		cout<<endl;
	}
	return 0;
}
