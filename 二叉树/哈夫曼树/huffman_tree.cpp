#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace  std;
map<char,int> Map;
map<char,string> mmm;
int counted=0;
struct node
{
  char c;
  int fre;
//  string code;
  node *left,*right;
  bool operator  <(const node &a) const{
    if(fre!=a.fre){
       return fre>a.fre;
     }else{
      return c>a.c;
     }
   
  }
}nn;
priority_queue <node>  mm;
#define local;
void preorder(node *root,string code){
  if(root->left==NULL&&root->right==NULL){
    cout<<root->c <<" "<< code<<" "<<root->fre<<endl;
    mmm[root->c]=code;
    return;
  }
  if(root->left!=NULL){
    preorder(root->left,code+'0');
  }
  if(root->right!=NULL){
    preorder(root->right,code+'1');
  }
  
}
void search(string line,node *root){
  if(root->left==NULL&&root->right==NULL){
    cout<<root->c;
    return;
  }
  if(line[counted]=='0'){
    counted++;
    search(line,root->left);
  }else{
    counted++;
    search(line,root->right);
  }
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
  string line;
  //cout<<1;
  while(cin>>line){
    counted=0;
    //cout<<line;
    for(int i=0;i<line.size();i++){
     // cout<<line<<endl;
     // cout<<endl;
      Map[line[i]]++;
    }
   int k=0;
   for(map<char,int> :: iterator it =Map.begin();it!=Map.end();it++){
  //  　t->first<<endl;
      nn.c=it->first;
      nn.fre=it->second;
     // printf("%c ",it->first);
      mm.push(nn);
   }
 // cout<<mm.size();
 //  
   while(mm.size() != 1){
    node *a=new node();
    node *b=new node(); 
    *a = mm.top(); 
    mm.pop();
    *b = mm.top();
    mm.pop();
    node *c=new node();
    c->fre=a->fre+b->fre;
    if(a->fre>=b->fre){
      c->left=b;
      c->right=a;
    }else{
      c->left=a;
      c->right=b;
    }
    //if(mm.size()==5){
      mm.push(*c); 
    // cout<<mm.size()<<endl;
   }
   node *root =new node();
    *root =mm.top();
  //  cout<<root->left->fr<<endl;
  cout<<"编码: "<<endl;
   preorder(root,"");
   string line2;
   
   cin>>line2;
 //  int debug=0;
   cout<<"译码: "<<endl;
   while(counted!=line2.size()){
    search(line2,root);
   // cout<<"  ";
   // cout<<counted<<endl
    //debug++;
   }
    //for()*/
   }
  return 0;
}
