
//
//  Toposort.cpp
//  RUN2
//
//  Created by 陈纪双 on 2018/12/6.
//  Copyright © 2018 陈纪双. All rights reserved.
//


#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace  std;
const int maxn=1e3;
vector < int > Toposort;
bool vis[maxn];
int theme=0;
struct node {
    string num;
    string name;
    int time;
    bool isvis;
    vector <int> next;
    node(){
        isvis=false;
    }
}nn[maxn];
void addedge(int a,int b){
    nn[a].next.push_back(b);
    nn[b].isroot=false;
}
void dfs(int i){
    vis[i]=1;
    for(int j=0;j<nn[i].next.size();j++){
        int to=nn[i].next[j];
        if(!vis[to]){
            dfs(to);
        }
    }
    Toposort.push_back(i);
}
map<string ,int > mm;
#define local
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/RUN/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/RUN/out","wt+",stdout);
#endif
    string line;
    string str;
    int k=0;
    int computer=0;
    vector< int > decide[10];
    while(getline(cin,line)){
        stringstream input(line);
        input>>str;
        mm[str]=++k;
        nn[k].num=str;
        input>>str;
        nn[k].name=str;
        int tem;
        input>>tem;
        nn[k].time=tem;
        input>>tem;
        if(tem==0){
            computer=k;
        }else{
            decide[tem-1].push_back(k);
        }
        char c;
        while(input>>str){
            stringstream cnt(str);
            cnt>>c;
            cnt>>tem;
            addedge(k,tem);
        }
    }
    for(int i=computer;i>=1;i--){
        if(!vis[i]){
            dfs(i);
        }
    }
    int count[8]={5,6,2,5,4,4,4,0};
    int i=0;
    for(int j=0;j<8;j++){
        cout<<"第";
        printf("%d",j+1);
        cout<<"学期:";
        int len=i+count[j]-1;
     //   cout<<len;
        for(;i<=len;i++){
            cout<<" "<<nn[Toposort[i]].name;
        }
       // cout<<decide[j].size()<<endl;
        for(int h=0;h<decide[j].size();h++){
            cout<<" "<<nn[decide[j][h]].name;
        }
       // cout<<decide[j][h];
       // nn[Toposort[j]].num<<" "<<
      
        cout<<endl;
    }
    return 0;
}
