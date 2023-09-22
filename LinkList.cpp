//LinkList.cpp
#include "LinkList.h"
#include <fstream>
#include <cstdlib>
template <typename T>
LinkList<T>::LinkList(int n, const T *array) : head(nullptr),num(0)	// 构造函数（含默认的构造函数、转换构造函数等）
{
    Node<T> *p;
    for(int i=n-1; i>=0; i--)
    {
        p = new Node<T>;				// 自动调用Node<T>默认的构造函数创建堆结点
        if(array!=nullptr)
            p->data = array[i];			// 如果array为nullptr，则保持p->data的默认状态
        p->next = head;					// 运用头插法，按数组元素倒序将堆结点依次插入到链表首结点前
        head = p;
    }
    cur_node = head;
    num = n;
}

template <typename T>
LinkList<T>::LinkList(const LinkList &list) : head(nullptr),cur_node(nullptr),num(0)	// (深)拷贝构造函数
{
    *this = list;	// 首先通过显式的冒号规则创建一条空链表，然后调用(深)赋值运算符函数赋值整条链表
}

template <typename T>
LinkList<T>::~LinkList()						// 析构函数
{
    FreeList();
}

template <typename T>
LinkList<T> & LinkList<T>::operator=(const LinkList &list)// (深)赋值运算符函数
{
    if(this == &list)					// 如果赋值运算表达式的右值对象与本对象为同一对象（它们的地址相同）
        return *this;					// 则直接返回本对象（*this）
    // 这是重载双目运算符函数时应该注意的问题。如果赋值表达式左、右两个对象为同一对象，贸然执行下面的语句将造成严重错误！
    // 因为，尽管右边的对象list还被视为const常量对象，释放了左边对象（即本对象）的所有结点后，右边对象的所有结点也就不存在了
    FreeList();							// 因为本对象不是右值对象，故可以释放本对象的所有结点。
    Node<T> *temp = nullptr;
    for(Node<T> *p=list.head; p!=nullptr; p=p->next)
    {
        Append(p->data);				// 本对象的“当前”结点随Append函数变化
        if(p == list.cur_node)			// 发现右面对象的“当前”结点
            temp = cur_node;			// 记录下本对象的“当前”结点
    }
    cur_node = temp;
    return *this;
}

template <typename T>
void LinkList<T>::PutList(std::ostream &out) const	// 输出链表所有结点的数据到引用out所绑定的ostream对象，该对象可以是cout，也可以是文件对象
{
    out << '(' << num << ')' << std::endl;			// 首先输出（或保存至文件）结点的个数
    for(Node<T> *p=head; p!=nullptr; p=p->next)
        out << p->data << std::endl;
}

template <typename T>
void LinkList<T>::GetList(std::istream &in)			// 从输入设备in获取数据，形成链表。
{
//	FreeList();
    T x;
    char str[80];
    int n;
    in.getline(str, 80, '(');					// 首先忽略'('字符及其可能的所有前导字符
    in.getline(str, 80);						// 读取字符至行尾
    n = atoi(str);
    for(int i=0; i<n; i++)
    {
        in >> x;
        Append(x);
    }
    cur_node = head;
    in.clear();
    in.sync();
}

template <typename T>
std::ostream & operator<<(std::ostream &out, const LinkList<T> &list)		// 本函数不是成员函数，仅为一个普通的C++函数
{
    list.PutList(out);
    return out;
}

template <typename T>
std::istream & operator>>(std::istream &in, LinkList<T> &list)			// 本函数不是成员函数，仅为一个普通的C++函数
{
    list.GetList(in);
    return in;
}

template <typename T>
int LinkList<T>::Save(const char *filename)		// 将链表所有结点的数据写入指定文件
{
    std::ofstream outfile(filename);
    if(outfile.fail())
        return 0;
    outfile << *this;
    outfile.close();
    return num;
}

template <typename T>
int LinkList<T>::Load(const char *filename)		// 从指定文件中读取数据，构造链表
{
    int n = NumNodes();
    std::ifstream infile(filename);
    if(infile.fail())
        return 0;
    infile >> *this;
    infile.close();
    cur_node = head;
    return num - n;
}

