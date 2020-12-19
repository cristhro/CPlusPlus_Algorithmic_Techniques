// Vector de acumulados suponiendo que el vector no es vac�o
// El vector v es de salida. Se asegura en el ensures que estar� definido
// se le reserva memoria en el c�digo

// Apartado A


function Sum(s : seq<int>) : int
ensures s == [] ==> Sum(s) == 0
ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..]) }

method problema1 (a: array<int>) returns (v : array<int>)
requires a != null && a.Length > 0
ensures v != null &&  a.Length == v.Length
ensures forall k:: 0 <= k < v.Length ==> v[k] == Sum(a[k..])
{
  v := new int[a.Length];
  var i := a.Length - 1;

  v[i] := a[i];
  while (i > 0)
  invariant  0 <= i < v.Length 
  invariant forall k:: i <= k < v.Length   ==> v[k] == Sum(a[k..])
  {
    v[i-1] := v[i]  + a[i-1]  ;
    i := i - 1;
  }
}

// Vector acumulado suponiendo que el vector puede ser vacio

/*method problema2 (a: array<int>) returns (v : array<int>)
requires a != null &&  a.Length == 0
ensures v != null && a.Length == v.Length
ensures forall k:: 0 <= k < v.Length ==> v[k] == Sum(a[k..])
{
	  v := new int[a.Length];
	  var i := a.Length - 1;

	  if (a.Length != 0) {
		  v[i] := a[i];
		  while (i > 0)
		  invariant  0 <= i < v.Length 
		  invariant forall k:: i <= k < v.Length   ==> v[k] == Sum(a[k..])
		  {
			v[i -1] := v[i]  + a[i-1]  ;
			i := i - 1;
		  }
	  }
}*/

// n-esimo termino de la sucesion de Fibonacci

function Fib (n : int) : int
{
	if (n < 2) then n
	else Fib(n-2) + Fib(n-1)
}

method Fibonacci (n : int) returns (f : int)
requires n >= 0
ensures f == Fib(n)
{
	if (n == 0) {f := 0;}
	else if (n == 1) {f := 1;}
	else {
		f := 1; var  l := 1; var m := 0;
		var i := 1;

		while( i < n)
			invariant 0 <= i <= n+2
			invariant  f == Fib(i)
			invariant  l == Fib(i)
			invariant  m == Fib(i - 1)
		{
			f := l + m;
			m := l;
			l := f;
		
			i := i + 1;
		}
		}
}
