import os #nos permite usar instrucciones de nuestro sistema operativo
import time

lista = []

while True:
    print("--- MENU PRINCIPAL ---"
          "\n1. Insertar un dato."
          "\n2. Eliminar un dato."
          "\n3. Buscar un dato."
          "\n4. Sobreescribirt un dato."
          "\n5. Mostrar el contenido de la lista."
          "\n6. Salir.")
    opcion = int(input("elije una opcion: "))
    if(opcion == 1):
        dato = input("ingrese un dato: ")
        lista.append(dato)
        print("dato insertado ccorectamente")
        time.sleep(2) # sedemora 2 segundos
        os.system("cls") #ayuda para que vuelva a aparecer el menu 
    elif (opcion == 2):
        dato = input("ingresa el dato a eliminar: ")
        if(dato in lista):
            lista.remove(dato)
            print("dato eliminado correctamente...")
            time.sleep(2)
            os.system("cls")
        else:
            print("el dato " + dato + " no existe en la lista...")
            time.sleep(2)
            os.system("cls")
    elif (opcion == 3):
        dato = input("ingresa el nombre a bsucar: ")
        if(dato in lista):
            print("el dato ya esta en la lista, y esta en la posicion", lista.index(dato)) #index muestra la posicion de un dato
            time.sleep(3)
            os.system("cls")
        else:
            print("el nombre " + dato + " no esta en la lista...")
            time.sleep(2)
            os.system("cls")
    elif(opcion == 4):
        datoAnterior = input("ingresa el dato la que quieres sobreescribir...")
        if (datoAnterior in lista):
            indice = lista.index(datoAnterior)
            DatoNuevo = input("ingrese el nuevo dato: ")
            lista[indice] = DatoNuevo
            print("el dato se sobreescribio correctamente")
            time.sleep(3)
            os.system("cls")
        else:
            print("el dato " + datoAnterior + "no existe...")
            time.sleep(3)
            os.system("cls")
    elif(opcion == 5):
        print(lista)
        time.sleep(3)
        os.system("cls")
    elif(opcion == 0):
        respuesta = input("estas seguro?:  (s/n): ")
        if(respuesta.upper() == "S"):
            print("saliendo del programa...")
            time.sleep(3)
            os.system("cls")
            break
    else:
        print("opcion no valida!!!")
        time.sleep(3)
        os.system("cls")