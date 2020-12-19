// Cristhian Rodriguez Gomez
// E51

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
		case 'd': p = diamante; break;
		case 'r': p = rubi; break;
		case 'e': p = esmeralda; break;
		case 'z': p = zafiro; break;
		case 'j': p = jade; break;
	}
	return entrada;
}

// función que resuelve el problema
int resolver(vector<piedrasPreciosas> &v, int tamSeq, int &numtipo1, int &numtipo2, piedrasPreciosas tipo1, piedrasPreciosas tipo2) {

	int tamV = v.size();
	int numSeqCumplen = 0;
	int sumParcialTipo1 = 0;
	int sumParcialTipo2 = 0;


	for (int j = 0; j < tamSeq; ++j) {
		if (v[j] == tipo1)
		{	
			sumParcialTipo1++;
		}
		if (v[j] == tipo2)
		{
			sumParcialTipo2++;
		}
	}

	if (sumParcialTipo1 >= numtipo1 && sumParcialTipo2 >= numtipo2)
	{
		numSeqCumplen++;
	}

	// Coste O(n)
	for (int i = tamSeq; i < tamV; i++) {
		if (v[i - tamSeq] == tipo1)
		{
			sumParcialTipo1--;
		} 
		if (v[i - tamSeq] == tipo2)
		{
			sumParcialTipo2--;
		}
		if (v[i] == tipo1)
			sumParcialTipo1++;
		if (v[i] == tipo2)
			sumParcialTipo2++;
		
		if (sumParcialTipo1 >= numtipo1 && sumParcialTipo2 >= numtipo2)
		{
			numSeqCumplen++;
		}
		
		
	}
	
	return numSeqCumplen;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
	int numpiedras,  tamSeq,  numtipo1, numtipo2; 
	piedrasPreciosas tipo1, tipo2;

	std::cin >> numpiedras  >> tamSeq >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;

	std::vector<piedrasPreciosas> v(numpiedras);

	for (piedrasPreciosas& i : v){
		std::cin >> i;
	}
		

	int sol = resolver(v, tamSeq, numtipo1, numtipo2, tipo1, tipo2);

	cout << sol << endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}