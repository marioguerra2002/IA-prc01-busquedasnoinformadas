#include <iostream>
#include <fstream>
#include <sstream>

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
  if (entrada.is_open()) {
    while (std::getline(entrada, auxiliar)) {
      for (unsigned i = 0; i < auxiliar.size(); ++i) {
        input += auxiliar[i];
      }
      std::cout << input << std::endl;
    }
  }
}