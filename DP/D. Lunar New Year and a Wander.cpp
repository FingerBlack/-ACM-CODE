	#include<iostream>
	#include<string>
	#include<stdio.h>
	#include<algorithm>
	#include<vector>
	#include<queue>
	using namespace  std;
	//#define local
	const int N=1e5+10;
	bool vis[N]={0};
	vector<int >map[N];
	priority_queue<int,vector<int>,greater<int> > q;
	void dfs(){
		cout<<'1';
		vis[1]=1;
		for(int i=0;i<map[1].size();i++){
			q.push(map[1][i]);
		}
		while(!q.empty()){
			int to=q.top();
			q.pop();
			if(!vis[to]){
				vis[to]=1 				cout<<" "<<to;
				for(int i=0;i<map[to].size();i++){
					q.push(map[to][i]);
				}
			}
		}
	}
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n,m;
		int x,y;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			map[x].push_back(y);
			map[y].push_back(x);
		}
		dfs();
		return 0;
	}
