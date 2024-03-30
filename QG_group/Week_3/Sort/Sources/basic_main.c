#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/Sort.h"
#include "./Sort.c"

int main(){
	int a[SIZE] = {0};
	char s[256]; 
	int i, n, k, len = 0;
	
	while( 1 ){
		len = 0;
		printf("********************************\n");
		printf("*     请选择生成数组的方式     *\n");
		printf("********************************\n");
		printf("*          1.手动输入          *\n");
		printf("*          2.随机生成          *\n");
		printf("*          3.退出程序          *\n");
		printf("********************************\n");
		printf("请选择需要的功能：");
		scanf( "%s", s );
		k = test_option( s, 3 );
		switch( k ){
			case 1:
				for( i = 0; ; i ++ ){
					printf( "请输入第%d个数( 输入x停止输入 )：", i + 1 );
					scanf( "%s", s );
					if( strcmp( s, "x" ) == 0 ){
						break;
					} 
					n = test_number( s );
					a[i] = n;
					len ++;
				}
				printf( "成功生成数组\n" ); 
				print( a, len );
				break;
			case 2:
				while( 1 ){
					printf( "请输入想要生成的数的个数：");
					scanf( "%s", s );
					len = test_number( s );
					if( len > SIZE ){
						printf( "个数太多，请重新输入！\n" );
						continue;
					}else if( len <= 0 ){
						printf( "请输入有效个数！\n" );
						continue;
					}
					break;
				}
				generate( a, len );
				printf( "成功生成数组：\n" ); 
				print( a, len );
				break;
			case 3:
				return 0; 
		}
		printf( "\n" ); 
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
		printf( "\n\n" );
	}
}
