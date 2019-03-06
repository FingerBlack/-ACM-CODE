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
const int N=100001;
int a[N];
int n,k;
bool bisearch(int l,int r,int kk){
	int ll=l-1;
	int rr=r+1;
	while(ll+1<rr){
		cout<<ll<<" " <<rr<<endl;
		int mid=(ll+rr)/2;
	//	cout<<a[mid]<<" "<<kk<<endl;
		if(a[mid]<kk){
			ll=mid;
		}else if(a[mid]>kk){
			rr=mid;
		}else if(a[mid]==kk){
			cout<<"ok"<<endl;
			return true;
		}
	}
	return false;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]<<endl;
	//}
	//cout<<n<<endl;
	int flag=0;
	int i=1;
	//bisearch(2,n,4);
	for(;i<=n;i++){
		if((k-a[i]<a[i]))break;		
	//	cout<<i<<" "<<n<<" "<<k-a[i]<<endl;
		if(bisearch(i,n,k-a[i])){
			flag=1;
			cout<<a[i]<<' '<<k-a[i]<<endl;
			break;
		}
	}
	cout<<a[i]<<' '<<k-a[i]<<endl;
	if(!flag){
		cout<<"No"<<endl;
	}
	return 0;
}

