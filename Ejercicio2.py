# Ejercicio 2
# Complete el siguiente codigo para recorrer la lista `x` e imprima
# los numeros impares mayores que 100 y que pare de imprimir al encontrar un numero primo.
import numpy as np

x = np.int_(np.random.random(100)*10000)
print(x)

numdivi=0

for i in range(len(x)):
    if( x[i]%2!=0 and x[i]>100):
        print(x[i])
        
        for j in range(1,i):
            if(x[i]%x[j]==0):
                numdivi+=1
        if(numdivi<=2):
            break
        
        