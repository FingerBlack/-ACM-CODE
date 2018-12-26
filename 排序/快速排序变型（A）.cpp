//
//  快速排序变型（A）.cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/17.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<time.h>
using namespace  std;
#define local

const int maxn=1e6;
int a[maxn];
template <typename E>
inline int findpivot(E A[],int l,int r){
    E a=A[l];
    E b=A[(l+r)/2];
    E c=A[r];
    if(a>b){
        E tem=a;
        a=b;
        b=tem;
    }
    if(a>c){
        E tem=a;
        a=b;
        b=tem;
    }
    if(b>c){
        E tem=a;
        a=b;
        b=tem;
    }
    if(b==A[l]){
        return l;
    }else if(b==A[r]){
        return r;
    }else{
        return (l+r)/2;
    }
}
template <typename E>
inline int findpivot2(E A[],int l,int r){
    return (l+r)/2;
}
template <typename E>
inline void swap(E A[],int l,int r){
    E c=A[l];
    A[l]=A[r];
    A[r]=c;
}
template <typename E>
inline void inssort(E A[],int l,int r){
    for(int i=l;i<=r;i++){
        for(int j=i;j>l;j--){
            if(A[j]<A[j-1])
                swap(A,j,j-1);
        }
    }
}

template <typename E>
inline int partition(E A[],int l,int r,E &pivot){
    do{
        while(A[++l]<pivot);
        while(l<r&&A[--r]>pivot);
        swap(A,l,r);
    }while(l<r);
        return l;
}
template <typename E>
void qsort(E A[],int l,int r ,int flag){
    if(r<=l){
        return ;
    }
    int pivot;
    if(flag==1){
    	pivot=findpivot(A, l, r);
    }else if(flag==2){
		pivot=findpivot2(A, l, r);
    }
    
    swap(A, pivot,r);
    int k=partition<E>(A, l-1, r,A[r]);
    swap(A, k,r);
    qsort(A, l, k-1,1);
    qsort(A, k+1, r,2);
}
template <typename E>
void qsort2(E A[],int l,int r ,int flag){
    if(r-l<=flag){
        inssort <int> (A,l,r);
        return ;
    }
    int pivot;
    if(flag==1){
        pivot=findpivot(A, l, r);
    }else if(flag==2){
        pivot=findpivot2(A, l, r);
    }
    
    swap(A, pivot,r);
    int k=partition<E>(A, l-1, r,A[r]);
    swap(A, k,r);
    qsort(A, l, k-1,1);
    qsort(A, k+1, r,2);
}
int main()
{
#ifdef local
 //   freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
    freopen("out","wt+",stdout);
#endif
    clock_t start,end;
    srand((int)time(0));
    int k=10000000;
    int x;
    ///////////
    start=clock();
    for(int i=1;i<=k;i++){
     //   x=rand()%k;
        a[i]=i;
    }
     qsort <int>(a,1,k,2);
    end=clock();
    printf("totile time=%fms\n",(float)(end-start)*1000/CLOCKS_PER_SEC);
    ///////////
    start=clock();
    for(int i=1;i<=k;i++){
        x=rand()%k;
        a[i]=i;
    }
     qsort <int>(a,1,k,1);
     end=clock();
    printf("totile time=%fms\n",(float)(end-start)*1000/CLOCKS_PER_SEC);
    ///////////
    start=clock();
    for(int i=1;i<=k;i++){
        x=rand()%k;
        a[i]=i;
    }
    qsort2 <int>(a,1,k,100);
     end=clock();
    printf("totile time=%fms\n",(float)(end-start)*1000/CLOCKS_PER_SEC);
    return 0;
}

