#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/Sort.h"
#include "./Test.c"
#include "./save_test_result.c"
#define MSIZE 100

int main() {
    int a[SIZE], b[MSIZE];
    char s1[256] = "../Data/test_Large.txt";
    char s2[256] = "../Data/test_Small.txt";
    generate( a, SIZE );
    printf( "�����������Խ�����...\n\n");
    LWriteFile( a, SIZE, s1 );
    printf( "��������������ɣ�����洢��Data�ļ��е��ļ�'test_Large.txt'��\n\n"); 
    generate( b, MSIZE );
    printf( "С���������Խ�����...\n\n");
    SWriteFile( b, MSIZE, s2 );
    printf( "С������������ɣ�����洢��Data�ļ��е��ļ�'test_Small.txt'��\n\n"); 
    return 0;
}
