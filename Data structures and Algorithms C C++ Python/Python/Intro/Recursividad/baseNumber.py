def printInt(number, base):
    
    digit = number%base #RESUIDO
    number = int(number/base) #COCIENTE

    temp = ""
    conversion = "0123456789ABCDEF"

    if number != 0:
        temp += printInt(number,base)
    
    #conversion[digit] ecoje el caracter siendo como array
    temp += conversion[digit]

    return temp #Acaba con recursividad


"""
Analysis:
· Base value is provided along with the number in the 
function parameter.
· Remainder of the number is calculated and stored in digit.
· If the number is greater than base then, number 
divided by base is passed as an argument to the 
printInt() method recursively.
· Number will be printed with higher order first than 
the lower order digits. Time Complexity is O(N)

"""

print(printInt(15,16))