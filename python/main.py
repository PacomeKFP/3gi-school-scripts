from bike import *
from bgf_decoder import *
from binary_polynom import *
from encapsulation import *
from utils import Utils


# Keys Generation
print("Stating Keys Generation.....")

h_0, h_1, g = Utils.generate_h_g()

secret_key = h_0, h_1
public_key = Utils.compute_public_key(h_0, h_1, g=g, bike_version=1)  # BIKE 1

print("Keys Generated with succcess.....")

# Encapsulation

print("Stating Key Encapsulation process.....")
e_0, e_1 = brute_force_generator_2()
c_0, c_1 = Utils.encapsulate(e_0, e_1, public_key, bike_version=1) # BIKE 1

print("Key Encapsulated with succcess.....")
# symmetric key derivation
symmetric_key = K(e_0, e_1)

# decapsulation

print("Stating Key Decapsulation process.....")
e_0_prime, e_1_prime = bgf_decoder(h_0, h_1, c_0, c_1)
print("Key Decapsulation prcess end .....")

symmetric_key_decapsuled = bytes()

if e_0_prime == None or e_1_prime == None or e_0_prime.hamming_weight() + e_1_prime.hamming_weight() != BIKE.t:
    print("Decapsulation error !")

else:
    symmetric_key_decapsuled = K(e_0_prime, e_1_prime)

print(f"Symmetric key: {symmetric_key}")
print(f"Symmetric key after decapsulation: {symmetric_key_decapsuled}")