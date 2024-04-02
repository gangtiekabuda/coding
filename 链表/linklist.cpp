#include "linklist.h"
#include <iostream>
#include <string>

using namespace  std;

//检查无误！
node* LinkList::last()
{

	if (isEmpty())
	{
		return NULL;
	}

	node* p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;

}

//检查无误！
node* LinkList::locate(int i)
{
	
	//i<0回空指针
	if (i < 0)
	{
		return NULL;
	}

	node* current = head;//当前所在结点指针
	int k = (with_head) ? 0 : 1;//计数
	while (current != NULL && k < i)
	{
		current = current->next;
		k++;
	}
	return current;

}

//头指针挪到屁股并释放内存就完成了清空
//检查无误！
void LinkList::makeEmpty()
{

	if (isEmpty())
	{
		cout << "空的不能再空啦！" << endl;
		throw 1;
		return;
	}

	node* p;
	while (head->next != NULL)
	{
		p = head->next;
		head->next = p->next;
		delete p;//释放临时指针的内存
	}

	//如果不带头结点还得删除掉第一个结点
	if (!with_head)
	{
		head = NULL;
	}

}

//头插尾插构造链表
//检查无误！
void LinkList::input(datas endTag, bool front)
{

	//为新元素申请结点
	node* p;

	datas* new_data = new datas;

	if (front)//前插法构造链表
	{
		cout << "请输入第一个数据：";
		cin >> new_data->num;
		cin >> new_data->intro;

		//直接输入结束符，立刻开溜
		if ((new_data->num == endTag.num) && (new_data->intro == endTag.intro))
		{
			return;
		}

		//不满足结束标志则持续输入
		while ((new_data->num != endTag.num) || (new_data->intro != endTag.intro))
		{
			p = new node;//为新结点申请空间
			p->information->num = new_data->num;
			p->information->intro = new_data->intro;
			if (head->next != NULL)
			{
				p->next = head->next;
			}
			head->next = p;
			cout << "请输入数据：";
			cin >> new_data->num;
			cin >> new_data->intro;
		}
	
	}

	else//尾插法构造链表
	{

		cout << "请输入第一个数据：";
		cin >> new_data->num;
		cin >> new_data->intro;

		if ((new_data->num == endTag.num) && (new_data->intro == endTag.intro))
		{
			return;
		}


		//不满足结束标志则持续输入
		while ((new_data->num != endTag.num) || (new_data->intro != endTag.intro))
		{
			p = new node;//为新结点申请空间
			p->information->num = new_data->num;
			p->information->intro = new_data->intro;
			last()->next = p;
			cout << "请输入数据：";
			cin >> new_data->num;
			cin >> new_data->intro;
		}

	}

}

//检查无误！
int LinkList::length()
{
	if (isEmpty())
		return 0;

	int count = 0;

	if (head->next != NULL)
	{
		node* p = head->next;
		count = 1;
		while (p->next != NULL)
		{
			p = p->next;
			count++;
		}

	}
	
	return (withHead()) ? count : count + 1;//无头结点时要把初始结点算进去!

}

//检查无误！
int LinkList::find(datas& x)
{

	node* p = (with_head) ? head->next : head;
	int i = 1;

	if (isEmpty())
	{
		cout << "无数据可供查找！" << endl;
		throw 2;
	}

	while ((p->information->num != x.num) || (p->information->intro != x.intro))
	{
		if (p->next == NULL)
			break;
		p = p->next;
		i++;
	}
	if ((p->information->num == x.num) && (p->information->intro == x.intro))
	{
		return i;
	}
	
	//找不到
	return -1;

}

//检查无误！
void LinkList::save_data(int k, datas& saved)
{

	if (isEmpty())
	{
		cout << "鬼！这里没东西可存！" << endl;
		throw 1;
		return;
	}

	else if (k < 1 || k > length())
	{
		cout << "所给下标溢出范围" << endl;
		throw 2;
		return;
	}

	else
	{

		saved = *(locate(k)->information);

	}

}

