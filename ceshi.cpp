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
const int N=10001;
int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int a[100]={1,2,3,2,9,3,6,5,2,4,5,6,7,8};
	sort(a,a+14,greater<int>());
	for(int i=0;i<14;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
