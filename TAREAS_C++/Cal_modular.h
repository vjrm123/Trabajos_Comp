#pragma once
class Calculadora
{
private:
	int Modulo, PriOperando, SegOperando;
public:
	Calculadora(int Modulo, int PriOperando, int SegOperando);
	Calculadora();
	void ajuste();
	void informacion(char, int);
	
	int ajuste(int);
	int Sumar();
	int Restar();
	int Multiplicacion();
	int Inverso(int PriOperando,int Modulo);
};
