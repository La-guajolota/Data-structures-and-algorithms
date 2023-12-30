import time
import math
import random

###
#UNO Solo regresa la posicion
###
def randomwalk(steps):
    position = (0,0) #Iniciamos en el origen

    for i in range(steps):
        angle = random.random() * 360 #Nueva direccion

        #Nueva ubicacion
        xpos = position[0] + math.cos(math.radians(angle))
        ypos = position[1] + math.sin(math.radians(angle))

        #Actualizamos 
        position = (xpos,ypos)
    
    return position


###
#DOS Se muestra en una matriz impresa
###

def postogrid(position, nrows, ncolumns):
    
    xpos, ypos = position #tuple unpacking

    columnpos = int(xpos + ncolumns / 2)
    rowpos = int(-ypos + nrows / 2)
    
    return (columnpos, rowpos)#Coordenadas en matriz


def random_pos(position, nrows, ncolumns):

    while True:
        angle = random.random() * 360 #Nueva direccion

        #Nueva ubicacion
        xpos = position[0] + math.cos(math.radians(angle))
        ypos = position[1] + math.sin(math.radians(angle))

        #Actualizamos 
        position = (xpos,ypos)

        #Nueva posicion en la matriz
        gridpos = postogrid(position,nrows,ncolumns)

        #Nos asegruamos que la nueva posicion generada este dentro de las dimenciones
        # del plano/matriz
        if (0 <= gridpos[1] <= nrows-1) and (0 <= gridpos[0] <= ncolumns-1):
            return position#Regresamos la posicion actual

#Teste de funcion random_pos
#print( random_pos((0,0),2,2)) #Sí funciona


def display_grid(particles, nrows, ncolumns):
    screen = [[" "] * ncolumns for i in range(nrows)]
    
    for element in particles:#Graficamos posicion
        xgrid, ygrid = postogrid(element, nrows, ncolumns)
        screen[ygrid][xgrid] = "*"
    
    print("#" * (ncolumns + 2))#Paredes
    
    for row in screen:
        print(f"#{''.join(row)}#")
    
    print("#" * (ncolumns + 2))

#Teste de funcion display_grid
#display_grid(([0,0],[1,1],[2,2],[3,3]),10,10) #Si fnciona
