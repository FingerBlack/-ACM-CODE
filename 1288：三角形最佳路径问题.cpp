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
const int N=1001;
int f[N][N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	 int r;
	 cin>>r;
	 for(int i=0;i<r;i++){
	 	for(int j=0;j<=i;j++){
	 		scanf("%d",&f[i][j]);
	 			//cout<<f[i][j]<<' ';
	 	}
	 	//cout<<endl;
	 }
	 for(int i=1;i<r;i++){
	 	f[i][0]+=f[i-1][0];
	 	for(int j=1;j<i;j++){
	 		f[i][j]+=max(f[i-1][j],f[i-1][j-1]);
	 	}
	 	f[i][i]+=f[i-1][i-1];
	 }
	 int maxn=f[r-1][0];
	 for(int i=1;i<r;i++){
	 	if(f[r-1][i]>maxn){
	 		maxn=f[r-1][i];
	 	}
	 //	cout<<f[r-1][i]<<endl;
	 }
	// for(int i=0;i<r;i++){
	 //	for(int j=0;j<=i;j++){
	 	//	cout<<f[i][j]<<' ';
	// 	} 
	 //	cout<<endl;
	// }
	 cout<<maxn<<endl;
	return 0;
}
