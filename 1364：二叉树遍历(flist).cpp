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
const int N=1e7;
char a[N],b[N];
int k=0,ans,d,n;
void find(int l1,int r1,int l2,int r2){
	int flag=0;
	for(int i=l2;i<=r2;i++){
		for(int j=l1;j<=r1;j++){
			if(b[i]==a[j]){
				flag=j;
				cout<<a[j];
				//cout<<' '<<j<<endl;
				break;
			}
			
		}
		if(flag){
			break;
		}
	}
	if(flag>l1){
		find(l1,flag-1,l2,r2);
	}
	if(flag<r1){
		find(flag+1,r1,l2,r2);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%s%s",a,b);
	find(0,strlen(a)-1,0,strlen(b)-1);
	return 0;
}
