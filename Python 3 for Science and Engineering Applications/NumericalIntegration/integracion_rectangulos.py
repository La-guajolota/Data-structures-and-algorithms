import math

'''
One final word of caution on eval(). We used this function so the mathematical function
given by the user can be directly run as Python code. This can be dangerous when the user
inputs not a function as intended by the programmer but malicious code. Theoretically,
the user could provide code that steals data or erases the hard drive. These are extreme
examples but should highlight that eval() must always be used with caution. Since we are
not writing software for the end-user but rather just small tools for us, this is no concern
at this point.
'''

def integration(function, x1, x2, n, pos_neg):
    
    if x1 >= x2:#Verificamos las condiciones de los limites de integracion
        raise AssertionError("x1 must be smaller than x2!")
    
    totallength = x2 - x1
    partlength = totallength / n #Resolucion LIM n->0
    totalarea = 0 #Acomulador

    for i in range(n):#Cuantas reparticiones se ejecuta
        xvalue = x1 + partlength * i #Domino
        yvalue = eval(function.replace("x", str(xvalue)))#Rango
        partarea = yvalue * partlength #Area de rectangulo
        
        if(pos_neg == "pos"):
            totalarea += abs(partarea) #Acomulamos area +
        else:
            totalarea += partarea #Acomulamos area

    return round(totalarea, 5)

#Integramos una parabola
print(integration("(x)**2",0,2*3.1416,10**4,"pos"))

#Integramos un seno
print(integration("math.sin(x)", 0, 1*math.pi, 10**4,""))