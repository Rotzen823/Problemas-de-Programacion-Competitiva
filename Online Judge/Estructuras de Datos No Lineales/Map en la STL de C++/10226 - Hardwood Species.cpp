#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
	char ax;

	cin >> n;

	scanf("%c", &ax);
	scanf("%c", &ax);

	while(n--){

		string pal = "";
		double t = 0;
		map<string, double> cont;

		while(getline(cin, pal)){
			if(pal == ""){
				break;
			}
			
			t++;
			cont[pal]++;
		}

		for(auto x : cont){
			cout << x.first << " ";
			double res = (x.second / t) * 100;

			printf("%0.4lf\n", res);
		}

		if(n){
			printf("\n");
		}
	}

    return 0;
}