//检查无误！
void LinkList::output()
{

	if (isEmpty())
	{
		cout << "空链表无法输出!" << endl;
		throw 1;
		return;
	}
	//带头结点的链表信息输出
	if (withHead())
	{
		node* p = head->next;
		p->information = head->next->information;
		int count = 1;
		while (p != NULL)
		{

			cout << "第" << count << "个结点数据信息如下:" << endl;
			cout << "数字为：" << p->information->num << endl;
			cout << "信息为：" << p->information->intro << endl;

			count++;
			p = p->next;

		}
	}
	//不带头结点的链表信息输出
	else
	{
		//将初始数据输出
		cout << "第1" << "个结点数据信息如下:" << endl;
		cout << "数字为：" << head->information->num << endl;
		cout << "信息为：" << head->information->intro << endl;
		node* p = head->next;
		p->information = head->next->information;
		int count = 1;
		while (p != NULL)
		{

			cout << "第" << count+1 << "个结点数据信息如下:" << endl;
			cout << "数字为：" << p->information->num << endl;
			cout << "信息为：" << p->information->intro << endl;

			count++;
			p = p->next;

		}
	}

}

//检查无误！
datas LinkList::remove(int k)
{
	//异常处理
	if (k<1 || k>length())
	{
		cout << "下标不合法！" << endl;
		throw 1;
	}
	if (isEmpty())
	{
		cout << "所要移去的结点为空结点" << endl;
		throw 1;
	}
	node* p = locate(k - 1);
	node* del = p->next; //被删除的结点的指针
	p->next = del->next;
	datas* save = new datas;
	save->num = del->information->num;
	save->intro = del->information->intro;
	delete del;

	return *save;
}

//按位插入
//检查无误！
void LinkList::insert(datas ins_data, int k)
{
	node* p = new node;//插入结点
	//将插入数据放入插入节点
	p->information->intro = ins_data.intro;
	p->information->num = ins_data.num;

	if (k == 1)//要插成第一个
	{
		if (with_head)
		{
			p->next = head->next;
			head->next = p;
		}

		else
		{
			p->next = head;
			head = p;
		}
	}

	else if (k == length() + 1)//代表成为新尾结点
	{
		last()->next = p;
	}

	node* current = locate(k - 1);

	//插入结点
	p->next = current->next;
	current->next = p;
}

//判断单调性
//检查无误！
int LinkList::single()
{

	if (isEmpty())
	{
		cout << "空表无单调性！" << endl;
		return 0;
	}

	node* p = (withHead()) ? head->next : head;
	if (length() == 1)
	{
		return 1;
	}
	int sign = (p->information->num < p->next->information->num) ? 1 : 2;//1增2减
	
	//判断是否具有单调性
	switch (sign)
	{
	case 1://递增
		while (p->next != NULL)
		{
			if (p->information->num > p->next->information->num)
			{
				return 0;
			}
			p = p->next;
		}
		return 1;
		break;
	case 2://递减
		while (p->next != NULL)
		{
			if (p->information->num < p->next->information->num)
			{
				return 0;
			}
			p = p->next;
		}
		return 2;
		break;
	default:
		return 0;
		break;
	}
}

