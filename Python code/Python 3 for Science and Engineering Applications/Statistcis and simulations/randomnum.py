import random

random.seed(123)
r = random.random()

print(r)

'''
Whenever results need to be reproducible, such as during debugging or in scientific
applications, it is necessary to set the seed. Computers generate random numbers
using pseudo-random number generators (PRNGs) because by design they are strictly
deterministic machines and all operations can be reproduced as they occur in a CPU. This
means that computers are bad at generating randomness. However, this shortcoming can
be circumvented by using special algorithms that generate seemingly random numbers.
Computers use certain factors that are presumably random, such as the number of processes
currently running, system load, available memory, user input, mouse movements, and so
on. These presumably "real" random factors are included in the algorithm's seed, which
guarantees different numbers will be generated the next time the algorithm is called. If this
is not desired, you can specify this seed and thus always get the same output. How many
numbers are taken from the seed is irrelevant. The example above shows how this function
can be used. It should be noted that the algorithms change over time and therefore it
cannot be guaranteed that different versions of Python will always produce the same
numbers even when using the same seed.
'''

#Creamos un arreglo de 10 numeros aleatorios ente 0 a 100 
z = [random.randrange(0,100) for i in range(10)]
print(z)

#Escojemos un elemento del arreglo
pick = random.choice(z)
print(pick)

#Draw a sample of 5 without replacement
#Esto significa que cada elemento seleccionado es único y no se repite en la muestra. 
data =  ["A", "B", "C", "D", "E", "F", "G", "H", "I"]
draw = random.sample(data, k=5)
print(draw)

#Draw a sample of 5 with replacement
#Como resultado, es posible que algunos elementos se seleccionen más de una vez en la muestra
draw = random.choices(data, k=5)
print(draw)

