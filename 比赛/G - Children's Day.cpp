#include<iostream>
using namespace  std;
#define local;
const int maxn=1000;
char str[11][11]={0};
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	int j=0;
	int k=0;
	char c='a';
	for(int i=3;i<=3;i++){
		for(int j=0;j<i;j++){
			// cout<<j<<endl;
			str[j][0]=c++;
			//c=(char)(c+1);
			//printf("%c ",str[1][0]);
		}
		j-=2;
		for(int h=1;h<i-1;h++,j--){
			str[j][h]=c++;
			//cout<<str[j][h];
		}
		for(;j<i;j++){
			str[j][i-1]=c++;
			cout<<str[0][0];
		}
			printf("%d",i);
		for(int m=0;m<3;m++){
			for(int n=0;n<3;n++){
			//	printf("%d",i);
			//	if(n!=i-1){
			//		printf(" ");
			//	}
			}
		//	cout<<endl;
		}
	}
	return 0;
}
