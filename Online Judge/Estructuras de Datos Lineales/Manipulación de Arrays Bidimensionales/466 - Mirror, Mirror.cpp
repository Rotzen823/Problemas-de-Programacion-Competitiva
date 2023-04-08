#include<bits/stdc++.h>
#define MAX 15

using namespace std;

char mat1[MAX][MAX];
char mat2[MAX][MAX];
bool comps[8];

void comparar(int n, int c){
	for(int k = 0; k < 8; k++){
		comps[k] = true;
	}

	for(int k = 0; k < n; k++){
		for(int j = 0; j < n; j++){
			if(mat1[k][j] != mat2[k][j]){//normal
				comps[0] = false;
			}
			if(mat1[k][j] != mat2[j][n - k - 1]){ //90 grados
				comps[1] = false;
			}
			if(mat1[k][j] != mat2[n - k - 1][n - j - 1]){//180 grados
				comps[2] = false;
			}
			if(mat1[k][j] != mat2[n - j - 1][k]){//270 grados
				comps[3] = false;
			}
			if(mat1[k][j] != mat2[n - k - 1][j]){//Vertical Reflection
				comps[4] = false;
			}
			if(mat1[k][j] != mat2[j][k]){//VR y 90 grados
				comps[5] = false;
			}
			if(mat1[k][j] != mat2[k][n - j - 1]){ // VR y 180 grados
				comps[6] = false;
			}
			if(mat1[k][j] != mat2[n - j - 1][n - k -1]){ //VR y 270 grados
				comps[7] = false;
			}
		}
	}

	if(comps[0]){
		printf("Pattern %d was preserved.\n", c);
	}
	else if(comps[1]){
		printf("Pattern %d was rotated 90 degrees.\n", c);
	}
	else if(comps[2]){
		printf("Pattern %d was rotated 180 degrees.\n", c);
	}
	else if(comps[3]){
		printf("Pattern %d was rotated 270 degrees.\n", c);
	}
	else if(comps[4]){
		printf("Pattern %d was reflected vertically.\n", c);
	}
	else if(comps[5]){
		printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", c);
	}
	else if(comps[6]){
		printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", c);
	}
	else if(comps[7]){
		printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", c);
	}
	else{
		printf("Pattern %d was improperly transformed.\n", c);
	}
}

int main(){
	int n,c = 0;
	while(scanf("%d", &n) != EOF){
		c++;
		char ax;
		for(int k = 0; k < n; k++){
			scanf("%c", &ax);
			for(int j = 0; j < n; j++){
				scanf("%c", &mat1[k][j]);
			}
			scanf("%c", &ax);
			for(int j = 0; j < n; j++){
				scanf("%c", &mat2[k][j]);
			}
		}

		comparar(n, c);
	}
	
	return 0;
}