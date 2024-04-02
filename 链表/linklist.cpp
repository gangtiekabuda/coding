#include "linklist.h"
#include <iostream>
#include <string>

using namespace  std;

//�������
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

//�������
node* LinkList::locate(int i)
{
	
	//i<0�ؿ�ָ��
	if (i < 0)
	{
		return NULL;
	}

	node* current = head;//��ǰ���ڽ��ָ��
	int k = (with_head) ? 0 : 1;//����
	while (current != NULL && k < i)
	{
		current = current->next;
		k++;
	}
	return current;

}

//ͷָ��Ų��ƨ�ɲ��ͷ��ڴ����������
//�������
void LinkList::makeEmpty()
{

	if (isEmpty())
	{
		cout << "�յĲ����ٿ�����" << endl;
		throw 1;
		return;
	}

	node* p;
	while (head->next != NULL)
	{
		p = head->next;
		head->next = p->next;
		delete p;//�ͷ���ʱָ����ڴ�
	}

	//�������ͷ��㻹��ɾ������һ�����
	if (!with_head)
	{
		head = NULL;
	}

}

//ͷ��β�幹������
//�������
void LinkList::input(datas endTag, bool front)
{

	//Ϊ��Ԫ��������
	node* p;

	datas* new_data = new datas;

	if (front)//ǰ�巨��������
	{
		cout << "�������һ�����ݣ�";
		cin >> new_data->num;
		cin >> new_data->intro;

		//ֱ����������������̿���
		if ((new_data->num == endTag.num) && (new_data->intro == endTag.intro))
		{
			return;
		}

		//�����������־���������
		while ((new_data->num != endTag.num) || (new_data->intro != endTag.intro))
		{
			p = new node;//Ϊ�½������ռ�
			p->information->num = new_data->num;
			p->information->intro = new_data->intro;
			if (head->next != NULL)
			{
				p->next = head->next;
			}
			head->next = p;
			cout << "���������ݣ�";
			cin >> new_data->num;
			cin >> new_data->intro;
		}
	
	}

	else//β�巨��������
	{

		cout << "�������һ�����ݣ�";
		cin >> new_data->num;
		cin >> new_data->intro;

		if ((new_data->num == endTag.num) && (new_data->intro == endTag.intro))
		{
			return;
		}


		//�����������־���������
		while ((new_data->num != endTag.num) || (new_data->intro != endTag.intro))
		{
			p = new node;//Ϊ�½������ռ�
			p->information->num = new_data->num;
			p->information->intro = new_data->intro;
			last()->next = p;
			cout << "���������ݣ�";
			cin >> new_data->num;
			cin >> new_data->intro;
		}

	}

}

//�������
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
	
	return (withHead()) ? count : count + 1;//��ͷ���ʱҪ�ѳ�ʼ������ȥ!

}

