#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "linklist.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace  std;

void Func_test();

void nohead_test();

void head_display();

void nohead_display();

typedef struct datas
{
	int num;
	string intro;
	datas()
	{
		num = 0;
		intro = "无";
	};
	datas(int n, string s)
	{
		num = n;
		intro = s;
	};
}datas;

//结点类结构体
typedef struct node
{

	datas* information;
	node* next;
	node() //无参构造结点
	{
		information = new datas;
		next = NULL;
	};
	node(datas& item, node* ptr = NULL) //带参构造结点（无头结点）
	{
		information = &item;
		next = ptr;
	};

}node;

class LinkList
{
public:
	//无参构造，带头结点的链表
	LinkList()
	{
		head = new node;//给头结点分配内存
		with_head = true;
	};

	//带参构造，无头结点的链表
	LinkList(node* x)
	{

		head = x;
		with_head = false;//不带头结点

	};

	//看是否带头结点
	bool withHead()
	{
		return with_head;
	}

	//复制构造函数
	LinkList(LinkList& L);

	//析构函数（用于释放内存，防止内存泄露）
	~LinkList()
	{
		makeEmpty();
	}

	node* get_head()
	{
		return head;
	}

	node* last();//获取尾指针

	void makeEmpty();//清空链表

	node* locate(int i); //返回链表中第i个元素的地址

	//判断是否为空链表（看头指针指向的下一结点指针是否为NULL即可）
	bool isEmpty()
	{
		return (with_head) ? head->next == NULL : head == NULL;
	}

	void input(datas endTag = { 0, "结束" }, bool front = true);//建立链表（默认为前插法）

	int length();//计算单链表的长度

	int find(datas& x);//返回第一个数据为x是第几个值

	void save_data(int k, datas& saved);//将第k个数据保存到saved

	void output();//输出链表

	datas remove(int k); //删除第k个值并返回

	void insert(datas ins_data, int k); //按位插入（默认带头结点）

	int single(); //判断有序性 

	void insert(datas ins_data); //按值插入，得先判断当前链表是否为严格递增或递减

	void reverse(); //翻转链表

private:
	node* head;//头节点指针
	bool with_head;
};


#endif
