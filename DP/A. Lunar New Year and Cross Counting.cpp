#include<iostream>
#include<string>
#include<stdio.h>
using namespace  std;
//#define local
const int N=10001;
char s[N][N];
int dir[5][2]={{0,0},{-1,-1},{1,-1},{1,1},{-1,1}};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int flag=0;
			for(int k=0;k<5;k++){
				int cx=i+dir[k][0];
				int cy=j+dir[k][1];
				if(cx>=0&&cx<n&&cy>=0&&cy<n&&s[cx][cy]=='X'){
					flag++;
				}

			//	if(i==2&&j==2){
			//	cout<<s[i][j];
			//	cout<<flag<<endl;
			//	}
			}
			if(flag==5){
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
