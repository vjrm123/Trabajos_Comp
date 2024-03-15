#include <iostream>

using namespace std;

// Función para crear una matriz dinámica
int** createMatrix(int rows, int cols) {
  int** matrix = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }
  return matrix;
}

// Función para liberar la memoria asignada a una matriz dinámica
void deleteMatrix(int** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

// Función para imprimir una matriz
void printMatrix(int** matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // Crear una matriz dinámica de 3x4
  int** matrix = createMatrix(3, 4);

  // Almacenar algunos valores en la matriz
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = i * 4 + j + 1;
    }
  }

  // Imprimir los valores de la matriz
  printMatrix(matrix, 3, 4);

  // Liberar la memoria asignada a la matriz
  deleteMatrix(matrix, 3);

  return 0;
}