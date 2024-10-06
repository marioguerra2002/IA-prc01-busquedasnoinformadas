#include "nodo.h"
#include "matriz_distancia.h"
#include <fstream>

class Grafo {
  public:
    Grafo(int, MatrizDistancia);
    Grafo() {};
    void printGrafo();
    void generarDot(const std::string&);
    std::vector<Nodo> getNodos() { return nodos; }
    void setPadres();
  private:
    std::vector<Nodo> nodos;
    MatrizDistancia matriz;
    int n;
    Nodo nodo_raiz;
};