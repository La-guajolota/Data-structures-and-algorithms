"""
Given a list of positive and negative integer s, find 
a contiguous subarray whose sum (sum of elements) is 
maximized. 

Analysis:
· Maximum subarray in a list is found in a single scan. 
We keep track of global maximum sum so far and the 
maximum sum, which include the current element.

· When we find global maximum value so far is less 
than the maximum value containing current value we 
update the global maximum value.

· Finally return the global maximum value.
"""

def maxSubArraySum(arr):
    size = len(arr)
    maxSoFar = 0
    maxEndingHere = 0
    i = 0

    while i<size:
        maxEndingHere += arr[1]

        if maxEndingHere < 0:#Si la suma da neg
            maxEndingHere = 0
        
        if maxSoFar < maxEndingHere:
            maxSoFar = maxEndingHere #Guardamos el resultado mejor por el momento
    
        i += 1
    
    return maxSoFar

### Ejemplo de implementacion
"""
lista = [1, -2, 3, 4, -4, 6, -4, 8, 2]
print( maxSubArraySum(lista))
"""


