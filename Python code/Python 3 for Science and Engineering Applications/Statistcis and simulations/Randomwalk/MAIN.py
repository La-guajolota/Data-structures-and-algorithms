import randomwalk as ran

FPS = 40#frames per second
n = 50 #Cantidad de puntos/ movimientos por mostrar
nrows = 10
ncolumns = 2*nrows

#Creamos la lista de los puntos,  empezamos en el origen
particles = [(0, 0)] * n #possible since tuples are immutable
#print(particles)

cont = 0
frame = 0
while True:

    pastPos = particles[cont]#poscion pasada
    particles[cont+1] = ran.random_pos(pastPos, nrows, ncolumns)#Siguiente
    cont += 1#Avanzamos a la nueva

    if(cont == n-1):
        cont = 0

    for p in particles:#Mostramos la actualizacion grafica del movimiento
        
        ran.display_grid(particles, nrows, ncolumns)
        ran.time.sleep(1 / FPS)
        print(f"Frame #{frame}")

    frame += 1
