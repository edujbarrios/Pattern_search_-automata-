/// Computabilidad Y Algoritmia
/// Grado: Ingieneria informática
/// Segundo Curso
/// Universidad de La Laguna
/// Práctica 6: Autómata reconocedor de patrones
/// Realizado por Eduardo José Barrios García

#include <iostream>
#include <fstream>
#include <string.h>
#include "pattern_search.h"
#define topelinea 256
using namespace std;

/* esta funcion construye la tabla del automata */
int computeTF(char* pat, int M, int TF[][topelinea])
{
    int state, x;
    pattern_search p;
    for (state = 0; state <= M; ++state){
        for (x = 0; x < topelinea; ++x){
        	TF[state][x] = p.getProximoEstado(pat, M, state, x);
        }
    }

    return 0;
}

int busqueda(char *patron, char* linea,ofstream& sal) //detecta las apariciones del patron
{
    int sizePatron = strlen(patron);
    int sizeLinea = strlen(linea);

    bool salida = false;

    int TF[sizePatron+1][topelinea];

    computeTF(patron, sizePatron, TF);


    int i, state=0;
    for (i = 0; i < sizeLinea; i++)
    {
        state = TF[state][(unsigned)linea[i]];
        if (state == sizePatron){
            salida = true;
            break;
        }
    }



    if(salida == true)
    {
    	sal <<"Si\n";
    }else{
    	sal << "No\n";
    }

    return 0;


}



int main(int argc, char *argv[]) {


	ifstream file(argv[2]);
	string str;
	char * patron = argv[1]; // recibe el patron como parametro

	ofstream sal;
	sal.open (argv[3]);
	bool errorLinea=false;

	while (getline(file, str)) {
		char *linea = new char[str.length() + 1];
		strcpy(linea, str.c_str());

		for( unsigned int indiceLinea=0;indiceLinea<strlen(linea);indiceLinea++)
		{
			if(linea[indiceLinea] < 97 || linea[indiceLinea] > 122) //detecta si hay un elemento fuera de las minusculas
			{
				errorLinea =true;
				break;
			}

		}
		if(errorLinea == false){
			busqueda(patron,linea,sal);
		}else{
			sal << "error\n";
		}
	}

	sal.close();

	return 0;
}
