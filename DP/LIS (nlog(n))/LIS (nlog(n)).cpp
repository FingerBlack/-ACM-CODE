#include<iostream>
#include<algorithm>
#include <stack>
using namespace  std;
#define local;
stack<int> str;
int n;
const int maxn=1e3;
int b[maxn],a[maxn];
int dp[maxn],path[maxn];
int lis_for_length(){
    int len=1;
    b[0]=a[0];
  //  cout<<b[0]<<endl;
    for (int i = 1; i < n; ++i)
    {
        /* code */
        b[a[i]>b[len-1]?len++:lower_bound(b, b+len,a[i])-b]=a[i];
        for(int i=0;i<len;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
         
    }
    return len;
}
int printlis(){
    int len=1;
    int maxs=1;
    int maxf=0;
    for (int i = 0; i < n; ++i)
    {   
        path[i]=i;
        dp[i]=1;
        /* code */
    }
  //  cout<<b[0]<<endl;
    for (int i = 1; i < n; ++i)
    {
        /* code */
        int maxx=0;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&maxx<dp[j]){
                maxx=dp[j];
                path[i]=j;
            }
            dp[i]=maxx+1;
            if(dp[i]>maxs){
                maxs=dp[i];
                maxf=i;
            }
        }         
    }
    int i=maxf;
    while(path[i]!=i){
        str.push(i);
        i=path[i];
    }
    str.push(path[i]);
    while(!str.empty()){
        cout<<a[str.top()]<<" ";
        str.pop();
    }
    cout<<endl;
    return maxs;
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
    
    while(cin>>n){
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int len=printlis();
        cout<<len<<endl;
      //  for(int i=0;i<len;i++){
       //     cout<<b[i]<<" ";
       // }
       // cout<<endl;
    }
    return 0;
}
