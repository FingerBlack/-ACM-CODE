#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
const double pi=acos(-1.0);
#define local
const double Exp=1e-5;
const int N=10001;
//int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	double L,n,C;
	cin>>L>>n>>C;
	double l1=(1+n*C)*L;
	L*=L;
	double l=0,r=pi,rr,l2;
	double mid;
	while(r-l>1e-12){
		mid=(l+r)/2;
		rr=l1/mid;
		//cout<<l<<" "<<r<<" "<<L<<" "<<l2<<endl;
		l2=2*rr*rr-2*rr*rr*cos(mid);
		//cout<<L2<<" "<<L<<endl;
		if(l2>L){
			l=mid;
		}else if(L>l2){
			r=mid;
		}else{
			break;
		}
	}
	//cout<<rr<<" "<<mid<<" "<<l2<<endl;
	printf("%.3lf\n",rr-rr*rr*sin(mid)/sqrt(l2));
	return 0;
}
//l1=r*a;
//l*l=r^2+r^2-2r^2cosa;
//r-1/2*r^2*sin(a)/l2;