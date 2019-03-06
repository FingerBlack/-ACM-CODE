	#include<iostream>
	#include<string>
	#include<stdio.h>
	#include<algorithm>
	using namespace  std;
	//#define local
	typedef long long ll;
	const int N=1e5+10;
	int f[N];
	struct node
	{
		ll a,c;
	}nn[N];
	struct node1
	{
		ll c;
		int index;
		bool operator<(const node1 n)const{
			if(c==n.c){
				return index<n.index;
			}
			return c<n.c;
		} 
	}nn1[N];
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&nn[i].a);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&nn[i].c);
			nn1[i].c=nn[i].c;
			nn1[i].index=i;
		}
		sort(nn1+1,nn1+1+n);
	//	for(int i=1;i<=n;i++){
	//		cout<<nn1[i].c<<" "<<nn1[i].index<<endl;
	//	}
		int kind,num;
		int minn=1;
		while(m--){
			ll cost=0;
			scanf("%d%d",&kind,&num);
			//for(int i=1;i<=n;i++){
		//		cout<<nn[i].a<<" ";
	//		}
	//		cout<<endl;

			if(nn[kind].a>num){
				nn[kind].a-=num;
				cost+=nn[kind].c*num;
				num=0;
			}else{
				num-=nn[kind].a;
				cost+=nn[kind].c*nn[kind].a;
			//	cout<<cost<<endl;
				nn[kind].a=0;
				if(kind==nn1[minn].index) minn++;
				while(minn!=n+1&&num!=0){
					int index=nn1[minn].index;
					//cout<<index<<endl;
					if(num>=nn[index].a){
						num-=nn[index].a;
						cost+=nn[index].c*nn[index].a;

				//		cout<<cost<<endl;
						nn[index].a=0;
						minn++;
					}else{
						nn[index].a-=num;
						cost+=nn[index].c*num;
			//			cout<<cost<<endl;
						num=0;
					}
					if(num==0){
						break;
					}
				}
			}
			//cout<<cost<<endl;
			if(num!=0){
				cost=0;
			}
			cout<<cost<<endl;
		}
		return 0;
	}
