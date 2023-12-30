import randomwalk as ran

FPS = 10
n = 5
nrows = 18
ncolumns = 50


particles = [(0, 0)] * n #possible since tuples are immutable

while True:

    particles = [ran.random_pos(p, nrows, ncolumns)]
    
    for p in particles:
        
        ran.display_grid(particles, nrows, ncolumns)
        ran.time.sleep(1 / FPS)



