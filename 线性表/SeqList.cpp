#include <iostream>
#include <algorithm>
#include <string>
#include "SeqList.h"

using namespace std;

void SeqList::show()
{

	cout << "�����Ա���Ϊ" << length << endl;
	string sort_func = (rev) ? "�Ӵ�С" : "��С����";
	cout << "�����Ա����з�ʽΪ" << sort_func << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "��" << i + 1 << "��Ԫ��Ϊ��" << data[i] << endl;
	}

}



//��λɾ��Ԫ��
void SeqList::del_index(int index)
{

	if (index<0 || index>length - 1)
	{
		cout << "�±�������޷�ɾ����" << endl;
		throw 1;
	}

	for (int i = index; i < length - 1; i++)
	{
		data[i] = data[i + 1];
	}
	length--;//����-1

}

//��ֵɾ��Ԫ��
void SeqList::del_num(int num, bool all)
{

	if (!all)
	{
		int index = get_num(num);

		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ����Ա��в�����Ԫ��" + to_string(num) << endl;
			throw 1;
		}

		del_index(index);

	}

	else
	{
		int index = get_num(num);

		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ����Ա��в�����Ԫ��" + to_string(num) << endl;
			throw 1;
		}

		//�ҵ�������ȫɾ��
		int ind[MaxSize];//������Ҳ��ȫ��һ����
		int count = 0;
		for (int i = index; i < length; i++)
		{
			if (data[i] == num)
			{
				ind[count] = i;
			}
		}
		//����ɾ��
		for (int i = 0; i <= count; i++)
		{
			del_index(ind[i] - i);
		}

	}

}

//��λ��ȡ
int SeqList::get_index(int index)
{
	if (index<0 || index>length - 1)
	{
		cout << "�����±������Χ��" << endl;
		throw 1;
	}
	else
	{
		return data[index];
	}
}

//��ֵ��ȡ
int SeqList::get_num(int x)
{
	int index = -1;//û�ҵ��ͷ���-1
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i;
	}
	return index;
}

//��λ����
void SeqList::insert(int num, int index)
{

	if (index<0 || index>length)
	{
		cout << "�����±������Χ��" << endl;
		throw 1;
	}

	else
	{
		if (index != length)
		{
			for (int j = length; j >= index + 1; j--)
				data[j] = data[j - 1];
			data[index] = num;
			length++; //����󳤶�+1
		}
		else
		{
			data[length] = num;
			length++;
		}

	}

}

//��ֵ����
void SeqList::insert(int num)
{

	if (!rev)//��С����
	{

		int index;

		//��ʼ�������±�
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
			//Ѱ�Ҳ���λ��
			for (int i = 0; i < length - 1; i++)
			{
				if (data[i] <= num && num <= data[i + 1])
				{
					index = i + 1;
					break;
				}
			}
		}

		//����
		insert(num, index);


	}

	else//�Ӵ�С
	{
		//��ʼ�������±�
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
			//Ѱ�Ҳ���λ��
			for (int i = 0; i < length - 1; i++)
			{
				if (data[i] >= num && num >= data[i + 1])
				{
					index = i + 1;
					break;
				}
			}
		}

		//����
		insert(num, index);

	}

}

//����2(�ϲ������Ա�)
SeqList combine(SeqList s1, SeqList s2, bool sift)//Ĭ�ϲ�ȥ��
{

	//����ʽ��ͬ���޷��ϲ�
	if (s1.get_rev() != s2.get_rev())
	{
		cout << "�����Ա�����ʽ��ͬ���޷��ϲ���" << endl;
		throw 1;
	}

	if (!sift)//��ȥ��
	{
		cout << "�����Ա�ȥ�غϲ��Ľ��Ϊ��" << endl;
		//���϶̵�һ��������ϳ���
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
	else//ȥ��
	{
		cout << "�����Ա�ȥ�غϲ��Ľ��Ϊ��" << endl;
		//���϶̵�һ��������ϳ���
		if (s2.get_length() < s1.get_length())
		{

			//ȥ��
			for (int i = 0; i < s2.get_length(); i++)
			{
				//����ظ������������ɾȥ֮���ٲ��뱻��������
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

			//ȥ��
			for (int i = 0; i < s1.get_length(); i++)
			{
				//����ظ������������ɾȥ֮���ٲ��뱻��������
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
	cout << "�����Ա�洢�������������£�" << endl;
	for (int i = 0; i < s1.get_length(); i++)
		cout << "��" << i + 1 << "��Ԫ���ǣ�" << temp[i] << endl;
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

	//�쳣���ԣ��������з�ʽ��ͬʱ�޷����кϲ���
	int c[] = {1,2,5,9,7,46,84};
	SeqList s3(c, sizeof(c)/4);
	ptr = &s3;
	ptr->show();
	combine(s1, s3);

}

