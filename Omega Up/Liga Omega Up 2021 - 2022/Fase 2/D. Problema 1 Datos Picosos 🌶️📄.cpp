#include<bits/stdc++.h>

using namespace std;

/*void mostrarDia(int day){
	switch(day){
		case 0:
			printf("Lunes");
			break;
		case 1:
			printf("Martes");
			break;
		case 2:
			printf("Mi%crcoles",130);
			break;
		case 3:
			printf("Jueves");
			break;
		case 4:
			printf("Viernes");
			break;
		case 5:
			printf("S%cbado",160);
			break;
		case 6:
			printf("Domingo");
			break;
	}
}*/

int main(){
	int n, day;
	double prom = 0, desv = 0, dif, maxDesv, s;
	string dias[] = {"Lunes","Martes","Miércoles","Jueves","Viernes","Sábado","Domingo"};
	bool anom = false;
	string d;
	
	cin>>n>>s>>d;
	double nums[n];	
	
	switch(d[0]){
		case 'L':
			day = 0;
			break;
		case 'M':
			switch(d[1]){
				case 'a':
					day = 1;
					break;
				case 'i':
					day = 2;
					break;
			}
			break;
		case 'J':
			day = 3;
			break;
		case 'V':
			day = 4;
			break;
		case 'S':
			day = 5;
			break;
		case 'D':
			day = 6;
			break;	
	}
	
	for(int k = 0; k < n; k++){
		cin >> nums[k];
		prom += nums[k];
	}
	
	prom /= n;
	
	for(int k = 0; k < n; k++){
		desv += ((nums[k] - prom) * (nums[k] - prom));
	}
	
	desv = sqrt(desv / n);
	maxDesv = desv * s;
	

	
	for(int k = 0; k < n; k++){
		dif = nums[k] - prom;
		
		if(dif > maxDesv){
			/*printf("D%ca #%d - ",161,k);
			mostrarDia((k + day) % 7);
			printf(" - M%cs de los normal\n",160);*/
			cout << "Día #" << k << " - " << dias[(k + day) % 7] << " - " << "Más de los normal\n";
			anom = true;
		}
		else if(-dif > maxDesv){
			/*printf("D%ca #%d - ",161,k);
			mostrarDia((k + day) % 7);
			printf(" - Menos de los normal\n");*/
			cout << "Día #" << k << " - " << dias[(k + day) % 7] << " - " << "Menos de los normal\n";
			anom = true;
		}
	}
	
	if(!anom){
		//printf("No hubo anomal%cas\n",161);
		cout << "No hubo anomalías";
	}
	
	return 0;
}
