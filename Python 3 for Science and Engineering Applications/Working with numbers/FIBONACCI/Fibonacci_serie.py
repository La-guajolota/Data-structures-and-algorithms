#Varaible que contienen la cantidad de terminos que se quiera imprimir
terminos = 10 

#Funcion reucrsiva
def fibonacci1(n):
    assert n > 0 #verificamos que no teminos = 0 o negativos
    a, b = 1, 1  #Primeros dos terminso dela sucesión 
    for i in range(n):
        print(a)
        a, b = b, a + b


#Misma función pero almacenamos resultados en listas
def fibonacci2(n):
    elements = [1, 1]
    for i in range(n):
        elements.append(elements[-1] + elements[-2]) #Suma el último elemento [-1] con el anterior a ese [-2]
    return elements[:-2]      # Regresamos toda la lista menos los ultimos elementos, desfase por los primeros 2 elementos de la lista


#Misma función pero almacenamos resultados en diccionarios
def fibonacci3(n):
    elements = {1:1, 2:1}
    def inner(n): #Funcion dentro de la fucnión fibonacci3
        if n not in elements:
            next_element = inner(n-1) + inner(n-2) #Función recursiva
            elements[n] = next_element
        return elements[n] 
    return inner(n)


#--------------------------------------------------------------------------
#Ejecutamos la función
