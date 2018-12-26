//
//  字符串处理_A.cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/11.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<map>
typedef unsigned long long ull;
using namespace  std;
#define local
const int maxn=1e5+10;
const int p=31;
string words[2*maxn];
 map<ull ,int > mm;
ull hash_table(string str){
    ull v=0;
    for(int i=0;str[i];i++){
        v=(v*p+(ull)str[i]);
    }
    return v&0x7fffffff;
}
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdout);
#endif
    std::ios::sync_with_stdio(false);
    string line;
    int k=0;
    while(getline(cin,line)&&line!="@END@"){
        int pos1=line.find('[');
        int pos2=line.find(']');
        string substr=line.substr(pos1+1,pos2-pos1-1);
        pos2+=2;
        
        string substr2=line.substr(pos2);
        words[++k]=substr;
        ull v1=hash_table(substr);
        ull v2=hash_table(substr2);
        mm[v2]=k;
        words[++k]=substr2;
        mm[v1]=k;
    }
    int n;
    cin>>n;
 //   map <string ,string > :: iterator it =mm.begin();
 //   for(;it!=mm.end();it++){
 //       cout<< it->first <<"  ["<<it->second<<"]"<<endl;
 //   }
//    cout<<n<<endl;
//    for(int i=0;i<20;i++){
//        cout<<words[i]<<endl;
 //   }
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,line);
     //   cout<<line<<endl;
        int pos1=line.find('[');
        int pos2=line.find(']');
        if(pos2!=-1&&pos1==0){
            line=line.substr(pos1+1,pos2-pos1-1);
        }
        ull v=hash_table(line);
  //      cout<<mm[v]<<endl;
       
       if(mm.find(v)==mm.end()){
            cout<<"what?"<<endl;
        }else{
            cout<<words[mm[v]]<<endl;
        }
    }
    return 0;
}
