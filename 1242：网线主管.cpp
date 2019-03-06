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
int f(int x){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i]/x;
		if(sum>=k){
			return true;
		}
	}
	//cout<<sum<<endl;
	return false;
}
int search(int a,int b){
	b++;
	while(b-a>1){
		int mid=(a+b)/2;
		if(f(mid)){
			a=mid;
		}else{
			b=mid;
		}
	}
	return a;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&n,&k);
	double maxx=0;
	double x;
	for(int i=0;i<n;i++){
		scanf("%lf",&x);
		a[i]=(int)x*100;
		maxx+=x*100;
	}
	//cout<<maxx/k<<endl;
	
	printf("%.2lf\n",search(1,maxx/k)/100.0);
	
	return 0;
}
