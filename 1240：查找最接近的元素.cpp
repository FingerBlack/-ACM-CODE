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
int bisearch(int ll,int rr,int k){
	int l=ll-1;
	int r=rr+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(a[mid]<k){
			l=mid;
		}else if(a[mid]>k){
			r=mid;
		}else if(a[mid]==k){
			return a[mid];
		}
	}
	if(r==rr+1){
		return a[l];
	}
	if(l==ll-1){
		return a[r];
	}
	if(k-a[l]<=a[r]-k){
		return a[l];
	}else{
		return a[r];
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int m,k;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&k);
		printf("%d\n",bisearch(1,n,k));
	}	
	return 0;
}
