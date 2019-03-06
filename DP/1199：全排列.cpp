#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace  std;
#define local
const int N=100;
char s[N];
void swaps(char *i,char*j){
	char tem=*i;
	*i=*j;
	*j=tem;
}
void reverses(char *a,char*b){
	char *i=a;
	char *j=b-1;
	while(i<j){
		swaps(i,j);
		i++;
		j--;
	}
}
bool f(char *first, char *end){
	if(first==end) return false;
	if(first+1==end) return false;
	char *i=end;
	i--;
	for(;;){
		
		char *ii=i;
		i--;
		if(*i<*ii){
			char *j=end;
			while(*i>=*--j);
			swaps(i,j);
			reverses(ii,end);
			return true;	
		}
		if(i==first) {reverses(first,end);return false;}
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%s",s);
	int len=strlen(s);
	//next_permutations(s,s+len);
	//printf("%s\n",s);
	do{
		printf("%s\n",s);
	}while(f(s,s+len));
	return 0;
}
