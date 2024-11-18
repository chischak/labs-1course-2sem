import math


class Figure:
    sides_count = 0


    def __init__(self, __color, *sides):
        self.__sides = list(sides)
        self.__color = []
        self.filled = False


    def get_color(self):
        return list(self.__color)


    def __is_valid_color(self, r, g, b):
        return all(isinstance(i, int) and 0 <= i <= 255 for i in (r, g, b))


    def set_color(self, r, g, b):
        for i in r,g,b:
            if isinstance(i,int) and 0 <= i <= 255:
                self.__color = (r, g, b)
            else:
                pass

    def __is_valid_sides(self, *new_sides):
        if len(new_sides) != self.sides_count:
            return False
        return all(isinstance(side, int) and side > 0 for side in new_sides)


    def get_sides(self):
        return self.__sides


    def __len__(self):
        return sum(self.__sides)


    def set_sides(self, *new_sides):
        if self.__is_valid_sides(*new_sides):
            self.__sides = list(new_sides)
        else:
            pass


class Circle(Figure):
    sides_count = 1


    def __init__(self, __color, circumference):
        super().__init__(circumference)
        self.__color = []
        self.__radius = circumference / (2 * math.pi)


    def get_radius(self):
        return self.__radius


    def get_square(self):
        return math.pi * self.__radius ** 2


class Triangle(Figure):
    sides_count = 3


    def get_square(self):
        a, b, c = self.__sides
        s = (a + b + c) / 2
        return (s * (s - a) * (s - b) * (s - c)) ** 0.5


class Cube(Figure):
    sides_count = 12


    def __init__(self, __color, side_length):
        super().__init__(__color)
        self.side_length = side_length * 12
        self.filled = False


    def get_volume(self):
        return self.side_length * 3


circle1 = Circle((200, 200, 100), 10) # (Цвет, стороны)
cube1 = Cube((222, 35, 130), 6)

# Проверка на изменение цветов:
circle1.set_color(55, 66, 77) # Изменится
print(circle1.get_color())
cube1.set_color(300, 70, 15) # Не изменится
print(cube1.get_color())

# Проверка на изменение сторон:
cube1.set_sides(5, 3, 12, 4, 5) # Не изменится
print(cube1.get_sides())
circle1.set_sides(15) # Изменится
print(circle1.get_sides())

# Проверка периметра (круга), это и есть длина:
print(len(circle1))

# Проверка объёма (куба):
print(cube1.get_volume())