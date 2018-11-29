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
	int num=0;
	while(scanf("%c",&c)!=-1){
		num++;

		int flag=-1;
		for(int i=0;i<size;i++){
			if(num>8){
				count++;
			}
			
			if(c==nn[i].c){
				nn[i].fre++;
				flag=i;
				break;
			}

		}
		int j;
		if(flag==-1 ){
			j=size;
			nn[size].c=c ;
			nn[size++].fre=1;//node(c,1);
		//	printf("%c\n",nn[size-1].c);
		}else{
			j=flag;
			if(j!=0){
			node tem=nn[j];
			nn[j]=nn[j-1];
			nn[j-1]=tem;	
			}
		}

					
		for(int i=0;i<size;i++){
		printf("%c (%d) ",nn[i].c,nn[i].fre );
		}
		putchar('\n');
	//	printf("%d\n",size );
	//	printf("%c",nn[0].c);
		
	}
//	printf("%d\n",size );
	for(int i=0;i<size;i++){
		printf("%c (%d) ",nn[i].c,nn[i].fre );
	}
	printf("\n%d\n",count);
	return 0;
}
