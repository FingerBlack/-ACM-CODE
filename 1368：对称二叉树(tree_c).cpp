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
char a[N];
int k=1,ans,d,m,n,flag=0,len;

 void travel(int Root){
	bool l,r;
	if(a[2*Root]=='#'||2*Root>len){
		l=false;
	}else{
		l=true;
	}
	if(a[2*Root+1]=='#'||2*Root+1>len){
		r=false;
	}else{
		r=true;
	}

	//cout<<l<<' '<<r<<endl;
	if(l^r){
		flag=1;
	}
	if(l&&!flag)
	travel(2*Root);
	if(r&&!flag)
	travel(2*Root+1);
	return;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x,l,r; 
	scanf("%s",a+1);
	len=strlen(a+1);
	travel(1);
	if(flag){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
