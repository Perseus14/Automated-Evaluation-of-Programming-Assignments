/*
                                Badhan Sen
                            Student of C.S.E
                jessore University of Science & Technology
                        Mail: galaxybd9@gmail.com

*/
#include<stdio.h>

int main ()
{
    long long int n, i=1, j=1, ck=0;
    scanf ("%I64d", &n);
    while (i<n){
        while (j<n){
            if (n==(i*i+i+j*j+j)/2){
                ck=1;
                break;
            }
            j++;
        }
        i++;
    }

    if (ck==1)
        printf ("YES");

    else
        printf ("NO");

    return 0;
}
