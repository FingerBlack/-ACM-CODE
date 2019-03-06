#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=10000;
int a[N];
bool f[N+1][101]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
 	int n,k;
 	/*cin>>n>>k;
	for(int i=0;i<n;i++){
		sca
	}*/
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]%=k;
	}
	
	f[1][a[1]]=true;
	for(int i=2;i<=n;i++){
		for(int j=0;j<k;j++){
			if(f[i-1][j]){
				f[i][(j+a[i])%k]=true;
				f[i][(j-a[i]+k)%k]=true;
			}
		}
	}
	if(f[n][0]){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
