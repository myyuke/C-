#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int elemType;
typedef struct NodeList{
    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表
void CreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    printf("请输入链表内各值以0结束:\n"); 
    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}


//反初始化带头结点和尾结点的非循环双向链表
void DestoryList(Node *pHead,Node *pTail){
    while (pHead->next!= pTail) {
        Node *pMove;
        pMove = pHead->next;
        pHead->next=pMove->next;
        pMove->next->prior=pHead;
        free(pMove);
    }
	free(pHead);
	free(pTail);
	printf("链表销毁成功\n");	
}



//正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}
//头部插入节点
int AddHeadList(Node *pHead,Node *pTail){
    Node *pInsert;	
    pInsert = (Node*)malloc(sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    printf("%s请输入插入头部数值\n",__FUNCTION__);
	scanf("%d",&(pInsert->element));
    
	pInsert->prior=pHead; 
    pInsert->next=pHead->next;
    pHead->next=pInsert;
    printf("%s函数执行，插入头部位置的节点成功\n",__FUNCTION__);
    return 1;	
} 

//尾部插入节点 
int AddLastList(Node *pHead,Node *pTail){
    Node *pInsert;	
    pInsert = (Node*)malloc(sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    printf("%s请输入插入头部数值\n",__FUNCTION__);
	scanf("%d",&(pInsert->element));
	
	pInsert->prior=pTail->prior; 
    pInsert->next=pTail;
    pTail->prior->next=pInsert;
    printf("%s函数执行，插入尾部位置的节点成功\n",__FUNCTION__);
    return 1;	
} 

//插入pos位置的节点
int AddPostList(Node *pHead,Node *pTail,int pos){
    Node *pInsert;	
    pInsert = (Node*)malloc(sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    printf("%s请输入插入数值\n",__FUNCTION__,pos);
	scanf("%d",&(pInsert->element));
	
	int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
        	pInsert->prior=pMove; 
            pInsert->next=pMove->next;
            pMove->next->prior =pInsert;
            pMove->next=pInsert;
            printf("%s函数执行，插入pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，插入pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return 0;	
} 

//删除pos位置的节点
int DeletePosList(Node *pHead,Node *pTail,int pos){

    int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，删除pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return 0;
}



//删除值为x的节点，若存在该节点则删除之
int DeleteValueList(Node *pHead,Node *pTail,int x){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (pMove->element == x) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除值为x=%d的节点成功\n",__FUNCTION__,x);
            return 1;
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，删除值为x的节点失败\n",__FUNCTION__);
    return 0;
}


//按索引位置获取 
int GetPosList(Node *pHead,Node *pTail,int pos){
    int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
            printf("%s函数执行\n获取位置节点数值%d\n",__FUNCTION__,pMove->element);
            return pMove->element;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，删除pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return 0;
}


//求链表所有元素相加的结果
int NumSum(Node *pHead,Node *pTail){
 	int numsum = 0;
 	Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        numsum+=pMove->element;
        pMove = pMove->next;
    }
    return numsum;
 } 

//求链表中最大元素
int MaxNum(Node *pHead,Node *pTail){
	int nums = 0;
	Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if(pMove->element>nums){
        	nums=pMove->element;
        }
        pMove = pMove->next;
    }
    return nums;
} 


int main(int argc, const char * argv[]) {
    Node *pHead;//头结点
    Node *pTail;//尾结点
    InitialList(&pHead, &pTail);
    CreateList(pHead, pTail);
    PrintList(pHead, pTail);
    printf("链表中所有数值之和：%d\n",NumSum(pHead, pTail));
    printf("链表中最大值：%d\n",MaxNum(pHead, pTail));
//  AddLastList(pHead, pTail);
/*  DeletePosList(pHead, pTail, 2);
    PrintList(pHead, pTail);

    DeleteValueList(pHead, pTail, 5);
    PrintList(pHead, pTail);*/
    system("pause");
    return 0;
}

