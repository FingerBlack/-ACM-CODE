	#include<iostream>
	#include<string>
	#include<stdio.h>
	#include<algorithm>
	#include<vector>
	#include<string.h>
	using namespace  std;
	#define local
	const int N=100001;
	int n,m;
	int f[N];
	int a[N];
	int maxx(){
		int maxn=a[0];
		int pos=0;
		for(int i=1;i<m;i++){
			if(a[i]>maxn){
				maxn=a[i];
				pos=i;
			}
		}
		return pos;
	}
	int minn(){
		int mina=a[0];
		int pos=0;
		for(int i=1;i<m;i++){
			if(a[i]<mina){
				mina=a[i];
				pos=i;
			}
		}
		return pos;
	}
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>f[i];
		}
		int time=0;
		if(n>m){
			for(int i=0;i<m;i++){
				a[i]=f[i];
			}			
			for(int i=m;i<n;){
				int minx=a[minn()];
			// 	cout<<minn()<<endl;
			//	for(int i=0;i<m;i++){
			//		cout<<a[i]<<" ";
			//	}
			//	cout<<endl;
			//	cout<<i<<endl;
				for(int j=0;j<m;j++){
					if(a[j]==minx){
						if(i==n){
							a[j]=0;
						}else{
							a[j]=f[i++];
						}
					}else{
						a[j]-=minx;
					}
				}
				time+=minx;
			}
			//for(int i=0;i<m;i++){
			//	cout<<a[i]<<" ";
			//}
			//cout<<endl;
			time+=a[maxx()];
		}else{
			for(int i=0;i<n;i++){
				a[i]=f[i];
			}
			for(int i=n;i<m;i++){
				a[i]=0;
			}
			time+=a[maxx()];
		}
		cout<<time<<endl;
		return 0;
	}
