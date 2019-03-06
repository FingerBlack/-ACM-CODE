#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
char a[N][N]={0};
int b[N][N];
int n,k;
int sum;
void f(int y,int l){

	if(l==k){
		sum++;
		return;
	
	}
	if(y==n){
		return;
	}
	int flag=0;
	for(int i=0;i<n;i++){
		if(a[i][y]=='#'){
			flag=0;
			for(int j=0;j<y;j++){
				if(b[i][j]==1&&a[i][j]=='#'){
					flag=1;
					break;
				}
			}
			if(!flag){
				b[i][y]=1;
				f(y+1,l+1);
				b[i][y]=0;
			}
		}
	}
	f(y+1,l);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	while(cin>>n>>k){
		
		if(n==-1&&k==-1){
			break;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		sum=0;
		f(0,0);
		cout<<sum<<endl;
	}
	return 0;
}
