from decapsulation import *

# We identify binary vectors by the set of their non zero positions
def one_round_bit_flippling(H: 'list[BinaryPolynom]', s:BinaryPolynom = BinaryPolynom(), u:int = 0):
    T = compute_threshold(s.hamming_weight())
    e = [BinaryPolynom(), BinaryPolynom()]
    J = [set() for i in range(BIKE.n)]
    for j in range(BIKE.n):
        l = min(ctr(H, j, s), T)
        J[l].add(j)
    
    e[T//BIKE.r].non_zero = J[T]
    for i in range(2):    
        e[i].decompact()
    
    s_prime = s+e[0]*H[0]+e[1]*H[1]
    S, delta = 5, 50
    d = BIKE.w//2 

def bit_flippiing(H: 'list[BinaryPolynom]', s:BinaryPolynom = BinaryPolynom(), u:int = 0):
    T = compute_threshold(s.hamming_weight())
    e = [BinaryPolynom(), BinaryPolynom()]
    J = [set() for i in range(BIKE.n)]
    for j in range(BIKE.n):
        l = min(ctr(H, j, s), T)
        J[l].add(j)

    e[T//BIKE.r].non_zero = J[T]
    for i in range(2):
        e[i].decompact()

    s_prime = s+e[0]*H[0]+e[1]*H[1]
    S, delta = 5, 50
    d = BIKE.w//2
    while s_prime.hamming_weight() > T:
        for i in range(d):
            s_prime = s_prime + e[0]*H[0]+e[1]*H[1]
        if s_prime.hamming_weight() > T:
            for i in range(d):
                s_prime = s_prime - e[0]*H[0]+e[1]*H[1]
        if s_prime.ham