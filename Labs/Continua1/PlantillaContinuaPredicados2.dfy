// Nombre del alumno ....

// Rellenar los ...


predicate divisible(n1 : int, n2 : int)
requires n1 > 0 && n2 > 0 
ensures divisible(n1,n2) == ...


method TestDivisible()
{
	//assert divisible(5,1);
	//assert divisible(25,5);
	//assert divisible(1000,1000);
	//assert divisible(10,20); // Este assert debe fallar
	//assert divisible(-5,2); // Este assert debe fallar
	//assert divisible(0,5);  // Este assert debe fallar
	//assert divisible(2,0); // Este assert debe fallar
	//assert divisible(1001,100);  // Este assert debe fallar
}


predicate VectorDivisible (s : seq<int>, n : int)
requires ...
requires ...
ensures VectorDivisible(s,n) == ...

method TestDivisibles() 
{
	//assert VectorDivisible([99],3);
	//assert VectorDivisible([5,100,10,25],5);
	//var s : seq<int>;
	//s := [];
	//assert VectorDivisible(s,3);
	//assert VectorDivisible([3,5,2,4,3,8,4,6,1,10],-2); // Este assert debe fallar
	//assert VectorDivisible([0,0,0],4); // Este assert debe fallar
	//assert VectorDivisible([3,4],0);  // Este assert debe fallar
	//assert VectorDivisible([-4,3],2);  // Este assert debe fallar
	//assert VectorDivisible([4,3],2);  // Este assert debe fallar
}

predicate Montana (s : seq<int>) 
ensures Montana(s) == ...

method TestMontana() 
{
	//assert Montana([2]);
	//assert Montana([2,2]);
	//assert Montana([-2,3,4,3,-2]);
	//assert Montana([-2,3,3,-2]);
	//assert Montana([5,6]); // Este assert debe fallar
	//var s : seq<int>;
	//s := [];
	//assert Montana(s);
	//assert Montana([0,0,0,0]); // Este assert debe fallar
	//assert Montana([0,0,0]); // Este assert debe fallar
	//assert Montana([3,-4,-4,3]);  // Este assert debe fallar
	}

