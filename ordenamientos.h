template < typename E >
void ordenamientoIntercambio( ListaEstatica< E > &L )
{
	int posOriginal = L.posicionActual();
	E menor, aux;
	for( int i = 0; i < L.tamanio() - 1; i++ )
	{
		L.irAPosicion( i );
		menor = L.obtenerElemento();
		for( int j = i + 1; j < L.tamanio(); j++ )
		{
			L.irAPosicion( j );
			if( L.obtenerElemento() < menor )
			{
				aux = L.obtenerElemento();
				L.eliminar();
				L.insertar( menor );
				L.irAPosicion( i );
				L.eliminar();
				L.insertar( aux );
				menor = aux;
			}
		}
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void ordenamientoSeleccion( ListaEstatica< E > &L )
{
	int posOriginal = L.posicionActual();
	E menor, aux;
	int pos;
	for( int i = 0; i < L.tamanio() - 1; i++ )
	{
		L.irAPosicion( i );
		menor = L.obtenerElemento();
		aux = menor;
		for( int j = i + 1; j < L.tamanio(); j++ )
		{
			L.irAPosicion( j );
			if( L.obtenerElemento() < menor )
			{
				menor = L.obtenerElemento();
				pos = j;
			}
		}
		if( menor != aux )
		{
			L.irAPosicion( i );
			L.eliminar();
			L.insertar( menor );
			L.irAPosicion( pos );
			L.eliminar();
			L.insertar( aux );
		}
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void ordenamientoInsercion( ListaEstatica< E > &L )
{
	int posOriginal = L.posicionActual();
	E aux;
	int pos;
	for( int i = 1; i < L.tamanio(); i++ )
	{
		L.irAPosicion( i );
		aux = L.eliminar();
		pos = i;
		for( int j = i - 1; j >= 0; j-- )
		{
			L.irAPosicion( j );
			if( aux < L.obtenerElemento() )
				pos = j;
		}
		L.irAPosicion( pos );
		L.insertar( aux );
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void ordenamientoBurbuja( ListaEstatica< E > &L )
{
	int posOriginal = L.posicionActual();
	E aux1, aux2;
	bool continuar = true;
	for( int i = 0; i < L.tamanio() - 1 && continuar; i++ )
	{
		continuar = false;
		for( int j = 0; j < L.tamanio() - ( i + 1 ); j++ )
		{
			L.irAPosicion( j );
			aux1 = L.obtenerElemento();
			L.irAPosicion( j + 1 );
			aux2 = L.obtenerElemento();
			if( aux2 < aux1 )
			{
				continuar = true;
				L.eliminar();
				L.insertar( aux1 );
				L.irAPosicion( j );
				L.eliminar();
				L.insertar( aux2 );
			}
		}
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void ordenacionShell( ListaEstatica< E > &L )
{
	int posOriginal = L.posicionActual();
	int salto, j, k;
	E aux1, aux2, aux3;
	salto = L.tamanio() / 2;
	while ( salto > 0 )
	{
		for ( int i = salto; i < L.tamanio(); i++ )
		{
			j = i - salto;
			while ( j >= 0 )
			{
				k = j + salto;
				L.irAPosicion( j );
				aux1 = L.obtenerElemento();
				L.irAPosicion( k );
				aux2 = L.obtenerElemento();
				if ( aux1 <= aux2 )
					j = -1;
				else
				{
					L.irAPosicion( j + 1 );
					aux3 = L.obtenerElemento();
					L.irAPosicion( j );
					L.eliminar();
					L.insertar( aux3 );
					L.irAPosicion( j + 1 );
					L.eliminar();
					L.insertar( aux1 );
					j -= salto;
				}
			}
		}
		salto = salto / 2;
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void ordenacionMergesort( ListaEstatica< E > &L, int primero, int ultimo )
{
	static int posOriginal = L.posicionActual();
	int central;
	if( primero < ultimo )
	{
		central = ( primero + ultimo ) / 2;
		ordenacionMergesort( L, primero, central );
		ordenacionMergesort( L, central + 1, ultimo );
		mezcla( L, primero, central, ultimo );
	}
	L.irAPosicion( posOriginal );
}

template < typename E >
void mezcla(ListaEstatica< E > &L, int izda, int medio, int drcha )
{
	int i = izda, j = medio + 1, k = 0;
	E aux1, aux2;
	E* tmp = new E[ drcha - izda + 1 ];

	while( i <= medio && j <= drcha )
	{
		L.irAPosicion( i );
		aux1 = L.obtenerElemento();
		L.irAPosicion( j );
		aux2 = L.obtenerElemento();
		if( aux1 < aux2 )
		{
			L.irAPosicion( i++ );
			tmp[ k ] = L.obtenerElemento();
		}
		else
		{
			L.irAPosicion( j++ );
			tmp[ k ] = L.obtenerElemento();
		}
		k++;
	}

	while( i <= medio )
	{
		L.irAPosicion( i++ );
		tmp[ k++ ] = L.obtenerElemento();

	}

	while( j <= drcha )
	{
		L.irAPosicion( j++ );
		tmp[k++] = L.obtenerElemento();
	}

	for( i = 0; i < k; i++ )
	{
		L.irAPosicion( i + izda );
		L.eliminar();
		L.insertar( tmp[ i ] );
	}

	delete tmp;
}

template < typename E >
void ordenacionQuicksort( ListaEstatica< E > &L, int primero, int ultimo )
{
	static int posOriginal = L.posicionActual();
	E aux1, aux2, aux3;
	int i, j, central;
	E pivote;
	central = (primero + ultimo) / 2;
	L.irAPosicion( central );
	pivote = L.obtenerElemento();
	i = primero;
	j = ultimo;
	do {
		L.irAPosicion( i );
		while (L.obtenerElemento() < pivote)
			L.irAPosicion( ++i ); 
		L.irAPosicion( j );
		while (L.obtenerElemento() > pivote)
			L.irAPosicion( --j );
		if (i <= j)
		{
			L.irAPosicion( i );
			aux1 = L.obtenerElemento();
			L.irAPosicion( j );
			aux2 = L.obtenerElemento();
			L.irAPosicion( i );
			L.eliminar();
			L.insertar( aux2 );
			L.irAPosicion( j );
			L.eliminar();
			L.insertar( aux1 );
			i++;
			j--;
		}
	}while (i <= j);

	if (primero < j)
		ordenacionQuicksort(L, primero, j);
	if (i < ultimo)
		ordenacionQuicksort(L, i, ultimo);
	L.irAPosicion( posOriginal );
}