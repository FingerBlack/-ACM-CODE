#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace  std;
#define local
const int N=10001;
int a[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	while(cin>>n){
		int max=-1;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
		if(sum-max<max){
			printf("%.1lf\n",1.0*(sum-max));
		}else{
			printf("%.1lf\n",max+1.0*(sum-max-max)/2);
		}
		sort(a,a+n);
	}
	return 0;
}
