import numpy as np
def matriz(input, size):
  #se le pasa de entrada ya las lineas del archivo
  #se guarda en una matriz
  datos = [[-1.00] * size for _ in range(size)]
  iterador_filas = 0
  iterador_columnas = 0
  iterador_datos = 0
  # se crea una matriz de tamaño size x size con valores -1.00
  
  for iterador_filas in range (size):
    print ("Valor de la columna: ", iterador_columnas)
    for iterador_columnas in range(iterador_filas, size): # para que empiece en la siguiente columna
      print ("Valor de la fila y columna: ", iterador_filas, iterador_columnas)
      if iterador_columnas == iterador_filas:
        #si son iguales es que es sí mismo
        datos[iterador_filas][iterador_columnas] = 0.00
      # evitar que el iterador de datos se salga del rango
      if iterador_datos >= len(input):
        break
      datos[iterador_filas][iterador_columnas] = float(input[iterador_datos].strip()) # strip() elimina los espacios en blanco
      iterador_columnas += 1
      iterador_datos += 1
      print ("Valor de la coumna dentro del bucle: ", iterador_columnas)
    iterador_filas += 1
    print ("Valor de la fila dentro del bucle: ", iterador_filas)
    # iterador_columnas = iterador_filas # para que empiece en la siguiente fila
  # for linea in input:
  #   for i in range(size):
  #print(datos)
  matriz = np.array(datos)
  print(matriz)
      
    
  #   datos.append(float(linea.strip()))
  #   # se guarda en una fila de la matriz todos los datos