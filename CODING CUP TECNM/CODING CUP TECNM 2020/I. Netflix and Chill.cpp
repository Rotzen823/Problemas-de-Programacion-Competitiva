#include<stdio.h>

typedef struct{
	int x;
	int y;
}letras;

letras teclado[125];

int main(){
	int n,m,c=0,aux,pX=0,pY=0,let,x,y;
	int limz=0,limd=0;
	char ins;
	char pelicula[1000],ax;
	scanf("%d %d",&n,&m);
	for(int k=0; k<n; k++){
		scanf("%c",&ax);
		for(int j=0; j<m; j++){
			scanf("%c",&ax);
			aux=ax;
			teclado[aux].x=j;
			teclado[aux].y=k;
		}
	}

	scanf("%c",&ax);
	gets(pelicula);
	
	while(pelicula[c]!='\0'){
		if(pelicula[c]>=65 && pelicula[c]<=90){
			pelicula[c]+=32;
		}
		let=pelicula[c++];
		x=teclado[let].x;
		y=teclado[let].y;
		//printf("\n%d %d ",x,y);
		
		if(pY<y){
			limz=pY;
			limd=y;
			ins='a';
		}
		else{
			limz=y;
			limd=pY;
			ins='A';
		}
		
		for(int k=limz; k<limd; k++){
			printf("%c",ins);
		}
		
		if(pX<x){
			limz=pX;
			limd=x;
			ins='d';
		}
		else{
			limz=x;
			limd=pX;
			ins='i';
		}
		for(int k=limz; k<limd; k++){
			printf("%c",ins);
		}
		printf("!");
		pX=x;
		pY=y;
	}
}

