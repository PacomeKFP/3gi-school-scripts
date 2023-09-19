"""
    Author: Pacome Kengali Fegue
    Content: Script to implement Cesar encryption method
"""
from enum import Enum


class Action(Enum):
    ENCRYPT = "Encrypt"
    DECRYPT = "Decript"

class Encodings(Enum):
    UNICODE = 1114112
    ASCII_128 = 128
    ASCII_256 = 256

class RouterUtils:
    @staticmethod
    def yes_no(question: str) -> bool:
        response = input(question)
        if response.lower() in ["yes", "y", "oui", "o", "ok"]:
            return True
        return False


class Cesar:
    def __init__(
        self,
        action: Action = Action.ENCRYPT,
        clear_data=None,
        encrypted_data=None,
        key="c",
        encoding: Encodings = Encodings.UNICODE,
    ):
        # TODO remove asserts and replace them by conditions
        assert len(key) == 1
        assert clear_data != None or encrypted_data != None
        assert type(action) == Action

        self.action = action
        self.clear_data = clear_data
        self.encrypted_data = encrypted_data
        if clear_data == None and encrypted_data != None and action == Action.ENCRYPT:
            print("It is still like you made a confusion on action to perform")
            change_action = RouterUtils.yes_no(
                f"Do you want to change action from {Action.ENCRYPT.name} to  {Action.DECRYPT.name} ? "
            )
            if change_action:
                self.action = Action.DECRYPT

        if clear_data != None and encrypted_data == None and action == Action.DECRYPT:
            print("It is still like you made a confusion on action to perform")
            change_action = RouterUtils.yes_no(
                f"Do you want to change action from {Action.DECRYPT.name} to  {Action.ENCRYPT.name} ? "
            )
            if change_action:
                self.action = Action.ENCRYPT

        if self.action == Action.ENCRYPT and self.clear_data == None:
            self.clear_data = input("Enter the string to encrypt")

        if self.action == Action.DECRYPT and self.encrypted_data == None:
            self.encrypted_data = input("Enter the string to DECRYPT")

        self.key = key
        self.encoding = encoding
        # TODO Verify encoding can support input string

    def encrypt(self) -> str:
        return "".join(
            chr((ord(letter) + ord(self.key)) % self.encoding.value)
            for letter in self.clear_data
        )

    def DECRYPT(self) -> str:
        return "".join(
            chr((ord(letter) - ord(self.key) + self.encoding.value) % self.encoding.value)
            for letter in self.encrypted_data
        )

    def run(self):
        if self.action == Action.ENCRYPT:
            return self.encrypt()
        if self.action == Action.DECRYPT:
            return self.DECRYPT()


def main():
    cesar = Cesar(clear_data="papa va au marché", encoding=Encodings.ASCII_256)
    print(cesar.run())

main()
