#include <stdio.h>

int main(void){
	long long int n, k;
	scanf ("%lld%lld", &n, &k);

	long long int noWin, dipW, c = 0;
	if (n % 2 == 0){
		long long int m = n/2;
		long long int bal = m % (k + 1);

		noWin = n/2 + bal;
		dipW = (m - bal)/(k + 1);
	}

	else{
		long long int m = (n - 1)/2;
		long long int bal = m % (k + 1);

		noWin = (n + 1)/2 + bal;
		dipW = (m - bal)/(k + 1);		
	}

	printf("%lld %lld %lld\n", dipW, k * dipW, noWin + c);
}