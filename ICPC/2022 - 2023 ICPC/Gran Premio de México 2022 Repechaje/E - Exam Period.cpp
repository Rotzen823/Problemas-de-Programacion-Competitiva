#include <bits/stdc++.h>
#define MAX 200005

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi grafo[MAX];
int tin[MAX], low[MAX], color[MAX];
bool ready[MAX];
int timer = 1, numC = 0;
stack<int> pila;

void tarjan(int u) {
  tin[u] = low[u] = timer++;
  ready[u] = true;
  pila.push(u);

  for (int v : grafo[u]) {
    if (!tin[v]) {
      tarjan(v);
    }

    if (ready[v]) {
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] == tin[u]) {
    numC++;
    while (true) {
      int v = pila.top();
      pila.pop();
      ready[v] = false;
      color[v] = numC;
      if (u == v) {
        break;
      }
    }
  }
}

bool solve2Sat(int n) {
  for (int k = 0; k < n; k++) {
    if (!tin[k]) {
      tarjan(k);
    }
  }

  for (int k = 0; k < n; k += 2) {
    if (color[k] == color[k + 1]) {
      return false;
    }
  }
  return true;
}

void add_edge(int a, bool na, int b, bool nb) {
  a <<= 1;
  b <<= 1;

  int notA = a + 1, notB = b + 1;
  if (na) {
    swap(a, notA);
  }
  if (nb) {
    swap(b, notB);
  }

  grafo[notA].push_back(b);
  grafo[notB].push_back(a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  bool imposible = false;
  for (int k = 0; k < m; k++) {
    int a, b, c;
    string op;
    cin >> a >> b >> op >> c;
    if (imposible) {
      continue;
    }

    if ((op == "<" && c == 0) || (op == ">" && c == 2)) {
      imposible = true;
    } else if ((op == "<=" && c == 2) || (op == ">=" && c == 0)) {
      continue;
    }

    if ((op == "!=" && c == 1)) {
      add_edge(a, true, b, false);
      add_edge(a, false, b, true);
    } else if ((op == "=" && c == 1)) {
      add_edge(a, true, b, true);
      add_edge(a, false, b, false);
    } else if ((op == "=" && c == 0) || (op == "<" && c == 1) ||
               (op == "<=" && c == 0)) {
      add_edge(a, true, b, true);
      add_edge(a, true, b, false);
      add_edge(a, false, b, true);
    } else if ((op == "=" && c == 2) || (op == ">" && c == 1) ||
               (op == ">=" && c == 2)) {
      add_edge(a, false, b, false);
      add_edge(a, true, b, false);
      add_edge(a, false, b, true);
    } else if ((op == "!=" && c == 2) || (op == "<" && c == 2) ||
               (op == "<=" && c == 1)) {
      add_edge(a, true, b, true);
    } else {
      add_edge(a, false, b, false);
    }
  }

  if (solve2Sat(n * 2) && !imposible) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
