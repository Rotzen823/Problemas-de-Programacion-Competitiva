#include <bits/stdc++.h>
#define MAX 105
 
using namespace std;

string pal[MAX];
pair<string, int> palN[MAX];

bool miComparacion(pair<string, int> a, pair<string, int> b){
	if(a.first == b.first){
		return pal[a.second] < pal[b.second];
	}

	return a.first < b.first;
}

int main() {
	char ax;
	int n;
	scanf("%d", &n);
	scanf("%c", &ax);
	scanf("%c", &ax);

	while(n--){
		int c = 0;
		string op = "";
		while(getline(cin, op)){
			if(op == ""){
				break;
			}
			
			pal[c] = op;
			palN[c].first = "";
			palN[c].second = c;
			for(char x : op){
				if(x != ' '){
					palN[c].first += x;
				}
			}
			sort(palN[c].first.begin(), palN[c].first.end());
			c++;
		}

		sort(palN, palN + c, miComparacion);

		/*for(int k = 0; k < c; k++){
			cout << palN[k].first << " " << palN[k].second << "\n";
		}*/
		vector<string> res;
		for(int k = 0; k < c; k++){
			for(int j = k + 1; j < c; j++){
				if(palN[k].first == palN[j].first){
					//cout << pal[palN[k].second] << " = " << pal[palN[j].second] << "\n";
					res.push_back(pal[palN[k].second] + " = " + pal[palN[j].second]);
				}
				else{
					break;
				}
			}
		}

		sort(res.begin(), res.end());

		for(auto x : res){
			cout << x << "\n";
		}


		if(n != 0){
			printf("\n");
		}
	}
    
    return 0;
}