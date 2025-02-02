#!/usr/bin/python3

class Square:
    def __init__(self, width, height):
        # Ensure width and height are equal for a square
        if width != height:
            raise ValueError("Width and height must be the same for a square.")
        self.width = width
        self.height = height

    def area_of_my_square(self):
        """ Area of the square """
        return self.width * self.width

    def perimeter_of_my_square(self):
        """ Perimeter of the square """
        return self.width * 4

    def __str__(self):
        return "{}".format(self.width)

if __name__ == "__main__":

    s = Square(width=12, height=12)  # Example with equal width and height
    print(s)
    print(s.area_of_my_square())
    print(s.perimeter_of_my_square())
