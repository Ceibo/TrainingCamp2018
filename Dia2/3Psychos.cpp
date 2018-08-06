#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#define dprint(v) cout << #v"=" << v << endl;

using namespace std;
bool estaOrdenado(std::vector<int> psychos){
	bool respuesta = true;
	for(int i = 0; i < psychos.size()-1; i++){
		if(psychos[i] > psychos[i+1]){
			respuesta = false;
			break;
		}
	}
	return respuesta;
}


int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	std::vector<int> psychos;

	int x = 0;
	bool flag = true;

	for(int i = 0; i < n; i++){
		int aux;
		cin >> aux;
		psychos.push_back(aux);
		if(i > 0 && psychos[i-1] > aux){
			flag = false;
		}
	}

	if( not(flag) ) {

	int tamAnterior = psychos.size()+1;
	while( psychos.size() != tamAnterior){
		std::vector<int> psychosAux;
		psychosAux.push_back(psychos[0]);
		for(int i = 1; i < psychos.size(); i++){
			if(psychos[i-1] < psychos[i]){
				psychosAux.push_back(psychos[i]);
			}
		}
		tamAnterior = psychos.size();
		psychos = psychosAux;
		if(psychos.size() != tamAnterior){
		x++;
		}
	}
	}
	cout << x <<endl;
	return 0;

}