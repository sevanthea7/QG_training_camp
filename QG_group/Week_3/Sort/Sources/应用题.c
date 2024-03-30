#include <stdio.h>
#include <stdlib.h>
#include "./Sort.c"

void ColorSort( int *a, int len ){
    int p0 = 0; 													// 指向0应该放置的位置
    int p2 = len - 1; 												// 指向2应该放置的位置
	int tmp, i; 
    for( i = 0; i <= p2; i ++ ){
        if( a[i] == 0 ){											// 如果当前元素是0，则与p0位置元素进行交换、更新p0
            int tmp = a[i];
            a[i] = a[p0];
            a[p0] = tmp;
            p0 ++;
        }else if( a[i] == 2 ){										// 如果当前元素是2，则与p2位置元素进行交换、更新p2
            tmp = a[i];
            a[i] = a[p2];
            a[p2] = tmp;
            p2 --;
            i--;
        }
    }
}

void Print( int *a, int len ){
	int i;
	for( i = 0; i < len; i ++ ){
		printf( "%d ", a[i] );
	}
	printf( "\n" );
}

int findK( int *a, int head, int tail, int k ){
    if( k > 0 && k <= tail - head + 1) {
        int p = SideSort( a, head, tail );
        if( p - head == k - 1 ){									// 如果基准值位置=k，则找到了第K小的数
            return a[p];
        }else if( p - head > k - 1 ){								// 如果基准值的位置>k，则在左边继续找
            return findK( a, head, p - 1, k );
        }else{													 	// 如果基准值的位置<k，则在右边继续找
            return findK( a, p + 1, tail, k - ( p - head + 1 ) );
        }
    }
    return -1; 														// 如果k不在有效范围内，返回-1
}

int main(){
	int i = 0;
	int k;
	char s[30];
	printf("颜色排序：\n");
	int a[7] = { 1, 2, 1, 0 , 2, 0 , 0 };
	ColorSort( a, 7 );
	Print( a, 7 );
	printf( "找到第三小的数\n" ); 
	int b[7] = { 5, 2, 8, 4, 3, 7, 6 };
	Print( b, 7 ); 
	printf( "%d", findK( b, 0, 6, 3 ) );
	return 0;
} 
