#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
 srand(time(NULL));
 double count = 0;
 for (int i = 0 ; i < 10000 ; i++){
    int A[100] = {0};

    /*先將數字依序放入array中*/

    for (int i =0 ; i < 100 ; i++){
        A[i] = i;
    }

    /*做shuffle的動作*/

    for (int j = 0 ; j < 100 ; j++){
        int temp = A[j];                /*先將第j個數暫存起來*/
        int randindex = rand() % 100;   /*隨便選一個index*/
        A[j] = A[randindex];           /*把這一個index中的數字存入A[j]*/
        A[randindex] = temp;            /*把原本在A[j]的數字放到A[randindex]中*/
    }
    int flag = 0;                       /* 0:失敗 1:成功*/
    for (int i = 0 ; i < 100 ; i++){    /*100個犯人*/
        flag = 0;
        int j = i;                      /*j為要打開的抽屜編號，第一個打開的抽屜為自己的編號*/
        for(int try = 0 ; try < 50 ; try++){         /*最多試50次*/
                if ( i == A[j]){         /*若編號i的犯人打開A[j]的抽屜號碼為i*/
                    flag = 1;            /*成功，終止迴圈*/
                    break;
                }
                else{                    /*下一個打開的抽屜號碼為A[j]*/
                    j = A[j];
                }
        }
        if(flag==0){                     /*有一人失敗則停止迴圈*/
        break;
        }
    }
    if(flag==1){
            count++;
        }
 }
 printf("%f\n",count/10000);
}
