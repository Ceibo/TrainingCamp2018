#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#define dprint(v) cout << #v"=" << v << endl;


using namespace std;

void metodo1(std::vector<int> &rgb, int &resultado){
  while(rgb[0] > 2 && rgb[2] > 2 && rgb[1] > 2){
    rgb[0] = rgb[0]-3;
    rgb[1] = rgb[1]-3;
    rgb[2] = rgb[2]-3;
    resultado++;
    resultado++;
    resultado++;
  }
}

void metodo2(std::vector<int> &rgb, int &resultado){
  while(rgb[0]!=0 && rgb[1] != 0 && rgb[2] != 0 ){
    rgb[0]--;
    rgb[1]--;
    rgb[2]--;
    resultado++;
  }

}
void metodo3(std::vector<int> &rgb, int &resultado){
  int x = 0;

  while(x < *max_element(rgb.begin(), rgb.end())){
    if(rgb[0] > 2){
      rgb[0] = rgb[0]-3;
      resultado++;
    }
    if(rgb[1] > 2){
      rgb[1] = rgb[1]-3;
      resultado++;
    }
    if(rgb[2] > 2){
      rgb[2] = rgb[2]-3;
      resultado++;
    }
    x++;
  }
}


int main(){

	int r, g, b;
	std::cin >> r;
	std::cin >> g;
	std::cin >> b;

  	std::vector<int>  rgb;
  	rgb.push_back(r);
  	rgb.push_back(g);
  	rgb.push_back(b);

  	int resultado(0);
    metodo1(rgb, resultado);
    metodo2(rgb, resultado);
    metodo3(rgb, resultado);

    std::cout << resultado << std::endl;    

    
    // for(int i = 0; i < 5; i++){
    // 	for(int j = 0; j < 5; j++){
    // 		for(int k = 0; k < 5; k++){
    // 			for(int l = 0; l <5; l++){
    // 				std::vector<int> prueba(3);
    // 				prueba[0] = 3*i;
    // 				prueba[1] = 3*j;
    // 				prueba[2] = 3*k;

    // 				prueba[0] = prueba[0]+l;
    // 				prueba[1] = prueba[1]+l;
    // 				prueba[2] = prueba[2]+l;

    // 				int resultadoEsperado = (i+j+k+l);
    // 				cout << "RGB: " << prueba[0] << prueba[1] << prueba[2] << endl;
    // 				int resultadoObtenido = resolver(prueba);
 			// 		cout << "Resultado Obtenido: " << resolver(prueba) << endl;
 			// 		cout << "Resultado Esperado: " << resultadoEsperado << endl;

    //  			}

    // 		}
    // 	}
    // }

	return 0;
}
