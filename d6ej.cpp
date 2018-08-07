#include <iostream>
#include <algorithm>
#include <queue>

#define DBG(x) cerr << #x << ": " << x << endl;

using namespace std;

int main(void)
{
//	long long total=2,tea=1,milk=1,num_T=0,den_T,num_M,den_M;
	string cadena;
	long long n;
	double milk_cup,tea_cup,milk_drank=0,tea_drank=0;
//	vector<pair<long long,long long>> teas_drank;
//	vector<pair<long long,long long>> milks_drank;
	
	cin >> n;
	cin >> cadena;

	milk_cup = 0.5;
	tea_cup = 0.5;
	
	for(long long i=0;i<cadena.size();i++){
//		teas_drank.push_back(make_pair(tea,total));
//		milks_drank.push_back(make_pair(milk,total));
		milk_drank += milk_cup;
		tea_drank += tea_cup;
		if(cadena[i] == 'H'){
			tea_cup = tea_cup/(double)2 +  0.5;
		}else{
			milk_cup = milk_cup/(double)2 +  0.5;
		}
	}
	if(tea_drank>milk_drank){
		cout << "H" << endl;
		return 0;
	}else if(tea_drank<milk_drank){
		cout << "M" << endl;
		return 0;
	}else{
		cout << "HM" << endl;
		return 0;
	}
	
	
}
