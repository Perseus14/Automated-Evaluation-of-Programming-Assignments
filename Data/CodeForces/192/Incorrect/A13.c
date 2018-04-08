    /*
        GARCIA LOMELI ABRAHAM AMOS
        ANALISIS DE ALGORITMOS 3CM2

        ESTE CODIGO FUE DESARROLLADO EL DIA 19 DE ABRIL DEL 2017
        
        FUNKY NUMBERS V1.2
    */

   #include <stdio.h>
    #include <stdlib.h>
	#include <math.h>
	
	void LlenaTabla(int numeroPrueba, int memo[], int posicionActual){
		//printf("entre a LlenaTabla con %d\n",posicionActual );
		if(posicionActual<=numeroPrueba){
			if(posicionActual==1){
				memo[posicionActual]=1;
			}
			else{
				memo[posicionActual]=memo[posicionActual-1]+posicionActual;
			}
			LlenaTabla(numeroPrueba,memo,posicionActual+1);
		}
	}


	int CompruebaFunky(int numeroPrueba, int memo[],int inicio, int final){
		int ejemplo=memo[inicio]+memo[final];
		if(numeroPrueba==ejemplo)
			return 1;
		else if(numeroPrueba<ejemplo){
			if(inicio<final-1){
				CompruebaFunky(numeroPrueba,memo,inicio,final-1);
			}
			else
				return 0;
		}
		else{
			if(inicio+1<final){
				CompruebaFunky(numeroPrueba,memo,inicio+1,final);
			}
			else{
				return 0;
			}
		}

	}


	void main()
	{
		int numeroPrueba;
		scanf("%d",&numeroPrueba);

		int tamano=(sqrt(2*numeroPrueba));
		
		int* memo=malloc(sizeof(int)*(tamano+2));
		int i;

		//for(i=0; i<numeroPrueba+2; i++)
		//	memo[i]=-1;

	
		LlenaTabla(tamano,memo,1);


		//printf("Imprimi bien la tabla\n");

		int veredicto=CompruebaFunky(numeroPrueba,memo,1,tamano);
		
		if(numeroPrueba==2)
			printf("YES\n");

		else if(veredicto==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}