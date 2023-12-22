
def normal(vector):
    #Normal de un vector
    return (sum(x**2 for x in vector))**0.5

def ProductoCruz(a,b):
    #Producto cruz de vectores a Y b
    assert len(a) == len(b) == 3 #Vectores de 3 ejes
    return [a[1]*b[2] - a[2]*b[1],
            a[2]*b[0] - a[0]*b[2],
            a[0]*b[1] - a[1]*b[0]]

'''
ZIP() function
>>> x1 = [1, 2, 3]
>>> x2 = ["a", "b", "c"]
>>> list(zip(x1, x2))
[(1, 'a'), (2, 'b'), (3, 'c')]
'''

def linea_punto_distancia(line, point):
    """Calcula la distancia entre punto y linea
    La linea viene con vectres de direccion y apoyo como tuple.
    Apoyo, direccion y el punto vienen en listas con 3 elementos.
    """
    support, direction = line
    d = [s - p for s, p in zip(support, point)]
    return normal(ProductoCruz(d, direction)) / normal(direction)

def point_point_distance(x, y):
    """Distance between two points in 2D"""
    assert len(x) == len(y) == 2
    return ((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2) ** 0.5 

def norm_vector(vector):
    """Create a vector with length 1 that keeps the direction of the
    input vector"""
    length = normal(vector)
    return [x / length for x in vector]

def falls_on_line(point_a, point_b, point_c, tolerance):
    """Tests whether a b c lie on a line"""
    direction_ab = norm_vector([a - b for a, b in zip(point_a, \
    point_b)])
    direction_bc = norm_vector([b - c for b, c in zip(point_b, \
    point_c)])
    scalar_product = sum(x * y for x, y in zip(direction_ab, \
    direction_bc))
    return 1 - abs(scalar_product) < tolerance

def compute_distance(vector, a, b, c):
    diagonal = ((0, 0, 0), (1, 1, 1)) # support and direction
    distances = [point_point_distance(vector, p) for p in (a, b, c)]
    distance = linea_punto_distancia(diagonal, distances)
    return distance, distances, vector

def move_vector(vector, coordinate, movement):
    if coordinate == 0:
        return [vector[0] + movement, vector[1]]
    else:
        return [vector[0], vector[1] + movement]