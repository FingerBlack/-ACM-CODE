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
priority_queue <int >qq;
int f(int a,int b,int c,int x){
	return a*x*x+b*x+c;
}
void deal(int a,int b,int c){
	for(int i=1;i<=m;i++){
		int fx=f(a,b,c,i);
		if(qq.size()<m){
			qq.push(fx);
		}else{
			if(fx<qq.top()){
				qq.pop();
				qq.push(fx);
			}else{
				break;
			}
		}
	}
}
void print(){
	if(qq.size()==1){
		cout<<qq.top();
		return;
	}
	int m=qq.top();
	qq.pop();
	print();
	cout<<' '<<m;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&n,&m);
	//sum[0]=0;
	
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		deal(a,b,c);
	}
	print();
	return 0;
}
