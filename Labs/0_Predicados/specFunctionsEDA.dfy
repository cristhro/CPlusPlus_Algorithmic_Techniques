// Cristhian Rodriguez Gomez
//Especificacion de predicados

// predicado par

predicate parReferencia (n : int)
requires n > 0
{n % 2 == 0}

//Predicados iguales
predicate igualesReferencia<T> (a : seq<T>)
{ forall u, w :: 0 <= u < |a| && 0 <= w < |a| ==> a[u] == a[w] }

predicate igualesReferencia2<T> (a : seq<T>)
{ forall u, w :: 0 <= u < w < |a| ==> a[u] == a[w] }

predicate igualesReferencia3<T> (a : seq<T>)
{ forall u :: 0 <= u < |a| -1 ==> a[u] == a[..][u+1] }

predicate igualesReferencia4<T> (a : seq<T>)
{ forall u :: 0 < u < |a| ==> a[..][u-1] == a[u] }

lemma IgualesEq ()
ensures forall s : seq<int> :: igualesReferencia(s) == igualesReferencia2(s) ==
                                igualesReferencia3(s) == igualesReferencia4(s)

// Predicado distintos

predicate distintosReferencia<T> (a : seq<T>)
{ forall u, w :: 0 <= u < |a| && 0 <= w < |a| && u != w ==> a[u] != a[w] }

predicate distintosReferencia2<T> (a : seq<T>)
{ forall u, w :: 0 <= u < w < |a| ==> a[u] != a[w] }

lemma DistintosEq ()
ensures forall s : seq<int> :: distintosReferencia(s) == distintosReferencia2(s)

// Predicado que indica que no hay dos elementos contiguos iguales

predicate contiguosDistintosRef<T> (s : seq<T>)
{ forall u :: 0 <= u < |s|-1 ==> s[u] != s[..][u+1] }

predicate contiguosDistintosRef2<T> (s : seq<T>)
{ forall u :: 0 < u < |s| ==> s[..][u-1] != s[u] }

lemma ContiguosDistintosEq ()
ensures forall s : seq<int> :: contiguosDistintosRef(s) == contiguosDistintosRef2(s)

// Una secuencia es estrictamente creciente

predicate EstricCrecienteRef (s : seq<int>)
ensures EstricCrecienteRef(s) == forall u , w :: 0 <= u < w < |s| ==> s[u] < s[w]

predicate EstricCrecienteRef2 (s : seq<int>)
	ensures EstricCrecienteRef2(s) == forall u :: 0 < u < |s| ==> s[..][u-1] < s[u]

lemma EstricCrecienteEq ()
ensures forall s : seq<int> :: EstricCrecienteRef(s) == EstricCrecienteRef2(s)

// Una secuencia es creciente

predicate crecienteRef (s : seq<int>)
ensures crecienteRef(s) == forall u , w :: 0 <= u < w < |s| ==> s[u] <= s[w]

predicate crecienteRef2 (s : seq<int>)
	ensures crecienteRef2(s) == forall u :: 0 < u < |s| ==> s[..][u-1] <= s[u]

lemma CrecienteEq ()
ensures forall s : seq<int> :: crecienteRef(s) == crecienteRef2(s)

// Todos los elementos de un vector son positivos
predicate positivoRef (s : seq<int>)
{ forall x :: 0 <= x < |s| ==> s[x] > 0}

// p es un número primo
predicate primoRef (p : int)
requires p > 1
{ 2 <= p && forall w :: 1 < w < p ==> p % w != 0 }
