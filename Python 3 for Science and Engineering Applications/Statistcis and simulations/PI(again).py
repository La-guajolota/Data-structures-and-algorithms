'''
In a previous task we calculated the constant Pi with arbitrary accuracy. The following task
has a similar objective, but will rely on random draws and statistics instead of numerical
computation. The basic idea is to repeatedly draw random points and to test whether
they lie inside or outside a circle. If a sufficient number of points is drawn, Pi can be
approximated in this way.
'''
import random
import matplotlib.pyplot as plt
import numpy as np

def pi2(n):
    inside = 0

    for i in range(n):
        x, y = random.random(), random.random()
        distance = (x ** 2 + y ** 2) ** 0.5#Pitagoras 

        if distance <= 1:#Dentro de la circunferencia
            inside += 1#contamos
            plt.scatter(x, y, color='green', marker='o')
        else:
            plt.scatter(x, y, color='red', marker='o')

    return 4 * (inside / n)#Apoximamos pi

##############################
# Cuarto de círculo
##############################

# Calcular las coordenadas x, y del cuarto de círculo
puntos_circunferencia = np.linspace(0, np.pi / 2, 100)# Crear un conjunto de puntos en el cuarto de círculo
x = np.cos(puntos_circunferencia)
y = np.sin(puntos_circunferencia)

###############
#Dibujamos todo
###############

plt.plot(x, y)#Grafiamos cuarto de circulo
PIaprox = pi2(100)#Puntos random para cacular pi

#Etiquetas
plt.axis('equal')  # Hacer que los ejes tengan la misma escala
plt.title(f'Cuarto de Círculo PI--> {PIaprox:.5f}')
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.grid(True)

#Imprime
plt.axis([0.0, 1.0, 0.0, 1.0])
plt.show()