template <typename T>
void LinkList<T>::ShowList() const				// 输出链表所有结点的数据（格式一：在一行中输出）
{
    std::cout << "head";
    for(Node<T> *p=head; p!=nullptr; p=p->next)
        std::cout << (p==cur_node? " ->*" : " -> ") << p->data;
    std::cout << " -> nullptr" << std::endl;
}

template <typename T>
Node<T> *LinkList<T>::Insert(const T &t)		// 插入一个结点成为新的首结点
{
    Node<T> *p = new Node<T>(t);
    p->next = head;
    head = p;
    num++;
    return cur_node = p;
}

template <typename T>
Node<T> *LinkList<T>::InsertBefore(const T &t)	// 在当前结点之前插入一个结点
{
    if(cur_node==nullptr || head==nullptr)
        return cur_node=nullptr;
    Node<T> *p = new Node<T>(t);
    if(cur_node == head)
    {
        p->next = head;
        head = p;
    }
    else
    {
        Skip(-1);
        p->next = cur_node->next;
        cur_node->next = p;
    }
    num++;
    return cur_node = p;
}

template <typename T>
Node<T> *LinkList<T>::InsertAfter(const T &t)	// 在当前结点之后插入一个结点
{
    if(cur_node==nullptr || head==nullptr)
        return cur_node=nullptr;
    Node<T> *p = new Node<T>(t);
    p->next = cur_node->next;
    cur_node->next = p;
    num++;
    return cur_node = p;
}

template <typename T>
Node<T> *LinkList<T>::Append(const T &t)		// 追加一个结点成为新的尾结点
{
    Node<T> *p = new Node<T>(t);				// Node<T>的转换构造函数使next为nullptr
    if(head==nullptr)
        head = p;
    else
    {
        for(cur_node=head; cur_node->next!=nullptr; cur_node=cur_node->next)
            ;
        cur_node->next = p;
    }
    num++;
    return cur_node = p;
}

template <typename T>
void LinkList<T>::FreeList()					// 释放链表中的所有结点
{
    Node<T> *p;
    while(head!=nullptr)
    {
        p = head;								// 暂时保存原链首结点地址，以便释放
        head = head->next;						// 原首结点脱链，原首结点的下一个结点成为链首结点
        delete p;								// 这里用到了隐含假设：假设所有结点都是动态结点
    }
    cur_node = nullptr;
    num = 0;
}

template <typename T>
T LinkList<T>::DeleteCurNode() 		// 删除当前结点，其下一个结点（成为新的当前结点），值返回被删结点数据域数值
{
    if(cur_node==nullptr || head==nullptr)
        return 0;
    Node<T> *p;
    T x;
    if(cur_node == head)
    {
        p = head;
        head = head->next;
        x = p->data;
        delete p;
        cur_node = head;
    }
    else
    {
        Skip(-1);
        p = cur_node->next;			// p指向待删除的结点
        cur_node->next = p->next;	// 待删除的结点脱链
        cur_node = p->next;			// 移动当前结点
        x = p->data;				// 取出其数据域数据值
        delete p;					// 释放带删除的结点
    }
    num--;
    return x;
}

template <typename T>
T LinkList<T>::ModifyData(const T &t) // 修改(替换)当前结点的数据域数值
{
    if(cur_node==nullptr)
        return 0;
    T x = cur_node->data;			// 取出当前结点数据域数据值
    cur_node->data = t;				// 替换数据域数据值
    return x;
}

template <typename T>
int LinkList<T>::NumNodes() const				// 返回结点数
{
    return num;
}

template <typename T>
int LinkList<T>::CurPos() const					// 返回当前结点的序号（-1表示无当前结点）
{
    if(cur_node == nullptr)
        return -1;
    int n = 0;
    Node<T> *p;
    for(p=head; p!=nullptr && p!=cur_node; p=p->next,n++)
        ;
    if(p==nullptr)									// 此时的cur_node指向不明
        return -1;
    return n;
}

template <typename T>
Node<T> *LinkList<T>::CurNode()					// 返回当前结点的地址（nullptr表示无当前结点）
{
    return cur_node;
}

