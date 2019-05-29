#include <stdio.h>
#include <stdlib.h>


struct Data{
    int data1;
    int data2;
    int data3;
    int data4;
};
typedef struct Data D;


struct node {
	int data;
	struct node* nextNodeAddr; // store an address that stores struct node
};
typedef struct node N;
struct List{
    N* head;   //List中第一個Node的Addr
    N* tail;   //the address of the last node of the list
};

typedef struct List L;

N* CreateNode(int data, N* nextNodeAddr);
N* AppendData(N* prevNodeAddr, int newData);

L CreateEmptyList(){
    L l;
    l.head = NULL;
    l.tail = NULL;

    return l;
}

void Push_back(L* lAddr, int data) {
	N* n;

	if (lAddr->tail == NULL) {// if list is empty
		n = CreateNode(data, NULL);
	}
	else {// if list is not empty
		n = AppendData(lAddr->tail, data);
	}
	lAddr->tail = n;

	if (lAddr->head == NULL) {
		lAddr->head = n;
	}
}



N* CreateNode(int data, N* nextNodeAddr) {
	N* n = malloc(sizeof(N));
	if (n == NULL) {
		return NULL;
	}


	n->data = data; //(*n).data = data;
	n->nextNodeAddr = nextNodeAddr;

	return n;
}

N* AppendData(N* prevNodeAddr, int newData) {
	N* newNodeAddr = CreateNode(newData, NULL);
	if (newNodeAddr == NULL) {
		return NULL;
	}

	(*prevNodeAddr).nextNodeAddr = newNodeAddr; //if *prevNodeAddr == NULL then fail.
	return newNodeAddr;
}

void _PrintList(N* firstNodeAddr) {
	for (N* nodeAddr = firstNodeAddr;
		nodeAddr != NULL;
		nodeAddr = (*nodeAddr).nextNodeAddr) {

		printf("%d -> ", (*nodeAddr).data);
	}
	printf("end\n");
}

void PrintList(L l){
    _PrintList(l.head);
}


void PrintArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

N* CreateListWithCycle(int n1, int n2){
    L l = CreateEmptyList();
    for(int i = 1; i <= (n1 + n2 - 1); i++){
        Push_back(&l, i);
    }
    N* nodeaddr = l.head ;
    for(int i = 1; i < n1 ; i++){      //linear search 找到第n1個Node
        nodeaddr = nodeaddr -> nextNodeAddr;
    }
    l.tail -> nextNodeAddr = nodeaddr;  //原本指向NULL改成指到第n1個Node
    return l.head;
}
int HasCycle(N* head){
    N* pslow = head;
    N* pfast = head;
    for (N* nodeAddr = head; nodeAddr != NULL; nodeAddr = nodeAddr -> nextNodeAddr){
		    pslow = pslow -> nextNodeAddr;
		    pfast = (pfast -> nextNodeAddr)-> nextNodeAddr;
		    if (pslow == pfast){
                printf("%d\n",1);
                break;
		    }
		    if (pfast == NULL){
                printf("%d\n",0);
                break;
		    }
		}
    return 0;
}
int CycleLength(N* head){
    int count = 0;
    N* pslow = head;
    N* pfast = head;
    for (N* nodeAddr = head; nodeAddr != NULL; nodeAddr = nodeAddr -> nextNodeAddr){
        pslow = pslow -> nextNodeAddr;
        pfast = (pfast -> nextNodeAddr)-> nextNodeAddr;
        if (pslow == pfast){
                break;
                }
        if (pfast == NULL){
            printf("cycle length : %d\n", count);
            return 0;
                }
        }
    do{
        pslow = pslow -> nextNodeAddr;
        count++;
    }while(pslow != pfast);
    printf("cycle length : %d\n", count);
    return 0;
}



int main() {
    L l = CreateEmptyList();
    for(int i = 1; i <= 10; i++){
        Push_back(&l, i);
    }
    HasCycle(l.head);
    CycleLength(l.head);

    /*N* lc;
    lc = CreateListWithCycle(94, 87);
    HasCycle(lc);
    CycleLength(lc);*/
    system("pause");
    return 0;
}






