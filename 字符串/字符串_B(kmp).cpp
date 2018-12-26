//
//  字符串_B(kmp).cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/12.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
const int maxn=1e6;
using namespace  std;
int nnext[maxn];
#define local
void getnext(string line){
    int i=-1,j=0;
    int len=line.length();
    nnext[0]=-1;
    while(j<len-1){
        if(i==-1||line[i]==line[j]){
            nnext[++j]=++i;
        }else{
            i=nnext[i];
        }
    }
}
int kmp(string s1,string s2){
    int i=0,j=0;
    int len1=s1.length();
    int len2=s2.length();
    getnext(s2);
    int count=0;
    while(i<len1&&j<len2){
        if(j==-1||s1[i]==s2[j]){
            i++;
            j++;
            if(j==len2){
                j=0;
                count++;
            }
        }else{
            j=nnext[j];
        }
    }
    return count;
}
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdout);
#endif
    string line1,line2;
    while(cin>>line1&&line1!="#"){
        cin>>line2;
        cout<<kmp(line1,line2)<<endl;
    }
    return 0;
}
