// Listas Enlazadas.cpp: define el punto de entrada de la aplicación de consola.
///30-04-2018  @Furiduri https://github.com/Furiduri
#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

 struct Datos
{
	char Nombre[20];
	char grupo[4];
	int Registro;
};

 //Declaracion de Prototipos
void LlenarUser(Datos &, int &);
void OrdenarRegistro(Datos *, int);
void ImprimirRegistro(Datos *, int);
void Llenar(Datos *,int &);

//Cuerpo del Programa
int main()
{
	Datos Grupo2M[20];
	Datos *A;
	A = Grupo2M;
	bool E = true;
	int n = 0;
	do {
		system("cls");
		char opc;
		cout << "1.Ingresar datos.\n2.Ordenar Datos.\n3.Imprimir.\n0.LLenado Rapido.\n4.Salir." << endl;
		cin.ignore(NULL);
		cout << "Ingrese la Opcion: ";
		cin.get(opc);
		switch (opc)
		{
		case '1':
			LlenarUser(Grupo2M[n], n);
			break;

		case '2':
			OrdenarRegistro(Grupo2M, n);
			break;

		case '3':
			ImprimirRegistro(Grupo2M, n);
			break;
		case '4':
			E = false;
			break;
		case '0':
			Llenar(Grupo2M, n);
		}
	} while (E == true);
	return 0;
}
//Se procede a la toma de datos
void LlenarUser(Datos &A, int &N)
{
	cin.ignore();
	cout << "\nNombre: ";
	gets_s(A.Nombre);
	cout << "Grupo: ";
	gets_s(A.grupo);
	cout << "Registro: ";
	cin >> A.Registro;

	N++;
}
//Llenar arreglos para evitar trabajos XD
void Llenar(Datos *A, int &N)
{
		srand(time(NULL));
		char Nomb[] = "Furi Copy";
		strcpy_s(A[N].Nombre, Nomb);
		char Grup[] = "2M";
		strcpy_s(A[N].grupo, Grup);
		A[N].Registro = rand() % 100+1;
		N++;
}
//Se ordenan la Estructura Grupo2M por el Numero de Registro (Metodo Shell)
void OrdenarRegistro(Datos *A, int N)
{
	int i, j, inc,tempD;
		Datos temp;
	for (inc = 1; inc<N; inc = inc * 3 + 1);
	while (inc > 0)
	{
		for (i = inc; i < N; i++)
		{
			j = i;
			tempD = A[i].Registro;
			temp = A[i];
			while ((j >= inc) && (A[j - inc].Registro > tempD))
			{
				A[j] = A[j - inc];
				j = j - inc;
			}

			A[j] = temp;
		}

		inc /= 2;
	}
	cout << "\n///Ordenados///";
	_getch();
}

//Se imprimen el contenido de la Estructura.
void ImprimirRegistro(Datos *A, int N)
{
	for (int c = 0; c < N; c++) {
		cout << "\nNombre: " << A[c].Nombre << endl;
		cout << "Grupo: " << A[c].grupo << endl;
		cout << "Registro: " << A[c].Registro << endl;
	}
	_getch();
}