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
const int N=2e5+10;
int a1[N]={0},a2[N]={0},a[N],n,m;
long long sum=0;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i%2==1){
			a1[i]=a1[i-1]+a[i];
			a2[i]=a2[i-1];
		}else{
			a2[i]=a2[i-1]+a[i];
			a1[i]=a1[i-1];
		}
	}

	for(int i=1;i<=n;i++){
		if(a1[i-1]+a2[n]-a2[i]==a2[i-1]+a1[n]-a1[i]){
			//cout<<i<<endl;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
