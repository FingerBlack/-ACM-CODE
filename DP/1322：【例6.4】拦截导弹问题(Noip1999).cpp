#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace  std;
#define local
const int N=1010;
//int f[N];
const int inf=0x3f3f;
bool vis[N]={0};
int minx[N];
char s[N];
int n;
int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n=0;
	while(cin>>f[n]){n++;};
	int k=0;
	//cout<<n;
	memset(minx,inf,sizeof minx);
	//cout<<minx[1];
	for(int i=0;i<n;i++){
		int pos=0;
		int minn=1e8;
		for(int j=1;j<=k;j++){
			if(f[i]<=minx[j]&&minn>minx[j]){
				pos=j;
				minn=minx[j];
			}
		}
		if(pos!=0){
			minx[pos]=f[i];
		}else{
			k++;
			minx[k]=f[i];
		}
	}
	cout<<k<<endl;
	return 0;
}