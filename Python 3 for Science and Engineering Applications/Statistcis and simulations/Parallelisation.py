from multiprocessing import Process, Queue

#genrador de numeros primos
def primegen(n, queue):

    if n % 2 == 0:# Es n par?
        n += 1 #Lo hacemos impar

    while True:
        for i in range(3, int(n**0.5 + 1), 2):
                if n % i == 0:
                    break
        else:
                queue.put(n)
        n += 2