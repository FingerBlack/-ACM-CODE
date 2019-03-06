#include<iostream>
#include<string>
#include<stack>
#include<string.h>
using namespace  std;
#define local
const int N=100;
int f[N];
struct nn
{
	char c;
	int pos;
	nn(char a,int b){
		c=a;
		pos=b;
	}
};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	string s;
	while(cin>>s){
		cout<<s<<endl;
		stack<nn> sta;
		memset(f,0,sizeof f);
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				sta.push(nn(s[i],i));
			}else if(s[i]==')'){
				if(sta.empty()||sta.top().c==')'){
					sta.push(nn(s[i],i));
				}else{
					sta.pop();			
				}
			}
		}
		while(!sta.empty()){
			nn tem=sta.top();
			if(tem.c==')')f[tem.pos]=1;
			else f[tem.pos]=2;
			sta.pop();
		}
		for(int i=0;i<s.size();i++){
			if(f[i]==0)cout<<' ';
			else if(f[i]==1) cout<<'?';
			else if(f[i]==2) cout<<'$';
		}
		cout<<endl;
	}
	return 0;
}
