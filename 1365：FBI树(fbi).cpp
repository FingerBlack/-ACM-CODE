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
char a[N],b[N];
int k=0,ans,d,n;
struct node
{
	char c;
	node *left,*right;
	node(){
		left=right=NULL;
	}
};
node * find(int left,int right){
	node *root= new node();
	if(left==right){
		if(a[left]=='0'){
			root->c='B';
		}
		if(a[left]=='1'){
			root->c='I';
		}
		return root;
	}
	root->left=find(left,(left+right)/2);
	root->right=find((left+right)/2+1,right);
	if(root->left->c=='I'&&root->right->c=='I'){
		root->c='I';
	}else if(root->left->c=='B'&&root->right->c=='B'){
		root->c='B';
	}else{
		root->c='F';
	}
	return root;
}
void travel(node *root){
	if(root->left!=NULL){
		travel(root->left);
	}
	if(root->right!=NULL){
		travel(root->right);
	}
	cout<<root->c;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%s",&n,a);
	
	travel(find(0,strlen(a)-1));
	return 0;
}
