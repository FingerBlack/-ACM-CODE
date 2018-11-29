#include<iostream>
using namespace std;

int h, w;
char array[25][25];
int digui(int i, int j){
	if (i<0 || j<0 || i>=h || j>=w){
		return 0;
	}
	if (array[i][j] == '#'){
		return 0;
	}
	else{
		array[i][j] = '#';
		return 1 + digui(i+1,j) + digui(i,j+1) + digui(i-1,j) + digui(i,j-1);
	}
}
int main(){
	while (scanf("%d%d", &w, &h)){
		if (w + h == 0){
			break;
		}
		for (int i = 0; i < h; i++){
			scanf("%s", array[i]);
		}
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (array[i][j] == '@'){
					printf("%d\n",digui(i, j));
				}
			}
		}
	}
}