	#include<iostream>
	#include<string>
	using namespace  std;
	#define local
	const int N=100;
	int f[N];
	void hannoi(int n,char a,char b,char c){
		if(n==1){
			printf("%c->1->%c\n",a,c);
		}else{
			hannoi(n-1,a,c,b);
			printf("%c->%d->%c\n",a,n,c);
			hannoi(n-1,b,a,c);
		}
	} 
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n;
		char a,b,c;
		cin>>n>>a>>b>>c;
		hannoi(n,a,c,b);
		return 0;
	}
