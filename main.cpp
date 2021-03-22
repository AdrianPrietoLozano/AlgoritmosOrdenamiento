#include <iostream>
#include "listaEstatica.h"
#include "ordenamientos.h"

using namespace std;

template < typename E >
void mostrarLista( ListaEstatica< E > & );

int main( void )
{
	ListaEstatica< int > lista( 15 );
	lista.ponAlFinal( 10 );
	lista.ponAlFinal( 40 );
	lista.ponAlFinal( 0 );
	lista.ponAlFinal( 10 );
	lista.ponAlFinal( 45 );
	lista.ponAlFinal( 28 );
	lista.ponAlFinal( 47 );
	lista.ponAlFinal( 450 );
	lista.ponAlFinal( 15 );
	lista.ponAlFinal( 22 );
	lista.ponAlFinal( 311 );
	lista.ponAlFinal( 12 );
	lista.ponAlFinal( 25 );
	lista.ponAlFinal( 6 );
	lista.ponAlFinal( 200 );

	cout << "\nLista Original" << endl;
	mostrarLista( lista );

	cout << "\nOrdenacion por Intecambio" << endl;
	ordenamientoIntercambio( lista );
	mostrarLista( lista );

	cout << "\nOrdenacion por Seleccion" << endl;
	ordenamientoSeleccion( lista );
	mostrarLista( lista );

	cout << "\nOrdenacion por Insercion" << endl;
	ordenamientoInsercion( lista );
	mostrarLista( lista );

	cout << "\nOrdenacion por Burbuja" << endl;
	ordenamientoBurbuja( lista );
	mostrarLista( lista );

	cout << "\nOrdenamiento Shell" << endl;
	ordenacionShell( lista );
	mostrarLista( lista );

	cout << "\nOrdenamiento Mergesort" << endl;
	ordenacionMergesort( lista, 0, lista.tamanio() - 1 );
	mostrarLista( lista );

	cout << "\nOrdenamiento Quicksort" << endl;
	ordenacionQuicksort( lista, 0, lista.tamanio() - 1 );
	mostrarLista( lista );

	return 0;
}

template < typename E >
void mostrarLista( ListaEstatica< E > &L )
{
	int pos = L.posicionActual();
	L.irAlInicio();
	cout << "[";
	for( int i = 0; i < L.tamanio(); i++ )
	{
		cout << L.obtenerElemento();
		if( !( i == ( L.tamanio() - 1 ) ) )
		{
			cout << ", ";
			L.siguiente();
		}
	}
	cout << "]" << endl;
	L.irAPosicion( pos );
}
