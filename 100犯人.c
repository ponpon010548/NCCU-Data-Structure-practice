#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
 srand(time(NULL));
 double count = 0;
 for (int i = 0 ; i < 10000 ; i++){
    int A[100] = {0};

    /*���N�Ʀr�̧ǩ�Jarray��*/

    for (int i =0 ; i < 100 ; i++){
        A[i] = i;
    }

    /*��shuffle���ʧ@*/

    for (int j = 0 ; j < 100 ; j++){
        int temp = A[j];                /*���N��j�ӼƼȦs�_��*/
        int randindex = rand() % 100;   /*�H�K��@��index*/
        A[j] = A[randindex];           /*��o�@��index�����Ʀr�s�JA[j]*/
        A[randindex] = temp;            /*��쥻�bA[j]���Ʀr���A[randindex]��*/
    }
    int flag = 0;                       /* 0:���� 1:���\*/
    for (int i = 0 ; i < 100 ; i++){    /*100�ӥǤH*/
        flag = 0;
        int j = i;                      /*j���n���}����P�s���A�Ĥ@�ӥ��}����P���ۤv���s��*/
        for(int try = 0 ; try < 50 ; try++){         /*�̦h��50��*/
                if ( i == A[j]){         /*�Y�s��i���ǤH���}A[j]����P���X��i*/
                    flag = 1;            /*���\�A�פ�j��*/
                    break;
                }
                else{                    /*�U�@�ӥ��}����P���X��A[j]*/
                    j = A[j];
                }
        }
        if(flag==0){                     /*���@�H���ѫh����j��*/
        break;
        }
    }
    if(flag==1){
            count++;
        }
 }
 printf("%f\n",count/10000);
}
