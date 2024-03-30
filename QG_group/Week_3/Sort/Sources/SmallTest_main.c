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
	printf("\n测试内容：100个数据进行100k次排序\n" );
    printf("运行时间:\n");
    printf( "InsertSort\tMergeSort\tQuickSortRec\tQuickSortNonRec\tCountSort\tRadixCountSort\n" );
    for( j = 0; j < 6; j ++ ){
		printf( "%d ms\t\t", result[j] );	
    }
    printf("\n");
    
    return 0;
}
