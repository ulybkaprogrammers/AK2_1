#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int main() {
	double start, end;
	double runTime;
	start = omp_get_wtime();
	int x = 1,
        int primeN = 0;

	int limit = 1000000000000;

#pragma omp parallel for schedule(dynamic) reduction(+ : primeN)
	for (x = 1; x <= limit; x++) {
		int i = 2;
		while (i <= x) {
			if (x % i == 0)
			break;
			i++;
			
			double y = i / 2;
			double z = i * 2;
			y *= 1000000000000;
			z *= 1000000000000;
		}
		if (i == x)
			primeN++;
		}

	end = omp_get_wtime();
	runTime = end - start;
	cout << "Dzialanie programu zakonczone" << endl;
	
	return 0;
}
