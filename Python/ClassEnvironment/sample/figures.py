# /usr/bin/python

class Figure:
    'Simple class defining a figure'
    countFigures = 0 # Class variable shared among ALL instances of this class. It is the number of created figures.

    def __init__(self, name): # Class constructor
        self.name = name # Assign name to the instance of the class
        Figure.countFigures += 1 # Modify the class variable to reflect that a new instance has been created

    def GetCount(self):
        return Figure.countFigures

class Square(Figure):
    'Simple subclass defining a square'

    def __init__(self,name,side):
        Figure.__init__(self,name)
        self.side = side # Assign side

    def GetArea(self):
        return self.side*self.side



if __name__ == '__main__':
    smallSq = Square('smallSq',5)
    bigSq = Square('bigSq',10)

    print Square.__doc__
    print smallSq.name, smallSq.side, smallSq.GetArea()
    print bigSq.name, bigSq.side, bigSq.GetArea()
