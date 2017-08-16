#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elemType;
typedef struct NodeList{
    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;
static void InitialList(Node **,Node **);//��ʼ����ͷ����β���ķ�ѭ��˫������
static void CreateList(Node *,Node *);//������ͷ����β����˫���ѭ������
static void DestoryList(Node *,Node *);//����ʼ����ͷ����β���ķ�ѭ��˫������
static void PrintList(Node *,Node *);//�����ӡ����
static int AddHeadList(Node *,Node *);//ͷ������ڵ�
static int AddLastList(Node *,Node *);//β������ڵ� 
static int AddPostList(Node *,Node *,int);//����posλ�õĽڵ�
static int DeletePosList(Node *,Node *,int );//ɾ��posλ�õĽڵ�
static int DeleteValueList(Node *,Node *,int );//ɾ��ֵΪx�Ľڵ㣬�����ڸýڵ���ɾ��֮
static int GetPosList(Node *,Node *,int );//������λ�û�ȡ 
static int NumSum(Node *,Node *);//����������Ԫ����ӵĽ��
static int MaxNum(Node *,Node *);//�����������Ԫ��
