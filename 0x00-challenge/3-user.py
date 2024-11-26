#!/usr/bin/python3
"""
User Model
"""
import hashlib
import uuid


class User():
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash in MD5
    """

    def __init__(self):
        """
        Initialize a new user:
        - assigned a unique `id`
        """
        self.id = str(uuid.uuid4())
        self.__password = None  # Private attribute to store hashed password

    @property
    def password(self):
        """
        Password getter
        """
        return self.__password

    @password.setter
    def password(self, pwd):
        """
        Password setter:
        - `None` if `pwd` is `None`
        - `None` if `pwd` is not a string
        - Hash `pwd` in MD5 before assign to `__password`
        """
        if pwd is None or not isinstance(pwd, str):
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        """
        Valid password:
        - `False` if `pwd` is `None`
        - `False` if `pwd` is not a string
        - `False` if `__password` is `None`
        - Compare `__password` and the MD5 value of `pwd` (case-insensitive)
        """
        if pwd is None or not isinstance(pwd, str):
            return False
        if self.__password is None:
            return False
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.__password


if __name__ == '__main__':
    print("Test User")

    # Create a user
    user_1 = User()
    if user_1.id is None:
        print("New User should have an id")

    # Ensure IDs are unique for each user
    user_2 = User()
    if user_1.id == user_2.id:
        print("User.id should be unique")

    # Test password hashing
    u_pwd = "myPassword"
    user_1.password = u_pwd
    if user_1.password != u_pwd:
        print("User.password should be hashed")

    # Ensure default password is None
    if user_2.password is not None:
        print("User.password should be None by default")

    # Test setting password to `None`
    user_2.password = None
    if user_2.password is not None:
        print("User.password should be None if setter to None")

    # Test invalid password (integer instead of string)
    user_2.password = 89
    if user_2.password is not None:
        print("User.password should be None if setter to an integer")

    # Test valid password
    if not user_1.is_valid_password(u_pwd):
        print("is_valid_password should return True if it's the right "
              "password")

    # Test invalid password
    if user_1.is_valid_password("Fakepwd"):
        print("is_valid_password should return False if it's not the right "
              "password")

    # Test comparing with `None`
    if user_1.is_valid_password(None):
        print("is_valid_password should return False if compare with None")

    # Test comparing with integer
    if user_1.is_valid_password(89):
        print("is_valid_password should return False if compare with integer")

    # Test if no password set before comparison
    if user_2.is_valid_password("No pwd"):
        print("is_valid_password should return False if no password set "
              "before")
