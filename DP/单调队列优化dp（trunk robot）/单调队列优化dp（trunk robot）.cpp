#include<iostream>
#include<cmath>
using namespace  std;
#define local;
const int maxn=1e5+5;
int dp[maxn];
int q[maxn];
int x[maxn],y[maxn],w[maxn],weight[maxn];
int dis[maxn];
int dist[maxn];
int n,C;
//dp[i]=dp[j]+dis[j+1]+dist[i]-dist[j+1]+dis[i];
//dp[j]-dist[j+1]+dis[j+1];
int func(int j){
	return dp[j]-dist[j+1]+dis[j+1];
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>C>>n;
		dist[0]=0;
		dis[0]=0;
		x[0]=0;
		y[0]=0;
		w[0]=0;
		q[0]=0;
		weight[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
			dis[i]=abs(x[i])+abs(y[i]);
			dist[i]=dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			weight[i]=weight[i-1]+w[i];
		}
		int front=1 ,rear=1;
		for(int i=1;i<=n;i++){
			while(front<=rear&&weight[i]-weight[q[front]]>=C){
				front++;
			}
			dp[i]=func(q[front])+dist[i]+dis[i];
			while(front<=rear&&func(i)<=func(q[rear])){
				rear--;
			}
			q[++rear]=i;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
// 单调队列维护：
// 1、 首位两端维护
// 2、 优化关键抓住哪个变量是不变，哪个是要变的；
// 3、  观察影响dp的两个因素：一个是 总重量，一个是 dp[j]要最小
//



