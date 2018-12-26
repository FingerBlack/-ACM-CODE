//
//  external_sort.cpp
//  ACM-CODE
//
//  Created by 陈纪双 on 2018/12/18.
//  Copyright © 2018 陈纪双. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<cstdio>
#include<sstream>
//#include<iostream.h>
const int block=512;
int B=1;
using namespace  std;
//#define local
struct record {
    unsigned int id;
    float key;
    bool operator <(const record&n)const{
        if(key!=n.key)
        return key>n.key;
        return id>n.id;
    }
    record(unsigned int a,float b ){
        id=a;
        key=b;
    }
    record(){
        
    }
}cache,temp[8][block],buffer[block];

class extsort{
public:
    string record_file_name,statistics_file_name,op,line;
    int N;
    int k[2];
    int last_length[8];
    string ffile;
  //  fstream fpoint[8];
    string file_name[2][100];
    fstream output[2][100];
    priority_queue<record> heap[2];
    int pointer [100];
    int len[2][100];
    int readblock[8];
    extsort(){
        k[1]=k[0]=0;
        string out01 ="Run01",out02 ="Run02",out11 ="Run11",out12 ="Run12";
        for(int i=0;i<50;i++){
            file_name[0][i]=out01+(char)(i+48);
        }
        for(int i=0;i<50;i++){
            file_name[0][i+50]=out02+(char)(i+48);
        }
        for(int i=0;i<50;i++){
            file_name[1][i]=out11+(char)(i+48);
        }
        for(int i=0;i<50;i++){
            file_name[1][i+50]=out12+(char)(i+48);
        }
        for(int i=0;i<100;i++){
            output[0][i].open(file_name[0][i],ios::trunc|ios::in|ios::binary|ios::out);
        }
        for(int i=0;i<100;i++){
            output[1][i].open(file_name[1][i],ios::trunc|ios::in|ios::binary|ios::out);
        }
       // output[1].open(file_name[1],ios::in|ios::binary|ios::out);
    }
    ~extsort(){
        for(int i=0;i<100;i++){
            remove(file_name[0][i].c_str());
        }
        for(int i=0;i<100;i++){
            remove(file_name[1][i].c_str());
        }
        // output[1].open(file_name[1],ios::in|ios::binary|ios::out);
    }
    void External_Sort(){
        fstream input(record_file_name,ios::in|ios::binary|ios::out);
        if(!input){
            cout<<"Error: file "<<record_file_name<<" wasn't find !!"<<endl;
            return;
        }
        record cache;
        //    cout<<cache.id<<" "<<cache.key<<endl;
        input.seekg(0);
        int now=0;
        //read 8 blocks and give all of them to the temp[i]
        for(int i=0;i<8;i++){
            input.read((char *)&temp[i], sizeof(record)*block);
            for(int j=0;j<block;j++)
                heap[now].push(temp[i][j]);
        }
        //get all the runs
        while(!input.eof()){
            input.read((char *)&buffer, sizeof(record)*block);
      //      cout<<cache.id<<" "<<cache.key<<endl;
            for(int j=0;j<block;j++){
                cache=buffer[j];
                if(heap[now].empty()){
                    now=1-now;
                    output[0][k[0]++]<<flush;
                }
                record Top=heap[now].top();
                if(cache.key>=Top.key||(cache.key==Top.key&&cache.id>=Top.id)){
                    heap[now].pop();
                    heap[now].push(cache);
                    output[0][k[0]].write((char*)&Top,sizeof(record));
                    len[0][k[0]]++;
                }else{
                    heap[now].pop();
                    output[0][k[0]].write((char*)&Top,sizeof(record));
                    len[0][k[0]]++;
                    heap[1-now].push(cache);
                }
            }
        }
        //read the rest runs of the heap;
        if(!heap[now].empty()){
            while(!heap[now].empty()){
                output[0][k[0]].write((char*)&heap[now].top(),sizeof(cache));
                 len[0][k[0]]++;
                heap[now].pop();
            }
            output[0][k[0]]<<flush;
            k[0]++;
        }
        if(!heap[1-now].empty()){
            while(!heap[1-now].empty()){
                output[0][k[0]].write((char*)&heap[1-now].top(),sizeof(cache));
                heap[1-now].pop();
                 len[0][k[0]]++;
            }
            output[0][k[0]]<<flush;
            k[0]++;
        }
        //
  
 /*  ffile=file_name[0][0];
        cat();
        for(int i=0;i<1000;i++)
        cout<<" //////////"<<endl;
        ffile=file_name[0][1];
        cat();
        cout<<" //////////"<<endl;
        ffile=file_name[0][2];
        cat();
  */
        now=0;
        int start=0,length=0;
     //   int buffer_count=0;
        while(1){
           // fstream []
            for(int i=0;i<k[now];i++){
                output[now][i].seekg(0);
            }
            for(int i=0;i<k[1-now];i++){
                output[1-now][i].seekg(0);
            }
            for(int i=0;i<8;i++){
                pointer[i]=0;
                last_length[i]=-1;
            }
            if(k[now]>=8){
                length=8;
            }else if(k[now]+k[1-now]==1){
                if(k[now]==1){
                    rename(file_name[now][0].c_str(), statistics_file_name.c_str());
                }else if(k[1-now]==1){
                    rename(file_name[1-now][0].c_str(), statistics_file_name.c_str());
                }
                break;
            }else if(k[now]<8){
                length=k[now];
            }
            
            for(int i=0;i<length;i++){
                if(len[now][start+i]>block){
                    output[now][start+i].read((char *)&temp[i],sizeof(record)*block);
                    len[now][start+i]-=block;
                    pointer[i]=0;
                }else if(len[now][start+i]<block&&len[now][start+i]>0){
                    output[now][start+i].read((char *)&temp[i],sizeof(record)*len[now][start+i]);
                    last_length[i]=len[now][start+i];
                    len[now][start+i]=0;
                    pointer[i]=0;
                }else if(len[now][start+i]==0){
                    pointer[i]=-1;
                }
              //  output[now][i].read((char*)&temp[i-start],sizeof(record)*block);
              //  len[now][i]-=block;
            }
            while(1){
                record minn(1e8,1e8);
                int position=-1;
                for(int i=0;i<length;i++){
                    if(pointer[i]!=-1&&(temp[i][pointer[i]].key<minn.key||(temp[i][pointer[i]].key==minn.key&&temp[i][pointer[i]].id<minn.id))){
                        minn=temp[i][pointer[i]];
                        position=i;
                    }
                }
                if(position==-1){
                    ffile=file_name[1-now][k[1-now]];
                    cat();
                    k[now]-=length;
                    k[1-now]++;
                    start+=length;
                    break;
                }
                pointer[position]++;
                output[1-now][k[1-now]].write((char *)&minn,sizeof(record));
                len[1-now][k[1-now]]++;
                output[1-now][k[1-now]]<<flush;
                if(pointer[position]==block||pointer[position]==last_length[position]){
                   // if(count==8)
                 
                    if(len[now][start+position]>block){
                        output[now][start+position].read((char *)&temp[position],sizeof(record)*block);
                            len[now][start+position]-=block;
                        pointer[position]=0;
                    }else if(len[now][start+position]<block&&len[now][start+position]>0){
                        output[now][start+position].read((char *)&temp[position],sizeof(record)*len[now][start+position]);
                        last_length[position]=len[now][start+position];
                        len[now][start+position]=0;
                        pointer[position]=0;
                    }else if(len[now][start+position]==0){
                        pointer[position]=-1;
                    }
                }
            }
            if(k[now]==0){
                
                for(int i=0;i<100;i++){
                    output[now][i].close();
                    remove(file_name[now][i].c_str());
                    output[now][i].open(file_name[now][i],ios::trunc|ios::in|ios::binary|ios::out);
                }
                for(int i=0;i<100;i++){
                    pointer[i]=0;
                }
                 start=0;
                 now=1-now;
            }
        }
        cout<<"extsort sucessfully"<<endl;
    }
    void set_n(){
        fstream outt("in",ios::trunc|ios::binary|ios::out);
        srand((unsigned int )time(0));
        for(int i=0;i<N;i++){
            for(int j=0;j<block;j++){
                cache.id=(unsigned int)rand()%10000;
                cache.key=(float)(rand()%1000000)/100;
                cout<<cache.id<<" "<<cache.key<<endl;
                outt.write((char*)&cache,sizeof( record));
            }
            outt<<flush;
        }
    }
    void cat(){
        fstream input(ffile,ios::binary|ios::in|ios::out|ios::app);
     //   if (input.good()) {
    //        cout<<"error"<<endl;return;
    //    }
        input.seekg(0,ios::beg);
        int count=0;
        while(!input.eof()){
            count++;
            input.read((char*)(&cache), sizeof(record));
            //cout<<input.good()<<endl;
            cout<<"ID: "<<cache.id<<" Key:"<<cache.key<<" "<<endl;
        }
    }
    void test(){
       cout<<"Darwin chenjisangdeMBP.lan 18.2.0 Darwin Kernel Version 18.2.0: Fri Oct  5 19:41:49 PDT 2018; root:xnu-4903.221.2~2/RELEASE_X86_64 x86_64"<<endl;
        // getchar();
        while(1){
            cout<<"chenjisangdeMBP:~ chenjishuang$";
             cout<<record_file_name<<" "<<statistics_file_name<<endl;
            getline(cin, line);
            stringstream ctr(line);
            cout<<line<<endl;
            if(ctr>>op){
       //         string record_file_name,statistics_file_name,op;
                if(op=="extsort"){
                    if(ctr>>record_file_name>>statistics_file_name){
                         External_Sort();
                    }else{
                        cout<<"Unrecognized option: -"<<record_file_name<<" "<<statistics_file_name<<endl;
                    }
                }else if(op=="set_n"){
                    if(ctr>>N){
                        set_n();
                      //  getchar();
                    }else{
                         cout<<"Unrecognized option: -"<<endl;
                    }
                }else if(op=="cat"){
                    
                    if(ctr>>ffile){
                        cat();
                    }else{
                        cout<<"Unrecognized option: -"<<ffile<<endl;
                    }
                }else{
                    cout<<"-bash: "<< op<<": command not found"<<endl;
                    continue;
                }
            }else{
                continue;
            }
        }
    }
    
};

int main()
{
#ifdef local
    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/in","r",stdin);
//    freopen("/Users/chenjishuang/Documents/XCODE/ACM-CODE/ACM-CODE/out","wt+",stdou);
#endif
    extsort test;
  //  test.test();
    test.record_file_name="in";
    test.statistics_file_name="out";
    test.ffile="out";
    test.External_Sort();
    test.cat();
    return 0;
}

