#include<stdio.h>

int main(){
	int Xa,Ya,Wa,Ha,Xb,Yb,Wb,Hb;
	int bolX=0, bolY=0,res=0;
	
	scanf("%d %d %d %d %d %d %d %d",&Xa,&Ya,&Wa,&Ha,&Xb,&Yb,&Wb,&Hb);
	
	if((Xa<=Xb+Wb && Xa>=Xb) && (Ya<=Yb+Hb && Ya>=Yb)) res=9;
	else if((Xa+Wa>=Xb && Xa+Wa<=Xb+Wb) && (Ya<=Yb+Hb && Ya>=Yb)) res=9;
	else if((Xa+Wa>=Xb && Xa+Wa<=Xb+Wb) && (Ya+Ha>=Yb && Ya+Ha<=Yb+Hb)) res=9;
	else if((Xa<=Xb+Wb && Xa>=Xb) && (Ya+Ha>=Yb && Ya+Ha<=Yb+Hb)) res=9;
	else if(Xa>=Xb && Xa+Wa<=Xb+Wb){
		if(Ya>Yb+Hb){
			res=2;
		}
		else{
			res=1;
		}
	}
	else if(Ya>=Yb && Ya+Ha<=Yb+Hb){
		if(Xa>Xb+Wb){
			res = 4;
		}
		else{
			res = 3;
		}
	}
	else if(Xa>Xb+Wb){
		if(Ya+Ha<Yb){
			res=6;
		}
		else if(Ya>Yb+Hb){
			res=8;
		}
	}
	else if(Xa+Wa<Xb){
		if(Ya+Ha<Yb){
			res=5;
		}
		else if(Ya>Yb+Hb){
			res=7;
		}
	}
	
	if(res==0) res=10;
	printf("%d",res);
	
}

