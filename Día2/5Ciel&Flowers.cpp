#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#define dprint(v) cout << #v"=" << v << endl;


using namespace std;
int resolver(std::vector<int> rgb){

  	int paquetes = 0;
  	std::vector<int> vecPaquetes;
  	std::vector<int> rgbAux = rgb;
	int r = rgb[0];
	int g = rgb[1];
	int b = rgb[2];

    int rAux = r/3;
    rgb[0]= r%3;
    //dprint(rgb[0]);
    paquetes = paquetes+rAux;

    int gAux = g/3;
    rgb[1]= g%3;
    //dprint(rgb[1]);
	paquetes = paquetes+gAux;   

    int bAux = b/3;
    rgb[2]= b%3;
    //dprint(rgb[2]);
    paquetes = paquetes+bAux;

	std::sort(rgb.begin(), rgb.end());
    paquetes = paquetes + rgb[0];

    vecPaquetes.push_back(paquetes);

   	std::sort(rgbAux.begin(), rgbAux.end());
 	int minimo = rgbAux[0];
	paquetes = minimo;
   	for(int i = 0; i < 3; i++){
   		if(rgbAux[i] > 0){
   		rgbAux[i] = rgbAux[i]-minimo;
   		}
   	}
	paquetes = paquetes + (rgbAux[1]/3);
	paquetes = paquetes + (rgbAux[2]/3);
	vecPaquetes.push_back(paquetes);

	std::sort(vecPaquetes.begin(), vecPaquetes.end());

    //std::cout << vecPaquetes[1] << std::endl;    

	return vecPaquetes[1];

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

  	int aux = resolver(rgb);
    std::cout << aux << std::endl;    

    
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
