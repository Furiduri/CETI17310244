// Punteros.cpp: define el punto de entrada de la aplicación de consola.
//1/05/2017 @Furiduri https://github.com/Furiduri

#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

//Se Creea una estructura de datos.
struct NODO
{
	char Nombre[20];
	int Registro;
};

//Prototipos de Funciones para LLenar los datos e Imprimir.
void llenar_Grupo(NODO *, int );
void Imprimir_Grupo(NODO *, int);
int Buscar(NODO *, int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	NODO Grupo[20], *P_Nodo;
	P_Nodo=&Grupo[0];
	//indicamos cuantos alumnos vamos a ingresar.
	cout<<"Ingrese cuantos Alumos desea Ingresar: ";
	int x;
	cin>>x;
	//Se llama a la funcion para llenar los datos.
	llenar_Grupo(P_Nodo, x);
	//Se llama a la funcion Para imprimir.
	Imprimir_Grupo(P_Nodo,x);
	//Buscar un registro.
	int key,Res;
	cout<<"Ingrese un Registro a buscar: ";
	cin>>key;
	Res=Buscar(Grupo, x, key);
	if(Res>-1){
		cout<<"//////////////"<<endl;
		cout<<"Encontrado."<<endl;
		cout<<"Nombre: "<<Grupo[Res].Nombre<<endl;
		cout<<"Registro: "<<Grupo[Res].Registro<<endl;
	}else if(Res==-1){
		cout<<"//////////////"<<endl;
		cout<<"ERROR: 404 Registro NOT FOUND"<<endl;
		cout<<"//////////////"<<endl;
	}
	_getch();
	return 0;
}

//LLena el arreglo Grupo.
void llenar_Grupo(NODO *A, int N){
	for(int c=0;c<N;c++){
		cout<<"//////////////"<<endl;
		cin.ignore();
		cout<<"Ingrese Nombre: ";
		gets_s(A->Nombre);
		cout<<"Ingrese Regtistro: ";
		cin>>A->Registro;
		A++;
	}
}

//Se Imprimen los Datos
void Imprimir_Grupo(NODO *A, int N){
	for(int c=0; c<N; c++){
		cout<<"//////////////"<<endl;
		cout<<"Nombre: "<<A->Nombre<<endl;
		cout<<"Registro: "<<A->Registro<<endl;
		A++;
	}
}

//Buscar Por mitad.
int Buscar(NODO *A, int N, int NaB) {
	for (int c = 0; c < N; c++)
	{
		if (A[c].Registro==NaB)
		{
			return c;
		}
	}
	return -1;
}
