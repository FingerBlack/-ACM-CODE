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
const double exps=1e-4;
double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
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
	cin>>a>>b>>c>>d;
	//ax3+bx2+cx+d=0
	//3ax2+2bx+c=0
	double x1=(-2*b-sqrt(4*b*b-4*3*a*c))/6*a;
	double x2=(-2*b+sqrt(4*b*b-4*3*a*c))/6*a;
	printf("%.2lf %.2lf %.2lf\n",deal(-100,x1),deal(x1,x2),deal(x2,100));
	return 0;
}
