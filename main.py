# Main que contiene la lógica de la aplicación y lectura de archivos.
import sys
from matriz import matriz
import numpy as np
def main():
  datos = []
  if len(sys.argv) != 2:
    print ("Uso: python main.py <fichero>")
    sys.exit(1)
  input = sys.argv[1]
  try:
    i = 0
    with open(input, "r") as f:
      # leer linea por linea
      fichero = f.readlines()
      n = int(fichero[0])
      prueba = float(fichero[1])
      prueba2 = float(fichero[2])
      prueba3 = float(fichero[3])
      fichero.pop(0)
      print ("Fichero: ", fichero)
      print ("Numero de elementos: ", n)
      print ("Prueba: ", prueba)
      print ("Prueba2: ", prueba2)
      print ("Prueba3: ", prueba3)
      matriz(fichero, n)
      # se le pasa de entrada ya las lineas del archivo y el tamaño de la matriz
      
  except FileNotFoundError:
    print ("El fichero no existe")
  except PermissionError:
    print ("No tienes permisos para leer el fichero")
  
      # fichero contiene las lineas del archivo
if __name__ == "__main__":
  main()