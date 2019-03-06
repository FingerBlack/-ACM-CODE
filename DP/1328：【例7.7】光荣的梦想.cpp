#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=10001;
int fff[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&fff[i]);
	//	cout<<fff[i]<<endl;
	}
	int count=0;
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			if(fff[j]<fff[j-1]){
				//cout<<endl;
				int tem=fff[j];
				fff[j]=fff[j-1];
				fff[j-1]=tem;
				count++;
			//	cout<<fff[j]<<endl;
			}
			//cout<<count<<endl;
		}
	}
//	for(int m=0;m<n;m++){
	//	cout<<f[m]<<" ";
//	}
//	cout<<endl;
	cout<<count<<endl;
	return 0;
}
