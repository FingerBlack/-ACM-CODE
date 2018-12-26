//
//  hash_function.cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/20.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<time.h>
#include<sstream>
using namespace  std;
#define local
const int maxn=1e5;
int random_input[10*maxn];
class Dictionary{
private:
    int size;
    int sizeofrecord;
    string records[maxn];
    int vis[maxn];
    bool isdelete[maxn];
    
    void operator = (const Dictionary& n){
        size=n.size;
        sizeofrecord=n.sizeofrecord;
        for(int i=0;i<maxn;i++)
            vis[i]=n.vis[i];
        for (int i=0 ; i<maxn; i++) {
            records[i]=n.records[i];
        }
    }
    int random[maxn];
public:
    int count;
    int getsize(){
        return sizeofrecord;
    }
    void init(){
        sizeofrecord=0;
        for(int i=0;i<maxn;i++){
            vis[i]=-1;
            isdelete[i]=0;
        }
    }
    Dictionary(){
        size=maxn;
       srand((unsigned int)time(0));
        for(int i=0;i<maxn;i++){
            vis[i]=-1;
            random[i]=i;
        }
        int seed;
        for(int i=0;i<maxn;i++){
            seed=rand()%(maxn-i)+i;
            int tem=random[seed];
            random[seed]=random[i];
            random[i]=tem;
        }
    }
    string find_linear(unsigned int k){
       unsigned int i=k;
        while(vis[i]!=k&&vis[i]!=-1){
            i++;
            i%=maxn;
        }
        if(vis[i]==-1||isdelete[i]==1){
            return "NULL";
        }
        return records[i];
    }
    string find_quatratic(unsigned int k){
        if(sizeofrecord==0){
            return NULL;
        }
        int count=1;
        unsigned int i=k;
        while(vis[i]!=k&&vis[i]!=-1){
            i+=(2*count-1);
            i%=maxn;
            count++;
        }
        if(vis[i]==-1||isdelete[i]==1){
            return "NULL";
        }
        return records[i];
    }
    string find_pseudo_rando(unsigned int k){
        if(sizeofrecord==0){
            return NULL;
        }
        int count=1;
        unsigned int i=k%maxn;
        while(vis[random[i]]!=k&&vis[random[i]]!=-1){
            i++;
            i%=maxn;
            count++;
        }
        if(vis[i]==-1||isdelete[i]==1){
            return "NULL";
        }
       return records[i];
    }
    string removeany(){
        for(int i=0;i<maxn;i++){
            if(isdelete[i]==0){
                isdelete[i]=1;
                return records[i];
            }
        }
        return "NULL";
    }
    bool insert_linear(unsigned int k,string record){
        if(sizeofrecord==maxn){
            return false;
        }
        unsigned int i=k%maxn;
        int cc=0;
        while(vis[i]!=-1){
            count++;
            i++;
            i%=maxn;
            cc++;
        }
        sizeofrecord++;
        vis[i]=k;
        records[i]=record;
        return true;
    }
    
