#Ejercicio4
# 'y' es una senal en funcion del tiempo 't' con las unidades descritas en el codigo.
# a. Grafique la senal en funcion del tiempo en la figura 'senal.png' ('y' vs. 't')
# b. Calule la transformada de Fourier (sin utilizar funciones de fast fourier transform) y
# grafique la norma de la transformada en funcion de la frecuencia (figura 'fourier.png')
# c. Lleve a cero los coeficientes de Fourier con frecuencias mayores que 10000 Hz y calcule 
# la transformada inversa para graficar la nueva senal (figura 'filtro.png')

import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq,fft2


n = 512 # number of point in the whole interval
f = 200.0 #  frequency in Hz
dt = 1 / (f * 128 ) #128 samples per frequency
t = np.linspace( 0, (n-1)*dt, n) 
y = np.sin(2 * np.pi * f * t) + np.cos(2 * np.pi * f * t * t)
noise = 1.4*(np.random.rand(n)+0.7)
y  =  y + noise

plt.figure()
plt.plot(t,y)
plt.title(" y vs t")
plt.savefig("senal.png")

def TFD(senial):
	coeficientes=[]
	for i in range(len(senial)):
		resultado=0
		for k in range(len(senial)):

			resultado += senial[k]*np.exp(-1j*np.pi*2*k*i/(len(senial)))
		coeficientes.append(abs(resultado/(len(senial))))

	return coeficientes

plt.figure()
plt.plot(TFD(y))
plt.title("Transformada")
plt.savefig("fourier.png")

transf= TFD(y)

def frecuencias(senial,d):
	n=len(senial)
	N=int(len(senial)/2)
	f1=[]
	f2=[]
	for i in range(0,N):
		f1.append(i)

	for i in range(1,N+1):
		f2.append(-i)
	f2=f2[::-1]

	frq=f1+f2
	return frq/(d*n)

transfnueva=np.copy(transf)
freq = frecuencias(y, t[1]-t[0])

plt.figure()
plt.plot(freq,transf)
plt.savefig("confrecuencias.png")
            
for i in range(len(transf)):
    
    if(np.abs(freq[i]>10000)):
       transfnueva[i]=0
    else:
       transfnueva[i]=transfnueva[i]
    
def TFDinv(senial):
	coeficientes=[]
	for i in range(len(senial)):
		resultado=0
		for k in range(len(senial)):

			resultado += senial[k]*np.exp(-1*-1j*np.pi*2*k*i/(len(senial)))
		coeficientes.append(abs(resultado/(len(senial))))

	return coeficientes
       
plt.figure()
plt.plot(freq,TFDinv(transfnueva))
plt.plot(freq,np.fft.ifft(transfnueva))
plt.savefig("filtro.png")