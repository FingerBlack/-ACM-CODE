#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace  std;
#define local
const int N=10001;
//nt f[N];
const double exps=1e-7;
double a,b,c,d;
double f(double x){
	return x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
}
double deal(double x1,double x2){
	while(1){
		double mid=(x1+x2)/2;
		if(f(mid)<exps&&f(mid)>-exps){
			return mid;
		}else if(f(x1)*f(mid)<0){
			x2=mid;
		}else if(f(x2)*f(mid)<0){
			x1=mid;
		}
	//	cout<<mid<<endl;
	}
	
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	//cin>>a>>b>>c>>d;
	//ax3+bx2+cx+d=0
	//3ax2+2bx+c=0
	printf("%.6lf\n",deal(1.5,2.4));
	return 0;
}
