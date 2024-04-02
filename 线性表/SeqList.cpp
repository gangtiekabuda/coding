#include <iostream>
#include <algorithm>
#include <string>
#include "SeqList.h"

using namespace std;

void SeqList::show()
{

	cout << "该线性表长度为" << length << endl;
	string sort_func = (rev) ? "从大到小" : "从小到大";
	cout << "该线性表排列方式为" << sort_func << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "第" << i + 1 << "个元素为：" << data[i] << endl;
	}

}



//按位删除元素
void SeqList::del_index(int index)
{

	if (index<0 || index>length - 1)
	{
		cout << "下标溢出，无法删除！" << endl;
		throw 1;
	}

	for (int i = index; i < length - 1; i++)
	{
		data[i] = data[i + 1];
	}
	length--;//长度-1

}

//按值删除元素
void SeqList::del_num(int num, bool all)
{

	if (!all)
	{
		int index = get_num(num);

		if (index == -1)
		{
			cout << "删除失败！线性表中不存在元素" + to_string(num) << endl;
			throw 1;
		}

		del_index(index);

	}

	else
	{
		int index = get_num(num);

		if (index == -1)
		{
			cout << "删除失败！线性表中不存在元素" + to_string(num) << endl;
			throw 1;
		}

		//找到了再来全删除
		int ind[MaxSize];//逆天了也就全是一个数
		int count = 0;
		for (int i = index; i < length; i++)
		{
			if (data[i] == num)
			{
				ind[count] = i;
			}
		}
		//进行删除
		for (int i = 0; i <= count; i++)
		{
			del_index(ind[i] - i);
		}

	}

}

//按位获取
int SeqList::get_index(int index)
{
	if (index<0 || index>length - 1)
	{
		cout << "所给下标溢出范围！" << endl;
		throw 1;
	}
	else
	{
		return data[index];
	}
}

//按值获取
int SeqList::get_num(int x)
{
	int index = -1;//没找到就返回-1
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i;
	}
	return index;
}

//按位插入
void SeqList::insert(int num, int index)
{

	if (index<0 || index>length)
	{
		cout << "所给下标溢出范围！" << endl;
		throw 1;
	}

	else
	{
		if (index != length)
		{
			for (int j = length; j >= index + 1; j--)
				data[j] = data[j - 1];
			data[index] = num;
			length++; //插入后长度+1
		}
		else
		{
			data[length] = num;
			length++;
		}

	}

}

//按值插入
void SeqList::insert(int num)
{

	if (!rev)//从小到大
	{

		int index;

		//初始化插入下标
		if (num <= data[0])
		{
			index = 0;
		}

		else if (num >= data[length - 1])
		{
			index = length;
		}

		else
		{
			//寻找插入位置
			for (int i = 0; i < length - 1; i++)
			{
				if (data[i] <= num && num <= data[i + 1])
				{
					index = i + 1;
					break;
				}
			}
		}

		//插入
		insert(num, index);


	}

	else//从大到小
	{
		//初始化插入下标
		int index;
		if (num >= data[0])
		{
			index = 0;
		}

		else if (num <= data[length - 1])
		{
			index = length;
		}

		else
		{
			//寻找插入位置
			for (int i = 0; i < length - 1; i++)
			{
				if (data[i] >= num && num >= data[i + 1])
				{
					index = i + 1;
					break;
				}
			}
		}

		//插入
		insert(num, index);

	}

}

//任务2(合并两线性表)
SeqList combine(SeqList s1, SeqList s2, bool sift)//默认不去重
{

	//排序方式不同则无法合并
	if (s1.get_rev() != s2.get_rev())
	{
		cout << "两线性表排序方式不同，无法合并！" << endl;
		throw 1;
	}

	if (!sift)//不去重
	{
		cout << "两线性表不去重合并的结果为：" << endl;
		//将较短的一个个插进较长的
		if (s2.get_length() < s1.get_length())
		{

			int end = (s2.get_length() % 2 == 0) ? s2.get_length() / 2 : s2.get_length() / 2 + 1;
			for (int i = 0; i < end; i++)
			{
				s1.insert(s2.get_index(i));
				if (!((s2.get_length() % 2 != 0)&&(i!= s2.get_length()/2)))
					s1.insert(s2.get_index(s2.get_length() - 1 - i));
			}

			return s1;

		}

		else
		{

			int end = (s1.get_length() % 2 == 0) ? s1.get_length() / 2 : s1.get_length() / 2 + 1;
			for (int i = 0; i < end; i++)
			{
				s2.insert(s1.get_index(i));
				if (s1.get_length() - 1 - i != i)
					s2.insert(s1.get_index(s1.get_length() - 1 - i));
			}

			return s2;

		}

	}
	else//去重
	{
		cout << "两线性表去重合并的结果为：" << endl;
		//将较短的一个个插进较长的
		if (s2.get_length() < s1.get_length())
		{

			//去重
			for (int i = 0; i < s2.get_length(); i++)
			{
				//如果重复则插入数组中删去之后再插入被插入数组
				if (s1.get_num(s2.get_index(i)) != -1)
				{
					s2.del_num(s2.get_index(i), true);
				}
			}

			int end = (s2.get_length() % 2 == 0) ? s2.get_length() / 2 : s2.get_length() / 2 + 1;
			for (int i = 0; i < end; i++)
			{
				s1.insert(s2.get_index(i));
				if (s2.get_length() - 1 - i != i)
					s1.insert(s2.get_index(s2.get_length() - 1 - i));
			}

			return s1;

		}

		else
		{

			//去重
			for (int i = 0; i < s1.get_length(); i++)
			{
				//如果重复则插入数组中删去之后再插入被插入数组
				if (s2.get_num(s1.get_index(i)) != -1)
				{
					s1.del_index(i);
				}
			}

			int end = (s1.get_length() % 2 == 0) ? s1.get_length() / 2 : s1.get_length() / 2 + 1;
			for (int i = 0; i < end; i++)
			{
				s2.insert(s1.get_index(i));
				if (s1.get_length() - 1 - i != i)
					s2.insert(s1.get_index(s1.get_length() - 1 - i));
			}

			return s2;

		}

	}

}

void test()
{

	int a[] = { 1, 3, 4, 2, 6, 5 };
	int b[] = { 8, 9, 12, 10, 7, 11 };

	SeqList s1(a, sizeof(a) / 4, true), s2(b, sizeof(b) / 4, true), * ptr;

	ptr = &s1;
	int temp[MaxSize];
	ptr->get_data(temp);
	cout << "该线性表存储的序列数据如下：" << endl;
	for (int i = 0; i < s1.get_length(); i++)
		cout << "第" << i + 1 << "个元素是：" << temp[i] << endl;
	ptr->insert(20);
	ptr->insert(0);
	ptr->insert(15);
	ptr->show();
	ptr = &s2;
	ptr->insert(30);
	ptr->insert(0);
	ptr->insert(15);
	ptr->show();
	SeqList combined = combine(s1, s2);
	ptr = &combined;
	ptr->show();
	combined = combine(s1, s2, true);
	ptr->show();

	//异常测试（两表排列方式不同时无法进行合并）
	int c[] = {1,2,5,9,7,46,84};
	SeqList s3(c, sizeof(c)/4);
	ptr = &s3;
	ptr->show();
	combine(s1, s3);

}

