#include <bits/stdc++.h>
#define MAX 30

using namespace std;

int n;
int blocks[MAX];
int pilas[MAX][MAX];
int idPilas[MAX];

int buscar(int i, int a) {
  for (int k = 0; k < idPilas[i]; k++) {
    if (pilas[i][k] == a) {
      return k;
    }
  }

  return -1;
}

void reiniciar(int i, int st) {
  for (int k = st; k < idPilas[i]; k++) {
    int a = pilas[i][k];
    pilas[a][0] = a;
    idPilas[a] = 1;
    blocks[a] = a;
  }
  idPilas[i] = st;
}

void move_onto(int a, int b) {
  int pA = buscar(blocks[a], a);
  int pB = buscar(blocks[b], b);

  reiniciar(blocks[a], pA + 1);
  reiniciar(blocks[b], pB + 1);

  idPilas[blocks[a]]--;
  blocks[a] = blocks[b];
  pilas[blocks[b]][pB + 1] = a;
  idPilas[blocks[b]]++;
}

void move_over(int a, int b) {
  int pA = buscar(blocks[a], a);

  reiniciar(blocks[a], pA + 1);

  idPilas[blocks[a]]--;
  blocks[a] = blocks[b];
  pilas[blocks[b]][idPilas[blocks[b]]] = a;
  idPilas[blocks[b]]++;
}

void pile_onto(int a, int b) {
  int pilaA = blocks[a];
  int pilaB = blocks[b];
  int pA = buscar(pilaA, a);
  int pB = buscar(pilaB, b);
  // printf("%d %d %d %d\n", pilaA, pilaB, pA, pB);

  reiniciar(pilaB, pB + 1);

  for (int i = pA, k = pB + 1; i < idPilas[pilaA]; i++, k++) {
    pilas[pilaB][k] = pilas[pilaA][i];
    blocks[pilas[pilaA][i]] = pilaB;
  }

  idPilas[pilaB] += (idPilas[pilaA] - pA);
  idPilas[pilaA] = pA;
}

void pile_over(int a, int b) {
  int pilaA = blocks[a];
  int pilaB = blocks[b];
  int pA = buscar(pilaA, a);
  int pB = buscar(pilaB, b);
  // printf("%d %d %d %d\n", pilaA, pilaB, pA, pB);

  for (int i = pA, k = idPilas[pilaB]; i < idPilas[pilaA]; i++, k++) {
    pilas[pilaB][k] = pilas[pilaA][i];
    blocks[pilas[pilaA][i]] = pilaB;
  }

  idPilas[pilaB] += (idPilas[pilaA] - pA);
  idPilas[pilaA] = pA;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int k = 0; k < n; k++) {
    blocks[k] = k;
    pilas[k][0] = k;
    idPilas[k] = 1;
  }

  string op, op2;
  int a, b;

  while (cin >> op && (op != "quit")) {
    cin >> a >> op2 >> b;

    if (a == b || blocks[a] == blocks[b]) {
      continue;
    }

    if (op == "move") {
      if (op2 == "onto") {
        move_onto(a, b);
      } else {
        move_over(a, b);
      }
    } else {
      if (op2 == "onto") {
        pile_onto(a, b);
      } else {
        pile_over(a, b);
      }
    }
  }

  for (int k = 0; k < n; k++) {
    printf("%d:", k);
    for (int j = 0; j < idPilas[k]; j++) {
      printf(" %d", pilas[k][j]);
    }
    printf("\n");
  }

  return 0;
}