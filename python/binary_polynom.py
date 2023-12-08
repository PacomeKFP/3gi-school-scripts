import random
from bike import *


class BinaryPolynom:  # Polynom or Vector
    def __init__(self, size=BIKE.r) -> None:
        self.size = size
        self.coefficients = [0 for i in range(self.size)]
        self.compact_row = list()
        self.non_zero = set()
        pass

    def zero_compact(self):
        self.non_zero = set([i for i in range(self.size)
                            if self.coefficients[i] == 1])

    def decompact(self):
        self.coefficients = [
            1 if i in self.non_zero else 0 for i in range(self.size)]

    def xor_coef_at_index(self, index: int, value: int = 1):
        if index >= self.size or value not in [0, 1]:
            return
        self.coefficients[index] ^= value

    def from_list(self, l):
        self.coefficients = list(map(int, l))

    def get_random_polynom_with_weight(self, weight=BIKE.w//2):
        self.coefficients[:weight] = [1 for i in range(weight)]
        random.shuffle(self.coefficients)
        self.compact()

    def hamming_weight(self):
        return self.coefficients.count(1)

    def transpose(self):
        self.coefficients[1:] = self.coefficients[1:][::-1]
        self.compact()

    def generate_col_and_compacted_col(self):
        self.col = [0]
        self.col[1:] = [self.coefficients[self.size-i]
                        for i in range(1, self.size)]

        self.compact_col = [i for i in self.compact_row]
        if self.compact_row[0] == 0:
            self.compact_col[0] = 0
            for i in range(len(self.compact_row)):
                self.compact_col[i] = self.size - self.compact_row[-i]
        else:
            for i in range(0, len(self.compact_row)):
                self.compact_col[i] = self.size - self.compact_row[-(i+1)]

    def __str__(self) -> str:
        return "".join(map(str, self.coefficients))

    def __repr__(self) -> str:
        return str(self.coefficients)

    def __add__(a, b):
        c = BinaryPolynom(a.size)
        for i in range(a.size):
            c.coefficients[i] = a.coefficients[i] ^ b.coefficients[i]
        return c

    def __eq__(self, __value: object) -> bool:

        if not isinstance(__value, BinaryPolynom):
            return False
        if self.size != __value.size:
            return False

        for i in range(self.size):
            if self.coefficients[i] != __value.coefficients[i]:
                return False
        return True

    def __sub__(a, b):
        return a + b

    def __mul__(a, b):  # TODO: Try to optimize this method.
        c = BinaryPolynom(a.size)

        for k in range(b.size):
            for j in range(k):
                c.coefficients[k] ^= a.coefficients[j] & b.coefficients[k-j]

        return c

    def compact(self):
        for i in range(len(self.coefficients)):
            if self.coefficients[i] == 1:
                self.compact_row.append(i)

    def truc(self, n: int):  # returns self % X^n
        if n > self.size:
            return self
        c = BinaryPolynom(n)
        c.coefficients = self.coefficients[:n]
        return c

    def right_shift(self, n: int):  # returns self >> n equivalent to self / X^n
        c = BinaryPolynom(self.size)
        if n < self.size:
            c.coefficients[n:] = self.coefficients[n:]

        return c
