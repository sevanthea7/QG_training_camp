#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Sort.c"

void LTest( int *a, int (*result)[3][6] ){
	int i, j, len;
    int tests[3] = { 10000, 50000, 200000 };
    for( i = 0; i < 3; i ++ ){
    	len = tests[i];
        generate( a, len );
        for( j = 0; j < 6; j ++ ){
			clock_t start = clock();								// 开始计时 
            switch( j ){											// 对应的函数测试 
                case 0:
                    InsertSort( a, len );
                    break;
                case 1:
                    MergeSort( a, 0, len-1 );
                    break;
                case 2:
                    QuickSortRec( a, 0, len-1 );
                    break;
                case 3:
                    QuickSortNonRec( a, 0, len-1 );
                    break;
                case 4:
                    CountSort( a, len );
                    break;
                case 5:
                    RadixCountSort( a, len );
                    break;
            }
            clock_t diff = clock() - start;							// 停止计时 
            (*result)[i][j] = diff;									// 存入数组相应位置 
		}
		printf( "数据量%d测试完成！\n", tests[i] );
	}
}

void STest( int *a, int len, int *result ){
	int j, k;
    for( j = 0; j < 6; j ++ ){
		clock_t start = clock();
		for( k = 0; k < TIMES; k ++ ){
            switch( j ){
                case 0:
                    InsertSort( a, len );
                    break;
                case 1:
                    MergeSort( a, 0, len-1 );
                    break;
                case 2:
                    QuickSortRec( a, 0, len-1 );
                    break;
                case 3:
                    QuickSortNonRec( a, 0, len-1 );
                    break;
                case 4:
                    CountSort( a, len );
                    break;
                case 5:
                    RadixCountSort( a, len );
                    break;
            }
    	}
        clock_t diff = clock() - start;
        result[j] = diff;
        printf( "第%d个函数测试完毕！\n", j + 1 );
	}
} 

