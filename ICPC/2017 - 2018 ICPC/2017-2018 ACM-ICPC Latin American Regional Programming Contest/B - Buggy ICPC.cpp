#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

bool isVowel(char x){
    return x == 'a' || x == 'e' || x == 'i' || x == 'o'
    || x == 'u';
}

int solve(string &s){
    int n = s.length();

    int vowel = 0;
    for(int i = 0; i < n; i++){
        if(isVowel(s[i])){
            vowel++;
        }
    }

    if(vowel == 0){
        return 1;
    }

    if(!isVowel(s[0])){
        return 0;
    }

    if(vowel == 1){
        return n;
    }

    int firstVowel = (vowel + 1) / 2;

    int positionV;
    for(int i = 0; i < n; i++){
        if(isVowel(s[i])){
            firstVowel--;
            if(!firstVowel){
                positionV = i;
            }
        }
    }

    int ans = 1;
    positionV++;
    while (!isVowel(s[positionV]))
    {
        positionV++;
        ans++;
    }
    
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    string s;
    cin >> s;

    cout << solve(s) << ENDL;

    return 0;
}
