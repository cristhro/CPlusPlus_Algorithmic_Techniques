// Cristhian Rodriguez Gomez

// Comprobar que un elemento del vector coincide con 
// la posicion que ocupa en el vector
/*
method coincide (v : array<int>) returns (b : bool)
requires v != null
ensures b == (forall k::0<=k<v.Length ==> v[k] != k);

method TestCoincide ()
{ 
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 2; v[2] := 1;
	v[3] := 5; v[4] := 7; v[5] := 0;
	var n := coincide(v);
	assert n;
}
*/
// Comprobar que un vector es creciente y que la diferencia
// entre dos valores consecutivos no es mayor que una cantidad
/*
predicate creciente (s : seq<int>) 
ensures creciente(s) == (forall k::0<=k<|s| - 1 ==> s[k] <= s[..][k+1])

predicate diferenciaAcotada (s: seq<int>, x : int) 
ensures diferenciaAcotada(s,x) == (forall k::0<=k<|s| - 1 ==> -x <= (s[..][k+1]-s[k]) <= x);

method diferencia(v : array<int>, x : int) returns (b : bool)
	requires v != null && creciente(v[..])
	ensures b== (diferenciaAcotada(v[..],x)); 

method TestDiferencia ()
{
	assert creciente([3,5,6]); // para comprobar el predicado creciente
	assert diferenciaAcotada([6,5,6],1);  // para comprobar el predicado diferenciaAcotada
	var v : array<int> := new int[3];
	v[0] := 1; v[1] := 5; v[2] := 6;
	var n := diferencia(v,10);
	assert n;  // Para comprobar el metodo
}*/
/*
//Todos los valores de una secuencia estan repetidos una vez y solo una.
function Count(s:seq<int>, x : int):int
	ensures s == [] ==> Count(s,x) == 0
	ensures s!= [] && s[0] == x ==> Count(s,x) == 1 + Count(s[1..],x)
	ensures s!= [] && s[0] != x ==> Count(s,x) == Count(s[1..],x)

method parejas(v : array<int>) returns (b : bool)
requires v != null
ensures b == forall k:: 0<= k < v.Length ==> Count(v[..], v[k]) == 2

method TestParejas ()
{
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 5; v[2] := 6;
	v[3] := 1; v[4] := 5; v[5] := 6;
	var n := parejas(v);
	assert n;
}
*/


