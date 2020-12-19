#pragma once
class manchasNegras
{
public:

	manchasNegras(char ** matriz, int f, int c) : F(f), C(c), tam_mayor_mancha(0)
	{
		// creamos array marcado
		marked = new bool*[F];
		for (int i = 0; i < F; i++)
			marked[i] = new bool[C];

		// inicializamos a false;
		for (int i = 0; i < F; i++){
			for (int j = 0; j < C; j++){

				if (matriz[i][j] == ' ')
					marked[i][j] = true;
				else 
					marked[i][j] = false;
			}
				
		}
			

		dfs_mancha(matriz);
	}
	int mancha_mas_grande() {
		return tam_mayor_mancha;
	}
private:
	int tam_mayor_mancha;
	bool ** marked;
	int F, C;

	void dfs_mancha(char ** matriz){
		int cont = 0;
		for (int i = 0; i < F; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (!marked[i][j]){
					
					cont = num_Connected(i, j);
					if (cont > tam_mayor_mancha)
						tam_mayor_mancha = cont;
				}
			}

		}
	}
	int num_Connected(int f, int c){
		int cont = 0;

		if (toWest(f, c - 1)){
			cont++;
			num_Connected(f, c - 1);
		}
		if (toEst(f,c + 1))
		{
			cont++;
			num_Connected(f, c + 1);
		}
		if (toNorth(f - 1, c))
		{
			cont++;
			num_Connected(f - 1, c);
		}
		if (toSouth(f + 1, c))
		{
			cont++;
			num_Connected(f + 1, c);
		}
		return cont;
	}

	bool toWest(int f, int c){
		if (c >= 0){
			return (marked[f][c]);
		}
		else return false;
	}
	bool toEst(int f, int c){
		if (c < C){
			return (marked[f][c ]);
		}
		else return false;
	}
	bool toNorth(int f, int c){
		if (f >= 0){
			return (marked[f][c]);
		}
		else return false;
	}
	bool toSouth(int f, int c){
		if (f < F){
			return (marked[f][c]);
		}
		else return false;
	}
	
};

