#include <stdio.h>
int dp [31623];
void CalculaT(){
	int i;
	dp [0] = 1;
	for (i = 1; i < 31623; i++)
		dp[i] = dp[i - 1] + (i+1);
}

int BusquedaBin(int ini, int fin, int x){
	if (ini > fin) return -1;
	int mitad = (ini + fin) / 2;
	if (dp[mitad] == x)
		return mitad;
	if (dp[mitad] < x) 
		return BusquedaBin(mitad + 1, fin, x);
return BusquedaBin(ini, mitad - 1, x);
}

int main (void){
	int n, i, cont = 0;
	scanf ("%d", &n);
	CalculaT();
	for (i = 0; i < 31623; i++){
		if (BusquedaBin(0, 31622, n - dp[i]) >= 0 && cont == 0){
			printf ("YES\n");
			cont++;
		}
	}
	if(cont == 0)
		printf("NO\n");	
return 0;
}