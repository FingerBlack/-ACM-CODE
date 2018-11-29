#include<iostream>
using namespace  std;
#define local;
struct node
{
	char c;
	int fre;
	node(){
		fre=0;
	}
	node(char a,int b){
		a=c;
		fre=b;
	}

}nn[100];
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	char c;
	int size=0;
	int count=0;
	c='A';
	for(int i=0;i<8;i++){
		nn[i].c=c;
		nn[i].fre=1;
		c++;
		size++;
	}
	while(scanf("%c",&c)!=-1){
		int flag=-1;
		for(int i=0;i<size;i++){
			count++;
			if(c==nn[i].c){
				nn[i].fre++;
				flag=i;
				break;
			}

		}
		if(flag==-1 ){
			nn[size].c=c ;
			nn[size++].fre=1;//node(c,1);
		//	printf("%c\n",nn[size-1].c);
		}else{
			int j=flag;
			for(int i=j-1;i>=0;i--){
				if(nn[j].fre>nn[i].fre){
					node tem=nn[j];
					nn[j]=nn[i];
					nn[i]=tem;
					j=i;
				}else{
					break;
				}
			}
		}
		for(int i=0;i<size;i++){
		printf("%c (%d) ",nn[i].c,nn[i].fre );
		}
		printf("%d",count);
		putchar('\n');
	//	printf("%d\n",size );
	//	printf("%c",nn[0].c);
		
	}
//	printf("%d\n",size );
//	for(int i=0;i<size;i++){
//		printf("%c (%d) ",nn[i].c,nn[i].fre );
//	}
	printf("%d\n",count);
	return 0;
}
