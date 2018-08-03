#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define DBG(x) cerr << #x << ": " << x << endl;
#define uppercase(x) ((((x)<='z') && (x)>=('a'))?(x)+('A'-'a'):(x))

using namespace std;



int main(void)
{
	char c_read;
	unordered_set<char> chars_total;
	vector<long> total_digits; // M 0 D 1 C 2 L 3 X 4 V 5 I 6
	vector<char> final_cosa,digits;
	string input;
	
	
	total_digits = vector<long>(7);
	digits = vector<char>(7);
	digits[0] = 'M';
	digits[1] = 'D';
	digits[2] = 'C';
	digits[3] = 'L';
	digits[4] = 'X';
	digits[5] = 'V';
	digits[6] = 'I';
	
	cin >> input;
	for(int i=0;i<7;i++){
		total_digits[i]=0;
	}
	for(long i=0;i<input.size();i++){
		for(int j=0;j<7;j++){
			if(digits[j] == uppercase(input[i])){
				total_digits[j]++;
				break;
			}
		}
	}
/*
DBG("sale")
	for(int i=0;i<7;i++){
		total_digits[i] = chars_total.count(digits[i]);
DBG(total_digits[i])
	}
*/

	for(int i=0;i<7;i+=2){
		if(total_digits[i] >=3){
			final_cosa.push_back(digits[i]);
			final_cosa.push_back(digits[i]);
			final_cosa.push_back(digits[i]);
		}else{
			for(int j = 0;j<total_digits[i];j++){
				final_cosa.push_back(digits[i]);
			}
		} 
		if(i!=6){
			if(total_digits[i+1] != 0){
				final_cosa.push_back(digits[i+1]);
			}
		}
	}

	for(int i=0;i<final_cosa.size();i++)
		cout<<final_cosa[i];

	return 0;
}
