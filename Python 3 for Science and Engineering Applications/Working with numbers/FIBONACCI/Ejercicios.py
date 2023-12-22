import math
import time
from sympy import GoldenRatio

phi = GoldenRatio.evalf()

'''
Code a function that produces the first 5,000 Fibonacci numbers and returns them in a list.
'''

def fibonacci1(n):
    elements = [1, 1]
    for i in range(n):
        elements.append(elements[-1] + elements[-2]) #Suma el último elemento [-1] con el anterior a ese [-2]
    return elements[:-2]      # Regresamos toda la lista menos los ultimos elementos, desfase por los primeros 2 elementos de la lista


'''
It is possible to calculate the n-th Fibonacci number without recursion by using the
formula of Moivre-Binet. Implement it in Python and compute the 1000th element of
the sequence. Use the regular approach shown above and compare results. What do
you notice? What went wrong?
'''

def fibonacci_binet(n):
    return round((phi**n - (-phi)**(-n)) / math.sqrt(5))

def fibonacci2(n):

    lista = [] 
    for i in range(n):
        lista.append(fibonacci_binet(i+1)) #evitamos el termino 0
    return lista

'''
Compare the performance of two different implementations of functions that generate
Fibonacci numbers. Hint: time.time() or time.monotonic() can be used to measure the
runtime of functions.
'''

def Tiempo_medido(func, TERMINOS):
    # Obtén el tiempo monotónico actual
    tiempo_inicio = time.perf_counter()

    #Operaciones a ejecutar que toman tiempo
    func(TERMINOS)

    # Obtén el tiempomonotónico después de la operación
    tiempo_fin = time.perf_counter()

    # Calcula la diferencia de tiempo
    diferencia_de_tiempo = tiempo_fin - tiempo_inicio
    print("Tiempo en segundos de ejecucion:", diferencia_de_tiempo)
    return diferencia_de_tiempo

def Resultados_ejerciocio3():
    terminos = 1000
    F1 = Tiempo_medido(fibonacci1,terminos)
    F2 = Tiempo_medido(fibonacci2,terminos)
    print("F1 es tants veces mas rapido",F2/F1 )

'''
The quotient of two adjacent Fibonacci numbers approaches the golden ratio
(1.6180339887…) when n approaches infinity. Compute the quotient for the elements
10^1, 10^2, 10^3 10^4, and 10^5 and the percentage deviation from the true resul
'''
def percentage_deviation(true_result, approximate_result):
    try:
        deviation = abs((true_result - approximate_result) / true_result) * 100
        return deviation
    except ZeroDivisionError:
        # Handle the case where the true_result is zero to avoid division by zero
        print("Error: True Result should not be zero.")
        return 


def quotient(termino_numerador):

    assert termino_numerador > 1

    a, b = 1, 1  #Primeros dos terminso dela sucesión 
    for i in range(termino_numerador):
        a, b = b, a + b

    Q = b/a
    return Q

#print(percentage_deviation(phi,quotient(10)))

'''
According to Zeckendorfs theorem, any integer can be written as the sum of exactly
two differing non-adjacent Fibonacci numbers. For example, 6 can be expressed as the
sum of 5 and 1. Create a function that accepts an integer as input and fractionates it
into two Fibonacci numbers. Hint: you can look up the required algorithm online.1
'''

'''
In the last function, fibonacci3(), we utilise two nested functions. Rewrite this function
to create a recursive solution that does not require an inner function. Hint: there is no
need for global variables here
'''