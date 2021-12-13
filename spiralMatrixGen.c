#include <stdio.h>
#include <string.h>
#define R 6
#define C 6

/*
based off of someone's code on google to print matrix in spiral order. I modded it so that the matrix itself has a "spiral" inside it.

         0  1  2  3  4 5 
        19 20 21 22 23 6 
        18 31 32 33 24 7 
        17 30 35 34 25 8 
        16 29 28 27 26 9 
        15 14 13 12 11 10 

when I use R or C anytime in comments, it means an arbitary value rowwise/columnwise, respectively

*/



int printMatrix(int m, int n, int a[m][n]){ //two layers of for loops beats using whatever is going on down below... for printing.

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    exit(0);
}

void spiralGen(int m, int n, int a[m][n]){
    int i, k = 0, l = 0;

    /*
        k - starting row index
        m - ending row index
        l - starting col index
        n - ending col index
        i - iterator
    */
    int x = 0; //for populating our matrix with values so that we can track the "spiral" movement.

    while(k < m && l < n){ //while our index vars are less than the limit... aka while we have not exhausted our scope...

        //first move through the first row (column-wise - or horizontally, if you are challanged like me c: ) using a for loop with n as our max value
        for(i = l; i < n; ++i){
            a[k][i] = x++;
        }
        k++; //increment starting row index to "move down"

/*
at this point we are here:

         0  1  2  3  4 X  <-- X marks the spot - and we want to go |
        19 20 21 22 23 6                                           |
        18 31 32 33 24 7                                           |  d o w n
        17 30 35 34 25 8                                           |
        16 29 28 27 26 9                                           |
        15 14 13 12 11 10                                          V

and then the for loop below says, "now we move down one row using the fact that we incremented k++ before. since we now want to go d o w n columnwise, we put our iterator i in this fashion:

    before we had: a[m][C] position
    now we have:   a[i][C] position

using m as our max value (m is the size of the rows in the matrix)

*/

        for(i = k; i < m; ++i){
            a[i][n-1] = x++; //we do [n-1] bc of off-by-one adjustment
        }
        n--; //make our scope smaller by "crossing out" the last printed col

/*
by doing n-- we have effectively done this (imagine ~ is our way of crossing off things):

         0  1  2  3  4 ~ 
        19 20 21 22 23 ~
        18 31 32 33 24 ~
        17 30 35 34 25 ~ 
        16 29 28 27 26 ~ 
        15 14 13 12 11 ~ 

but since we did k++ earlier, we moved our position to point the second row, so what we have so far is actually this:

         ~  ~  ~  ~  ~ ~ 
        19 20 21 22 23 ~
        18 31 32 33 24 ~
        17 30 35 34 25 ~ 
        16 29 28 27 26 ~ 
        15 14 13 12 11 ~ 

and so now we want to move this way:

         ~  ~  ~  ~  ~ ~ 
        19 20 21 22 23 ~
        18 31 32 33 24 ~
        17 30 35 34 25 ~ 
        16 29 28 27 26 ~ 
        15 14 13 12 11 ~ 
this way <------------

*/

        //TODO check this section

        if(k < m){ //if our scope has not been exhausted rowwise...
            for(i = n - 1; i >= l; --i){ //then we start moving "backwards" by decrementing columnwise from position a[R][i] to a[R][l]
                a[m-1][i] = x++; //we do the            
            }
            m--; //crossing out the row m
        }

/*

Now we have this: 
         ~  ~  ~  ~  ~ ~ 
        19 20 21 22 23 ~
        18 31 32 33 24 ~
        17 30 35 34 25 ~ 
        16 29 28 27 26 ~ 
         ~  ~  ~  ~  ~ ~ 


*/

        //print first col from the remaining col
        if(l < n){ //if scope has not been exhausted columnwise...
            for(i = m - 1; i >= k; --i){ //then we start moving upwards by decrementing rowwise from position a[i][l] to a[k][l]
                a[i][l] = x++;
            }
            l++; 
        }

/*
So now we have this: 
         ~  ~  ~  ~  ~ ~ 
       ^ ~  20 21 22 23 ~
       | ~  31 32 33 24 ~
       | ~  30 35 34 25 ~ 
       | ~  29 28 27 26 ~ 
         ~  ~  ~  ~  ~ ~ 

And then the next time we loop through our first for loop in this block, we will have this:

            -------> 
         ~  ~  ~  ~  ~ ~ 
         ~  ~  ~  ~  ~ ~
         ~  31 32 33 24 ~
         ~  30 35 34 25 ~ 
         ~  29 28 27 26 ~ 
         ~  ~  ~  ~  ~ ~ 
etc

*/

    }

    printMatrix(R, C, a);

    
}

int main(void){

    int a[R][C];
    
    int i = 0, j = 0, temp = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            a[i][j] = temp;
        }
    }
 
    spiralGen(R, C, a);
    return 0;
}
