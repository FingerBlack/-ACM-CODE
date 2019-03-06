#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int n;
int f[N];
int vis[N]={0};
int maxn;
int sum=0;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void dfs(int x,int sign){

	if(vis[x]!=0) {dfs(x+1,sign);}
	else{
		if(x==n||sum==n){
			return;
		}
		int flag=0;
		for(int j=0;j<x;j++){
			if(vis[j]==sign){
				if(gcd(f[x],f[j])!=1){
					flag=1;
					break;
				}
			}
		}	
		if(!flag){
			sum++;
			//cout<<sign<<endl;
			vis[x]=sign;
		}	
		dfs(x+1,sign);
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
		cin>>f[i];
	}
	int k=0;
	while(1){
		if(sum==n){
			break;
		}
		for(int i=0;i<n;i++){
			if(vis[i]==0){
			//cout<<sum<<endl;
				vis[i]=++k;
				sum++;
				dfs(i+1,k);
				break;
			}
		}
	/*	for(int i=0;i<n;i++){
			cout<<vis[i]<<" ";
		}
		cout<<endl;*/
	}
	
	
	cout<<k<<endl;
	return 0;
}
