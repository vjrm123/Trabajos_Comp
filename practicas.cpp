#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Cal_modular.cpp"

#include <iostream>
#include <fstream>
#include <string>

void EncriptarArchivo(const std::string& nombreArchivo, int clave) {
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cout << "No se pudo abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream archivoSalida("encriptado.txt");
    if (!archivoSalida) {
        std::cout << "No se pudo crear el archivo de salida." << std::endl;
        archivoEntrada.close();
        return;
    }

    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        std::string palabra;
        std::string lineaEncriptada;
        for (char c : linea) {
            if (std::isdigit(c)) {
                int valor = c - '0';
                int valorEncriptado = (valor * clave) % 10;
                palabra += std::to_string(valorEncriptado);
            } else {
                palabra += c;
            }
        }
        archivoSalida << palabra << std::endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    std::cout << "El archivo ha sido encriptado exitosamente." << std::endl;
}

void DesencriptarArchivo(const std::string& nombreArchivo, int clave) {
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cout << "No se pudo abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream archivoSalida("desencriptado.txt");
    if (!archivoSalida) {
        std::cout << "No se pudo crear el archivo de salida." << std::endl;
        archivoEntrada.close();
        return;
    }

    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        std::string palabra;
        std::string lineaDesencriptada;
        for (char c : linea) {
            if (std::isdigit(c)) {
                int valor = c - '0';
                int valorDesencriptado = (valor * clave) % 10;
                palabra += std::to_string(valorDesencriptado);
            } else {
                palabra += c;
            }
        }
        archivoSalida << palabra << std::endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    std::cout << "El archivo ha sido desencriptado exitosamente." << std::endl;
}

int main() {
    EncriptarArchivo("archivo.txt", 5);
    DesencriptarArchivo("encriptado.txt", 5);
    return 0;
}