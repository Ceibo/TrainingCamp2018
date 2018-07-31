#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

int main(){
	std::vector<std::vector<int>> intentos;
	int cantIntentos;
  	std::cin >> cantIntentos;
    for(int i = 0; i < cantIntentos ; i++){
      	int numero;
  		std::cin >> numero;
  		intentos[i].push_back(numero);

  		int bulls;
  		std::cin >> bulls;
  		intentos[i].push_back(bulls);	

  		int cows;
  		std::cin >> cows;
  		intentos[i].push_back(cows);
  	}

  	first = base / 1000;
	second = base / 100 % 10;
	third =  base / 10 % 10;
	fourth = base % 10;

}
