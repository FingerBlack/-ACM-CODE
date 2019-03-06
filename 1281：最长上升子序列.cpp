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
	int f[N][N];
	int a[N];
	int pre[N]={0};
	int pos[N];
	int k=1;
	int uppercase(int kk){
		int l=0,r=k,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(pos[mid]<kk){
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
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		pos[k++]=a[0];
		for(int i=1;i<n;i++){
	//		for(int i=0;i<n;i++){
	//		//scanf("%d",&a[i]);
	//			cout<<pos[i]<<' ';
	//		}
	//		cout<<endl;
			if(a[i]>pos[k-1]){
				pos[k++]=a[i];
			}else{
				pos[uppercase(a[i])]=a[i];
			}
		}
	//	for(int i=0;i<n;i++){
			//scanf("%d",&a[i]);
	//			cout<<pos[i]<<' ';
	//		}
		cout<<k-1<<endl;
		return 0;
	}
