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
	const int N=1001,inf=1e9;
	int f[N][N];
	int a[N];
	int pre[N]={0};
	int pos[N];
	int k=1;
	int uppercase(int kk){
		int l=0,r=k,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(a[pos[mid]]>kk){
				l=mid;
			}else{
				r=mid;
			}
		}
		return r;
	} 
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n=0;
		while(scanf("%d",&a[n])!=-1){n++;};
		int pp=0;
		pos[0]=-1;
		pos[k++]=0;
	//	cout<<n<<endl;
		for(int i=1;i<n;i++){
	//		for(int i=0;i<k;i++){
	//			cout<<a[pos[i]]<<' ';
	//		}
	//		cout<<k;
	//		cout<<endl;
			if(a[i]<=a[pos[k-1]]){
				pos[k++]=i;
			//	cout<<i<<' '<<pos[k-2]<<endl;
			}else{
				pp=uppercase(a[i]);
			//	cout<<pp<<endl;
				pos[pp]=i;
			}
		}
		cout<<k-1<<endl;
		
		return 0;
	}
