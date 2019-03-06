#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int a[N][N]={0};
int b[N][8];
int k=0;
void f(int y){
	if(y==8){
	//	cout<<"No. "<<++k<<endl;
		for(int j=0;j<8;j++){
			for(int i=0;i<8;i++){
				if(a[i][j]==1){
					b[k][j]=i+1;
				}
			}
		}
		k++;
		return;
	}
	int flag=0;
	for(int i=0;i<8;i++){
		flag=0;
		for(int j=0;j<y;j++){
			if(a[i][j]==1){
				flag=1;
				break;
			}
		}
		for(int ii=i-1,jj=y-1;ii>=0&&jj>=0;ii--,jj--){
			if(a[ii][jj]==1){
				flag=1;
				break;
			}
		}
		for(int ii=i+1,jj=y-1;ii<8&&jj>=0;ii++,jj--){
			if(a[ii][jj]==1){
				flag=1;
				break;
			}
		}
		if(!flag){
			a[i][y]=1;
			f(y+1);
			a[i][y]=0;
		}
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
	f(0);
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<8;i++){
			cout<<b[n-1][i];
		}
		cout<<endl;
	}
	return 0;
}
