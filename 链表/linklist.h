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
		intro = "��";
	};
	datas(int n, string s)
	{
		num = n;
		intro = s;
	};
}datas;

//�����ṹ��
typedef struct node
{

	datas* information;
	node* next;
	node() //�޲ι�����
	{
		information = new datas;
		next = NULL;
	};
	node(datas& item, node* ptr = NULL) //���ι����㣨��ͷ��㣩
	{
		information = &item;
		next = ptr;
	};

}node;

class LinkList
{
public:
	//�޲ι��죬��ͷ��������
	LinkList()
	{
		head = new node;//��ͷ�������ڴ�
		with_head = true;
	};

	//���ι��죬��ͷ��������
	LinkList(node* x)
	{

		head = x;
		with_head = false;//����ͷ���

	};

	//���Ƿ��ͷ���
	bool withHead()
	{
		return with_head;
	}

	//���ƹ��캯��
	LinkList(LinkList& L);

	//���������������ͷ��ڴ棬��ֹ�ڴ�й¶��
	~LinkList()
	{
		makeEmpty();
	}

	node* get_head()
	{
		return head;
	}

	node* last();//��ȡβָ��

	void makeEmpty();//�������

	node* locate(int i); //���������е�i��Ԫ�صĵ�ַ

	//�ж��Ƿ�Ϊ��������ͷָ��ָ�����һ���ָ���Ƿ�ΪNULL���ɣ�
	bool isEmpty()
	{
		return (with_head) ? head->next == NULL : head == NULL;
	}

	void input(datas endTag = { 0, "����" }, bool front = true);//��������Ĭ��Ϊǰ�巨��

	int length();//���㵥����ĳ���

	int find(datas& x);//���ص�һ������Ϊx�ǵڼ���ֵ

	void save_data(int k, datas& saved);//����k�����ݱ��浽saved

	void output();//�������

	datas remove(int k); //ɾ����k��ֵ������

	void insert(datas ins_data, int k); //��λ���루Ĭ�ϴ�ͷ��㣩

	int single(); //�ж������� 

	void insert(datas ins_data); //��ֵ���룬�����жϵ�ǰ�����Ƿ�Ϊ�ϸ������ݼ�

	void reverse(); //��ת����

private:
	node* head;//ͷ�ڵ�ָ��
	bool with_head;
};


#endif
