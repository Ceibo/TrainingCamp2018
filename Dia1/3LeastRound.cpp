#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

void multiplicidades(int numero, std::pair<int, int> &contadorMultiplicidad){
	int multiplicidad2 = 0;
	int multiplicidad5 = 0;
		if(numero%2 == 0){
			int aux2 = intlog(2, numero);
			multiplicidad2 = multiplicidad2+aux2;
		}

		if(numero%5 == 0){
			int aux5 = intlog(5, numero);
			multiplicidad5 = multiplicidad5+aux5;
		}
	//Ahora actualizo el contador y listo
	contadorMultiplicidad.first = contadorMultiplicidad.first+multiplicidad2;
	contadorMultiplicidad.second = contadorMultiplicidad.second+multiplicidad5;

}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> matriz;
	for(int i = 0; i < n*n; i++){
		int elemento;
		std::cin >> elemento;
		matriz.push_back(elemento);
	} //ya esta la entrada

	//Acá calculamos las permutaciones posibles
	std::vector<int> permutaciones;
	for(int i = 0; i < (2*n)-2; i++){
		if(i < n-1){
			permutaciones.push_back(0);
		}
		else{
			permutaciones.push_back(1);
		}
	}

	std::vector<std::vector<int> > caminos;

	caminos.push_back(permutaciones);

	while(next_permutation(permutaciones.begin(),permutaciones.end())){
		caminos.push_back(permutaciones);
	}//Listo, en permutaciones tenemos todos los posibles vectores.
	
	// 0 ==> Right; 1 ==> Down
	// 0 ==> Sumo 1; 1 ==> Sumo n
	std::vector<int> camino_final;
	
	camino_final = caminos[0];

	int multiplicidad = 0;

	for(int i = 0; i < caminos.size() ; i++){
		std::vector<int> recorrido;
		int aux = 0;

		pair<int, int> contadorMultiplicidad = make_pair(0,0);

		for(int j = 0; j < (2*n)-2; j++){
			if(caminos[i][j] == 0){
				aux++;//Cambio de columna
			}else{
				aux = aux+n;//Cambio de fila
			}
			recorrido.push_back(matriz[aux]);
			if(matriz[aux] == 0){
				contadorMultiplicidad = make_pair (1,1);
				break;
			}else{
			multiplicidades(matriz[aux], contadorMultiplicidad);
			}
		}//Ahora tenemos en recorrido todos los numeros que hay en la permutación.
		int multiplicidadAux = contadorMultiplicidad.first;
		if(contadorMultiplicidad.first > contadorMultiplicidad.second){
			multiplicidadAux = contadorMultiplicidad.second;
		}
		if(multiplicidadAux < multiplicidad || i == 0){
			multiplicidad = multiplicidadAux;
			camino_final = caminos[i];
		}
	}

	std::cout << multiplicidad << std::endl;
	for(int i = 0; i < (2*n)-2; i++){
		if(camino_final[i] == 0){
			std::cout << 'R';
		} else{
			std::cout << 'D';
		}
	}

  return 0;
}