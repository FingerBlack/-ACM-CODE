#include<iostream>
#include<string>
#include<string.h>
#include<cstring>

using namespace  std;
#define local;
const int maxn=1e5;
int Next[maxn];
void getnext(string str){
	//cout<<1<<endl;
	int i=0;
	int j=-1;
	Next[0]=-1;
	int len=str.length();
//	int []next=new int[len+1];
	while(i<len-1){
		if(j==-1||str[i]==str[j]){
			Next[++i]=++j;
		//cout<<i<<endl;
		}else{
			j=Next[j];
		}
	}
	
}
int kmp(string s1,string s2){
	int i=0,j=0;
	int len1=s1.length();
	int len2=s2.length();
	//cout<<1;
	getnext(s2);
	//
//	for(int i=0;i<len2;i++){
//		cout<<Next[i]<<" ";
//	}
	
	while(i<len1&&j<len2){
		if(j==-1||s1[i]==s2[j]){
			//cout<<i<<" "<<j<<endl;
			i++;
			j++;
		}else{
			j=Next[j];
		}
	}
	if(j==len2){
	//	cout<<i<<" "<<j<<endl;
		//cout<<i-j<<endl;
		return i-j;
	}else{
		return -1;
	}

}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/字符串/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/字符串/out","wt+",stdout);
#endif
	string line1;
	string line2;
	while(cin>>line1>>line2){
		//cout<<line1<<endl;
		cout<<kmp(line1,line2)<<endl;
	//	cout<<line2<<endl;
	}
	return 0;
}
