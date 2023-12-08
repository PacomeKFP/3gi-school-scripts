from bike import *
from binary_polynom import BinaryPolynom
from math import ceil
def compute_threshold(s_w:int, bike_variant: int = 1, quantum_security_level: int = 1):
    if bike_variant in [1, 2]:
        if quantum_security_level == 1:
            return ceil(13.530 + 0.0069722 * s_w)
        if quantum_security_level == 3:
            return ceil(15.932 + 0.0052936 * s_w)

        if quantum_security_level == 5:
            return ceil(17.489 + 0.0043536 * s_w)

    else:
        if quantum_security_level == 1:
            return ceil(13.209 + 0.0060515 * s_w)

        if quantum_security_level == 3:
            return ceil(15.561 + 0.0046692 * s_w)

        if quantum_security_level == 5:
            return ceil(17.061 + 0.0038459 * s_w)

def compute_treshold(s: BinaryPolynom):
    return int(max([13.530 + 0.0069722 * (s.hamming_weight()), 36]))


def ctr(h_0: BinaryPolynom, position: BinaryPolynom, s: BinaryPolynom):
    count = 0
    for i in range(len(h_0.compact_col)):
        if s.coefficients[(h_0.compact_col[i] + position) % BIKE.r] == 1:
            count += 1
    return count


def flip_adjusted_error_position(e_i: BinaryPolynom, position: int):
    ajusted_position = position
    if position not in [0, e_i.size]:
        ajusted_position = e_i.size - position
    e_i.xor_coef_at_index(ajusted_position)


def recompute_syndrome(s: BinaryPolynom, pos: int, h_i: BinaryPolynom):
    for j in range(len(h_i.compact_row)):
        if h_i.compact_row[j] <= pos:
            s.xor_coef_at_index(pos-h_i.compact_row[j])
        else:
            s.xor_coef_at_index(s.size + pos-h_i.compact_row[j])


def BGFIter(s: BinaryPolynom, e: 'list[BinaryPolynom]', black: 'list[BinaryPolynom]', gray: 'list[BinaryPolynom]',  T: int, H: 'list[BinaryPolynom]'):

    pos = [BinaryPolynom(), BinaryPolynom()]

    for i in range(len(H)):  # for each part or the error (e_0, e_1)

        for j in range(0, BIKE.r):
            counter = ctr(H[i], j, s)
            if counter >= T:
                # e[i].xor_coef_at_index(j)
                flip_adjusted_error_position(e[i], j)
                pos[i].coefficients[j] = 1
                black[i].coefficients[j] = 1
            elif counter >= T-TAU:
                gray[i].coefficients[j] = 1

    for i in range(len(H)):  # for each part of the error (e_0, e_1)

        for j in range(s.size):
            if pos[i].coefficients[j] == 1:  # if the position was flipped, we need to flip the error[j]
                recompute_syndrome(s, j, H[i])


def BFMaskedIter(s: BinaryPolynom, e: 'list[BinaryPolynom]',  mask: 'list[BinaryPolynom]',  T: int, H: 'list[BinaryPolynom]'):
    # assert (len(e) == len(H) == len(mask))

    pos = [BinaryPolynom(), BinaryPolynom()]

    for i in range(len(H)):  # for each part or the error (e_0, e_1)

        for j in range(0, BIKE.r):
            counter = ctr(H[i], j, s)
            if counter >= T and mask[i].coefficients[j] == 1:
                # e[i].xor_coef_at_index(j)
                flip_adjusted_error_position(e[i], j)
                pos[i].coefficients[j] = 1

    for i in range(len(H)):  # for each part of the error (e_0, e_1)

        for j in range(s.size):
            if pos[i].coefficients[j] == 1:  # if the position was flipped, we need to flip the error[j]
                recompute_syndrome(s, j, H[i])

