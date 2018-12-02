#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max = 100000 + 10;
int dp[Max][50];
int cnt[Max];
int a[Max];
int righ[Max],lef[Max],num[Max];
void unit(int len){
	for (int i = 1; i <= len; i++){
		dp[i][0] = cnt[i];
	}
	for (int j = 1; (1 << j) <= len + 1; j++){
		for (int i = 1; i + (1 << j) - 1 <= len; i++){
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j-1))][j-1]);
		}
	}
}
int RMQ(int l, int r){
	int k = 0;
	while ((1 << (k+1)) <= r - l + 1) k++;
	return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF&&n){
		int m;
		scanf("%d", &m);
		memset(cnt, 0, sizeof(cnt));

		scanf("%d", &a[1]);
		int len = 1;
		cnt[len] = 1;
		lef[1] = 1;
		num[1] = len;
		for (int i = 2; i <= n; i++){
			scanf("%d", &a[i]);
			if (a[i] == a[i - 1]){
				cnt[len]++;
				num[i] = len;
			}
			else{
				righ[len] = i - 1;
				len++;
				lef[len] = i;
				num[i] = len;
				cnt[len] = 1;
			}
		}
		unit(len);
		int x, y;
		while (m--){
			scanf("%d%d", &x, &y);
			if (num[x] == num[y]){
				printf("%d\n", y - x + 1);
			}
			else{
				int ans = 0;
				if (num[x] + 1 <= num[y] - 1){
					ans = RMQ(num[x] + 1, num[y] - 1);
				}
				ans = max(ans, max(righ[num[x]] - x + 1, -lef[num[y]] + y + 1));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}