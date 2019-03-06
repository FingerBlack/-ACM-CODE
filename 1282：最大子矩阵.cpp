	#include<iostream>
	#include<string>
	#include<stdio.h>
	#include<algorithm>
	#include<vector>
	#include<string.h>
	#include<set>
	#include<math.h>
	#include<stack>
	using namespace  std;
	#define local
	const int N=1001;
	//int f[N][N];
	int a[N][N];
	int pre[N]={0};
	int ans[N];
	int k=1;
	int n;
	int maxx(){
		int b=ans[0],maxn=ans[0];
		for(int i=1;i<n;i++){
			if(b<0){
				b=ans[i];
			}else{
				b+=ans[i];
			}
			if(b>maxn){
				maxn=b;
			}
		}
		return maxn;
	}
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
	
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		}
		int maxn=-1e8;
		for(int i=0;i<n;i++){
			memset(ans,0,sizeof ans);
			for(int j=i;j<n;j++){
				for(int k=0;k<n;k++){
					ans[k]+=a[j][k];
				}
				int maxsub=maxx();
				if(maxsub>maxn){
					maxn=maxsub;
				}
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
