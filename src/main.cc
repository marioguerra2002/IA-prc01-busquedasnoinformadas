#include "matriz_distancia.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
  if (argc != 5) {
    std::cerr << "Uso: " << argv[0] << " <archivo_entrada> <nodo_inicial> <nodo_final> <archivo_salida>\n";
    return 1;
  }
  std::ifstream entrada(argv[1]);
  std::ofstream salida(argv[4]);
  if (!entrada) {
    std::cerr << "No se pudo abrir el archivo de entrada\n";
    return 1;
  }
  if (!salida) {
    std::cerr << "No se pudo abrir el archivo de salida\n";
    return 1;
  }
  int nodo_inicial = std::stoi(argv[2]);
  int nodo_final = std::stoi(argv[3]);
  std::string input; // line
  std::string auxiliar;
  std::vector <std::string> input_vector;
  if (entrada.is_open()) {
    while (std::getline(entrada, auxiliar)) {
      for (unsigned i = 0; i < auxiliar.size(); ++i) {
        input += auxiliar[i];
      }
      input_vector.push_back(input);
      auxiliar.clear();
      input.clear();
    }
    auxiliar.clear();
    std::cout << "\n";
    for (unsigned i = 0; i < input_vector.size(); ++i) {
      std::cout << input_vector[i] << std::endl;
    }
    // el primer elemento del vector es el numero de nodos
    int n = std::stoi(input_vector[0]);
    std::cout << "Numero de nodos: " << n << std::endl;
    // borrar el primer elemento del vector
    input_vector.erase(input_vector.begin());
    for (unsigned i = 0; i < input_vector.size(); ++i) {
      std::cout << input_vector[i] << std::endl;
    }
    MatrizDistancia matriz(n, input_vector);
  }
}