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

void find(int left1,int right1,int left2,int right2){
	//int lena=strlen(a);
	//int lenb=strlen(b);
	int root=-1;
	for(int i=left2;i<=right2;i++){
		if(a[left1]==b[i]){
			root=i;
			break;
		}
	}
	if(root>left2)
	find(left1+1,left1+root-left2,left2,root-1);
	if(root<right2)
	find(left1+1+root-left2,right1,root+1,right2);
	cout<<a[left1];
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
