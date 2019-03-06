#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
#define local
const int N=10001;
int f(int num){
	int k=0;
	while(num!=1){
		num=sqrt(num);
		k++;
	}
	return k;
}
int cmp(string a,string b){
	if(a.size()!=b.size()){
		if (a.size()<b.size()){
			return 1;
		}else{
			return 2;
		}
	}
	for(int i=0;i<a.size();i++){
		if(a[i]<b[i]){
			return 1;
		}
		if(a[i]>b[i]){
			return 2;
		}
	}
	return 2;
}
int s=65280+2+12+2;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int m=1;
	string line;
	while(cin>>line){
		//cout<<line<<endl;
		if(cmp(line,"4294967296")==2||line=="0"){
			cout<<"TAT"<<endl;
		}else if(cmp(line,"65536")==2&&cmp(line,"4294967296")==1){
			cout<<5<<endl;
		}else if(cmp(line,"256")==2&&cmp(line,"65536")==1){
			cout<<4<<endl;
		}else if(cmp(line,"16")==2&&cmp(line,"256")==1){
			cout<<3<<endl;
		}else if(cmp(line,"4")==2&&cmp(line,"16")==1){
			cout<<2<<endl;
		}else if(cmp(line,"2")==2&&cmp(line,"4")==1){
			cout<<1<<endl;
		}else if(cmp(line,"1")==2&&cmp(line,"2")==1){
			cout<<0<<endl;
		}	
	}
	
	return 0;
}
