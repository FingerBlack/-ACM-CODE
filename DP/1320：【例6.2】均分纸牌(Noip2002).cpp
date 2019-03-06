#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=101;
int n;
int f[N];
int sum;
int maxx(){
	int x=0;
	for(int i=0;i<n;i++){
		if(f[i]>f[x]){
			x=i;
		}
	}
	return x;
}
int sumof(int l, int r){
	int count=0;
	for(int i=l;i<=r;i++){
		count+=f[i];
	}
//	cout<<count<<endl;
//	cout<<sum<<endl;
//	cout<<l<<" "<<r<<endl;
//	cout<<(l+r+1)*sum<<endl;
	return count-(r-l+1)*sum;
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
		sum+=f[i];
	}
	sum/=n;
	int maxn=maxx();
	int count=0;
	while(f[maxn]!=sum){
		int lc=0,rc=0;
		if(maxn!=0)lc=sumof(0,maxn-1);
		if(maxn!=n-1)rc=sumof(maxn+1,n-1);
		//cout<<lc<<endl;
		//cout<<rc<<endl;
		if (lc<0||maxn==n-1)
		{
			if(-lc>=f[maxn]){
				f[maxn-1]+=(f[maxn]);
				f[maxn]=0;
			}else{
				f[maxn-1]+=(-lc);
				f[maxn]+=lc;
			}
		}else if(rc<0||maxn==0){
			if(-rc>=f[maxn]){
				f[maxn+1]+=(f[maxn]);
				f[maxn]=0;
			}else{
				f[maxn+1]+=(-rc);
				f[maxn]+=rc;
			}
		}else{
			break;
		}
		count++;
		maxn=maxx();
	//	for(int i=0;i<n;i++){
	//		cout<<f[i]<<" ";
	//	}
	//	cout<<endl;
	}
	cout<<count<<endl;
	return 0;
}
