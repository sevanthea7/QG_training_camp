#include <stdio.h>
#include <stdlib.h>
#include "./Sort.c"

void ColorSort( int *a, int len ){
    int p0 = 0; 													// ָ��0Ӧ�÷��õ�λ��
    int p2 = len - 1; 												// ָ��2Ӧ�÷��õ�λ��
	int tmp, i; 
    for( i = 0; i <= p2; i ++ ){
        if( a[i] == 0 ){											// �����ǰԪ����0������p0λ��Ԫ�ؽ��н���������p0
            int tmp = a[i];
            a[i] = a[p0];
            a[p0] = tmp;
            p0 ++;
        }else if( a[i] == 2 ){										// �����ǰԪ����2������p2λ��Ԫ�ؽ��н���������p2
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
        if( p - head == k - 1 ){									// �����׼ֵλ��=k�����ҵ��˵�KС����
            return a[p];
        }else if( p - head > k - 1 ){								// �����׼ֵ��λ��>k��������߼�����
            return findK( a, head, p - 1, k );
        }else{													 	// �����׼ֵ��λ��<k�������ұ߼�����
            return findK( a, p + 1, tail, k - ( p - head + 1 ) );
        }
    }
    return -1; 														// ���k������Ч��Χ�ڣ�����-1
}

int main(){
	int i = 0;
	int k;
	char s[30];
	printf("��ɫ����\n");
	int a[7] = { 1, 2, 1, 0 , 2, 0 , 0 };
	ColorSort( a, 7 );
	Print( a, 7 );
	printf( "�ҵ�����С����\n" ); 
	int b[7] = { 5, 2, 8, 4, 3, 7, 6 };
	Print( b, 7 ); 
	printf( "%d", findK( b, 0, 6, 3 ) );
	return 0;
} 
