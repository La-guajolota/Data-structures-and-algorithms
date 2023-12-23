"""
The Monty Hall problem comes from a well-known American game show. The procedure
is quite simple: one win and two blanks (goats) are hidden behind three doors. The
candidate chooses one of the doors (e.g. door 2). Then the game master opens a door
with a blank (e.g. door 1). Now the candidate has the option to revise his original
decision or to stick to it. The question is now: Can the candidate increase her chances
of winning if she changes her choice after opening the first door? We assume the game
master always opens a door with a blank. Define a function that approximates the
candidate's chances of winning for both decisions (change or keep) using simulations.
"""
import random
import matplotlib.pyplot as plt
import numpy as np

def SimulGame(n):
    RATIO = [0,0] #Juegos ganados
    winsKEPP = 0
    winsCHANGE = 0

    for i in range(n):#Cantidad de juegos por simular
        
        Puertas = [0,0,0]#Ninguno tiene el premio
        WinPuerta = random.randint(0,2)
        Puertas [WinPuerta] = 1 # Puerta ganadora

        #El jugador escoge una puerta
        UserPuerta = random.randint(0,2)

        #El GameMaster abre puerta blank
        MasterPuesta = random.randint(0,2)
        while(MasterPuesta == winsCHANGE):#Escojemos otra puerta hasta que no se toopa con el premio
            MasterPuesta = random.randint(0,2)
        
        #Solo queda la puetas escogida y la sobrante
        #NOS QUEDAMOS CON LA MISMA OBCION
        if(UserPuerta == WinPuerta):
            winsKEPP += 1 

        #CAMBIAMOS A LA OTRA PUERTA SOBRANTE
        UserPuerta = 3 - (UserPuerta + MasterPuesta)
        if(UserPuerta == WinPuerta):
            winsCHANGE += 1 
            
         
    #Porcentajes de exito en cambiar o continuar con nuestra eleleccion
    RATIO[0] = winsKEPP/n    
    RATIO[1] = winsCHANGE/n

    #print(f'Sumkeep--> {RATIO[0]:.5f} Sumchange --> {RATIO[1]:.5f}')

    return  RATIO



def Dibujamos_Simulaciones(n):
    Sumkeep = 0
    Sumchange = 0

    for veces in range(n):

        KEPP, CHANGE = SimulGame(100)
        plt.scatter(KEPP, CHANGE, color='green', marker='o',)

        Sumkeep += KEPP
        Sumchange += CHANGE
        plt.scatter(Sumkeep/n, Sumchange/n, color='red', marker='o',)

    #print(f'Sumkeep--> {Sumkeep/n:.5f} Sumchange --> {Sumchange/n:.5f}')
    

Dibujamos_Simulaciones(100)

#Etiquetas
plt.axis('equal')  # Hacer que los ejes tengan la misma escala
plt.title('Juego de Mont Hall')
plt.xlabel('Eje X mas a la dercha es mejor KEPP')
plt.ylabel('Eje Y mas a la izquierda es mejor CHANGE')
plt.grid(True)

#Imprime
plt.show()