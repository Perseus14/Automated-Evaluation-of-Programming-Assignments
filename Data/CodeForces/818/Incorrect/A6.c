#include <stdio.h>

int main(void){
	long int n, k;
	scanf ("%ld%ld", &n, &k);

	long int noWin, dipW, c = 0;
	if (n % 2 == 0){
		noWin = n/2;
		int m = n/2;

		while(m % (k + 1) != 0 && m >= 0){
			c++;
			m--;
		}

		dipW = m/(k + 1);
	}

	else{
		noWin = (n + 1)/2;
		int m = (n - 1)/2;

		while(m % (k + 1) != 0 && m >= 0){
			c++;
			m--;
		}

		dipW = m/(k + 1);		
	}

	printf("%ld %ld %ld\n", dipW, k * dipW, noWin + c);
}