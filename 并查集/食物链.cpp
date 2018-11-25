#include<iostream>
using namespace  std;
#define local;
const int maxn=1e5+6;
int n,k,x,y,d;
struct node{
	int pre;
	int relation;
}f[maxn];
int find(int  i){
	if(f[i].pre==i){
		return i;
	}
	int tem=f[i].pre;
	f[i].pre=find(tem);
	f[i].relation=(f[i].relation+f[tem].relation)%3;
	return f[i].pre;
}
void init(){
	for(int i=0;i<n;i++){
		f[i].pre=i;
		f[i].relation=0;
	}
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	while(cin>>n>>k){
		int fff=0;
		init();
		for(int i=0;i<k;i++){

			scanf("%d%d%d",&d,&x,&y);
			if(x>n||y>n){
				fff++;
				continue;
			}
			if(d==2&&x==y){
				fff++;
				continue;
			}
			int dx=find(x);
			int dy=find(y);
			if(dx!=dy){
				f[dy].pre=dx;
				f[dy].relation=(f[x].relation+d-1+3-f[y].relation)%3;
			}else{
				int relation=(3-f[x].relation+f[y].relation)%3;
				if((d-1)!=relation){
					fff++;
					continue;
				}
			}
			
		}
		cout<<fff<<endl;
	}
	return 0;
}
