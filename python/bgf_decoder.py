from bike import *
from binary_polynom import BinaryPolynom
from decapsulation import *
LOG_FILE_PATH = "logs/bgf_decoder.txt"

def bgf_decoder(h_0: BinaryPolynom, h_1: BinaryPolynom, c_0: BinaryPolynom, c_1: BinaryPolynom):
    H = [h_0, h_1]

    # Step 1: Compute the syndrome
    s = c_0 * h_0 + c_1 * h_1

    # Step 2: Decoding Using the Black-Grey Flip decoder
    e = [BinaryPolynom(), BinaryPolynom()]

    for h_i in H:
        h_i.compact()
        h_i.generate_col_and_compacted_col()

    black, gray = [BinaryPolynom(), BinaryPolynom()], [BinaryPolynom(), BinaryPolynom()]
    for i in range(1, 51):  # Iterating 50 times
        T = compute_threshold(s.hamming_weight())
        BGFIter(s, e, black, gray, T, H)

        if i == 1:
            t = (len(h_0.compact_col) + 1) // 2 + 1
            BFMaskedIter(s, e, black, T, H)
            BFMaskedIter(s, e, gray, T, H)

        print(f"The syndrome weight is: {s.hamming_weight()}")

    if s.hamming_weight() == 0:
        return e
    else:
        print("Decapsulation failed")
        return None, None