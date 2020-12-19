function Jacob (n : int) : int
ensures n < 2 ==> Jacob(n) == n
ensures n >= 2 ==> Jacob(n) == Jacob(n-1) + 2 * Jacob(n-2)
{
	if (n < 2) then n
	else Jacob(n-1) + 2 * Jacob(n-2)
}

method Jacobsthal (n : int) returns (j : int)
requires n >= 0
ensures j == Jacob(n)
{


}
