#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<queue>
using namespace  std;
#define local
int n,m;
const int N=30000;
const int inf=1e9;
int a,b,c;

struct node
{
	string name;
	int num;
	node(string a,int b){
		name=a;
		num=b;
	}
	bool operator< (const node &n)const{
		return num<n.num;
	}
};
priority_queue <node >qq;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d",&n);
	string order,name;
	int k;
	for(int i=0;i<n;i++){
		cin>>order;
		if(order=="push"){
			cin>>name>>k;
			qq.push(node(name,k));
		}else if(order=="pop"){
			if(qq.empty()){
				cout<<"none"<<endl;
			}else{
				cout<<qq.top().name<<' '<<qq.top().num<<endl;
				qq.pop();
			}
		}
	}
	return 0;
}
