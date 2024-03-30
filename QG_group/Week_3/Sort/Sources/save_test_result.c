#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MSIZE 100

void LWriteFile( int *a, int len, char s[256] ){
    FILE *file = fopen( s, "w");
    if( file == NULL ){
        printf( "�ļ���ʧ�ܣ�\n");
        return;
    }
    int result[3][6];
    int tests[3] = { 10000, 50000, 200000 };
    LTest( a, &result );
    int i, j;
    fprintf( file, "������������\n" );
    fprintf( file, "Size\tInsertSort\tMergeSort\tQuickSortRec\tQuickSortNonRec\tCountSort\tRadixCountSort\n" );
    for( i = 0; i < 3; i ++ ){
        fprintf( file, "%d\t", tests[i] );
        for( j = 0; j < 6; j ++ ){
            if( result[i][j] < 10000 ){
                fprintf( file, "%d ms\t\t", result[i][j] );
            } else {
                fprintf( file, "%d ms\t", result[i][j] );
            }
        }
        fprintf( file, "\n" );
    }
    
    fclose(file);
}


void SWriteFile( int *a, int len, char s[256] ){
    FILE *file = fopen( s, "w");
    if( file == NULL ){
        printf( "�ļ���ʧ�ܣ�\n");
        return;
    }
    int result[6];
    int i, j;
    STest( a, len, result );
    fprintf( file, "С����������\n" );
    fprintf( file, "InsertSort\tMergeSort\tQuickSortRec\tQuickSortNonRec\tCountSort\tRadixCountSort\n" );
    for( j = 0; j < 6; j ++ ){
        fprintf( file, "%d ms\t\t", result[j] );
    }
    fprintf( file, "\n" );

    
    fclose(file);
}


