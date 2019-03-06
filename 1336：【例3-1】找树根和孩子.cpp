#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<vector>
using namespace  std;
#define local
const int N=10001;
int n,m;
int pre[N]={0},x,y,maxx[N];
vector <int > s[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		pre[y]=x;
		s[x].push_back(y);
		maxx[x]++;
	}
	int flag=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(maxn<maxx[i]){
			flag=i;
			maxn=maxx[i];
		}
		//maxn=max(maxn,maxx[i]);
		if(pre[i]==0){
			cout<<i<<endl;
		}
	}
	cout<<flag<<endl;
	sort(s[flag].begin(), s[flag].end());
	for(int i=0;i<s[flag].size();i++){
		if(i){
			cout<<' ';
		}
		cout<<s[flag][i];
	}
	return 0;
}
