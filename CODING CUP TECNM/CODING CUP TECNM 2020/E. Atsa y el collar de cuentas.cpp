#include<stdio.h>

int main(){
	char c;
	int n,ax;
	scanf("%c %d",&c,&n);
	
	switch(c){
		case 'A':
			n++;
			break;
		case 'V':
			n+=2;
			break;
	}
	
	ax=n%3;
	switch(ax){
		case 0:
			printf("R");
			break;
		case 1:
			printf("A");
			break;
		case 2:
			printf("V");
			break;
	}
	
}

