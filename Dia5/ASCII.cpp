#include <vector>
#include <iostream>
#define dprint(v) cout << #v"=" << v << endl //;)

using namespace std;
int main(){
    //freopen("ascii.in", "r", stdin);
    //freopen("ascii.out", "w", stdout); 
    int h, w; 
    cin >> h;
    cin >> w;

    char c;
    vector<vector<char> > poligono;
    float area = 0;

    for(int i = 0; i < h; i++){
        vector<char> vacio;
        poligono.push_back(vacio);
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c;
            poligono[i].push_back(c);
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(poligono[i][j] == '.'){
                area ++;
            }else{
                area = area + 0.5;
            }
        }
    }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            int extIzq = 0;
            int extDer = 0;
            while(poligono[i][j] == '.' && j < w){
                extIzq++;
            }
            while(poligono[i][w-j-1] == '.' && j > 0){
                extDer++;
            }
            area = area - extIzq - extDer;
    }

    cout << area << endl;
    return 0;
}