#include<bits/stdc++.h>

using namespace std;

int main(){
	double xK,yK,x,y,B1,B0,sumX=0,sumY=0,avgX,avgY,sumXY=0,sumXsq=0,sumYsq,r,rSq,num,den;
	int n;
	cin>>xK;
	cin>>n;
	for(int k=0; k<n; k++){
		cin>>x>>y;
		sumX+=x;
		sumY+=y;
		sumXY+=(x*y);
		sumXsq+=(x*x);
		sumYsq+=(y*y);
	}
	avgX=sumX/n;
	avgY=sumY/n;
	B1=(sumXY-(n*avgX*avgY))/(sumXsq-(n*avgX*avgX));
	B0=avgY-(B1*avgX);
	num=(n*sumXY)-(sumX*sumY);
	den=(n*sumXsq-(sumX*sumX))*(n*sumYsq-(sumY*sumY));
	den=sqrt(den);
	r=num/den;
	rSq=r*r;
	yK=B0+B1*xK;
	printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n",B0,B1,r,rSq,yK);
}