//按值插入(任务1、2)
//检查无误！
void LinkList::insert(datas ins_data)
{
	//初始化为第一个有信息结点用来判断特殊情况
	node* p = (withHead()) ? head->next : head;
	int index = 1;//当前处于第一个结点
	switch (single())
	{
	case 0://无序时抛错
		cout << "该链表数字排列无序，无法按值插入！" << endl;
		throw 1;
		return;
		break;
	case 1://递增排列
		//比第一个还小就插在第一个
		if (ins_data.num <= p->information->num)
		{
			insert(ins_data, 1);
		}
		//比最后一个还大就插在尾
		else if (ins_data.num >= last()->information->num)
		{
			node* ins_node = new node;
			//插入值赋给插入节点
			*(ins_node->information) = ins_data;
			last()->next = ins_node;//插入尾结点后
		}
		//不然就寻找合适的位置下标index
		else
		{
			while (1)
			{
				if (ins_data.num >= p->information->num && //比这一个大
					ins_data.num <= p->next->information->num)//比下一个小
				{
					insert(ins_data, index + 1);
					break;
				}//循环边界，当ins_data.num在第index和第index+1数据之间则插成第index+1个
				p = p->next;
				index++;
			}
		}
		break;
	case 2://递减排列
		//比第一个还大就插在第一个
		if (ins_data.num >= p->information->num)
		{
			insert(ins_data, 1);
		}
		//比最后一个还小就插在尾
		else if (ins_data.num <= last()->information->num)
		{
			node* ins_node = new node;
			//插入值赋给插入节点
			*(ins_node->information) = ins_data;
			last()->next = ins_node;//插入尾结点后
		}
		//不然就寻找合适的位置下标index
		else
		{
			while (1)
			{
				if (ins_data.num <= p->information->num && //比这一个小
					ins_data.num >= p->next->information->num)//比下一个大
				{
					insert(ins_data, index + 1);
					break;
				}//循环边界，当ins_data.num在第index和第index+1数据之间则插成第index+1个
				p = p->next;
				index++;
			}
		}
		break;
		break;
	default:
		break;
	}

}

//翻转链表
void LinkList::reverse()
{

	if (isEmpty())
	{

		cout << "空表无法反转！" << endl;
		throw 1;
		return;

	}

	node* start = (withHead()) ? head->next : head;
	node* end = last();
	node* pre = start;
	//翻转
	while (start->next != NULL)
	{
		//暂时储存下一节点的next信息
		node* temp = start->next->next;
		//下一节点的next接到前一结点
		start->next->next = pre;
		//储存前一结点信息以便下一次拼接
		pre = start->next;
		//当前结点的next后跳一位
		start->next = temp;

	}

	//重新赋值head
	if (withHead())
	{
		//有头指针时，反转后将头结点指向end
		head->next = end;
	}
	else
	{
		//无头指针时，翻转后只需要把end赋给head
		head = end;
	}

}



void Func_test()
{
	LinkList L1;
	L1.input();
	L1.output();
	cout << L1.isEmpty() << endl;
	cout << L1.length() << endl;
	datas d = { 2, "b" };
	cout << L1.find(d) << endl;
	if (L1.locate(L1.find(d))->information->num == 2)
	{
		cout << "locate函数检查无误！" << endl;
	}
	else
	{
		cout << "locate函数有误！" << endl;
	}
	cout << "尾部数字为：" << L1.last()->information->num << endl;

	//检查单调性
	if (L1.single() == 0)
	{
		cout << "无单调性" << endl;
	}
	else
	{
		string dd_str = (L1.single() == 1) ? "递增" : "递减";
		cout << dd_str << endl;
	}

	//检查按值插入
	datas insert_data = { 2, "被按值插入的数字" };
	L1.insert(insert_data, L1.withHead());
	L1.output();

	//检查按位插入
	insert_data = { 0, "被按位插入的数字" };
	L1.insert(insert_data, 1);
	L1.output();

	//检查remove
	datas rem, temp;//用来储存被删除的结点信息
	int length = L1.length();
	temp = *(L1.locate(1)->information);
	rem = L1.remove(1);
	int length_ = L1.length();
	if (length_ == length - 1 && rem.num == temp.num && rem.intro == temp.intro)
	{
		cout << "remove函数检查无误！" << endl;
	}
	else
	{
		cout << "remove函数出问题咯！" << endl;
	}

	//翻转
	L1.reverse();
	L1.output();

	//检查makeEmpty
	L1.makeEmpty();
	string mE_ass_err = (L1.length() == 0) ? "makeEmpty函数正确无误！" : 
		"makeEmpty函数有问题";
	cout << mE_ass_err << endl;

}

