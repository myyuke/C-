#include "dlist.c"
int main(int argc, const char * argv[]) {
    Node *pHead;//ͷ���
    Node *pTail;//β���
    InitialList(&pHead, &pTail);
    CreateList(pHead, pTail);
    PrintList(pHead, pTail);
    printf("������������ֵ֮�ͣ�%d\n",NumSum(pHead, pTail));
    printf("���������ֵ��%d\n",MaxNum(pHead, pTail));
//  AddLastList(pHead, pTail);
/*  DeletePosList(pHead, pTail, 2);
    PrintList(pHead, pTail);

    DeleteValueList(pHead, pTail, 5);
    PrintList(pHead, pTail);*/
    system("pause");
    return 0;
}

