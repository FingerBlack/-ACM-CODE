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
	int num;
	node *left,*right;
	node(){
		num=0;
		left=right=NULL;
	}
};
node * find(int left1,int right1,int left2,int right2){
	int root=-1;
	node *Root=new node;
	Root->c=a[left1];
	if(left1==right1){
		Root->num=1;
		return Root;
	}
	for(int i=left2;i<=right2;i++){
		if(a[left1]==b[i]){
			root=i;
			break;
		}
	}
	if(root>left2){
		Root->left=find(left1+1,left1+root-left2,left2,root-1);
		Root->num+=Root->left->num;
	}
	if(root<right2){
		Root->right=find(left1+root-left2+1,right1,root+1,right2);
		Root->num+=Root->right->num;
	}

	return Root;
}
void travel(node *root){
	for(int i=0;i<root->num;i++){
		cout<<root->c;
	}
	cout<<endl;
	if(root->left!=NULL){
		travel(root->left);
	}
	if(root->right!=NULL){
		travel(root->right);
	}
	
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%s%s",a,b);
	travel(find(0,strlen(a)-1,0,strlen(b)-1));
	return 0;
}
