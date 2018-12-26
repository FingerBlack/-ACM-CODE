//
//  字符串处理_C(tries).cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/12.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
using namespace  std;
#define local
struct node{
    char c;
    int n;
    node *fail;
    node *next[26];
    int count;
    node(){
        fail=NULL;
        count=0;
        memset(next, NULL, sizeof(next));
    }
}*q[10000];
int head,tail;
node* root=new node();
void insert(string str){
    node *now=root;
    int i=0;
    while(str[i]){
        int index=str[i]-'a';
        if(now->next[index]==NULL) now->next[index]=new node();
        now=now->next[index];
        i++;
    }
    now->count++;
}
void auto_build(){
    head=tail=0;
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail){
        node *tem=q[tail++];
        node *p=NULL;
        for(int i=0;i<26;i++){
            if(tem->next[i]!=NULL){
                if(tem==root){
                    tem->next[i]->fail=root;
                }else{
                    p=tem->fail;
                    while(p!=NULL){
                        if(p->next[i]!=NULL){
                            tem->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL){
                        tem->next[i]=root;
                    }
                }
                q[head++]=tem->next[i];
            }
        }
    }
}
int query(string str){
    int index,len=str.length(),i=0;
    node *p=root;
    int cnt=0;
    while(str[i]){
        index=str[i]-'0';
        while(p->next[i]==NULL&&p!=root){
            p=p->fail;
        }
        if(p->next[i]==NULL){
            i++;
            continue;
        }
        node *tem=p;
        while(tem!=root&&tem->count!=-1){
            cnt+=tem->count;
            tem->count=-1;
            tem=tem->fail;
        }
        i++;
    }
    return cnt;
}
int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdout);
#endif
    
    
    return 0;
}
