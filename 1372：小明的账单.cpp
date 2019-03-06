#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace  std;
#define local
int n,m;
const int N=30000;
const int inf=1e9;
int a,b,c;
struct node1
{
	int num;
	int k;
	node1(int a,int b){
		num=b;
		k=a;
	}
	bool operator <(const node1 &n)const{
		return k<n.k;
	}
};
struct node2
{
	int num;
	int k;
	node2(int a,int b){
		num=b;
		k=a;
	}
	bool operator <(const node2 &n)const{
		return k>n.k;
	}
};
priority_queue <node1  >qq;
priority_queue <node2 >pp;
map<int ,int > ss;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif

	scanf("%d",&n);
	int k=0;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&a);
			qq.push(node1(a,k));
			pp.push(node2(a,k));
			ss[k]++;
			k++;
		}
		if(!ss[pp.top().num]){
			pp.pop();
		}
		if(!ss[qq.top().num]){
			qq.pop();
		}
		cout<<pp.top().k<<' '<<qq.top().k<<endl;;
		ss[pp.top().num]--;
		ss[qq.top().num]--;
		qq.pop();
		pp.pop();
	}
	return 0;
}
