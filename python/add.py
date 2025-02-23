# Basic Math Operations in Python

# Taking user input
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

# Performing operations
addition = num1 + num2
subtraction = num1 - num2
multiplication = num1 * num2
division = num1 / num2 if num2 != 0 else "Undefined (division by zero)"
floor_division = num1 // num2 if num2 != 0 else "Undefined (division by zero)"
modulus = num1 % num2 if num2 != 0 else "Undefined (modulus by zero)"
exponentiation = num1 ** num2

# Displaying results
print("\n--- Results ---")
print(f"Addition: {num1} + {num2} = {addition}")
print(f"Subtraction: {num1} - {num2} = {subtraction}")
print(f"Multiplication: {num1} * {num2} = {multiplication}")
print(f"Division: {num1} / {num2} = {division}")
print(f"Floor Division: {num1} // {num2} = {floor_division}")
print(f"Modulus: {num1} % {num2} = {modulus}")
print(f"Exponentiation: {num1} ** {num2} = {exponentiation}")

# Additional Math Functions
import math

print("\n--- Additional Math Functions ---")
print(f"Square root of {num1}: {math.sqrt(num1) if num1 >= 0 else 'Undefined (negative number)'}")
print(f"Square root of {num2}: {math.sqrt(num2) if num2 >= 0 else 'Undefined (negative number)'}")
print(f"Absolute value of {num1}: {abs(num1)}")
print(f"Absolute value of {num2}: {abs(num2)}")
print(f"Logarithm (base 10) of {num1}: {math.log10(num1) if num1 > 0 else 'Undefined (non-positive number)'}")
print(f"Logarithm (base 10) of {num2}: {math.log10(num2) if num2 > 0 else 'Undefined (non-positive number)'}")

print("\nThank you for using the Math Operations Program!")
