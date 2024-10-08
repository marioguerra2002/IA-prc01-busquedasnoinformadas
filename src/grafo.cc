#include "grafo.h"

Grafo::Grafo(int n_, MatrizDistancia matriz_, Nodo nodo_raiz_, Nodo nodo_final_) {
  n = n_;
  matriz = matriz_;
  for (int i = 0; i < n; ++i) {
    Nodo nodo(i, matriz);

    nodos.push_back(nodo);
  }
  nodo_raiz = nodo_raiz_;
  nodo_final = nodo_final_;
  // setPadres();
}
void Grafo::printGrafo() {
  for (int i = 0; i < n; ++i) {
    nodos[i].printNodo();
    nodos[i].printVecinos();
    std::cout << "\n";
  }
}

int Grafo::getNumeroAristas() {
  int aristas = 0;
  for (int i = 0; i < n; ++i) {
    aristas += nodos[i].getVecinos().size();
  }
  return aristas;
}

void Grafo::generarDot(const std::string& nombre_archivo) {
    std::ofstream archivo(nombre_archivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de salida: " << nombre_archivo << "\n";
        return;
    }

    archivo << "graph G {\n";
    for (int i = 0; i < n; ++i) {
      // Supongamos que cada nodo tiene un método getNombre() que devuelve el nombre del nodo
      std::string nombreNodo = std::to_string(nodos[i].getId());

      for (const auto& vecino : nodos[i].getVecinos()) {
        // Aquí suponemos que el vecino es representado por su índice o nombre
        std::string nombreVecino = std::to_string(vecino.first); // El nombre del vecino
        float coste = vecino.second; // El coste hacia el vecino

        // Asegúrate de no duplicar aristas
        if (nombreNodo < nombreVecino) {
            archivo << nombreNodo << " -- " << nombreVecino 
            << " [label=\"" << coste << "\"];\n";
        }
      }
    }
    archivo << "}\n";
    archivo.close();
}


