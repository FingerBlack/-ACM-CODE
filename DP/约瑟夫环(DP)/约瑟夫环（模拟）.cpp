#include<iostream>
using namespace  std;
#define local;
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	int x=0;
	int n,k,m;
	while(cin>>n>>m>>k){
		x=0;
		for(int i=2;i<=n;i++){
			x=(x+m)%i;
			//cout<<(x+k)%i<<endl;
			//cout<<x<<endl;
		}
		cout<<(x+k)%n<<endl;
	}
	return 0;
}
