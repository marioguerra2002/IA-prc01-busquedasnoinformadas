#include "matriz_distancia.h"

MatrizDistancia::MatrizDistancia(int n) : n(n) {
  matriz.resize(n);
  for (int i = 0; i < n; ++i) {
    matriz[i].resize(n);
  }
}

void MatrizDistancia::setDistancia(int i, int j, int distancia) {
  matriz[i][j] = distancia;
  matriz[j][i] = distancia;
}

int MatrizDistancia::getDistancia(int i, int j) const {
  return matriz[i][j];
}

int MatrizDistancia::getN() const {
  return n;
}
