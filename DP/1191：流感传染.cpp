#include<iostream>
#include<string>
#include <queue>
using namespace  std;
#define local
typedef long long ll;
const int N=100;
char s[N][N];
int f[N][N];
int cx,cy;
int point[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool check(int x,int y){
	for(int i=0;i<9;i++){
		if(x==point[i][0]&&y==point[i][1])
			return false;
	}
	return true;
}

int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	queue < pair <int ,int > > q;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>s[i][j];
			if(s[i][j]=='@'){
				q.push(make_pair(i,j));
			}
		}
	}
	cin>>m;
	for(int k=0;k<m-1;k++){
		int size=q.size();
		for(int i=0;i<size;i++){
			pair<int ,int >tem =q.front();
			q.pop();
			for(int t=0;t<4;t++){
				int cx=tem.first+point[t][0];
				int cy=tem.second+point[t][1];						//cout<<cx<<" "<<cy;
				if(cx>=0&&cx<n&&cy>=0&&cy<n&&s[cx][cy]=='.'){
					s[cx][cy]='@';
					q.push(make_pair(cx,cy));
				}
			}
		}
	/*	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<s[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	*/
	}

	int sum=0;
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='@'){
					sum++;
				}
		}
	}
	cout<<sum<<endl;
	return 0;
}
