#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cuadrada(ll a, ll b, ll c){
    int s = 0;
    ll raiz = (b * b) - (4 * a * c);

    if(raiz < 0){
        return 0;
    }

    ll r = (ll) sqrt(raiz);

    if(r * r != raiz){
        return 0;
    }

    ll x1 = -b + r;
    a *= 2;

    if(x1 % a == 0){
        s++;
    }
    x1 /= a;

    ll x2 = -b - r;

    if(x2 % a == 0){
        s++;
    }
    x2 /= a;

    if(s == 2 && x1 == x2){
        s--;
    }

    return s;
}

int lineal(ll b, ll c){
    if(c % b == 0){
        return 1;
    }

    return 0;
}

int main(){
    ll a, b, c;

    cin >> a >> b >> c;

	if(a == 0 && b == 0 && c == 0){
		printf("-1\n");
		return 0;
	}

    if(a == 0 && b == 0){
        printf("0\n");
        return 0;
    }

    if(a == 0){
        printf("%d\n", lineal(b, c));
        return 0;
    }

    printf("%d\n", cuadrada(a, b, c));
 
    return 0;
}