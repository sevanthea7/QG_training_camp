#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Test.c"

#define MSIZE 100
#define TIMES 100000

int main(){
    int a[MSIZE];
    int len = MSIZE;
    int result[6];
    generate( a, len ); 
    STest( a, len, result );
	int j;
	printf("\n�������ݣ�100�����ݽ���100k������\n" );
    printf("����ʱ��:\n");
    printf( "InsertSort\tMergeSort\tQuickSortRec\tQuickSortNonRec\tCountSort\tRadixCountSort\n" );
    for( j = 0; j < 6; j ++ ){
		printf( "%d ms\t\t", result[j] );	
    }
    printf("\n");
    
    return 0;
}
