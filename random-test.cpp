#include<iostream>
#include"random.hpp"
using namespace std;

int main(){
	unsigned initial = xor32();
	unsigned current = xor32();
	cout << initial << ' ' << current << endl;
	unsigned counter = 0;
	do{
		current = xor32();
		counter++;
	}while(initial!=current);
	cout << "Counter:" << counter << endl;
	return 0;
}
