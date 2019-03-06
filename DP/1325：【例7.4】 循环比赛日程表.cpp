#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=10001;
int a[N][N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x=1;
	int k;
	cin>>k;
	a[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<x;j++){
			for(int h=0;h<x;h++){
				a[j][h+x]=a[j][h]+x;
				a[j+x][h+x]=a[j][h];
				a[j+x][h]=a[j][h+x];
			}
		}
		x<<=1;
	}
	for(int j=0;j<x;j++){
			for(int h=0;h<x;h++){
				if(h)cout<<' ';
				cout<<a[j][h];
			}
			cout<<endl;
		}
	return 0;
}