    bool insert_quatratic(unsigned int k,string record){
        if(sizeofrecord==maxn){
            return false;
        }
        unsigned int i=k%maxn;
        int cc=0;
        int countt=1;
        while(vis[i]!=-1){
            i+=(2*countt-1);
            i%=maxn;
            countt++;
            if(countt>1000000000){
                return false;
            }
            cc++;
        }
        count+=cc;
        sizeofrecord++;
        vis[i]=k;
        records[i]=record;
        return true;
    }
    bool insert_pseudo_random(unsigned int k,string record){
        if(sizeofrecord==maxn){
            return false;
        }
        int i=k%maxn;
       // int count=1;
        while(vis[random[i]]!=-1){
            i++;
            i%=maxn;
            count++;
        }
        sizeofrecord++;
        vis[i]=k;
        records[i]=record;
        return true;
    }
    string remove_linear(unsigned int k){
        if(sizeofrecord==0){
            return "NULL";
        }
        unsigned int i=k%maxn;
        int cc=0;
        while(vis[i]!=k&&vis[i]!=-1){
            i++;
            i%=maxn;
            if (i==k){
                return "NULL";
            }
            cc++;
           
        }
        if(vis[i]==-1||isdelete[i]){
            return "NULL";
        }
        count+=cc;
        sizeofrecord--;
        //    vis[i]=-1;
        //    records[i]=record;
        isdelete[i]=1;
        return records[i];
        
    }
    string remove_quatratic(unsigned int k){
        if(sizeofrecord==0){
            return "NULL";
        }
        unsigned int i=k%maxn;
        int cc=0;
        int countt=1;
        while(vis[i]!=k&&vis[i]!=-1){
            i+=(2*countt-1);
            i%=maxn;
            if(countt>1000000000){
                return "NULL";
            }
            cc++;
            
        }
        if(vis[i]==-1||isdelete[i]){
            return "NULL";
        }
        count+=cc;
        isdelete[i]=1;
        sizeofrecord--;
        //    vis[i]=-1;
        //    records[i]=record;
        return records[i];
        
    }
    string remove_pseudo_random(unsigned int k){
        if(sizeofrecord==0){
            return "NULL";
        }
        unsigned int i=k%maxn;
        int cc=0;
        while(vis[random[i]]!=k&&vis[random[i]]!=-1){
            i++;
            if(i==k){
                return "NULL";
            }
            i%=maxn;
            cc++;
        }
        if(vis[i]==-1||isdelete[i]){
            return "NULL";
        }
        count+=cc;
        isdelete[i]=1;
        sizeofrecord--;
        //    vis[i]=-1;
        //    records[i]=record;
        return records[i];
        
    }
};
void input_init(){
    for(int i=0;i<10*maxn;i++){
        random_input[i]=i;
    }
    int seed;
    for(int i=0;i<10*maxn;i++){
        seed=rand()%(10*maxn-i)+i;
        int tem=random_input[seed];
        random_input[seed]=random_input[i];
        random_input[i]=tem;
    }
}
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdout);
#endif
    srand((unsigned int)time(0));
    input_init();
    string out="123";
    Dictionary a;
    a.init();
    a.count=0;
    for(int i=0;i<90000;i++){
        a.insert_linear(random_input[i], out);
     //   cout<<a.count<<endl;
        if((a.getsize())%10000==0){
            int tem=a.getsize();
            cout<<"a= "<<(double)tem/maxn<<endl;
            //////
            a.count=0;
            int cc=0;
            for(int j=tem/5;j<tem/5+100;j++){
                if(!a.insert_linear(random_input[j], out))
                    continue;
                cc++;
            }
            cout<<"linear probling:"<<endl;
             cout<<"insert average number of probling:"<<(double)(a.count)/cc<<endl;
            a.count=0;
            cc=0;
            for(int j=tem/5;j<tem/5+100;j++){
                if(a.remove_linear(random_input[j])=="NULL")
                    continue;
                cc++;
            }
             cout<<"remove average number of probling:"<<(double)(a.count)/cc<<endl;
            //////
            a.count=0;
             cc=0;
            for(int j=tem/2;j<tem/2+100;j++){
                if(!a.insert_quatratic(random_input[j], out))
                    continue;
                cc++;
            }
            cout<<"quatratic probling:"<<endl;
             cout<<"insert average number of probling:"<<(double)(a.count)/cc<<endl;
            a.count=0;
            cc=0;
            for(int j=tem/3;j<tem/3+100;j++){
                if(a.remove_quatratic(random_input[j])=="NULL")
                    continue;
                cc++;
            }
           cout<<"remove average number of probling:"<<(double)(a.count)/cc<<endl;
            ///////
            a.count=0;
            cc=0;
            for(int j=tem/6;j<tem/6+100;j++){
                if(!a.insert_pseudo_random(random_input[j], out))
                    continue;
                cc++;
            }
            cout<<"pseudo_random probling:"<<endl;
            cout<<"insert average number of probling:"<<(double)(a.count)/cc<<endl;
            a.count=0;
            cc=0;
            for(int j=tem/6;j<tem/6+100;j++){
                if(a.remove_pseudo_random(random_input[j])=="NULL")
                    continue;
                cc++;
            }
            cout<<"remove average number of probling:"<<(double)(a.count)/cc<<endl;
        }
    }
    a.init();
   return 0;
}
