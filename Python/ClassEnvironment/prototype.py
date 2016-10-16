# /usr/bin/python

class Square:
    'Simple class defining a square'
    countSquares = 0 # Class variable shared among ALL instances of this class. It is the number of created squares.

    def __init__(self, name, side): # Class constructor
        self.name = name # Assign name to the instance of the class
        self.side = side # Assign side
        Square.countSquares += 1 # Modify the class variable to reflect that a new instance has been created

    def GetCount(self):
        return Square.countSquares

    def GetArea(self):
        return self.side*self.side

if __name__ == '__main__':
    smallSq = Square('smallSq',5)
    bigSq = Square('bigSq',10)

    print Square.__doc__
    print smallSq.name, smallSq.side, smallSq.GetArea()
    print bigSq.name, bigSq.side, bigSq.GetArea()
