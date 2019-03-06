#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace  std;
#define local
const int N=100;
double f(){
	char s[N];
	scanf("%s",s);
	switch(s[0]){
		case '+': return f()+f();
		case '-': return f()-f();
		case '*': return f()*f();
		case '/': return f()/f();
		default : return atof(s);
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	double ans=f();
	printf("%lf\n",ans);
	return 0;
}
