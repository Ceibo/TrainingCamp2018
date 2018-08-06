#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define DBG(x) cerr << #x << ": " << x << endl;
#define uppercase(x) ((((x)<='z') && (x)>=('a'))?(x)+('A'-'a'):(x))
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

void add(string &input,string adder, int size)
{
	forn(i,size)
		input += adder;
	return;
}

void sub(string &input,int size)
{
	if(size!=0)
		input.erase(input.size()-size,size);
}

void obt_rom(string input, vector<char> digits)
{
	unordered_set<char> chars_total;
	vector<long> total_digits; // M 0 D 1 C 2 L 3 X 4 V 5 I 6
	vector<char> final_cosa;

	total_digits = vector<long>(7);
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
	cout << endl;
	
	return;
}

int main(void)
{
	vector<char> final_cosa,digits;
	string test;
	
	digits = vector<char>(7);
	digits[0] = 'M';
	digits[1] = 'D';
	digits[2] = 'C';
	digits[3] = 'L';
	digits[4] = 'X';
	digits[5] = 'V';
	digits[6] = 'I';
	test = "";
	forn(i1,4){
		add(test,"M",i1);
		forn(i2,2){
		add(test,"D",i2);
		forn(i3,4){
		add(test,"C",i3);
		forn(i4,2){
		add(test,"L",i4);
		forn(i5,4){
		add(test,"X",i5);
		forn(i6,2){
		add(test,"V",i6);
		forn(i7,4){
		add(test,"I",i7);
		obt_rom(test,digits);
		sub(test,i7);
		}
		sub(test,i6);
		}
		sub(test,i5);
		}
		sub(test,i4);
		}
		sub(test,i3);
		}
		sub(test,i2);
		}
		sub(test,i1);
	}
}
