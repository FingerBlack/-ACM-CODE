#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=100010;
int a[N];
long long ans=0;
void mergrsort(int l,int r){
	if(l>=r)return ;
	
	int m=(l+r)/2;
	mergrsort(l,m);
	mergrsort(m+1,r);
	//cout<<l<<" "<<m<<" "<<m+1<<" "<<r<<endl;
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	int tem[N];
	int k=0;
	int i=l;
	int j=m+1;
	while(i<=m&&j<=r){
		if(a[i]>a[j]){
			ans+=(m-i+1);
		//	cout<<ans<<endl;
			tem[k++]=a[j++];
		
		}else {
			tem[k++]=a[i++];
		}
	//	cout<<k<<endl;
	//	cout<<r-l+1<<endl;
	}
	while(i<=m)tem[k++]=a[i++];
	while(j<=r)tem[k++]=a[j++];
	//if(l==0&&r==2)cout<<i<<" "<<j<<" "<<m+1<<" "<<r+1<<endl;
	for(int i=0;i<k;i++){
		a[i+l]=tem[i];
	//	if(l==0&&r==2)
	//	cout<<tem[i]<<" ";
	}
	//cout<<endl;
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
		scanf("%d",&a[i]);//cout<<a[i]<<endl;

	}
	mergrsort(0,n-1);
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
	cout<<ans<<endl;
	return 0;
}
