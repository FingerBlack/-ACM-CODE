#include<iostream>
using namespace  std;
#define local;
int n,m,a,b;
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a%b);
}


int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
    int T;
    int Case = 0;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        int m = gcd(a,b);
        cout<<"Case #"<<++Case<<": ";
        int k=n/m;
      //while(k!=1&&k!=0){
//
  //      }
        if((k-2)%2==0){
            cout<<"Iaka"<<endl;
        }else{
            cout<<"Yuwgna"<<endl;
        }
    }
    return 0;
}

