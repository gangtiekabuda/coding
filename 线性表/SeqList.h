#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "SeqList.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MaxSize = 100;

class SeqList
{

public:
	//无参构造，即构造空线性表
	SeqList()
	{
		length = 0;
		rev = false;//默认是从小打大
	};

	//带参构造，reverse代表反转排序顺序，默认从小到大
	SeqList(int a[], int n, bool reverse = false)
	{
		rev = reverse;
		length = n;
		//对给的数组进行快排
		sort(a, a + n);
		if (!reverse)
		{
			for (int i = 0; i < n; i++)
				data[i] = a[i];
		}
		else//倒序赋给data
		{
			for (int i = 0; i < n; i++)
			{
				data[i] = a[n - 1 - i];
			}
		}
	};

	//判断是否为空表
	bool empty()
	{
		return (length == 0) ? true : false;
	}

	//获取所储存的数据序列
	void get_data(int a[])
	{
		for (int i = 0; i < length; i++)
			a[i] = data[i];
	}

	//获取长度
	int get_length()
	{
		return length;
	}

	//按位删除元素
	void del_index(int index);

	//按值删除元素
	void del_num(int num, bool all = false);

	//按位获取
	int get_index(int index);

	//按值获取
	int get_num(int x);

	//按位插入
	void insert(int num, int index);

	//按值插入(任务1)
	void insert(int num);

	//展示线性表
	void show();

	bool get_rev()
	{
		return rev;
	}

private:
	int length;  //线性表长度
	int data[MaxSize]; //数据储存于数组之中
	bool rev; //判断是从小到大还是从大到小
};

SeqList combine(SeqList s1, SeqList s2, bool sift = false);

void test();

#endif
