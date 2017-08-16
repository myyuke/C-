#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elemType;
typedef struct NodeList{
    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;
static void InitialList(Node **,Node **);//初始化带头结点和尾结点的非循环双向链表
static void CreateList(Node *,Node *);//创建带头结点和尾结点的双向非循环链表
static void DestoryList(Node *,Node *);//反初始化带头结点和尾结点的非循环双向链表
static void PrintList(Node *,Node *);//正序打印链表
static int AddHeadList(Node *,Node *);//头部插入节点
static int AddLastList(Node *,Node *);//尾部插入节点 
static int AddPostList(Node *,Node *,int);//插入pos位置的节点
static int DeletePosList(Node *,Node *,int );//删除pos位置的节点
static int DeleteValueList(Node *,Node *,int );//删除值为x的节点，若存在该节点则删除之
static int GetPosList(Node *,Node *,int );//按索引位置获取 
static int NumSum(Node *,Node *);//求链表所有元素相加的结果
static int MaxNum(Node *,Node *);//求链表中最大元素
