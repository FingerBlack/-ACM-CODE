#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long 
const int Max = 1000000 + 10;
int cnt[Max];
int dt[Max];
LL a[Max];
int n;
int maxn = 0;
int lowbit(int x){
	return x&-x;
}
LL sum(int i){
	LL res=0;
	while (i>0)
	{
		res += cnt[i];
		i -= lowbit(i);
	}
	return res;
}
void add(int x, int v){
	while (x <= maxn){
		
		cnt[x] += v;
		x += lowbit(x);
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		maxn = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &dt[i]);
			maxn = max(maxn,dt[i] );
		}
		for (int i = 1; i <= n; i++){
			int m = dt[i];
			add(m,1);
			a[i] = sum(m);
		}
		LL x1, x2, y1, y2;
		LL SSUM=0;
		for (int i = 2; i < n; i++){
			x1 = a[i]-1;
			y1 = i - a[i];
			x2 = sum(dt[i])-a[i];
			y2 = n - sum(dt[i]) - y1;
			SSUM += x1*y2;
			SSUM += x2*y1;
		}
		printf("%lld\n", SSUM);
	}
	return 0;
}