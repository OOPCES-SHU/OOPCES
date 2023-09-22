//LinkList.h
#ifndef OOPCES_LINKLIST_H
#define OOPCES_LINKLIST_H


#include <iostream>
#include "Node.h"

template <typename T> class LinkList			// 单向链表类模板设计
{
public:
    LinkList(int n=0, const T *array=nullptr);		// 构造函数（含默认的构造函数、转换构造函数等）
    LinkList(const LinkList &list);				// (深)拷贝构造函数
    ~LinkList();								// 析构函数
    LinkList & operator=(const LinkList &list);	// (深)赋值运算符函数

    void PutList(std::ostream &out) const;			// 输出链表所有结点的数据到引用out所绑定的ostream对象，该对象可以是cout，也可以是文件对象
    void GetList(std::istream &in);					// 从输入设备in获取数据，形成链表。
    int Save(const char *filename);				// 将链表所有结点的数据写入指定文件
    int Load(const char *filename);				// 从指定文件中读取数据，构造链表
    void ShowList() const;						// 输出链表所有结点的数据（另一种格式：在一行中输出）

    Node<T> *Insert(const T &t);				// 插入一个结点成为新的首结点
    Node<T> *InsertBefore(const T &t);			// 在当前结点之前插入一个结点
    Node<T> *InsertAfter(const T &t);			// 在当前结点之后插入一个结点
    Node<T> *Append(const T &t);				// 追加一个结点成为新的尾结点

    void FreeList();							// 释放链表中的所有结点
    T DeleteCurNode();				// 删除当前结点，其下一个结点（成为新的当前结点），值返回被删结点数据域数值
    T ModifyData(const T &t);		// 修改(替换)当前结点的数据域数值

    int NumNodes() const;						// 返回结点数
    int CurPos() const;							// 返回当前结点的序号（-1表示无当前结点）
    Node<T> *CurNode();							// 返回当前结点的地址（nullptr表示无当前结点）
    T & CurData();					// 引用返回当前结点数据域成员，函数调用表达式可做左值

    Node<T> *GoTop(), *Go(int n), *GoBottom();	// 当前结点绝对定位：首结点、第n个结点(n从0起)、尾结点
    Node<T> *Skip(int n=1) ;			// 当前结点相对定位（n可为负数），默认n为1表示下一个结点
    template <typename TYPE> Node<T> *Locate(const TYPE &x, bool newsearch=false); // 当前结点依条件（给定TYPE类型）定位

    template <typename TYPE> void Sort(const TYPE &x, bool ascending=true);	// 根据TYPE类型排序（升序或降序）
    void Reverse();								// 链表结点倒置

private:
    Node<T> *head, *cur_node;					// 链表首结点地址（指针）、当前结点地址（指针）
    int num;									// 用于记录链表中结点的个数
};

#endif //OOPCES_LINKLIST_H
