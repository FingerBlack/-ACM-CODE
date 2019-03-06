#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace  std;
#define local
const int N=101;
int f[N][N];
struct point
{
	int x,y;
	bool operator <(const point &n)const{
		return x<n.x;
	}
}p[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	memset(f,0,sizeof f);
	int t;
	cin>>t;
	int n,m;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		p[i].x=n;
		p[i].y=m;
	}
	
	int flag=0;
	sort(p,p+t);
	stack<point >s;
	s.push(p[0]);
	point maxx;
	//for(int i=0;i<t;i++){
//		cout<<p[i].x<<" "<<p[i].y<<endl;
//	}
	for(int i=1;i<t;i++){
		maxx=s.top();
	//	cout<<maxx.y<<endl;
		if(p[i].y>=maxx.y){
			while(!s.empty()){
				maxx=s.top();
				if(p[i].y>=maxx.y)
					s.pop();
				else
					break;
			}
			s.push(p[i]);
		}else  if(p[i].x>p[i-1].x){
		//	cout<<p[i].x<<" "<<p[i].y<<endl;
			s.push(p[i]);
		}
	}
	int k=0;
	while(!s.empty()){
		p[k++]=s.top();
		s.pop();
	}
	cout<<'('<<p[k-1].x<<','<<p[k-1].y<<')';
	for(int i=k-2;i>=0;i--){
		cout<<','<<'('<<p[i].x<<','<<p[i].y<<')';
	}
	cout<<endl;
	return 0;
}