//�������
int LinkList::find(datas& x)
{

	node* p = (with_head) ? head->next : head;
	int i = 1;

	if (isEmpty())
	{
		cout << "�����ݿɹ����ң�" << endl;
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
	
	//�Ҳ���
	return -1;

}

//�������
void LinkList::save_data(int k, datas& saved)
{

	if (isEmpty())
	{
		cout << "������û�����ɴ棡" << endl;
		throw 1;
		return;
	}

	else if (k < 1 || k > length())
	{
		cout << "�����±������Χ" << endl;
		throw 2;
		return;
	}

	else
	{

		saved = *(locate(k)->information);

	}

}

//�������
void LinkList::output()
{

	if (isEmpty())
	{
		cout << "�������޷����!" << endl;
		throw 1;
		return;
	}
	//��ͷ����������Ϣ���
	if (withHead())
	{
		node* p = head->next;
		p->information = head->next->information;
		int count = 1;
		while (p != NULL)
		{

			cout << "��" << count << "�����������Ϣ����:" << endl;
			cout << "����Ϊ��" << p->information->num << endl;
			cout << "��ϢΪ��" << p->information->intro << endl;

			count++;
			p = p->next;

		}
	}
	//����ͷ����������Ϣ���
	else
	{
		//����ʼ�������
		cout << "��1" << "�����������Ϣ����:" << endl;
		cout << "����Ϊ��" << head->information->num << endl;
		cout << "��ϢΪ��" << head->information->intro << endl;
		node* p = head->next;
		p->information = head->next->information;
		int count = 1;
		while (p != NULL)
		{

			cout << "��" << count+1 << "�����������Ϣ����:" << endl;
			cout << "����Ϊ��" << p->information->num << endl;
			cout << "��ϢΪ��" << p->information->intro << endl;

			count++;
			p = p->next;

		}
	}

}

//�������
datas LinkList::remove(int k)
{
	//�쳣����
	if (k<1 || k>length())
	{
		cout << "�±겻�Ϸ���" << endl;
		throw 1;
	}
	if (isEmpty())
	{
		cout << "��Ҫ��ȥ�Ľ��Ϊ�ս��" << endl;
		throw 1;
	}
	node* p = locate(k - 1);
	node* del = p->next; //��ɾ���Ľ���ָ��
	p->next = del->next;
	datas* save = new datas;
	save->num = del->information->num;
	save->intro = del->information->intro;
	delete del;

	return *save;
}

//��λ����
//�������
void LinkList::insert(datas ins_data, int k)
{
	node* p = new node;//������
	//���������ݷ������ڵ�
	p->information->intro = ins_data.intro;
	p->information->num = ins_data.num;

	if (k == 1)//Ҫ��ɵ�һ��
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

	else if (k == length() + 1)//�����Ϊ��β���
	{
		last()->next = p;
	}

	node* current = locate(k - 1);

	//������
	p->next = current->next;
	current->next = p;
}

//�жϵ�����
//�������
int LinkList::single()
{

	if (isEmpty())
	{
		cout << "�ձ��޵����ԣ�" << endl;
		return 0;
	}

	node* p = (withHead()) ? head->next : head;
	if (length() == 1)
	{
		return 1;
	}
	int sign = (p->information->num < p->next->information->num) ? 1 : 2;//1��2��
	
	//�ж��Ƿ���е�����
	switch (sign)
	{
	case 1://����
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
	case 2://�ݼ�
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

//��ֵ����(����1��2)
//�������
void LinkList::insert(datas ins_data)
{
	//��ʼ��Ϊ��һ������Ϣ��������ж��������
	node* p = (withHead()) ? head->next : head;
	int index = 1;//��ǰ���ڵ�һ�����
	switch (single())
	{
	case 0://����ʱ�״�
		cout << "�������������������޷���ֵ���룡" << endl;
		throw 1;
		return;
		break;
	case 1://��������
		//�ȵ�һ����С�Ͳ��ڵ�һ��
		if (ins_data.num <= p->information->num)
		{
			insert(ins_data, 1);
		}
		//�����һ������Ͳ���β
		else if (ins_data.num >= last()->information->num)
		{
			node* ins_node = new node;
			//����ֵ��������ڵ�
			*(ins_node->information) = ins_data;
			last()->next = ins_node;//����β����
		}
		//��Ȼ��Ѱ�Һ��ʵ�λ���±�index
		else
		{
			while (1)
			{
				if (ins_data.num >= p->information->num && //����һ����
					ins_data.num <= p->next->information->num)//����һ��С
				{
					insert(ins_data, index + 1);
					break;
				}//ѭ���߽磬��ins_data.num�ڵ�index�͵�index+1����֮�����ɵ�index+1��
				p = p->next;
				index++;
			}
		}
		break;
	case 2://�ݼ�����
		//�ȵ�һ������Ͳ��ڵ�һ��
		if (ins_data.num >= p->information->num)
		{
			insert(ins_data, 1);
		}
		//�����һ����С�Ͳ���β
		else if (ins_data.num <= last()->information->num)
		{
			node* ins_node = new node;
			//����ֵ��������ڵ�
			*(ins_node->information) = ins_data;
			last()->next = ins_node;//����β����
		}
		//��Ȼ��Ѱ�Һ��ʵ�λ���±�index
		else
		{
			while (1)
			{
				if (ins_data.num <= p->information->num && //����һ��С
					ins_data.num >= p->next->information->num)//����һ����
				{
					insert(ins_data, index + 1);
					break;
				}//ѭ���߽磬��ins_data.num�ڵ�index�͵�index+1����֮�����ɵ�index+1��
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

//��ת����
void LinkList::reverse()
{

	if (isEmpty())
	{

		cout << "�ձ��޷���ת��" << endl;
		throw 1;
		return;

	}

	node* start = (withHead()) ? head->next : head;
	node* end = last();
	node* pre = start;
	//��ת
	while (start->next != NULL)
	{
		//��ʱ������һ�ڵ��next��Ϣ
		node* temp = start->next->next;
		//��һ�ڵ��next�ӵ�ǰһ���
		start->next->next = pre;
		//����ǰһ�����Ϣ�Ա���һ��ƴ��
		pre = start->next;
		//��ǰ����next����һλ
		start->next = temp;

	}

	//���¸�ֵhead
	if (withHead())
	{
		//��ͷָ��ʱ����ת��ͷ���ָ��end
		head->next = end;
	}
	else
	{
		//��ͷָ��ʱ����ת��ֻ��Ҫ��end����head
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
		cout << "locate�����������" << endl;
	}
	else
	{
		cout << "locate��������" << endl;
	}
	cout << "β������Ϊ��" << L1.last()->information->num << endl;

	//��鵥����
	if (L1.single() == 0)
	{
		cout << "�޵�����" << endl;
	}
	else
	{
		string dd_str = (L1.single() == 1) ? "����" : "�ݼ�";
		cout << dd_str << endl;
	}

	//��鰴ֵ����
	datas insert_data = { 2, "����ֵ���������" };
	L1.insert(insert_data, L1.withHead());
	L1.output();

	//��鰴λ����
	insert_data = { 0, "����λ���������" };
	L1.insert(insert_data, 1);
	L1.output();

	//���remove
	datas rem, temp;//�������汻ɾ���Ľ����Ϣ
	int length = L1.length();
	temp = *(L1.locate(1)->information);
	rem = L1.remove(1);
	int length_ = L1.length();
	if (length_ == length - 1 && rem.num == temp.num && rem.intro == temp.intro)
	{
		cout << "remove�����������" << endl;
	}
	else
	{
		cout << "remove���������⿩��" << endl;
	}

	//��ת
	L1.reverse();
	L1.output();

	//���makeEmpty
	L1.makeEmpty();
	string mE_ass_err = (L1.length() == 0) ? "makeEmpty������ȷ����" : 
		"makeEmpty����������";
	cout << mE_ass_err << endl;

}

void nohead_test()
{
	
	datas* init_data = new datas;
	*init_data = { 0, "��ʼ���" };
	node* init_node = new node;
	init_node->information = init_data;

	//������ͷ��������
	LinkList L1(init_node);
	L1.input();
	L1.output();
	cout << "��2���������Ϊ" << L1.locate(2)->information->num << endl;

	cout << "------��������------" << endl;
	cout << L1.length() << endl;

	//��λ��ֵ����
	datas ins_data = { 10, "������Ľ��" };
	L1.insert(ins_data, 2);
	L1.output();

	//��λɾ�����
	L1.remove(2);
	L1.output();

	//�����Լ��
	if (L1.single() == 0)
	{
		cout << "�޵�����" << endl;
	}
	else
	{
		string ddx = (L1.single() == 1) ? "����" : "�ݼ�";
		cout << ddx << endl;
	}

	//��ֵ������
	ins_data = { 15, "������Ľ��" };
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
		cout << "locate�����������" << endl;
	}
	else
	{
		cout << "locate��������" << endl;
	}
	cout << "β������Ϊ��" << L1.last()->information->num << endl;

	//��鵥����
	if (L1.single() == 0)
	{
		cout << "�޵�����" << endl;
	}
	else
	{
		string dd_str = (L1.single() == 1) ? "����" : "�ݼ�";
		cout << dd_str << endl;
	}

	//��鰴ֵ����
	datas insert_data = { 30, "�����������" };
	L1.insert(insert_data);
	L1.output();

	//��鰴λ����
	insert_data = { 2, "�����������" };
	L1.insert(insert_data, 1);
	L1.output();

	//���save_data
	datas save_data;
	L1.save_data(3, save_data);
	cout << "--------��������ǵ�������㣬��Ϣ����----------" << endl;
	cout << "num��" << save_data.num << endl;
	cout << "intro��" << save_data.intro << endl;

	datas remove_data = L1.remove(2);
	L1.output();
	cout << "------��ɾ���Ľ����Ϣ����--------" << endl;
	cout << "num��" << remove_data.num << endl;
	cout << "intro��" << remove_data.intro << endl;

	//��ת��ʾ
	L1.reverse();
	cout << "------��ת���������Ϣ����--------" << endl;
	L1.output();

	//��ռ��
	L1.makeEmpty();
	cout << "��պ�������Ϊ��" << L1.length() << endl;

}

void nohead_display()
{
	datas* init_data = new datas;
	*init_data = { 0, "��ʼ���" };
	node* init_node = new node;
	init_node->information = init_data;

	//������ͷ��������
	LinkList L1(init_node);
	L1.input();
	L1.output();
	cout << "��2���������Ϊ" << L1.locate(2)->information->num << endl;

	cout << "------��������------" << endl;
	cout << L1.length() << endl;

	//��λ��ֵ����
	datas ins_data = { 10, "������Ľ��" };
	L1.insert(ins_data, 2);
	L1.output();

	//��λɾ�����
	datas remove_data = L1.remove(2);
	L1.output();
	cout << "------��ɾ���Ľ����Ϣ����--------" << endl;
	cout << "num��" << remove_data.num << endl;
	cout << "intro��" << remove_data.intro << endl;

	//�����Լ��
	if (L1.single() == 0)
	{
		cout << "�޵�����" << endl;
	}
	else
	{
		string ddx = (L1.single() == 1) ? "����" : "�ݼ�";
		cout << ddx << endl;
	}

	//��ֵ������
	ins_data = { 15, "������Ľ��" };
	L1.insert(ins_data, L1.withHead());
	L1.output();

	//��ת��ʾ
	L1.reverse();
	cout << "------��ת���������Ϣ����--------" << endl;
	L1.output();

}
