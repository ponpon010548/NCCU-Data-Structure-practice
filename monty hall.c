#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
 double count1=0 , count2=0 ;
 srand(time(NULL));
 //����Ĺ�o���y����
 for (int i =0;i<10000;++i){
    int door[3] = {0};
    int a = rand()%3; //��@�Ӫ����car
    door[a] = 1; //0:goat , 1:car
    int b = rand()%3; //�Ĥ@�������
    if (door[a] == door[b] ){
        count1++;
    }
 }
 printf("no switch and win :%f\n",count1/10000);

// ���BĹ�o���y����
 for (int j = 0;j<10000;++j){
    int door[3]={0};
    int a = rand()%3;
    door[a] = 1;
    int b = rand()%3;
    if(door[b]==0){                  //����
            count2++;
        }
 }
 printf("switch and win:%f\n",count2/10000);
}
