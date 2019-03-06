#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f[N];
int fenmu[N],fenzi[N];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;char c;
	cin>>t;
	//cout<<t;
	cin>>fenzi[0]>>c>>fenmu[0];
	int gcd1=gcd(fenzi[0],fenmu[0]);
	if(gcd1!=1){
		fenmu[0]/=gcd1;
		fenzi[0]/=gcd1;
	}
	int i=1;
	t--;
	while(t--){
		cin>>fenzi[i]>>c>>fenmu[i];
		gcd1=gcd(fenzi[i],fenmu[i]);
		if(gcd1!=1){
			fenmu[i]/=gcd1;
			fenzi[i]/=gcd1;
		}
		int gbs=(fenmu[i]*fenmu[i-1])/gcd(fenmu[i],fenmu[i-1]);
		//cout<<gbs<<endl;
		fenzi[i]=fenzi[i]*(gbs/fenmu[i])+fenzi[i-1]*(gbs/fenmu[i-1]);
		fenmu[i]=gbs;
		gcd1=gcd(fenzi[i],fenmu[i]);
		if(gcd1!=1){
			fenmu[i]/=gcd1;
			fenzi[i]/=gcd1;
		}
		i++;
	}
	if(fenmu[i-1]==1){
		cout<<fenzi[i-1];
	}else{
		cout<<fenzi[i-1]<<'/'<<fenmu[i-1]<<endl;
	}
	return 0;
}
