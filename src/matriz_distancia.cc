#include "matriz_distancia.h"
#include <iostream>
#include <sstream>
#include <iomanip>

MatrizDistancia::MatrizDistancia(int n_, std::vector<std::string> input) {
  n = n_;
  matriz = new float*[n]; // matriz de n x n
  this->n = n; // cantidad de nodos
  std::cout << "Tamano de la matriz: " << n << std::endl;
  // dar valores -1 a toda la matriz (no es realmente necesario pero por si acaso)
  for (int i = 0; i < n; ++i) {
    matriz[i] = new float[n];
    for (int j = 0; j < n; ++j) {
      matriz[i][j] = -1.0;
    }
  }
  auto data_iterator = input.begin();
  matriz [0][0] = 0.00; // la distancia de un nodo a si mismo es 0 (1,1)
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) { // j = i para que no se repitan las aristas
      if (i == j) {
        matriz[i][j] = 0.00; // la distancia de un nodo a si mismo es 0 y se rompe el ciclo
        continue;
      }
      if (data_iterator != input.end()) { // si no se ha llegado al final del vector para evitar segmentation fault
        std::string data = *data_iterator; // obtener el valor del vector en la posicion actual
        float value = std::stof(data); // convertir el valor a float
        matriz[i][j] = value; // añadir el valor a la matriz
        matriz[j][i] = value; // añadir el valor a la matriz
        // lo ponemos dos veces ya que por ejemplo 1->2 es igual a 2->1 (el coste)
        data_iterator++; // avanzar al siguiente valor
      }
    }
  }
  // mostrar la matriz con formato
}
  // añadir los valores de las aristas a la matriz. Es importante destacar que va de 1-15,luego de 2-15, luego de 3-15, etc.

void MatrizDistancia::printMatriz() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << std::setw(3) << std::setprecision(2) << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
  


// void MatrizDistancia::setMatrizSize(int n) {
//   this->n = n;
//   for (int i = 0; i < n; ++i) {
//     matriz[i] = new float[n];
//   }
// }

