// Nombre del alumno.....

// Rellena los ....
// Comenta y descomenta los metodos según los vayas probando

function Sum(s : seq<int>) : int 
ensures s == [] ==> Sum(s) == 0
ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..]) }

method problema1 (v:array<int>, p: int) returns (b : bool)
requires v != null
requires ...
ensures b == ...

/*
method TestProblema1() 
{ 
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 4; v[2] := 1;
	v[3] := 5; v[4] := 7; v[5] := 0;
	var n := problema1(v,1);
	assert n;
}


function SumPares(s : seq<int>) : int 
ensures s == [] ==> SumPares(s) == 0
ensures s != [] && ... ==> SumPares(s) == s[0] + SumPares(s[1..])
ensures s != [] && ... ==> SumPares(s) == SumPares(s[1..])


method problema2 (v:array<int>, p: int) returns (b : bool)
requires v != null
requires ...
ensures b == ...


method TestProblema2() 
{ 
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 4; v[2] := 1;
	v[3] := 5; v[4] := 7; v[5] := 0;
	var n := problema2(v,3);
	//assert n;
}


method problema3 (v:array<int>, n : int) returns (p : int)
requires v != null ...
ensures ...
ensures ...
ensures ...


method TestProblema3() 
{ 
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 4; v[2] := 1;
	v[3] := 5; v[4] := 7; v[5] := 0;
	var n := problema3(v,5);
	assert Sum(v[..3]) == 6;
	assert n == 3;
}
*/
