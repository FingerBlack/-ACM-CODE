#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<map>
#include<set>
#include<math.h>
#include<queue>
using namespace  std;
#define local
const int N=30;
int n,a[N][N],x;
long long sum=0;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	map <int,int >mm;
	queue<int >qq;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			mm[x]++;
		}
	}
	if(n%2==0){
		int flag=0;
		for(map<int ,int >::iterator it=mm.begin();it!=mm.end();it++){
		//	cout<<it->first<<' '<<it->second<<endl;
			if(it->second%4!=0){
				flag=1;
				break;
			}
		}
		map<int ,int >::iterator it=mm.begin();
		if(flag==1){
			cout<<"NO"<<endl;
		}else{
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					a[i][j]=a[n+1-i][j]=a[i][n+1-j]=a[n+1-i][n+1-j]=it->first;
					it->second-=4;
					if(it->second==0){
						it++;
					}
				}
			}
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(j!=1)cout<<' ';
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
	}else{
		
		int flag=0,center=-1;
		for(map<int ,int >::iterator it=mm.begin();it!=mm.end();it++){
			//cout<<it->first<<' '<<it->second<<endl;
			int m=it->second/4;
			while(m--){
				qq.push(it->first);
				sum++;
			}
			if(it->second%2!=0){
			
				flag++;
				if(flag==2){
					break;
				}
				center=it->first;
			}
		}
		//cout<<sum<<endl;
		if(sum<(n/2)*(n/2)||flag==2||flag==0){
			cout<<"NO"<<endl;
		}else{
			a[n/2+1][n/2+1]=center;
			mm[center]--;
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					a[i][j]=a[n+1-i][j]=a[i][n+1-j]=a[n+1-i][n+1-j]=qq.front();
					mm[qq.front()]-=4;
					qq.pop();
				}
			}

			map<int ,int >::iterator it=mm.begin();
			while(it!=mm.end()&&it->second==0){
				it++;
			}
			for(int i=1;i<=n/2;i++){
				a[n/2+1][i]=a[n/2+1][n+1-i]=it->first;
				it->second-=2;
				while(it!=mm.end()&&it->second==0){
					it++;
				}
			}
			for(int i=1;i<=n/2;i++){
				a[i][n/2+1]=a[n+1-i][n/2+1]=it->first;
				it->second-=2;
				while(it!=mm.end()&&it->second==0){
					it++;
				}
			}
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(j!=1)cout<<' ';
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
				
	}
	return 0;
}
