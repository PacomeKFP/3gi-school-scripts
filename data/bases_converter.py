from random import randint
from tqdm import tqdm


class BasesConverter:
    def __init__(
        self,
        input: str,
        separator: str = "-",
        initial_base: int = 10,
        final_base: int = 2,
    ) -> None:
        self.check_conform_string_as_number(input, separator)
        self.check_base_conformity(input, separator, initial_base)
        self.input = [int(number) for number in input.split(separator)]
        self.separator = separator
        self.initial_base = initial_base
        self.final_base = final_base
        self.output = []

    def check_conform_string_as_number(self, input: str, separator: str) -> bool:
        if not input.replace(separator, "").isdigit():
            print("l'entrée est incorrecte veillez la modifier")
            self.input = input(
                f"Entrer la chaine en separant les chiffres par des {separator}: "
            )
            self.check_conform_string_as_number(self.input, separator)

    def check_base_conformity(
        self, input: str, separator: str, initial_base: str
    ) -> bool:
        numbers = input.split(separator)
        for number in numbers:
            if int(number) >= initial_base:
                print(
                    "[❌] Ce nombre n'est pas valide, les chiffre sont plus grand que la base entrée"
                )
                self.initial_base = int(
                    input(f"Entrer la nouvelle base (nombre superieur à {number}) :")
                )
                self.check_base_conformity(input, separator, self.initial_base)
        print("[✔] La base est conforme")

    def convert(
        self, initial_number: list[int], initial_base: int, final_base: int
    ) -> list[int]:
        quotients: list[int] = [digit for digit in initial_number]
        final_number = []
        retaining = 0
        number_len = len(quotients)
        index = 0
        last_null = -1
        while last_null != number_len - 1:
            extended_digit_10 = quotients[index] + retaining * initial_base
            while extended_digit_10 < final_base:
                quotients[index] = 0
                last_null = index
                index += 1

                if index == number_len:
                    final_number.insert(0, extended_digit_10)
                    return final_number
                
                extended_digit_10 = extended_digit_10 * initial_base + quotients[index]

            quotients[index] = extended_digit_10 // final_base
            retaining = extended_digit_10 % final_base
            index += 1
            if index == number_len:
                final_number.insert(0, retaining)
                retaining = 0
                index = 0
        return final_number

    def verify(self)->bool:
        
        input = 0
        for digit in self.input:
            input = input*self.initial_base + digit

        output = 0
        for digit in self.result:
            output = output*self.final_base + digit

        return input == output;
    def run(self):
        self.result = self.convert(self.input, self.initial_base, self.final_base)
        print(f"{self.separator}".join(str(digit) for digit in self.result))
        print(self.verify())
    
    def run_test(self, tours=1048576):
        success = 0
        initial_lt_final = 0
        for tour in tqdm(range(tours)):
            self.initial_base = randint(2, 4096)
            self.input = [randint(0 * i, self.initial_base - 1) for i in range(randint(2, 256))]
            self.final_base = randint(2, 4096)
            if self.initial_base == self.final_base:
                self.final_base += 1
            if self.initial_base < self.final_base:
                initial_lt_final += 1
            self.result = self.convert(self.input, self.initial_base, self.final_base)
            if self.verify():
                success += 1
        
        return tours, success, initial_lt_final
            
            
    


if __name__ == "__main__":
    converter = BasesConverter(input="5-154-12-45-12-48", initial_base=176, final_base=176)
    converter.run_test()
