#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace  std;
map<char,int> Map;
struct node
{
  char c;
  int fre;
  node *left,*right;
  bool operator  <(const node &a) const{
    return fre>a.fre;
  }
}nn;
priority_queue <node>  mm;
#define local;
void preorder(node *root,string code){
  if(root->left==NULL&&root->right==NULL){
    cout<<root->c <<" "<< code<<endl;
    return;
  }
  if(root->left!=NULL){
    preorder(root->left,code+'0');
  }
  if(root->right!=NULL){
    preorder(root->right,code+'1');
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
   preorder(root,"");
    //for()*/
   }
  return 0;
}
