//
//  字符串处理_D(tires).cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/14.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<unordered_map>
#include<map>
using namespace std;
int countt=0;
const int p=31,maxn=2005;
int dp[maxn][maxn];
typedef unsigned int ull;

#define local
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdout);
#endif
//    time_t start ,end ;
//    double cost;
    int t,q,l,r;
    cin>>t;
    string line,substr;
    
 //   time(&start);
    while (t--) {
       
        cin>>line;
        cout<<line.length()<<endl;
        scanf("%d",&q);
        int len=line.length();
        memset(dp, 0, sizeof dp);
        unordered_map<ull,int> slots;
        for(int j=0;j<len;j++){
            ull v=0;
            for(int i=j;i>=0;i--){
                if(i==j) v=(ull)line[i];
                else v=(v*p+(ull)line[i]);
                unordered_map<ull, int> :: iterator it=slots.find(v);
                if(it==slots.end()){
                    slots.insert(make_pair(v, i));
                }else{
                    dp[it->second][j]--;
                    it->second=i;
                 }
                dp[i][j]++;
                dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
        }
        for(int m=0;m<q;m++){
            scanf("%d%d",&l,&r);
            cout<<dp[l-1][r-1]<<endl;
        }
    }
    return 0;
}
