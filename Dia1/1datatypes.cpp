#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector


int main(){
	int n;
  	std::cin >> n;
  	std::vector<int>  tamanos;
    for(int i = 0; i < n ; i++){
      int a;
  		std::cin >> a;
  		tamanos.push_back(a);
  	}
  	
    std::sort(tamanos.begin(), tamanos.end());
    
    for(int i = 0; i < n-1; i++){
        int k = i+1;
        for(int j = i+1; tamanos[i]==tamanos[j]; j++){
          k = j+1;
        }

        if(2*tamanos[i] > tamanos[k] && k != n){
            std::cout << "YES";
            return 0;
        }
    }
    
    std::cout << "NO";
	return 0;
}