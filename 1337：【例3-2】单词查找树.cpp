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
int tree[N][30]={0};
int tot=0;
void insert(char* s){
	int root=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		int id=int(s[i]-'0');
		if(tree[root][id]==0){
			tree[root][id]=tot++;
		}
		root=tree[root][id];
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	char s[100];
	while(scanf("%s",s)!=-1){
		insert(s);
	}
	cout<<tot<<endl;
	return 0;
}
