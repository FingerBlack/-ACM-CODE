//
//  main.cpp
//  Dijkstra (堆优化版本)
//
//  Created by 陈纪双 on 2018/12/5.
//  Copyright © 2018 陈纪双. All rights reserved.
#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace  std;
#define local
typedef long long  LL;
const int maxn =1e6+5;
const int inf=1e9;
//int map[maxn][maxn];
bool vis[maxn];
long long  d1[maxn];
long long  d2[maxn];
int n,m;
struct edge
{
    int t;
    int next;
    long long v;
    //    edge(){}
}e1[maxn],e2[maxn];
int cnt=0,cnt2=0;
int head[maxn],head2[maxn];
void add_edge(int u, int v, long long  w) //我们用邻接表来建图
{
    e1[cnt].t = v;
    e1[cnt].v = w;
    e1[cnt].next = head[u];
    head[u] = cnt ++;
    e2[cnt2].t = u;
    e2[cnt2].v = w;
    e2[cnt2].next = head2[v];
    head2[v] = cnt2 ++;
}
priority_queue< pair<int ,long long > > que;
void  dijkstra(){
    for(int i=0;i<n;i++){
        d1[i]=d2[i]=inf;
    }
    memset(vis,0,sizeof vis);
    d1[0]=0;
    d2[0]=0;
    que.push(make_pair(0, 0));
    while(!que.empty()){
        pair<int, long long > tem=que.top();
        que.pop();
        int u=tem.first;
        if(vis[u]){
            continue;
        }
        LL pre=-tem.second;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e1[i].next){
            int to=e1[i].t;
            long long  w=e1[i].v;
            LL len=w+pre;
            //        for(int i=0;i<n;i++){
            //        cout<<vis[i]<<endl;
            //    }
            //    cout<<u<<" "<<w<<" "<<to<<endl;
            if(d1[to]>len){
                d1[to]=len;
                que.push(make_pair(to,-len));
            }
        }
        //     for(int i=0;i<n;i++){
        //       cout<<d1[i]<<" ";
        // }
        //       cout<<endl;
    }
    memset(vis,0,sizeof vis);
    que.push(make_pair(0, 0));
    while(!que.empty()){
        pair<int, long long > tem=que.top();
        que.pop();
        int u=tem.first;
        if(vis[u]){
            continue;
        }
        LL pre=-tem.second;
        vis[u]=1;
        for(int i=head2[u];i!=-1;i=e2[i].next){
            int to=e2[i].t;
            long long  w=e2[i].v;
            LL len=w+pre;
            //        for(int i=0;i<n;i++){
            //        cout<<vis[i]<<endl;
            //    }
            //    cout<<u<<" "<<w<<" "<<to<<endl;
            if(d2[to]>len){
                d2[to]=len;
                que.push(make_pair(to,-len));
            }
        }
        //       for(int i=0;i<n;i++){
        //         cout<<d2[i]<<" ";
        //      }
        //    cout<<endl;
    }
}

int main()
{
#ifdef local
    freopen("in","r",stdin);
    freopen("out","wt+",stdout);
#endif
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        int f,t;
        long long v;
        cnt=cnt2=0;
        //memset(map,0,sizeof map);
        for(int i=0;i<=n;i++){
            head[i]=head2[i]=-1;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%lld",&f,&t,&v);
            add_edge(f-1, t-1, v);
        }
        dijkstra();
        long long sum=0;
        for(int i=0;i<n;i++){
            //     cout<<d1[i]<<" "<<d2[i]<<endl;
            sum+=(long long)(d2[i]+d1[i]);
        }
        // cout<<endl;
        printf("%lld\n",sum);
    }
    return 0;
}
