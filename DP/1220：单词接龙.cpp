	#include<iostream>
	#include<string>
	#include<algorithm>
	#include<string.h>
	using namespace  std;
	#define local
	const int N=100;
	string s[N];
	int n; 	
	int maxn=0;
	int vis[N];
	int check(string a,string b){
		for(int i=a.size();i>=1;i--){
			if(a[i]==b[0]){
				int j=0;
				int ii=i;
				while(a[ii]==b[j]&&ii<a.size()&&j<b.size()){ii++;j++;}
				if(ii==a.size()){
					return j;	
				}
			}
		}
		return 0;
	}
	void dfs(int x,int sum){
		int flag=0;
		for(int i=0;i<n;i++){
			int len=check(s[x],s[i]);
			if(vis[i]<2&&len){
				flag=1;
				vis[i]++;
				dfs(i,sum+s[i].size()-len);
				vis[i]--;
			}
		}
		if(!flag){
			//cout<<maxn<<endl;
			maxn=max(sum,maxn);
			//cout<<maxn<<endl;
		}
	}
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		char c;
		cin>>c;
		
		for(int i=0;i<n;i++){
	              
			if(s[i][0]==c){
		 		memset(vis,0,sizeof vis);
				vis[i]=1;
				dfs(i,s[i].size());
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
