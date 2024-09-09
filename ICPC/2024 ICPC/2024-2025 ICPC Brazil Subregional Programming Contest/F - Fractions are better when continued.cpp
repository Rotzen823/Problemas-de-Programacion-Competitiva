#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi  = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define ENDL '\n'

struct Frac {
  int num, den;

  Frac(int num, int den) {
    int g = __gcd(num, den);
    this->num = num / g;
    this->den = den / g;
  }

  Frac operator*(Frac f) const { return Frac(num * f.num, den * f.den); }
  Frac operator/(Frac f) const { return (*this) * Frac(f.den, f.num);  }
  Frac operator+(Frac& f) const { return Frac(num * f.den + den * f.num , den * f.den); }
  Frac operator-(Frac& f) const { return Frac(num * f.den - den * f.num , den * f.den); }
  bool operator<(Frac& other) const { return num * other.den < other.num  * den; }
  bool operator==(Frac& other) const { return num == other.num  && den == other.den; }
  bool operator!=(Frac& other) const { return !(*this == other); }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;

    Frac uno(1, 1);
    Frac anterior(1, 1);

    for(int i = 1; i <= n; i++) {
        Frac act = uno / (uno + anterior);
        anterior = act;
    }

    cout << anterior.num << ENDL;

    return 0;
}
