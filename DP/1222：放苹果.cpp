#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f[N];
int sum=0;
int m,n;
void dfs(int i,int j,int nn){
	if(nn==0){
		sum++;
		//cout<<endl;
		return;
	}
	if(j==n){
		//cout<<endl;
		 return;
	}
	for(int k=i;k<=nn;k++){
		//cout<<nn<<": "<<k<<" ";
		dfs(k,j+1,nn-k);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		sum=0;
		cin>>m>>n;
		dfs(1,0,m);
		cout<<sum<<endl;
	}
	return 0;
}
