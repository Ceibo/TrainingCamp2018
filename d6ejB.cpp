#include <iostream>
#include <algorithm>
#include <queue>

#define DBG(x) cerr << #x << ": " << x << endl;

using namespace std;

int main(void)
{
	string cadena;
	long n,temp;
	vector< int> last_milk;
	vector< int> last_tea;
	vector< int> total_milk;
	vector< int> total_tea;

	cin >> n;
	cin >> cadena;

	last_tea = vector<int> (n);
	last_milk = vector<int> (n);
	total_milk = vector<int> (n);
	total_tea = vector<int> (n);

	for(long i=0;i<n;i++){
		last_tea[i] = 0;
		last_milk[i] = 0;
		total_tea[i] = 0;
		total_milk[i] = 0;
	}
	last_tea[0] = 1;
	last_milk[0] = 1;

	for(long i=0;i<n;i++){
		for(long j=0;j<i+1;j++){
			total_milk[j] = total_milk[j] + last_milk[n-1-i+j];
			total_tea[j] = total_tea[j] + last_tea[n-i-1+j];
		}
/*
		for(long j=i;j>0;j--){
			last_milk[j] = last_milk[j-1];
			last_tea[j] = last_tea[j-1];
		}
*/
		if(cadena[i] == 'H'){
			last_tea[n-i-1] = 1;
			last_milk[n-i-1] = 0;
		}else{
			last_tea[n-i-1] = 0;
			last_milk[n-i-1] = 1;
		}
	}
	for(long j=n-1;j>0;j--){
		if(total_milk[j]>1){
			temp = total_milk[j];
			total_milk[j] = temp%2;
			total_milk[j-1]+= (temp-total_milk[j]);
		}
		if(total_tea[j]>1){
			temp = total_tea[j];
			total_tea[j] = temp%2;
			total_tea[j-1]+= (temp-total_tea[j]);
		}
	}
	for(long i=0;i<n;i++){
		if(total_tea[i]>total_milk[i]){
			cout << "H" << endl;
			return 0;
		}else if(total_tea[i]<total_milk[i]){
			cout << "M" << endl;
			return 0;
		}
	}
	cout << "HM" << endl;

	return 0;
}
