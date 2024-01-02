"""
Write a method that will return the sum of all 
the elements of the integer list given list and 
its size as an argument.
"""
def SumArray(arr):
    
    size = len(arr)
    total = 0
    index = 0

    while index < size:
        total += arr[index]
        index += 1

    return total 


### Ejemplo de implementacion
"""
lista = [1,2,3,4,5,6,7,8,9,10]
print(SumArray(lista))
"""

