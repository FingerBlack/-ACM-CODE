#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=10001;
char f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		f[i]='o';
	}
	for(int i=n+1;i<=2*n;i++){
		f[i]='*';
	}
	for(int i=2*n+1;i<=2*n+2;i++){
		f[i]='-';
	}
	f[2*n+3]='\0';
	int Case=0;
	int tem=2*n+2;
	printf("step %d:%s\n",Case++, f+1);
	while(1){
		if(n>3){
			if(f[n]=='o'&&f[n+1]=='*'){
				f[n]=f[n+1]='-';
				f[2*n+1]='o';
				f[2*n+2]='*';
				printf("step%2d:%s\n",Case++, f+1);
			}
			if(f[n]=='-'&&f[n+1]=='-'){
				if(n>4){
					f[n]=f[n+1]='*';
					f[2*n-1]=f[2*n]='-';
					printf("step%2d:%s\n",Case++, f+1);
				}
				n--;
			}
		}else{
			char s[4][100]={
				"ooo*o**--",
				"o--*o**oo",
				"o*o*o*--o",
				"--o*o*o*o"
			};
			for(int i=0;i<4;i++){
				printf("step%2d:",Case++);
				for(int j=0;j<9;j++){
					printf("%c",s[i][j]);
				}
				for(int j=10;j<=tem;j++){
					printf("%c",f[j]);
				}
				cout<<endl;
			}
			break;
		}
		
	}
	return 0;
}
