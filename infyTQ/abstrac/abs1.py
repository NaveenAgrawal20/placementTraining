from abc import ABC, abstractmethod


class Polygon(ABC):
    @abstractmethod
    def noSides(self):
        print("SIDES")

    def jig(self):
        print("JIGS")

class Rectangle(Polygon):
    def noSides(self):
        print("5")

    def isYes(self):
        print(True)


class Animal(ABC):

    def move(self):
        print("EVERYBODY CAN")

# t = Polygon()  NOT POSSIBLE
t = Rectangle()
t.noSides()
t.jig()

a = Animal()
a.move()