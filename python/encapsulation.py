import random
from binary_polynom import BinaryPolynom
from bike import *
import hashlib

# Generer e0 et e1 deux polynomes tels que |e0| + |e1| = t

def brute_force_generator(t = BIKE.t):

    is_ok = False
    e0, e1 = BinaryPolynom(), BinaryPolynom()
    while not is_ok:
        e0.get_random_polynom_with_weight(random.randint(1, t))
        e1.get_random_polynom_with_weight(random.randint(1, t))
        is_ok = (e0.hamming_weight() + e1.hamming_weight() == t)
    
    return e0, e1

def brute_force_generator_2(t = BIKE.t):
    k = random.randint(1, t)
    e0, e1 = BinaryPolynom(), BinaryPolynom()
    e0.get_random_polynom_with_weight(k)
    e1.get_random_polynom_with_weight(t-k)
    
    return e0, e1

def K(e_0, e_1):
    bit_string = str(e_0) + str(e_1)
    hash = hashlib.sha3_256()
    hash.update(bit_string.encode())

    return hash.digest()[:SHARED_KEY_SIZE//8]