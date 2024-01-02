"""
For example, a list [10,20,30,40,50,60] rotate by 
2 positions to:

                [30,40,50,60,10,20]
"""

def reverseArray(arr,start,end):
    i = start
    j = end

    while i<j:
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp

        i += 1
        j -= 1

def rotateArray(arr,k):
    n = len(arr)

    """
    Rotating list is done in two parts trick:
    
    1_ In the first part, we first reverse elements of 
    list first half and then second half.
    
    2_ Then we reverse the whole list there by 
    completing the whole rotation.
    """
    #Parte 1
    reverseArray(arr,0,k-1)
    reverseArray(arr,k,n-1)
    #Parte 2
    reverseArray(arr,0,n-1)


### Ejemplo de implementacion
"""
lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
rotateArray(lista,4)
print(lista)
"""
