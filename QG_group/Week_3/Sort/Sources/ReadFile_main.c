#include <stdio.h>
#include <stdlib.h>
#include "./Sort.c"
#include "../Header/Sort.h"


int ReadFile( int *a, char s[256] ){
    FILE *file = fopen( s, "r" );
    int i;
    if( file == NULL ){
        printf( "文件读取失败!\n");
        return -1;
    }    
    int cnt = 0;
    while( fscanf( file, "%d", &a[cnt] ) == 1) {
        cnt ++;
        if( cnt >= SIZE) {											// 如果读入的数字的量大于数组大小的话，停止读入 
            break;
        }
    }
    fclose( file );
    return cnt;
}

int main(){
	int a[SIZE];
	char s[256];
	int i, n, k, len = 0;   
	int flag = 1;
	while( 1 ){
		if( flag ){
			while( 1 ){
				printf( "请输入要导入文件的文件名( 建议文件'../Data/test.txt' )：" );
				scanf( "%s", s );
				len = ReadFile( a, s );
				if( len != -1 ){
					break;
				}    	
			} 
			printf("成功导入数组：\n");
			print( a, len );
			flag = 0;
		} else{
			len = ReadFile( a, s );
			printf("成功导入数组：\n");
			print( a, len );
		}
		
		
		k = Menu1();
		switch( k ){
			case 1:
				if( InsertSort( a, len ) ){
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 2:
				if( len > 0 ){
					MergeSort( a, 0, len-1 );
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 3:
				if( len > 0 ){
					QuickSortRec( a, 0, len-1 );
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 4:
				if( len > 0 ){
					QuickSortNonRec( a, 0, len-1 );
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 5:
				if( CountSort( a, len ) ){
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 6:
				if( RadixCountSort( a, len ) ){
					printf( "成功排序数组：\n" ); 
					print( a, len );
				}else{
					printf( "排序失败！\n" );
				}
				break;
			case 7:
				return 0;
		}
		printf("\n数组已恢复未排序操作，可重新选择：\n");
	}
	
	
}
