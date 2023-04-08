#include <bits/stdc++.h>
#define MAX 1005
 
using namespace std;

string pal[MAX];
pair<string, int> palN[MAX];

int main() {
	string op;
	int c = 0;
	vector<string> res;
	while(cin >> op, !(op == "#")){
		pal[c] = op;
		palN[c].first = "";
		palN[c].second = c;
		for(char x : op){
			if(x >= 'a' && x <= 'z'){
				palN[c].first += (x - 32);
			}
			else{
				palN[c].first += x;
			}
		}
		sort(palN[c].first.begin(), palN[c].first.end());
		c++;
	}

	sort(palN, palN + c);

	/*for(int k = 0; k < c; k++){
		cout << palN[k].first << " " << palN[k].second << "\n";
	}*/

	if(palN[0].first != palN[1].first){
		res.push_back(pal[palN[0].second]);
	}

	for(int k = 1; k < (c - 1); k++){
		if(palN[k].first != palN[k + 1].first && palN[k].first != palN[k - 1].first){
			res.push_back(pal[palN[k].second]);
		}
	}

	if(palN[c - 1].first != palN[c - 2].first){
		res.push_back(pal[palN[c - 1].second]);
	}
	
	sort(res.begin(), res.end());

	for(auto x : res){
		cout << x << "\n";
	}
    
    return 0;
}