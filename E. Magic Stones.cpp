	#include<iostream>
	#include<string>
	#include<stdio.h>
	#include<algorithm>
	#include<vector>
	#include<string.h>
	#include<set>
	#include<math.h>
	#include<map>
	using namespace  std;
	#define local
	const int N=2e5+10;
	int x;
	int a[N],b[N];
	map <int ,int >mm;
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n;
		scanf("%d",&n);
	//	memset(map,0,sizeof map);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++)
			mm[a[i]-a[i-1]]++;
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		int flag=0;
		for(int i=1;i<n;i++)
			if(mm[b[i]-b[i-1]]==0){
				flag=1;
				break;
			}else{
				mm[b[i]-b[i-1]]--;
			}
		if(n==3)
		if(a[1]!=b[1]){
			flag=1;
		}
		if(flag){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}

	//1 1 1 5 1 21 1 85 73 341
	//1 3 7 15 31 63 127 255 511
	//3 9 15