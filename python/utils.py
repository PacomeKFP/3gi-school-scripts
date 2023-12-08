import random
from bike import BIKE
from binary_polynom import BinaryPolynom
from encapsulation import *


class Utils:

    def __init__(self) -> None:
        pass

    @staticmethod
    def odd_div_2(r=BIKE.r) -> int:
        if (r // 2) % 2 == 0:
            return r//2 + 1
        return r//2

    @staticmethod
    def compute_public_key(h0: BinaryPolynom, h1: BinaryPolynom, bike_version: int = 3, g: BinaryPolynom = BinaryPolynom()) -> 'tuple[BinaryPolynom]':
        if bike_version == 1:
            return (h1*g, h0*g)

        if bike_version == 2:  # Incompleted, has to compute h0_inverse
            pol = BinaryPolynom()
            pol.get_random_polynom_with_weight(pol.size)
            return (pol, h1*h0)

        if bike_version == 3:
            return (h1+g*h0, g)

    @staticmethod
    def generate_h_g():
        h_0 = BinaryPolynom()
        h_0.get_random_polynom_with_weight()

        h_1 = BinaryPolynom()
        h_1.get_random_polynom_with_weight()

        g = BinaryPolynom()
        g.get_random_polynom_with_weight(Utils.odd_div_2())

        return h_0, h_1, g

    def encapsulate(e_0: BinaryPolynom, e_1:BinaryPolynom, public_key: 'tuple[BinaryPolynom]', bike_version: int = 3) -> 'tuple[BinaryPolynom]':

        if bike_version == 1:
            m = BinaryPolynom()
            m.get_random_polynom_with_weight(random.randint(1, BIKE.r))
            return m*public_key[0] + e_0, m*public_key[1] + e_1  # BIKE 1

        if bike_version == 2:
            return e_0 + e_1*public_key[1], None

        if bike_version == 3:
            e = BinaryPolynom()
            e.get_random_polynom_with_weight(Utils.odd_div_2())

            return e + e_1*public_key[0], e_0 + e_1*public_key[1]
        
