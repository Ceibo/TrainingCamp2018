#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#define dprint(v) cout << #v"=" << v << endl;


using namespace std;
int main(){
	int n; 
	cin >> n;
	std::vector<pair<int, int>> coordenadas;
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a;
		cin >> b;
		pair<int, int> coordenada = make_pair(a, b);
		coordenadas.push_back(coordenada); 
	}

	std::vector<int> coordenadasX1;
	for(int i = 0; i < n; i++){
		int aux = coordenadas[i].first;
		coordenadasX1.push_back(aux);
	}
    std::sort(coordenadasX1.begin(), coordenadasX1.end());
    int minX1 = coordenadasX1[0]; 


	std::vector<int> coordenadasX2;
	for(int i = 0; i < n; i++){
		int aux = coordenadas[i].second;
		coordenadasX2.push_back(aux);		
	}
	std::sort(coordenadasX2.begin(), coordenadasX2.end());
	int maxX2 = coordenadasX2[n-1];

	pair<int, int> encontrado = make_pair(minX1, maxX2);

	int resultado = -1;
	for(int i = 0; i < n; i++){
		if(coordenadas[i] == encontrado){
			resultado = i+1;
			break;
		}
	}
	cout << resultado;	
	return 0;
}