#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<set>
#include<map>
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
	int n;
	scanf("%d",&n);
	map <int,int > s;
	int x;
	while(n--){
		scanf("%d",&x);
		s[x]++;
	}
	for(map <int,int>::iterator it=s.begin();it!=s.end();it++){
		printf("%d %d\n", it->first,it->second);
	}
	return 0;
}
