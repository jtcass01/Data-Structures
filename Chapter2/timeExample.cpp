#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int count1(int countStop){
	clock_t initialTime, finalTime;
	
	initialTime = clock();
	
	int sum = 0;
	
	for (unsigned i = 0; i<countStop; i++){
		sum++;
	}

	finalTime = clock(); //- initialTime;
	
	cout << "Count 1 - Run Time: " << finalTime << endl;
}

int count2(int countStop){
	clock_t initialTime, finalTime;
	
	initialTime = clock();

	
	int sum = 0;
	
	for (unsigned i = 0; i<countStop; i++){
		for (unsigned j = 0; j < countStop; j++){
			sum++;
		}
	}

	finalTime = clock() - initialTime;

	cout << "Count 2 - Run Time: " << finalTime << endl;
}

int count3(int countStop){
	clock_t initialTime, finalTime;
	
	initialTime = clock();

	int sum = 0;
	
	for (unsigned i = 0; i<countStop; i++){
		for (unsigned j = 0; j < countStop*countStop; j++){
			sum++;
		}
	}

	finalTime = clock() - initialTime;

	cout << "Count 3 - Run Time: " << finalTime << endl;
}

int count4(int countStop){
	clock_t initialTime, finalTime;
	
	initialTime = clock();

	int sum = 0;
	
	for (unsigned i = 0; i<countStop; i++){
		for (unsigned j = 0; j < i; j++){
			sum++;
		}
	}

	finalTime = clock() - initialTime;

	cout << "Count 4 - Run Time: " << finalTime << endl;
}

int count5(int countStop){
	clock_t initialTime, finalTime;
	
	initialTime = clock();

	int sum = 0;
	
	for (unsigned i = 0; i<countStop; i++){
		for (unsigned j = 0; j < countStop*countStop; j++){
			for (unsigned k= 0; k < j; k++){
				sum++;
			}
		}
	}

	finalTime = clock() - initialTime;

	cout << "Count 5 - Run Time: " << finalTime << endl;
}

int count6(int countStop){
	clock_t time;
	
	time = clock();
	
	int sum = 0;

	for (unsigned i = 1; i<countStop; i++){
		for (unsigned j = 1; j < countStop*countStop; j++){
			if(j%i == 0){
				for (unsigned k= 0; k < j; k++){
					sum++;
				}
			}
		}
	}

	time = clock() - time;

	cout << "Count 6 - Run Time: " << (double) time << endl;
}


int main() {
	int countStop = 10;
	
	int sum1, sum2, sum3, sum4, sum5, sum6;
	
	cout << "---TIMES---" << endl;
	sum1 = count1(countStop);
	sum2 = count2(countStop);
	sum3 = count3(countStop);
	sum4 = count4(countStop);
	sum5 = count5(countStop);
	sum6 = count6(countStop);
	
	cout << "---SUMS---" << endl;
	cout << "sum1: " << sum1 << endl;
	cout << "sum2: " << sum2 << endl;
	cout << "sum3: " << sum3 << endl;
	cout << "sum4: " << sum4 << endl;
	cout << "sum5: " << sum5 << endl;
	cout << "sum6: " << sum6 << endl;
}
