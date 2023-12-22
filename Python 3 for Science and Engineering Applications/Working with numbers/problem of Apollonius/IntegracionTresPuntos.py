import math
import tresPuntos as TP

def circlefinder(a, b, c, tolerance=0.01, maxiter=10**5):
    if a == b or b == c or c==a:
        raise ValueError("Enter three distinct points!")
    if TP.falls_on_line(a, b, c, tolerance=0.1):
        raise ValueError("All given points lie on one line!")
    center = [(a[0] + b[0] + c[0]) / 3, (a[1] + b[1] + c[1]) / 3]
    step = 1
    dist1, distances, _ = TP.compute_distance(center, a, b, c)
    for iteration in range(maxiter):
        candidates = []
        for sign in (-1, 1):
            for coordinate in (0, 1):
                    candidates.append(TP.compute_distance \
                        (TP.move_vector(center, \
                        coordinate, sign * step), a, b, c))
        new_dist1, new_distances, new_center = min(candidates)
        if new_dist1 < dist1:
            dist1, distances, center = new_dist1, new_distances, \
            new_center
        else:
            step *= 0.5
        if dist1 < 0.01 * tolerance:
            break
    else:
        raise ArithmeticError("Does not converge")
    
    dist_a, dist_b, dist_c = distances
    if not (math.isclose(dist_a, dist_b, abs_tol=tolerance) and math.isclose(dist_a, dist_c, abs_tol=tolerance)):
        raise ArithmeticError("Estimate is not true center")
    
    return [(round(center[0], 3), round(center[1], 3)), round(dist_a, 3)]