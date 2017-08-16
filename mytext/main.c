#include "dlist.c"
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

