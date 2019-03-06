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
			if(a[pos[mid]]<=kk){
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
			pre[i]=-1;
		}
		int pp=0;
		pos[0]=-1;
		pos[k++]=0;
		for(int i=1;i<n;i++){
	//		for(int i=0;i<n;i++){
	//			cout<<pos[i]<<' ';
	//		}
	//		cout<<endl;
			if(a[i]>=a[pos[k-1]]){
				pos[k++]=i;
				pre[i]=pos[k-2];
			//	cout<<i<<' '<<pos[k-2]<<endl;
			}else{
				pp=uppercase(a[i]);
			//	cout<<pp<<endl;
				pos[pp]=i;
				pre[i]=pos[pp-1];
			}
		}
		
		cout<<"max="<<k-1<<endl;
		stack<int >ss;
		int i=pos[k-1];
		
		while(pre[i]!=-1){
			ss.push(a[i]);
	//		cout<<i<<endl;
			i=pre[i];
		}
		ss.push(a[i]);
		int flag=0;
		while(!ss.empty()){
			if(flag){
				cout<<' ';
			}
			flag++;
			cout<<ss.top();
			ss.pop();
		}
		return 0;
	}
