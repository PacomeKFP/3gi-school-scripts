LAMBDA = 1
SHARED_KEY_SIZE = 256
BLACK_GREY_DECODER_ITERATION_NUMBER = 5
TAU = 3


class BikeParams:
    def __init__(self, quantum_security_level=LAMBDA, bike_variant= 1):
        if bike_variant in [1, 2]:
            if quantum_security_level == 1:
                self.n, self.r, self.w, self.t = 20326, 10163, 142, 134
            if quantum_security_level == 3:
                self.n, self.r, self.w, self.t = 39706, 19853, 206, 199
            if quantum_security_level == 5:
                self.n, self.r, self.w, self.t = 65498, 32749, 274, 264

        else:
            if quantum_security_level == 1:
                self.n, self.r, self.w, self.t = 22054, 11027, 134, 154
            if quantum_security_level == 3:
                self.n, self.r, self.w, self.t = 43366, 21683, 198, 226
            if quantum_security_level == 5:
                self.n, self.r, self.w, self.t = 72262, 36131, 266, 300


BIKE = BikeParams()