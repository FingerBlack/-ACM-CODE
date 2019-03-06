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
const int N=4e7;
int x;
int a[30]={1,1
,1
,5
,1
,21
,1
,85
,73
,341
,89
,1365
,1
,5461
,4681
,21845
,1
,87381
,1
,349525
,299593
,1398101
,178481
,5592405
,1082401
,22369621
};
struct node
{
	int l,r,k;
	int al,ar;
}nn[30];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	//scanf("%d",&n);
	int maxx=-1;
	int k=3; 
	int l=1;
	int r=3;
	nn[0].l=1;
	nn[0].k=3;
	nn[0].r=3;
	nn[0].al=1;
	l=3;
	int m=1;
	for(int i=1;i<25;i++){
		r=2*l+1;
		nn[i].l=l;
		nn[i].r=r;
		nn[i].k=2*nn[i-1].k+1;
		nn[i].al=a[m++];
		l=r;
	}
	int p;
	scanf("%d",&p);
	while(p--){
		scanf("%d",&x);
		for(int i=0;i<25;i++){
		//	cout<<x<<" "<<nn[i].l<<" " <<nn[i].r<<endl;
			if(x>nn[i].l&&x<nn[i].r){
				printf("%d\n",nn[i].k);
				break;
			}
			if(x==nn[i].l){
				printf("%d\n",nn[i].al);
				break;
			}
		}
	}
	return 0;
}

//1 1 1 5 1 21 1 85 73 341
//1 3 7 15 31 63 127 255 511
//3 9 15