template <typename T>
T & LinkList<T>::CurData()			// 引用返回当前结点数据域成员，函数调用表达式可做左值
{
    if(cur_node!=nullptr)
        return cur_node->data;
    else
        return 0;
}

template <typename T>
Node<T> *LinkList<T>::GoTop()					// 当前结点绝对定位：首结点、第n个结点(n从0起)、尾结点
{
    return cur_node = head;
}

template <typename T>
Node<T> *LinkList<T>::Go(int n)					// 当前结点绝对定位：首结点、第n个结点(n从0起)、尾结点
{
    if(n<0 || n>num)
        return cur_node=nullptr;
    int i=0;
    cur_node = head;
    while(cur_node!=nullptr && i<n)
    {
        cur_node = cur_node->next;
        i++;
    }
    return cur_node;
}

template <typename T>
Node<T> *LinkList<T>::GoBottom()				// 当前结点绝对定位：首结点、第n个结点(n从0起)、尾结点
{
    if(head==nullptr)								// 空链表时
        cur_node = nullptr;
    for(cur_node=head; cur_node->next!=nullptr; cur_node=cur_node->next)	// 此时链表非空，cur_node->next合法
        ;
    return cur_node;
}

template <typename T>
Node<T> *LinkList<T>::Skip(int n) 	// 当前结点相对定位（n可为负数），默认n为1表示下一个结点
{
    if(cur_node == nullptr)
    {
        return nullptr;
    }
    int m = CurPos() + n;
    return cur_node = Go(m);
}

template <typename T> template <typename TYPE>
Node<T> *LinkList<T>::Locate(const TYPE &x, bool newsearch) // 当前结点依条件（给定TYPE类型）定位
{
    static Node<T> *p=head;
    static TYPE data = x;
    if(newsearch)
    {
        p = head;
        data = x;
    }
    for(; p!=nullptr && TYPE(p->data)!=TYPE(data); p=p->next)	// for循环的表达式1为空：从链表的"当前"结点起继续查找
        ;													// TYPE()为类型强制转换运算符
    cur_node = p;
    if(p!=nullptr)		// 如果找到，在返回找到的结点地址（cur_node）之前，p"悄悄"地向前走一步，为继续查找做好准备
        p = p->next;
    return cur_node;
}

template <typename T> template <typename TYPE>
void LinkList<T>::Sort(const TYPE &x, bool ascending)	// 根据TYPE类型排序（升序或降序）
{
    if(head==nullptr || head->next==nullptr) return;
    Node<T> *p, *pGuard, *rest;
    // 首先将原链表拆成两条链表
    rest = head->next;			// 旧链：原第一个结点起
    head->next = nullptr;			// 新链：单结点链表，原第 0 个结点
    // 依次处理，直至旧链为空
    while(rest != nullptr)
    {
        p = rest;
        rest = rest->next;		// 卸下旧链“首”结点
        if( (ascending && ((TYPE)p->data < (TYPE)head->data)) || (!ascending && TYPE(p->data) > TYPE(head->data)) )
        {
            p->next = head;
            head = p;
            continue;
        }
        pGuard = head;
        while(pGuard->next!=nullptr &&
              ((ascending && TYPE(pGuard->next->data) <= TYPE(p->data)) ||
               (!ascending && TYPE(pGuard->next->data) >= TYPE(p->data))) )
            pGuard = pGuard->next;
        p->next = pGuard->next;
        pGuard->next = p;
    }
}

template <typename T>
void LinkList<T>::Reverse()						// 链表结点倒置
{
    if(head==nullptr || head->next==nullptr)			// 空链表、单结点链表：无须操作
        return;
    // 首先将原链表拆成两条链表
    Node<T> *p, *rest = head->next;				// 将原链表的第二个结点起至尾结点，视为“剩余链表”rest
    head->next = nullptr;							// 将原链表的首节点作为一条新链表（目前仅有一个结点）
    while(rest!=nullptr)							// 将“剩余链表”处理完即结束循环
    {
        p = rest;
        rest = rest->next;						// 将“剩余链表”的首节点卸下（并不删除），用p记住
        p->next = head;
        head = p;								// 将卸下的结点插入新链表的首部
    }											// 注意：由于只修改了各结点的next的值，cur_node不变
}