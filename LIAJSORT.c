#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX  1000000000
#define MIN -1000000000

/**
 * @brief The core function of the liajsort made by Li101
 * Basically this function is a custom implementation of the 
 * Count Sort algorithm powered by BLSD (bitwise operation)
 * @param t an array of unsorted int
 * @param r the number of elements in t 
 */
void LIAJSORT(int *t, int r)
{
    //p for the positive numbers, n for the negative
    int *p = malloc(sizeof(*p));
    int *n = malloc(sizeof(*n));
    
    p[0]=0;
    n[0]=0;

    //TODO: explain variables here
    int u =0, l = 0, s = 0, e = 0;
    
    _Bool pt;

    for(int i = 0; i < r; i++)
    {
        // TODO: adding more comments in order to make this code more readable 

        e = (t[i] >= 0 ? t[i] % 32 : t[i] % 32);
        pt = (t[i] >= 0 ? 1 : 0);
        u = (pt ? t[i] / 32 : -t[i] / 32);
        
        if(pt) {
            if( u > l ) {
                l = u;
                p = realloc(p,(u + 1)*sizeof(int32_t));
                p[u] |= (1<<e);
            } else {
                p[u] |= (1<<e);
            }
        }  else {
            if( u > s ) {
                s = u;
                n = realloc(n,(u + 1)*sizeof(int32_t));
                n[u] |= (1<<e);
            } else  {
                n[u] |= (1<<e);
            }
                
        }
            
    }
        
        /*to print the array after sorting
        i've commented it because of the big size of input (>300000)
        
        //to print the negative numbers
        for(int i = s;i >- 1 ;i--)
            for(int j = 0 ;j < 32;j++)
                if(n[i]&(1<<j))printf("%d ->",-i*32 - (32 - j));
                
        // to print the positive numbers   
        for(int i = 0;i<l + 1;i++)
            for(int j = 0 ;j < 32;j++)
                if(p[i]&(1<<j))printf("%d ->",i*32 + j);
         */            
        printf("\n");
    
        
        /* void **tab[4];
        tab[0] = p;
        tab[1]=n;
        I was thinking to a way to return the array p,n and their size(respectivily l and s)
        but ....bored
         */
    }

/**
 * @brief A simple function to generate random n numbers
 * 
 * @param n the number
 * @return int* 
 */
int* gener(int n)
{   
    int *r = malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < n; i++)
        r[i] = (rand() % (MAX - MIN + 1)) + MIN;

    return r;
}

int main()
{
    //n refer to the number of number I want to be generated
    int n = 300000;

    //t is an array where I store the generated n numbers
    int *t = gener(n);

    //t1 stocks the main time 
    clock_t t1 = clock();
    
    LIAJSORT(t,n);

    printf("time = %f\n", (float)(clock() - t1) / CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
