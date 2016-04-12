#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int main() {
	double start, end;
	double runTime;
	start = omp_get_wtime();
	int num = 1, primes = 0;

	int limit = 1000000;

#pragma omp parallel for schedule(dynamic) reduction(+ : primes)
	for (num = 1; num <= limit; num++) {
		int i = 2;
		while (i <= num) {
			if (num % i == 0)
				break;
			i++;
		}
		if (i == num)
			primes++;
		}

	end = omp_get_wtime();
	runTime = end - start;
	cout << "Dzialanie programu zakonczone" << endl;
	
	return 0;
}
