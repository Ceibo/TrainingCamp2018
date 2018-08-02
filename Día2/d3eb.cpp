#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DBG(x) cerr << #x << ": " << x << endl;
#define MAX(A,B) ((A)>(B)?(A):(B))

using namespace std;

long cut(vector<long> &posible,long length,vector<long> & cache);

int main(void)
{

//cache -2 -> no leido
// -1 es que no se puede
	long length,res;
	vector<long> posible(3);
	vector<long> cache;

	cin >> length;
	cin >> posible[0];
	cin >> posible[1];
	cin >> posible[2];

	cache = vector<long>(length+1);
	for(long i=0;i<length+1;i++)
		cache[i] = -2;

	sort(posible.begin(),posible.end());
	cout << cut(posible,length,cache);

	return 0;
}

long cut(vector<long> &posible,long length, vector<long> & cache) 
{
	long max_posible,a=-1,b=-1,c=-1,temp_l;
	vector<long> opts;
	
	opts = vector<long>(3);

	if(length == 0){
		cache[length] = 0;
		return 0;
	}
	if(length < posible[0]){
		if(length > 0)
			cache[length] = -1;
		return -1;
	}

	for(int i =0;i<3;i++){
		if( (temp_l = length-posible[i]) < 0){
			opts[i] = -1;
		}else{
			if(cache[temp_l] == -2){ //no esta cacheado
				cache[temp_l] = opts[i] = cut(posible,temp_l,cache);
			}else{
				opts[i] = cache[temp_l];
			}
		}
	}

	max_posible = MAX(MAX(opts[0],opts[1]),opts[2]);
	if(max_posible == -1){
		cache[length] = max_posible;
		return -1;
	}else{
		cache[length] = max_posible+1;
		return max_posible+1;
	}
}
