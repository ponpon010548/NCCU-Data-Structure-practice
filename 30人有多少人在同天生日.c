#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
 double count = 0;
 int flag = 0;
 int A[30]={0};
 srand(time(NULL));
 for (int i =0;i<10000;i++){
     flag = 0;
     for (int l = 0;l<30;l++){
        int a = rand()%365;
        A[l]= a;
        }
     for (int j =0;j<30;j++){
        for(int k =j+1;k<30;k++){
            if (A[j]==A[k]){
               flag = 1;
               }
            }
         }
     if (flag>0){
        count++;
      }

    }
 printf("%f\n",count/10000);
}
