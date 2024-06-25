#Binary seacrh in a sorted list

def bin_search(arr, value):
    size = len(arr)
    low = 0 #limite inferior
    high = size-1 #limite superior

    while low <= high:
        mid = int(low + (high-low)/2)

        if arr[mid] == value:
            return True
        else:#Acortamos la ventana de busqueda
            if arr[mid] < value:
                low = mid+1
            else:#Entonces es mayor que
                high = mid-1 
    
    return False

### Ejemplo de implementacion

lista = [1,2,3,4,5,6,7,8,9,10]
print(bin_search(lista,4))
