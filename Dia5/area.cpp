#define DBG(x) cerr << #x << ": " << x << endl;
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <numeric>
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
#define uppercase(x) ((((x)<='z') && (x)>=('a'))?(x)+('A'-'a'):(x))

bool lineaCompleta(std::vector<char> &linea){
    int tam = linea.size();
    bool respuesta = true;
    forn(x, tam){
        if(linea[x] != '.'){
            respuesta = false;
            return respuesta;
        }
    }
    return respuesta;
}

int primerLineaNoCompleta(std::vector<std::vector<char> > &matriz){
    forn(i, matriz.size()){
        if(not(lineaCompleta(matriz[i]))){
            return i;
        }
    }
    return 0;
}

int ultimaLineaNoCompleta(std::vector<std::vector<char> > &matriz){
    for(int i = matriz.size()-1; i >= 0; i--){
        if(not(lineaCompleta(matriz[i]))){
            return i;
        }
    }
    return matriz.size()-1;
}


using namespace std;
int main(){
    freopen("ascii.in", "r", stdin);
    freopen("ascii.out", "w", stdout); 
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

    int pLNC = primerLineaNoCompleta(poligono);
    int uLNC = ultimaLineaNoCompleta(poligono);
    for(int i = pLNC; i < uLNC+1; i++){
        forn(j, w){
            if(not(lineaCompleta(poligono[i]))){
                if(poligono[i][j] != '.'){
                    break;
                }else{
                    area --;
                }
            }
        }
    }


    for(int i = pLNC; i < uLNC+1; i++){
         if(not(lineaCompleta(poligono[i]))){
            for(int j = w-1; j >= 0; j--){
                if(poligono[i][j] != '.'){
                    break;
                }else{
                    area --;
                }
            }
        }
    }


    cout << area << endl;
    return 0;
}