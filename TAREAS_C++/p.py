def obtener_residuo_y_cociente(dividendo, divisor):
    cociente = 0
    while dividendo >= divisor:
        dividendo -= divisor
        cociente += 1
    residuo = dividendo

    return cociente, residuo


# Ejemplo de uso
dividendo = 15
divisor = 3

cociente, residuo = obtener_residuo_y_cociente(dividendo, divisor)
print("Dividendo:", dividendo)
print("Divisor:", divisor)
print("Cociente:", cociente)
print("Residuo:", residuo)