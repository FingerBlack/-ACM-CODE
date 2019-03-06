#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace  std;
#define local
const int N=1001;
//double f[N];
double sum=0;
double summ=0;
struct sss
{
	double a;
	int b;
	bool operator <(const sss n)const{
		return a<n.a;
	}
}f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f[i].a;
		f[i].b=i+1;
	}
	sort(f,f+n);
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<f[i].b;
	}
	cout<<endl;
	for(int i=0;i<n-1;i++){
		sum=f[i].a+sum;
		summ=sum+summ;
		//cout<<f[i]<<endl;
	}
	printf("%.2lf\n",summ/n);
	return 0;
}
