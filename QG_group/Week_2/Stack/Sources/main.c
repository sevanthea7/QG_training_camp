#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/stack_calculator.h"
#include "./Stack_Calculator.c"

int main(){
	char s[30];
	int k, n, e, len, r;
	Stack S;
    InitLStack( &S );							// 初始化链栈
    printf("***************************\n");
	printf("*        1.链栈           *\n");
	printf("*        2.计算器         *\n");
	printf("***************************\n");
	printf( "请选择需要的功能：");
	scanf( "%s", s );
	k = test_option( s, 2 ); 					// 判断用户选择的功能
	if( k == 1 ){
		while(1){
			again:
			printf("********************************\n");
			printf("*     	   1.元素入栈          *\n");
		    printf("*          2.元素出栈          *\n");
		    printf("*       3.判断栈是否为空       *\n");
		    printf("*         4.取栈顶元素         *\n");
		    printf("*          5.清空栈            *\n");
		    printf("*          6.销毁栈            *\n");
		    printf("*        7.检测栈的长度        *\n");
		    printf("*        8.重新初始化栈        *\n");
		    printf("*          9.打印栈            *\n");
		    printf("*         10.退出程序          *\n");
		    printf("********************************\n");
		    printf("请选择需要的功能：");
		    scanf( "%s", s );
			k = test_option( s, 10 ); 
			switch( k ){
				case 1:
					if( S == NULL ){
						printf( "栈已销毁，请重新初始化栈！\n" ); 
						goto again;
					}
					while(1){
						printf( "请输入链栈的第%d个元素(Element Type: int)，输入x停止入栈：", ( S -> cnt + 1 ) );
						scanf( "%s", s );
						if( strcmp( s, "x" ) == 0 ){
							break;
						} 
						n = test_number( s );
						PushLStack( S, n );
					}
					break;
				case 2:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "栈为空，没有可以出栈的元素。\n" );
						goto again;
					} else if( r == -1 ){
						goto again;
					}
					PopLStack( S, &e );
					printf( "栈顶元素%d出栈成功。\n", e );
					break;
				case 3:
					r = EmptyLStack( S );
					if( r == 1 ){
						printf( "\n************栈不为空************\n\n" );
					} else if( r == 0 ) {
						printf( "\n*************栈为空*************\n\n" );
					}
					break;
				case 4:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "栈为空，没有可取的元素。\n" );
						goto again;
					} else if( r == -1 ){
						goto again;
					}
					GetTopElement( S, &e );
					printf( "栈顶元素为：%d\n", e );
					break;
				case 5:
					r = EmptyLStack( S );
					if ( r == 0 ){
						printf( "栈已为空。\n" );
						goto again; 
					}else if( r == -1 ){
						goto again;
					}else if( ClearStack( S ) == 1 ){
						printf( "清空成功！" ); 
					}
					break;
				case 6:
					if( DestroyStack( &S ) == 1 ){
						printf("销毁成功！\n" );
					}
					break;
				case 7:
					if( S == NULL ){
						printf( "栈已销毁，请重新初始化栈！\n" ); 
						goto again;
					} else {
						len = GetLength( S );
						printf( "栈的长度为：%d\n", len );
					}
					break;
				case 8: 
					if( S != NULL ){
						printf( "栈不需要初始化，请直接操作。\n" ); 
						goto again;
					}
					InitLStack( &S );
					printf("初始化成功！\n");
					break;
				case 9: 
					if ( EmptyLStack( S ) == 0 ){
						printf( "栈为空，没有可打印元素。\n" );
						goto again;
					}
					PrintStack( S );
					break;
				case 10:
					return 0;
			}
		}
	} else {
		do{
			char f[256] = { 0 };
		    char postf[512] = { 0 };
		    printf( "请输入算式(输入x停退出程序)：");
		    scanf( "%s", f );
		    if( strcmp( f, "x" ) == 0 ){
		    	break;
			} 
			ClearStack( S );
			r = transform( f, postf );
		    if( r == 1 ){
		        printf("后缀表达式：%s\n", postf );
			    r = calculate( S, postf );
			    if( r == 1 ){
			    	int ans;
				    GetTopElement( S, &ans );
				    printf( "%s=%d\n", f, ans );
				}
			}
		} while( 1 );
		
	}
    return 0;
}
