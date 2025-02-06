# (I) FUNCTIONS

# (A) 1. A simple Python function
def fun():
    print("Welcome to GFG")
# Driver code to call a function
fun()

# (A) 2. Function to add two numbers
def add(num1: int, num2: int) -> int:
    """Add two numbers"""
    return num1 + num2

# Driver code
num1, num2 = 5, 15
ans = add(num1, num2)
print(f"The addition of {num1} and {num2} results {ans}.")

# Functions for addition, multiplication, subtraction, and division
def add_multiple(*args):
    return sum(args)

def multiply_multiple(*args):
    result = 1
    for num in args:
        result *= num
    return result

def subtract(a, b):
    return a - b

def divide(a, b):
    return a / b if b != 0 else "Cannot divide by zero"

print("Addition:", add_multiple(1, 2, 3, 4))
print("Multiplication:", multiply_multiple(2, 3, 4))
print("Subtraction:", subtract(10, 3))
print("Division:", divide(10, 2))

# (B) Function Arguments
# 3. Function to check if a number is prime
def is_prime(n):
    if n in [2, 3]:
        return True
    if n == 1 or n % 2 == 0:
        return False
    r = 3
    while r * r <= n:
        if n % r == 0:
            return False
        r += 2
    return True

print(is_prime(78), is_prime(79))

# 4. Default Arguments
def myFun(x, y=50):
    print("x:", x)
    print("y:", y)

myFun(10)

# 5. Keyword Arguments
def student(firstname, lastname):
    print(firstname, lastname)

student(firstname='Geeks', lastname='Practice')
student(lastname='Practice', firstname='Geeks')

# 6. Positional Arguments
def nameAge(name, age):
    print("Hi, I am", name)
    print("My age is", age)

print("Case-1:")
nameAge("Suraj", 27)
print("\nCase-2:")
nameAge(27, "Suraj")

# 7. Arbitrary Arguments (*args)
def myFun(*argv):
    for arg in argv:
        print(arg)

myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')

# 8. Arbitrary Keyword Arguments (**kwargs)
def myFun(**kwargs):
    for key, value in kwargs.items():
        print(f"{key} == {value}")

myFun(first='Geeks', mid='for', last='Geeks')

# 9. Docstring Example
def evenOdd(x):
    """Function to check if the number is even or odd"""
    if x % 2 == 0:
        print("even")
    else:
        print("odd")

print(evenOdd.__doc__)

# (II) CLASSES

# 1. Instantiating a class
class Dog:
    sound = "barks"

pomerean = Dog()
print('Pomerean', pomerean.sound)

# 2. Class with attributes and methods
class Dog:
    attr1 = "mammal"
    attr2 = "dog"
    
    def fun(self):
        print("I'm a", self.attr1)
        print("I'm a", self.attr2)

Rodger = Dog()
print(Rodger.attr1)
Rodger.fun()

# (III) EXCEPTIONS

# A) Try-Except
while True:
    try:
        x = int(input("Please enter a number: "))
        break
    except ValueError:
        print("Oops! Not a valid number. Try again.")

# B) Try-Except-Else
def divide(x, y):
    try:
        result = x // y
    except ZeroDivisionError:
        print("Sorry! You are dividing by zero")
    else:
        print("Yeah! Your answer is:", result)

divide(3, 2)
divide(3, 0)

# C) Try-Finally
def divide_finally(a, b):
    try:
        print(a / b)
    except ZeroDivisionError as e:
        print('catch ZeroDivisionError:', e)
    finally:
        print('All finish')

divide_finally(1, 2)
divide_finally(1, 0)

# (IV) INHERITANCE

# A) Single Inheritance
class Parent:
    def func1(self):
        print("This function is in the parent class.")

class Child(Parent):
    def func2(self):
        print("This function is in the child class.")

obj = Child()
obj.func1()
obj.func2()

# B) Multiple Inheritance
class Mother:
    mothername = ""
    def mother(self):
        print(self.mothername)

class Father:
    fathername = ""
    def father(self):
        print(self.fathername)

class Son(Mother, Father):
    def parents(self):
        print("Father:", self.fathername)
        print("Mother:", self.mothername)

s1 = Son()
s1.fathername = "RAM"
s1.mothername = "SITA"
s1.parents()

# C) Multilevel Inheritance
class Grandfather:
    def __init__(self, grandfathername):
        self.grandfathername = grandfathername

class Father(Grandfather):
    def __init__(self, fathername, grandfathername):
        self.fathername = fathername
        Grandfather.__init__(self, grandfathername)

class Son(Father):
    def __init__(self, sonname, fathername, grandfathername):
        self.sonname = sonname
        Father.__init__(self, fathername, grandfathername)
    
    def print_name(self):
        print('Grandfather name:', self.grandfathername)
        print("Father name:", self.fathername)
        print("Son name:", self.sonname)

s1 = Son('Anand', 'Bhagwat', 'Santosh')
print(s1.grandfathername)
s1.print_name()

# D) Hierarchical Inheritance
class Parent:
    def method(self):
        print("Parent method")

class Child1(Parent):
    def method1(self):
        print("Child1 method")

class Child2(Parent):
    def method2(self):
        print("Child2 method")

obj1 = Child1()
obj1.method()
obj1.method1()
obj2 = Child2()
obj2.method()
obj2.method2()
