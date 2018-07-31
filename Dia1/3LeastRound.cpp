#include <bits/stdc++.h>
using namespace std;
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#define dprint(v) cout << #v"=" << v << endl;

int main(){
	int n;
	//std::cin >> n;
	n = 9;
	std::vector<int> matriz;
	for(int i = 0; i < n*n; i++){
		int elemento=1e9;
		//std::cin >> elemento;
		matriz.push_back(elemento);
	}
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
	}
	// 0 ==> Right; 1 ==> Down
	// 0 ==> Sumo 1; 1 ==> Sumo n
	std::vector<int> camino_final;
	int redondez = 0;
	camino_final = caminos[0];
	for(int i = 0; i < caminos.size() ; i++){
		int x = matriz[0];//Elemento inicial
		int aux = 0;
		for(int j = 0; j < (2*n)-2; j++){
			if(caminos[i][j] == 0){
				aux++;//Cambio de columna
			}else{
				aux = aux+n;//Cambio de fila
			}
			x = x*matriz[aux];
		}//Una vez terminado el primer for, en x deberiamos tener el producto ese que queríamos.
		//Ahora tenemos que ver si nos gusta o no.

		int redondezAux = 0;

		if(x == 0){
			redondezAux = 1;
		} else{
			while(x % 10 == 0){
				redondezAux++;
				x = x/10;
			}
		}
		if(i == 0){
			redondez = redondezAux;
		}

		if(redondezAux == 0){
			redondez = redondezAux;
			camino_final = caminos[i];
			break;
		}

		if(redondezAux < redondez){
			redondez = redondezAux;
			camino_final = caminos[i];
		}
	}

	std::cout << redondez << std::endl;
	for(int i = 0; i < (2*n)-2; i++){
		if(camino_final[i] == 0){
			std::cout << 'R';
		} else{
			std::cout << 'D';
		}
	}

  return 0;
}