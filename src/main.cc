
#include "dfs.h"

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
  int nombre_nodo_inicial = std::stoi(argv[2]);
  int nombre_nodo_final = std::stoi(argv[3]);
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
    // for (unsigned i = 0; i < input_vector.size(); ++i) {
    //   std::cout << input_vector[i] << std::endl;
    // }
    // el primer elemento del vector es el numero de nodos
    int n = std::stoi(input_vector[0]);
    // std::cout << "Numero de nodos: " << n << std::endl;
    // borrar el primer elemento del vector
    input_vector.erase(input_vector.begin());
    // for (unsigned i = 0; i < input_vector.size(); ++i) {
    //   std::cout << input_vector[i] << std::endl;
    // }
    MatrizDistancia matriz(n, input_vector);
    // matriz.printMatriz();
    Nodo nodoinicial(nombre_nodo_inicial, matriz);
    Nodo nodofinal(nombre_nodo_final, matriz);

    // nodoinicial.printVecinos();
    // nodofinal.printVecinos();
    // std::cout << "\n";
    if (nombre_nodo_inicial == nombre_nodo_final) {
      salida << "Numero de nodos: 1" << std::endl;
      salida << "Numero de aristas: 1" << std::endl;
      salida << "Nodo inicial: " << nombre_nodo_inicial << std::endl;
      salida << "Nodo final: " << nombre_nodo_final << std::endl;
      salida << "_______________________________________" << std::endl;
      salida << "Iteracion: 0" << std::endl;
      salida << "Nodos generados: " << nombre_nodo_inicial << std::endl;
      salida << "_____________________________________" << std::endl;
      salida << "Camino hasta el nodo final: " << nombre_nodo_inicial << " -> " << nombre_nodo_final << std::endl;
      salida << "Coste total: 0.00" << std::endl;
      return 0;
    }
    Grafo grafo(n, matriz, nodoinicial, nodofinal);
    //grafo.generarDot(argv[4]);
    // grafo.printGrafo();
    std::cout << "Introduzca si quiere la búsqueda por amplitud (BFS) o profundidad (DFS): " << std::endl;
    std::string in;
    std::cin >> in;
    if (in == "BFS" || in == "bfs") {
      BFS bfs(grafo, nodoinicial, nodofinal);
      salida << bfs.printBFS(nodofinal, nodoinicial) << std::endl;
    } else if (in == "DFS" || in == "dfs") {
      DFS dfs(grafo, nodoinicial, nodofinal);
      salida << dfs.printDFS(nodofinal, nodoinicial) << std::endl;
    } else {
      std::cerr << "Introduzca una opción válida y vuelva a intentarlo" << std::endl;
      return 1;
    }
    //

    // meter ss en archivo de salida


  }
}
