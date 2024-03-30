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
    printf( "大数据量测试进行中...\n\n");
    LWriteFile( a, SIZE, s1 );
    printf( "大数据量测试完成！结果存储在Data文件夹的文件'test_Large.txt'中\n\n"); 
    generate( b, MSIZE );
    printf( "小数据量测试进行中...\n\n");
    SWriteFile( b, MSIZE, s2 );
    printf( "小数据量测试完成！结果存储在Data文件夹的文件'test_Small.txt'中\n\n"); 
    return 0;
}
