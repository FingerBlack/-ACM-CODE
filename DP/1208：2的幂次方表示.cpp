		#include<iostream>
		#include<string>
		using namespace  std;
		#define local
		const int N=100;
		int a[N];
		void f(int n){
			if(n==0){
				cout<<"2(0)";
				return;
			}else if(n==1){
				cout<<"2";
				return;
			}
			cout<<"2(";
			int k=0;
			int i=0;
			int a[N];
			while(n){
				if(n%2==1){
					a[k++]=i;
				}
				i++;
				n/=2;
			}
			for(int i=k-1;i>=1;i--){
				f(a[i]);
				cout<<"+";
			}
			f(a[0]);
			cout<<")";
		}
		int main()
		{
		#ifdef local
		freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
		freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
		#endif
			int n;
			cin>>n;
		//	cout<<n;
			int k=0;
			int i=0;
			while(n){
				if(n%2==1){
					a[k++]=i;
				}
				i++;
				n/=2;
			}
			//cout<<k;
			//cout<<a[0];
			for(int i=k-1;i>=1;i--){
			//	cout<<a[i]<<endl;
				f(a[i]);
				cout<<"+";
			}
			f(a[0]);
			return 0;
		}
