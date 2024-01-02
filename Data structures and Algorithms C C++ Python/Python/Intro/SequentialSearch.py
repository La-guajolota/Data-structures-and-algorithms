#Write a method, which will search a list for some 
#given value.

def seq_search(arr,value):
    size = len(arr)
    i=0

    while i<size:

        if value==arr[i]:
            return True
        
        i += 1
    
    return False

### Ejemplo de implementacion
"""
lista = [1,2,3,4,5,6,7,8,9,10]
print(seq_search(lista,102))
"""