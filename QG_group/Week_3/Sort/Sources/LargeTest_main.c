#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Test.c"

int main(){
    int a[SIZE];
    int result[3][6];
    LTest( a, &result );
    int i, j;
    printf("\n运行时间:\n");
    printf( "Size\tInsertSort\tMergeSort\tQuickSortRec\tQuickSortNonRec\tCountSort\tRadixCountSort\n" );
    for( i = 0; i < 3; i ++ ){
    	int tests[3] = { 10000, 50000, 200000 };
        printf( "%d\t", tests[i] );
        for( j = 0; j < 6; j ++ ){
        	if( result[i][j] < 10000 ){
        		printf( "%d ms\t\t", result[i][j] );
			} else{
				printf( "%d ms\t", result[i][j] );
			}
            
        }
        printf("\n");
    }
    return 0;
}
