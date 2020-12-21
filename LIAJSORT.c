#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX  1000000000
#define MIN -1000000000

void LIAJSORT(int *t,int r)
{
    //p for the postivie numbers,n for the negative
    int *p = malloc(sizeof(*p)),*n = malloc(sizeof(*n));p[0]=0 ;n[0]=0;
    int u =0,l = 0,s = 0 , e = 0;
    _Bool pt;
    for(int i = 0 ;i < r;i++)
        {
            e = (t[i] >= 0 ? t[i]%32:  t[i]%32);
            pt = (t[i] >=0 ? 1 : 0);
            u = (pt ? t[i]/32 : -t[i]/32);
            if(pt)
                {
                    if( u > l )
                        {
                            l = u;
                            p = realloc(p,(u +1)*sizeof(int32_t));
                            p[u] |= (1<<e);
                        }
                    else  
                        p[u] |= (1<<e);
                }
            else 
                {
                    if( u > s )
                        {
                            s = u;
                            n = realloc(n,(u +1)*sizeof(int32_t));
                            n[u] |= (1<<e);
                        }
                    else  
                        n[u] |= (1<<e);
                
                        
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

//to generate n randoms numbers
int* gener(int n)
{   
    srand(time(NULL));
    int *r = malloc(n*sizeof(int));
    for(int i = 0;i < n;i++)
            r[i] = (rand() % (MAX - MIN + 1)) + MIN;

    return r;
}

int main()
{
    int n = 300000,*t=gener(n) ;
    clock_t t1 = clock();
    LIAJSORT(t,n);
    printf("time = %f\n",(float)(clock()-t1)/CLOCKS_PER_SEC);

    
    
    return EXIT_SUCCESS;
}
