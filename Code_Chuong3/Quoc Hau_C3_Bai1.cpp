#include<iostream>
#include<stdio.h>
using namespace std;
//10.1 Khai bao cau truc Stack
struct Node {
	int info;
	Node* link;
};
Node* sp;
//10.2 Khoi tao Stack rong 
void init()
{
	sp = NULL;
}
//10.3 Kiem tra Stack rong
int isEmty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//10.4 Them phan tu vao Stack
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;

}
//10.5 Lay ra mot phan tu tu Stack
int Pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat Stack
void Process_Stack()
{
	Node* p = sp;
	do
	{
		cout << p->info << "<--";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}
int main()
{
	int choice, sp, x;
	system("cls");
	cout << "=====BAI TAP 10 CHUONG 2 STACK DSLK====" << endl;
	cout << "1. Khoi tao Stack rong" << endl;
	cout << "2. Them mot phan tu vao Stack" << endl;
	cout << "3. Lay mot phan tu ra khoi Stack" << endl;
	cout << "4. Kiem tra Stack co rong hay khong" << endl;
	cout << "5. Xuat Stack" << endl;
	cout << "6. Ket thuc chuong trinh" << endl;
	do
	{
		cout << "\nVui long nhap so de thuc hien ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao Stack rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap phan tu can them x=";
			cin >> x;
			Push(x);
			cout << "Stack sau khi them la:";
			Process_Stack();
			break;
		case 3:
			Pop(x);
			cout << "Stack sau khi them la:";
			Process_Stack();
			break;
		case 4:
			if (isEmty() == 1)
				cout << "Stack rong" << endl;
			else
				cout << "Stack da co phan tu!" << endl;
			break;
		case 5:
			Process_Stack();
		case 6:
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}


