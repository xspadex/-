// 静态链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#define MAXSIZE 10
#define INCREMENT 10//堆上长度扩展（未实现）
#define OK 1
#define ERROR 0
#define OVERFLOW -1

using namespace std;

typedef string ElemType;
typedef struct {
	ElemType data;
	int next;
}node,NList[MAXSIZE];

//链表初始化
int initList(NList L) {
	for (int i = 0; i < MAXSIZE - 1; i++) {
		L[i].next = i + 1;
	}
	L[MAXSIZE - 1].next = 0;

	L[0].next = 2;//空闲链表头指针
	L[1].next = 1;//占用链表头指针
	return OK;
}

//链表长度
int GetLength(NList L) {
	int index = 1;
	int count = 1;
	while (L[index].next!=1) {
		count++;
		index = L[index].next;
	}
	return count-1;
}

//print链表
int printList(NList L) {
	int index = 1;
	while (L[index].next != 1) {
		index = L[index].next;
		cout << L[index].data << " ";
	}
	cout << "." << endl;
	return OK;
}

//get
int getElem(NList L,int pos, ElemType out) {
	int index = 1;
	for (int i = 0; i < pos; i++) {
		if (L[index].next == 1) return ERROR;
		index = L[index].next;
	}
	out = L[index].data;
	return OK;
}

//插入
int insertElem(NList L, int pos, ElemType in) {//其后
	int prior;
	int index = 1;
	for (int i = 0; i < pos; i++) {
		if (L[index].next == 1) return ERROR;
		index = L[index].next;
	}
	prior = index;//前驱
	index = L[0].next;//本结点
	if (L[index].next == 0) return OVERFLOW;//保留空的尾结点
	L[index].data = in;//赋值
	L[0].next = L[index].next;//空闲链表的链接
	L[index].next = L[prior].next;//插入常规操作1（后）
	L[prior].next = index;//插入常规操作2（前）
	return OK;
}


//删除
int deleteElem(NList L, int pos) {//本结点
	if (pos <= 0) return ERROR;
	int prior;
	int index = 1;
	for (int i = 0; i < pos; i++) {
		prior = index;//前驱
		if (L[index].next == 1) return ERROR;
		index = L[index].next;
	}
	L[prior].next = L[index].next;//删除常规操作
	L[index].next = L[0].next;//插入空闲链表操作1
	L[0].next = index;//插入空闲链表操作2
	return OK;
}

//print底层结构
int printStruct(NList L, int size) {
	for (int i = 0; i < size; i++) {
		cout << "index=" << i << " data=" << L[i].data << " next=" << L[i].next << endl;
	}
	return OK;
}

int main()
{
	NList L;
	initList(L);
	insertElem(L, 0, "Tomorrow");
	insertElem(L, 1, "Wendy");
	insertElem(L, 2, "going");
	insertElem(L, 3, "to");
	insertElem(L, 4, "die");
	//deleteElem(L, 2);
	//insertElem(L, 1, "Wendy's");
	cout << GetLength(L) << endl;
	printList(L);
	printStruct(L, 10);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
