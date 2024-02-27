#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	int mas=0, menos=0;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		if(c=='+'){
			mas++;
		}else{
			menos++;
		}
	}

	if(mas<menos){
		swap(mas, menos);
	}
	
	set<ii>s;
	
	while(mas && menos){
		int GCD = __gcd(mas, menos);
		int axMas = mas/GCD;
		int axMenos = menos/GCD;
		s.insert({axMas, axMenos});
        //cout << mas << " " << menos << "\n";
		mas--;
		menos--;
	}

	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int x, y;
		cin>>x>>y;
		if(mas==menos){
			cout<<"YES"<<ENDL;
			continue;
		}

		if(x<y){
			swap(x, y);
		}

		int GCD = __gcd(x, y);
		x = x/GCD;
		y = y/GCD;

		if(s.count(ii(x, y))){
			cout<<"YES"<<ENDL;
		}else{
			cout<<"NO"<<ENDL;
		}

	}

    return 0;
}
