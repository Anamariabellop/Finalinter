# Ejercicio 2
# Complete el siguiente codigo para recorrer la lista `x` e imprima
# los numeros impares mayores que 100 y que pare de imprimir al encontrar un numero primo.
import numpy as np

x = np.int_(np.random.random(100)*10000)
print(x)


for i in range(len(x)):
    if( x[i]%2!=0 and x[i]>100):
        print(x[i])
    else:
        break
        
        