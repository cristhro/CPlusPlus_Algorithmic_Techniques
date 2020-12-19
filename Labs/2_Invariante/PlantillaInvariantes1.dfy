// Bœsqueda secuencial
/*
method search (v : array<int>, x : int) returns (b : bool) 
requires v != null
ensures b == forall k::0<=k<v.Length ==>v[k]==x
{	var i := 0;
	while (i < v.Length && v[i] == x)
	invariant 0<=i<=v.Length
	invariant forall k::0<=k<i==>v[k]==x
	decreases v.Length - i
	{
		i := i+1;
	}
	b := i == v.Length;
}
*/


// Comprobar si ningœn elemento est‡ en su posici—n
/*
method coincidePosicion (v : array<int>) returns (b : bool)
requires v != null
ensures b == forall k :: 0 <= k < v.Length ==> v[k] != k
{
	var i := 0;
	while (i < v.Length && v[i] != i)
	invariant 0<=i<=v.Length
	invariant  forall k :: 0 <= k < i ==> v[k] != k
	decreases v.Length - i
	{
		i := i+1;
	}
	b := i == v.Length;
}
*/

// Comprobar que ningœn elemento coincide con la suma de los elementos a su izquierda
method coincideSuma (v : array<int>) returns (b : bool)
requires v != null
ensures b == forall k :: 0 <= k < v.Length ==> v[k] != Sum(v[..k])
{
	var i := 0;
	while (i < v.Length && v[i] != Sum(v[..i]))
	invariant 0<=i<=v.Length
	invariant   forall k :: 0 <= k < i ==> v[k] != Sum(v[..k])
	decreases v.Length - i
	{
		i := i+1;
	}
	b := i == v.Length;
}

/*
method positivo (v : array<int>) returns (r : bool)
requires v != null
ensures r==forall k::0<=k<v.Length==>v[k]>0
{
	var i := 0; r := true;
	while (i < v.Length && r)
	invariant 0<=i<=v.Length
	invariant r==forall k::0<=k<i==>v[k]>0
	decreases v.Length - i
	{
		if (v[i] <= 0) { r := false; }
		i := i+1;
	}
}*/