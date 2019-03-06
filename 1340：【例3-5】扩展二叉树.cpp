#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
#define local
const int N=1e7;
char a[N];
int k=0;
struct node
{
	char c;
	node *left,*right;
	node(){
		left=NULL;
		right=NULL;
	}
};
node* find(){
	//int lena=strlen(a);
	//int lenb=strlen(b);
	node *root=new node;
	root->c=a[k];
	k++;
	if(a[k]!='.'){
		root->left=find();
	}
	k++;
	if(a[k]!='.'){
		root->right=find();
	}
	return root;
}
void find1(node*root){
	if(root->left!=NULL){
		find1(root->left);
	}
	cout<<root->c;
	if(root->right!=NULL){
		find1(root->right);
	}
}
void find2(node*root){
	
	if(root->left!=NULL){
		find2(root->left);
	}
	if(root->right!=NULL){
		find2(root->right);
	}
	cout<<root->c;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%s",a);
	node *Root=find();
	find1(Root);
	cout<<endl;
	find2(Root);

	return 0;
}
