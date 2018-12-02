#include<iostream>
#include<string>
#include<string.h>
using namespace  std;
#define local;
const int maxn=1e6+10;
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
	int max=0;
	while(i<len1&&j<len2){
		if(j==-1||s1[i]==s2[j]){
			//cout<<i<<" "<<j<<endl;
			i++;
			j++;
			if(j>max){
				max=j;
			}
		}else{
			j=Next[j];
		}
	}
	return max;
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	int t; 
	cin>>t;
	string line;
	while(t--){
		memset(Next,0,sizeof Next);
		cin>>line;
		int len=line.size();
		string str;
		int i=0;
	//	cout<<"len"<<len<<endl;
		int flag=0;
		int l=-1,r=-1;
		string line1,line2;
		for(i=0;i<len;i++){
			if(3*(i+1)>len){
					break;
			}
			if(line[i]==line[len-1]&&line[len-1-i]==line[0]){
				//cout<<"i="<<i<<endl;]	
				line1=line.substr(0,i+1);
				line2=line.substr(len-1-i);
				if(line1==line2){
					l=i+1;
					r=len-1-i;
				}
			}
		}
		
		if(l==-1||r==-1){
			cout<<0<<endl;
		}else{
			str=line.substr(0,l);
			cout<<kmp(line,str)<<endl;
		}	
	}
	return 0;
}
