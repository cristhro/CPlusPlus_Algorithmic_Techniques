/*
	Nombre: Cristhian
	Apellidos: Rodriguez Gomez
*/
include "specFunctionsEDA.dfy"
/*
// Define el predicado par 
predicate par (n : int) 
requires n > 0
// Escribir el predicado en los puntos suspensivos
ensures par(n) == (n % 2 == 0)

// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestPar () {
	assert forall n :: n > 0 ==> parReferencia(n) == par(n);
	}


// Comprueba que el predicado es cierto para algunos numeros
// Este test es œtil para poder identificar errores del predicado (numeros que no lo cumplen)
// y corregirlo cuando el test anterior falla.
// Si el test anterior es correcto este debe ser tambien correcto.
method TestParNum() 
{
	//assert par(2);
	//assert par(3);
	//assert par(0); // Este assert debe fallar
	//assert par(-2);   // Este assert debe fallar
	//assert par(-5);  // Este assert debe fallar
	//assert par(10000);
	}

	// ------------------------------------------

	
// Escribir un predicado que indique que todos los elementos de una secuencia son 
// son positivos
predicate positivo (s : seq<int>)
ensures positivo(s) == (forall n :: 0 <= n < |s| ==> s[n] > 0)


// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestPositivo () {
	assert forall s : seq<int> :: positivoRef(s) == positivo(s);
	}

	
// Comprueba que el predicado es cierto para algunas secuencias
// Este test es œtil para poder identificar errores del predicado (secuencias que no lo cumplen)
// y corregirlo cuando el test anterior falla.
// Si el test anterior es correcto este debe ser tambien correcto.
method TestPositivoSeq() 
  {
	assert positivo([2]);
	assert positivo([2,2,2,2,2]);
	assert positivo([5,6,2]);
	var s : seq<int>;
	s := [];
	assert positivo(s);
	//assert positivo([-20,10,5]); // Este assert debe fallar
	//assert positivo([0,0,0]); // Este assert debe fallar
	//assert positivo([3,-4,5,6]);  // Este assert debe fallar
}

// ------------------------------------------

// Escribir un predicado que indique que todos los elementos de una secuencia son 
// iguales

predicate iguales (a : seq<int>) 
ensures iguales(a) == (forall n,m :: 0 <= n < |a| && 0 <= m < |a| ==> a[n] == a[m]) // Escribir aqui el predicado


// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestIguales () {
	IgualesEq();
	assert forall s : seq<int> :: igualesReferencia(s) == iguales(s);
	}

// Comprueba que el predicado es cierto para algunas secuencias
// Este test es œtil para poder identificar errores del predicado (secuencias que no lo cumplen)
// y corregirlo cuando el test anterior falla.
// Si el test anterior es correcto este debe ser tambien correcto.
method TestIgualesSeq() 
{
	assert iguales([1,1,1,1,1]);
	assert iguales([2]);
	var s : seq<int>;
	s := [];
	assert iguales(s);
	//assert iguales([1,1,1,1,2]); // Este assert debe fallar
}

// ------------------------------------------

// Escribir un predicado que indique que los elementos de una secuencia son todos distintos


predicate distintos (a : seq<int>) 
ensures distintos(a) == (forall n,m :: 0 <= n < |a| && 0 <= m < |a| && n!=m ==> a[n] != a[m])   // Escribir aqui el predicado


// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestDistintos () {
	DistintosEq();
	assert forall s : seq<int> :: distintosReferencia(s) == distintos(s);
	}

// Comprueba que el predicado es cierto para algunas secuencias
// Este test es œtil para poder identificar errores del predicado (secuencias que no lo cumplen)
// y corregirlo cuando el test anterior falla.
// Si el test anterior es correcto este debe ser tambien correcto.
method TestDistintosSeq() 
{
  	assert distintos([1,4,2,8]);
	assert distintos([6,3,1,9,2]);
	assert distintos([2]);
	var s : seq<int>;
	s := [];
	assert distintos(s);
	//assert distintos([3,4,3,6]); // Este assert debe fallar
	//assert distintos([6,3,3,1,5]);  // Este assert debe fallar
}

// ------------------------------------------

// Escribir un predicado que indique que los elementos de una secuencia son todos distintos


predicate contiguosDistintos (s : seq<int>) 
ensures contiguosDistintos(s) == (forall u :: 0 <= u < |s|-1 ==> s[u] != s[..][u+1])   // Escribir aqui el predicado


// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestContiguosDistintos () {
	ContiguosDistintosEq();
	assert forall s : seq<int> :: contiguosDistintosRef(s) == contiguosDistintos(s);
	}

// Comprueba que el predicado es cierto para algunas secuencias
// Este test es œtil para poder identificar errores del predicado (secuencias que no lo cumplen)
// y corregirlo cuando el test anterior falla.
// Si el test anterior es correcto este debe ser tambien correcto.
method Test() 
{
  	assert contiguosDistintos([1,4,2,8]);
	assert contiguosDistintos([6,3,1,9,2]);
	assert contiguosDistintos([2]);
	var s : seq<int>;
	s := [];
	assert contiguosDistintos(s);
	assert contiguosDistintos([3,4,3,6]); 
	//assert contiguosDistintos([6,3,3,1,5]);  // Este assert debe fallar
}

// ------------------------------------------

// Define el predicado estrictamente creciente 
predicate estrictamenteCreciente (s : seq<int>) 
ensures	estrictamenteCreciente(s) ==  (forall u,m :: 0 <= u < m < |s| ==> s[u] < s[m])// escribe aqui el predicado


// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestEstrictamenteCreciente () {
	EstricCrecienteEq();
	assert forall s : seq<int> :: EstricCrecienteRef(s) == estrictamenteCreciente(s);
	}

// Comprueba casos
method Test() 
  {
	assert estrictamenteCreciente([3,4,5,6]);
	assert estrictamenteCreciente([3,4,5,6]);
	assert estrictamenteCreciente([2]);
	var s : seq<int>;
	s := [];
	assert estrictamenteCreciente(s);
	assert estrictamenteCreciente([2,5,8,10,15,20]);
	assert estrictamenteCreciente([3,4,5,2]); // Este assert debe fallar
	assert estrictamenteCreciente([3,4,4,6]);  // Este assert debe fallar
}
*/

// ------------------------------------------


// Define el predicado creciente 
predicate creciente (s : seq<int>) 
ensures creciente(s) == (forall u,m :: 0 <= u < m < |s| ==> s[u] <= s[m])// escribe aqui el predicado

// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestCreciente () {
	CrecienteEq();
	assert forall s : seq<int> :: crecienteRef(s) == creciente(s);
	}

// Comprueba casos
method Test() 
  {
	assert creciente([3,4,5,6]);
	assert creciente([3,4,5,6]);
	assert creciente([2]);
	var s : seq<int>;
	s := [];
	assert creciente(s);
	assert creciente([2,5,8,10,15,20]);
	// assert creciente([3,4,5,2]); // ERROR
	assert creciente([3,4,4,6]);
	assert creciente([2,2,2,2,2]);
}

// ------------------------------------------


// p es un nœmero primo
predicate primo (p : int) 
requires p > 1
ensures primo(p) == ( forall w:: 1  < w < p ==> p%w != 0 ) 

// Comprueba que el predicado es correcto 
// comprobando su equivalencia con un predicado correcto
method TestPrimo () {
	assert forall n :: n > 1 ==> primoRef(n) == primo(n);
	}

// Comprueba casos
method Test() 
  {
	assert primo(3);
	assert primo(88);
	assert primo(9);  // Este assert debe fallar
}
