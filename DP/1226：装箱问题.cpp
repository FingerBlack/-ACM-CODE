#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=10001;
int f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif

	while(cin>>f[0]>>f[1]>>f[2]>>f[3]>>f[4]>>f[5]){
		if(!f[0]&&!f[1]&&!f[2]&&!f[3]&&!f[4]&&!f[5]){
			break;
		}
		int count=0;
		while(f[5]!=0){
			f[5]--;
			count++;
		}
		while(f[4]!=0){
			if(f[0]>=11){
				f[0]-=11;
			}else{
				f[0]=0;
			}
			count++;
			f[4]--;
		}
		while(f[3]!=0){
			int tem=20;
			f[3]--;
			if(f[1]>=5){
				f[1]-=5;
				tem=0;
			}else{
				f[1]=0;
				tem-=f[1]*4;
			}
			if(f[0]>=tem){
				f[0]-=tem;
			}else{
				f[0]=0;
			}
			count++;
		}
		while(f[2]!=0){
			int tem=27;
			if(f[2]>=4){
				f[2]-=4;
				tem=0;
			}else{
				if(f[2]==3){
					tem=9;
					if(f[1]>=1){
						f[1]-=1;
						tem-=4;
					}else{
						f[1]=0;
						tem-=4;
					}
				}else if(f[2]==2){
					tem=18;
					if(f[1]>=3){
						f[1]-=3;
						tem=6;
					}else{
						f[1]=0;
						tem-=f[1]*4;
					}
				}else if(f[2]==1){
					tem=27;
					if(f[1]>=5){
						f[1]-=5;
						tem=7;
					}else{
						f[1]=0;
						tem-=f[1]*4;
					}
				}
				f[2]=0;
			}
			if(f[0]>=tem){
				f[0]-=tem;
			}else{
				f[0]=0;
			}
			count++;
		}
		while(f[1]!=0){
			int tem=36;
			if(f[1]>=9){
				f[1]-=9;
				tem=0;
			}else{
				f[1]=0;
				tem-=f[1]*4;
			}
			if(f[0]>=tem){
				f[0]-=tem;
			}else{
				f[0]=0;
			}
			count++;
		}
		while(f[0]!=0){
			int tem=36;
			if(f[0]>=36){
				f[0]-=36;
			}else{
				f[0]=0;
			}
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
