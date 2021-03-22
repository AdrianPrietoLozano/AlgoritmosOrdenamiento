#include <iostream>
#include "lista.h"
#include "Assert.cpp"

template< typename E >
class ListaEstatica : public Lista< E>
{
	private:
		int tamanioMaximo;
		int tamanioActual;
		int posActual;
		E *arreglo;
	public:
		ListaEstatica( int );
		~ListaEstatica( void );
		void vaciar( void );
		void insertar( const E & );
		void ponAlFinal( const E & );
		E eliminar( void );
		void irAlInicio( void );
		void irAlFinal( void );
		void anterior( void );
		void siguiente( void );
		int tamanio( void ) const;
		int posicionActual( void ) const;
		void irAPosicion( int );
		const E &obtenerElemento( void ) const;
};

template< typename E >
ListaEstatica< E >::ListaEstatica( int tamanio )
{
	tamanioMaximo = tamanio;
	tamanioActual = 0;
	posActual = 0;
	arreglo = new E[tamanio];
}

template< typename E >
ListaEstatica< E >::~ListaEstatica( void )
{
	delete [] arreglo;
}

template< typename E >
void ListaEstatica< E >::vaciar( void )
{
	delete [] arreglo;
	arreglo = new E[tamanioMaximo];
	tamanioActual = 0;
	posActual = 0;
}

template< typename E >
void ListaEstatica< E >::insertar( const E &nuevo )
{
	Assert( tamanioActual < tamanioMaximo, "la lista esta llena\n" );
	for( int i = tamanioActual; i > posActual; --i )
		arreglo[ i ] = arreglo[ i-1 ];
	arreglo[ posActual ] = nuevo;
	++tamanioActual;
}

template< typename E >
void ListaEstatica< E >::ponAlFinal( const E &nuevo )
{
	Assert( tamanioActual < tamanioMaximo, "la lista esta llena\n" );
	arreglo[ tamanioActual ] = nuevo;
	++tamanioActual;
}

template< typename E >
E ListaEstatica< E >::eliminar( void )
{
	Assert( tamanioActual > 0, "la lista esta vacia\n" );
	E aux = arreglo[ posActual ];
	for( int i = posActual; i < ( tamanioActual - 1 ); ++i )
		arreglo[ i ] = arreglo[ i + 1 ];
	--tamanioActual;
	return aux;
}

template< typename E >
void ListaEstatica< E >::irAlInicio( void )
{
	posActual = 0;
}

template< typename E >
void ListaEstatica< E >::irAlFinal( void )
{
	posActual = ( tamanioActual - 1 );
}

template< typename E >
void ListaEstatica< E >::siguiente( void )
{
	Assert( ( posActual < ( tamanioActual - 1 ) ), "no se puede realizar la accion\n" );
	++posActual;
}

template< typename E >
void ListaEstatica< E >::anterior( void )
{
	Assert( posActual > 0, "no se puede realizar la accion\n" );
	--posActual;
}

template< typename E >
int ListaEstatica< E >::tamanio( void ) const
{
	return tamanioActual;
}

template< typename E >
int ListaEstatica< E >::posicionActual( void ) const
{
	return posActual;
}

template< typename E >
void ListaEstatica< E >::irAPosicion( int pos )
{
	Assert( ( pos >= 0 ) && ( pos <= tamanioActual ), "posicion fuera de rango\n");
	posActual = pos;
}

template< typename E >
const E &ListaEstatica< E >::obtenerElemento( void ) const
{
	Assert( tamanioActual != 0, "lista vacia\n" );
	return arreglo[ posActual ];
}