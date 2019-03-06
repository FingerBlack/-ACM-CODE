#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
//#define local
const int N=100001;
int a[N];
int b,k;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&b,&k);
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	if(b%2==1){
		int flag=1;
		for(int i=0;i<k;i++){
			if(a[i]%2==1){
				flag=-flag;
			}
		}
		if(flag>0){
			cout<<"even"<<endl;
		}else{
			cout<<"odd"<<endl;
		}
	}else{
		if(a[k-1]%2==1){
			cout<<"odd"<<endl;
		}else{
			cout<<"even"<<endl;
		}
	}
	return 0;
}
