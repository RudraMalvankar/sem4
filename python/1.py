# Expt1

# 1. Create string Hello World and print.
string_hello = "Hello World"
print(string_hello)

# 2. Print all data types. Change one type into another (Implicit and Explicit conversion). Find data types.
a = 10      # Integer
b = 10.5    # Float
c = "Python" # String
d = True    # Boolean
e = [1, 2, 3]  # List
f = (4, 5, 6)  # Tuple
g = {7, 8, 9}  # Set
h = {'a': 1, 'b': 2}  # Dictionary

print(type(a), type(b), type(c), type(d), type(e), type(f), type(g), type(h))

# Implicit conversion
x = a + b  # Integer + Float -> Float
print(x, type(x))

# Explicit conversion
y = int(b)  # Float to Integer
print(y, type(y))

# Arithmetic operations
add = a + y
sub = a - y
div = a / y
mul = a * y
avg = (a + y) / 2

print(f"Add: {add}, Sub: {sub}, Div: {div}, Mul: {mul}, Avg: {avg}")

# 3. Create and print array, set, tuple, list, and dictionary. Add and delete data.
import array
arr = array.array('i', [1, 2, 3])
arr.append(4)
arr.pop()
print(arr)

s = {1, 2, 3}
s.add(4)
s.remove(4)
print(s)

l = [1, 2, 3]
l.append(4)
l.remove(4)
print(l)

t = (1, 2, 3)  # Tuples are immutable
print(t)

d = {'a': 1, 'b': 2}
d['c'] = 3
d.pop('c')
print(d)

# 4. Create string and concatenate using different methods
str1 = "Hello"
str2 = "World"
print(str1 + " " + str2)
print("{} {}".format(str1, str2))
print(f"{str1} {str2}")
print(" ".join([str1, str2]))
print("%s %s" % (str1, str2))

# 5. Programs on string and other sequential data type indexing, slicing, reversing
sample_string = "Python"
print(sample_string[0])
print(sample_string[-1])
print(sample_string[1:4])
print(sample_string[::-1])

sample_list = [10, 20, 30, 40, 50]
print(sample_list[0])
print(sample_list[-1])
print(sample_list[1:4])
print(sample_list[::-1])

# 6. Program using for and while loops
print("For loop example:")
for i in range(5):
    print(i)

print("While loop example:")
i = 0
while i < 5:
    print(i)
    i += 1

# 7. Control statement - Find the greatest number among two
num1 = 10
num2 = 20
if num1 > num2:
    print(f"Greatest number is {num1}")
elif num2 > num1:
    print(f"Greatest number is {num2}")
else:
    print("Both numbers are equal")

# 8. Check if a number is palindrome
def is_palindrome(n):
    return str(n) == str(n)[::-1]

num = 121
if is_palindrome(num):
    print(f"{num} is a palindrome")
else:
    print(f"{num} is not a palindrome")

#Output

'''Hello World
<class 'int'> <class 'float'> <class 'str'> <class 'bool'> <class 'list'> <class 'tuple'> <class 'set'> <class 'dict'>
20.5 <class 'float'>
10 <class 'int'>
Add: 20, Sub: 0, Div: 1.0, Mul: 100, Avg: 10.0
array('i', [1, 2, 3])
{1, 2, 3}
[1, 2, 3]
(1, 2, 3)
{'a': 1, 'b': 2}
Hello World
Hello World
Hello World
Hello World
Hello World
P
n
yth
nohtyP
10
50
[20, 30, 40]
[50, 40, 30, 20, 10]
For loop example:
0
1
2
3
4
While loop example:
0
1
2
3
4
Greatest number is 20
121 is a palindrome
'''