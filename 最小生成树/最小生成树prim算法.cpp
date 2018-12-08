#include<iostream>
#include<vector>
using namespace  std;
#define local;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int lowercase[maxn];
bool vis[maxn];
int pre[maxn];
int n,m;
struct edge
{
    int t,dis;
    edge(int a,int b){
        t=a;
        dis=b;
    }
};
vector < edge > map[maxn];

int prime(){
    int sum=0;
    memset(vis,false,sizeof vis);
    memset(lowercase,inf,sizeof lowercase);
    for(int i=1;i<=n;i++){
        pre[i]=1;
    }
    for(int i=0;i<map[1].size();i++){
        lowercase[map[1][i].t]=map[1][i].dis;
    }
    //for(int i=0;i<n;i++){
    //        cout<<lowercase[i]<<endl;
    //    }
    vis[1]=1;
    //sum+=lowercase[1];
    //cout<<n<<endl;
    int k;
    for(int i=1;i<n;i++){
        int min=inf;
        k=0;
        for(int j=2;j<=n;j++){
            if(lowercase[j]<min&&!vis[j]){
                min=lowercase[j];
                k=j;
            }
        }
        sum+=lowercase[k];
        //    cout<<pre[k]<<" "<<k<<endl;
        vis[k]=true;
        for(int j=0;j<map[k].size();j++){
            int to=map[k][j].t;
            if(lowercase[to]>map[k][j].dis&&!vis[to]){
                lowercase[to]=map[k][j].dis;
                pre[to]=k;
            }
        }
    }
    
    return sum;
}
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/最小生成树/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/最小生成树/out","wt+",stdout);
#endif
    while(cin>>n>>m){
        int f,t,val;
        for(int i=0;i<m;i++){
            cin>>f>>t>>val;
            map[f].push_back(edge(t,val));
            map[t].push_back(edge(f,val));
        }
        cout<<prime()<<endl;
    }
    return 0;
}

