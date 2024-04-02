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
	//�޲ι��죬����������Ա�
	SeqList()
	{
		length = 0;
		rev = false;//Ĭ���Ǵ�С���
	};

	//���ι��죬reverse����ת����˳��Ĭ�ϴ�С����
	SeqList(int a[], int n, bool reverse = false)
	{
		rev = reverse;
		length = n;
		//�Ը���������п���
		sort(a, a + n);
		if (!reverse)
		{
			for (int i = 0; i < n; i++)
				data[i] = a[i];
		}
		else//���򸳸�data
		{
			for (int i = 0; i < n; i++)
			{
				data[i] = a[n - 1 - i];
			}
		}
	};

	//�ж��Ƿ�Ϊ�ձ�
	bool empty()
	{
		return (length == 0) ? true : false;
	}

	//��ȡ���������������
	void get_data(int a[])
	{
		for (int i = 0; i < length; i++)
			a[i] = data[i];
	}

	//��ȡ����
	int get_length()
	{
		return length;
	}

	//��λɾ��Ԫ��
	void del_index(int index);

	//��ֵɾ��Ԫ��
	void del_num(int num, bool all = false);

	//��λ��ȡ
	int get_index(int index);

	//��ֵ��ȡ
	int get_num(int x);

	//��λ����
	void insert(int num, int index);

	//��ֵ����(����1)
	void insert(int num);

	//չʾ���Ա�
	void show();

	bool get_rev()
	{
		return rev;
	}

private:
	int length;  //���Ա���
	int data[MaxSize]; //���ݴ���������֮��
	bool rev; //�ж��Ǵ�С�����ǴӴ�С
};

SeqList combine(SeqList s1, SeqList s2, bool sift = false);

void test();

#endif
