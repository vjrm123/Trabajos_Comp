import os
import time
def Multiplicacion(a, b):
    return a * b

def Sumar(a, b):
    return a + b

def Restar(a, b):
    return a - b

def Division(a, b):
    return a / b if b != 0 else  "No se puede dividir entre cero"

Numero1 = float(input(" Ingrese el primer numero..."))
Operador = input("Ingrese el operador...")
Numero2 = float(input("Ingrese el segundo numero..."))
Resultado = 0

if (Operador == "*"):
    Resultado = Multiplicacion(Numero1, Numero2)
elif (Operador == "+"):
    Resultado = Sumar(Numero1, Numero2)
elif (Operador == "-"):
    Resultado = Restar(Numero1, Numero2)
elif (Operador == "/"):
    Resultado = Division(Numero1, Numero2)
else:
    print("ingreso un operador invalido...")

print(f"El resultado es: {Resultado}")