void nohead_test()
{
	
	datas* init_data = new datas;
	*init_data = { 0, "初始结点" };
	node* init_node = new node;
	init_node->information = init_data;

	//构造无头结点的链表
	LinkList L1(init_node);
	L1.input();
	L1.output();
	cout << "第2个结点数字为" << L1.locate(2)->information->num << endl;

	cout << "------长度如下------" << endl;
	cout << L1.length() << endl;

	//按位插值检验
	datas ins_data = { 10, "被插入的结点" };
	L1.insert(ins_data, 2);
	L1.output();

	//按位删除检查
	L1.remove(2);
	L1.output();

	//单调性检查
	if (L1.single() == 0)
	{
		cout << "无单调性" << endl;
	}
	else
	{
		string ddx = (L1.single() == 1) ? "递增" : "递减";
		cout << ddx << endl;
	}

	//按值插入检查
	ins_data = { 15, "被插入的结点" };
	L1.insert(ins_data);
	L1.output();

}

void head_display()
{
	LinkList L1;
	L1.input();
	L1.output();
	cout << L1.isEmpty() << endl;
	cout << L1.length() << endl;
	datas d = { 2, "b" };
	cout << L1.find(d) << endl;
	if (L1.locate(L1.find(d))->information->num == 2)
	{
		cout << "locate函数检查无误！" << endl;
	}
	else
	{
		cout << "locate函数有误！" << endl;
	}
	cout << "尾部数字为：" << L1.last()->information->num << endl;

	//检查单调性
	if (L1.single() == 0)
	{
		cout << "无单调性" << endl;
	}
	else
	{
		string dd_str = (L1.single() == 1) ? "递增" : "递减";
		cout << dd_str << endl;
	}

	//检查按值插入
	datas insert_data = { 30, "被插入的数字" };
	L1.insert(insert_data);
	L1.output();

	//检查按位插入
	insert_data = { 2, "被插入的数字" };
	L1.insert(insert_data, 1);
	L1.output();

	//检查save_data
	datas save_data;
	L1.save_data(3, save_data);
	cout << "--------被保存的是第三个结点，信息如下----------" << endl;
	cout << "num：" << save_data.num << endl;
	cout << "intro：" << save_data.intro << endl;

	datas remove_data = L1.remove(2);
	L1.output();
	cout << "------被删除的结点信息如下--------" << endl;
	cout << "num：" << remove_data.num << endl;
	cout << "intro：" << remove_data.intro << endl;

	//翻转演示
	L1.reverse();
	cout << "------翻转后的链表信息如下--------" << endl;
	L1.output();

	//清空检查
	L1.makeEmpty();
	cout << "清空后链表长度为：" << L1.length() << endl;

}

void nohead_display()
{
	datas* init_data = new datas;
	*init_data = { 0, "初始结点" };
	node* init_node = new node;
	init_node->information = init_data;

	//构造无头结点的链表
	LinkList L1(init_node);
	L1.input();
	L1.output();
	cout << "第2个结点数字为" << L1.locate(2)->information->num << endl;

	cout << "------长度如下------" << endl;
	cout << L1.length() << endl;

	//按位插值检验
	datas ins_data = { 10, "被插入的结点" };
	L1.insert(ins_data, 2);
	L1.output();

	//按位删除检查
	datas remove_data = L1.remove(2);
	L1.output();
	cout << "------被删除的结点信息如下--------" << endl;
	cout << "num：" << remove_data.num << endl;
	cout << "intro：" << remove_data.intro << endl;

	//单调性检查
	if (L1.single() == 0)
	{
		cout << "无单调性" << endl;
	}
	else
	{
		string ddx = (L1.single() == 1) ? "递增" : "递减";
		cout << ddx << endl;
	}

	//按值插入检查
	ins_data = { 15, "被插入的结点" };
	L1.insert(ins_data, L1.withHead());
	L1.output();

	//翻转演示
	L1.reverse();
	cout << "------翻转后的链表信息如下--------" << endl;
	L1.output();

}
