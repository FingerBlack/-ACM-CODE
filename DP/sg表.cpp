#include<iostream>
#include<string>
#include<set>
using namespace  std;
#define local
const int N=1e5;
int f[N];
int sg[N];
void solve()  
{  
    sg[1] = 0;   
    for (int i = 2;i <= N;++i)  
    {  
        set<int>s;  
        for (int j = 2;j <= 9;++j)  
        {  
            int to = i/j;  
            if (i%j)to++;  
            s.insert(sg[to]);   
        }  
        int g = 0;  
        while (s.count(g)) ++g;  
        sg[i] = g;  
    }  
    for (int i = 0;i <= 9000;++i)   
    {  
        cout<<i<<" "<<sg[i]<<endl;  
    }   
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	solve();
	return 0;
}

