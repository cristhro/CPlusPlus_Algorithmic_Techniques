// Nombre del alumno ......

// Debes rellenar los ...

predicate predicado1(n : int)
requires ...
ensures predicado1(n) == (...)
{ ...}

// Descomenta uno a uno los assert y compruebalos.
// Una vez comprobados vuelve a comentarlos
method Testpredicado1()
{
	//assert predicado1(5);
	//assert predicado1(25);
	//assert predicado1(1000);
	//assert predicado1(-5); // Este assert debe fallar
	//assert predicado1(0);  // Este assert debe fallar
	//assert predicado1(2); // Este assert debe fallar
	//assert predicado1(1001);  // Este assert debe fallar
}


// Descomenta para hacer el predicado 2
/*
predicate predicado2 (s : seq<int>, n:int)
ensures predicado2(s,n) == ...
{ ... }
*/

method Testpredicado2() 
{
	//assert predicado2([2],5);
	//assert predicado2([-5,-7,-1,-3],0);
	//assert predicado2([5,6],10);
	//var s : seq<int>;
	//s := [];
	//assert predicado2(s,-5);
	//assert predicado2([3,5,2,4,3,8,4,6,1,10],-2); // Este assert debe fallar
	//assert predicado2([0,0,0],0); // Este assert debe fallar
	//assert predicado2([3,-4],0);  // Este assert debe fallar
	//assert predicado2([-4,3],0);  // Este assert debe fallar
}

// Descomenta para hacer el predicado
/*
predicate predicado3 (s : seq<int>)
ensures predicado3(s) ==...
{ ...}
*/
  
method Testpredicado3() 
{
	//assert predicado3([2]);
	//assert predicado3([-2,3,-2,3,-2]);
	//assert predicado3([5,6]);
	//var s : seq<int>;
	//s := [];
	//assert predicado3(s);
	//assert predicado3([3,5,2,4,3,8,4,6,1,10]); 
	//assert predicado3([0,0,0]); // Este assert debe fallar
	//assert predicado3([3,-4]);  // Este assert debe fallar
	//assert predicado3([-3,-1,5]);  // Este assert debe fallar
	//assert predicado3([-3,-1,-5,-7]);  // Este assert debe fallar
	}

