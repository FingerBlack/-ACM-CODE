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
int x;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d",&n);
	set<int > s;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s.insert(x);
	}
	set<int>::iterator it=s.begin();
	cout<<*it;
	it++;
	for(;it!=s.end();it++){
		cout<<" "<<*it;
	}
	return 0;
}

