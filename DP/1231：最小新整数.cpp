#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace  std;
#define local
const int N=1000;
//int f[N];
bool vis[N]={0};
char s[N];
int n;
struct sss
{
	char c;
	int pos	;
	bool operator <(const sss &n)const{
		return c<n.c;
	}
}f[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%s",s);
	scanf("%d",&n);
	int len=strlen(s);
	for(int j=0;j<n;j++){
	//	for(int i=0;i<len-j;i++){
	//		cout<<s[i];
	//	}
	//	cout<<endl;
	for(int i=0;i<len-j-1;i++){
			if(s[i]>s[i+1]){
				for(int k=i;k<len-j-1;k++){
					s[k]=s[k+1];
				}	
				break;
			}
		}
		
	}
	int flag=0;
	for(int i=0;i<len-n;i++){
		if(s[i]!='0'){
			flag=1;
		}
		if(flag){
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}