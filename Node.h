//Node.h
#ifndef OOPCES_NODE_H
#define OOPCES_NODE_H

template <typename T> class LinkList;	// 最外层：链表类（模板）提前声明
template <typename T> class Node		// 中间层：结点类（模板）
{
public:
    Node() : next(nullptr) {}										// 默认的构造函数，故意不初始化data以保持data的“原生态”
    Node(const T &t) : data(t), next(nullptr) {}					// 转换构造函数
    Node(const Node<T> &node) : data(node.data), next(nullptr) {}	// 拷贝构造函数
    Node<T> & operator=(const Node<T> &node)					// 重载赋值运算符函数
    {
        data = node.data;				// 结点间赋值时，仅改变数据域，不改变链接方式
        return *this;
    }
    friend class LinkList<T>;			// 声明友类，以使LinkList<T>类的成员函数访问结点类的私有成员data和next
private:
    T data;								// 最里层：数据域（形式数据类型）
    Node<T> *next;						// 指针域
};


#endif //OOPCES_NODE_H
