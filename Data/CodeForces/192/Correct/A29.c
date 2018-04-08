#include <stdio.h>

int n;
int arr[44725];

int busqueda(int num)
{
	int l = 0, r = 44720, m;

	while(l <= r)
	{
		m = (l + r)/2;		
		if(num + arr[m] == n)
			return m;
		else if(num + arr[m] < n)
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}

int main(){
	
	int i;
	
	for(i = 0; i <= 44720; i++){
		arr[i] = i*(i + 1)/2;
	}
	
	scanf("%d", &n);
	for(i = 1; i <= 44720; i++){
		if(busqueda(arr[i])){
			printf("YES\n");
			break;
		}
	}
	if(i > 44720)
		printf("NO\n");
	return 0;	
}
