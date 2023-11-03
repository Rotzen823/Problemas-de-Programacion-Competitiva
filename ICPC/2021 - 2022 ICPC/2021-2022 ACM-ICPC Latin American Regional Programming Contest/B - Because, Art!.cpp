#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
const double PI = acos(-1);

//const int N = 4200000; // 200MB
const int N = 2100000; // 100MB
struct Complex {
    double x, y;

    Complex(double x = 0, double y = 0) : x(x), y(y) {}

    friend Complex operator + (const Complex &u, const Complex &v) { return Complex(u.x + v.x, u.y + v.y); }
    friend Complex operator - (const Complex &u, const Complex &v) { return Complex(u.x - v.x, u.y - v.y); }
    friend Complex operator * (const Complex &u, const Complex &v) {
        return Complex(u.x * v.x - u.y * v.y, u.x * v.y + u.y * v.x); 
    }
} a[N], b[N];

int P[N];
void init_P(int n) {
    int l = 0; while ((1 << l) < n) ++l;
    for (int i = 0; i < n; ++i) P[i] = (P[i >> 1] >> 1) | ((i & 1) << l - 1);
}

vector<Complex> init_W(int n) {
    vector<Complex> w(n); w[1] = 1;
    for (int i = 2; i < n; i <<= 1) {
        auto w0 = w.begin() + i / 2, w1 = w.begin() + i;
        Complex wn(cos(PI / i), sin(PI / i));
        for (int j = 0; j < i; j += 2)
            w1[j] = w0[j >> 1], w1[j + 1] = w1[j] * wn;
    }
    return w; 
} auto w = init_W(1 << 21);

void DIT(Complex *a, int n) {
    for (int k = n >> 1; k; k >>= 1)
        for (int i = 0; i < n; i += k << 1)
            for (int j = 0; j < k; ++j) {
                Complex x = a[i + j], y = a[i + j + k];
                a[i + j + k] = (x - y) * w[k + j], a[i + j] = x + y;
            }
}
void DIF(Complex *a, int n) {
    for (int k = 1; k < n; k <<= 1)
        for (int i = 0; i < n; i += k << 1)
            for (int j = 0; j < k; ++j) {
                Complex x = a[i + j], y = a[i + j + k] * w[k + j];
                a[i + j + k] = x - y, a[i + j] = x + y;
            }
    for (int i = 0; i < n; ++i) a[i].x /= n, a[i].y /= n;
    reverse(a + 1, a + n);
}

vi Mul(const vi &A, const vi &B, int n1, int n2) {
    int n = 1; while (n < n1 + n2 - 1) n <<= 1; init_P(n);
    for (int i = 0; i < n1; ++i) a[i] = Complex(A[i], 0);
    for (int i = 0; i < n2; ++i) b[i] = Complex(B[i], 0);
    fill(a + n1, a + n, Complex(0, 0)); fill(b + n2, b + n, Complex(0, 0));
    DIT(a, n); DIT(b, n);
    for (int i = 0; i < n; ++i) a[i] = a[i] * b[i];
    DIF(a, n); vi ans(n1 + n2 - 1); for (int i = 0; i < n1 + n2 - 1; ++i) ans[i] = (ll) (a[i].x + 0.5);
    return ans;
}

void solve(vi const& a, vi const& b, vi &res){
    vi suma;
    int n = a.size();
    int i = 0;
    while(i < n && ((a[i] < 0 && b[i] < 0) || (a[i] == 0 || b[i] == 0))){
        suma.push_back(a[i] * b[i]);
        i++;
    }

    int j = n - 1;
    while(j >= i && ((a[j] > 0 && b[j] > 0) || (a[j] == 0 || b[j] == 0))){
        suma.push_back(a[j] * b[j]);
        j--;
    }

    sort(suma.begin(), suma.end(), greater<ll>());
    suma.push_back(0);
    for(int k = 1; k < (int) suma.size(); k++){
        suma[k] += suma[k - 1];
    }

    vi ax, bx;
    if(i <= j && a[i] < 0){
        for(int k = i, r = j; k <= j; k++, r--){
            ax.push_back(abs(a[r]));
            bx.push_back(abs(b[k]));
        }
    }
    else{
        for(int k = i, r = j; k <= j; k++, r--){
            ax.push_back(abs(a[k]));
            bx.push_back(abs(b[r]));
        }
    }

    vi pol;
    if(ax.size() > 0){
        pol = Mul(ax, bx, ax.size(), bx.size());
    }

    res.resize(n);
    for(int k = 0; k < n; k++){
        if((k + 1) < (int) suma.size()){
            res[k] = suma[k];
            continue;
        }
        res[k] = suma[suma.size() - 1] - pol[(k + 1) - suma.size()];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    vi a(n), b(n);

    for(int k = 0; k < n; k++){
        cin >> a[k];
    }

    for(int k = 0; k < n; k++){
        cin >> b[k];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vi maxR, minR;
    solve(a, b, maxR);
    
    vi c(n);

    for(int k = 0, j = n - 1; k < n; k++, j--){
        c[k] = -a[j];
    }

    solve(c, b, minR);

    for(int k = 0; k < n; k++){
        cout << -minR[k] << " " << maxR[k] << "\n";
    }

    return 0;
}
