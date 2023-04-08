#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, cent, lin, lar;
	char car;
	double sum;
	map<char, double> let;
	string linea;
	cin >> n;

	while(n--){

		cin >> m;
		
		while(m--){
			cin >> car >> cent;
			let[car] = cent;
		}

		sum = 0;
		cin >> lin;
		
		cin.ignore();
		while(lin--){
			linea = "";
			getline(cin, linea);
			lar = linea.length();

			for(int k = 0; k < lar; k++){
				if(let.count(linea[k])){
					sum += let[linea[k]];
				}
			}
		}
		
		sum /= 100;

		printf("%.2lf$\n", sum);
		let.clear();
	}

    return 0;
}