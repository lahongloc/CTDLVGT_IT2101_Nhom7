#include<iostream>
#include<stdio.h>
using namespace std;
//3.1 Khai bao cau truc danh sach
struct Node {
	int info;
	Node* link;
};
Node* first;
//3.2 Khoi tao danh sach rong
void Init()
{
	first = NULL;
}
//3.3 Xuat danh sach
void Process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\n";
		p = p->link;
	}
	cout << endl;
}
//3.4 Tim mot phan tu trong danh sach
Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info == x)
	{
		p = p->link;
	}
	return p;
}
//3.5 Them mot phan tu vao dau danh sach
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
//3.6 Xoa mot phan tu dau danh sach
int Delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 Them mot phan tu vao cuoi danh sach
void Insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//3.8 Xoa mot phan tu cuoi danh sach
int Delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9 Tim mot phan tu trong danh sach neu tim thay thi xoa phan tu nay
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			//Phan tu giua danh sach
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
		}
		else if (p == first)
		{
			//Phan tu dau danh sach
			first = p->link;
			delete p;
		}
		else if (p->link == NULL && p->info == x)
		{
			//Phan tu cuoi danh sach
			q->link = NULL;
			delete p;
		}
		return 1;
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "==========BAI TAP 3 CHUONG 2 DANH SACH LIEN KET DON==========" << endl;
	cout << "1. Khoi tao danh sach lien ket don rong" << endl;
	cout << "2. Them phan tu vao dau danh sach" << endl;
	cout << "3. Them phan tu vao cuoi danh sach" << endl;
	cout << "4. Xoa phan tu o dau danh sach" << endl;
	cout << "5. Xoa phan tu o cuoi danh sach" << endl;
	cout << "6. Xuat danh sach lien ket don" << endl;
	cout << "7. Tim phan tu gia tri x trong danh sach don" << endl;
	cout << "8. Tim va xoa phan tu gia tri x trong danh sach don" << endl;
	cout << "9. Ket thuc chuong trinh" << endl;
	do {
		cout << "Vui long chon lenh ban muon thuc hien" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao thanh cong danh sach lien ket don" << endl;
			break;
		case 2:
			cout << "Vui long nhap x= ";
			cin >> x;
			Insert_first(x);
			cout << "Sau khi them dau danh sach voi gia tri x= " << x << "la: ";
			Process_list();
			break;
		case 3:
			cout << "Vui long nhap x= ";
			cin >> x;
			Insert_last(x);
			cout << "Sau khi them cuoi danh sach voi gia tri x= " << x << " la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "Xoa khong thanh cong, danh sach rong" << endl;
			else
			{
				cout << "Xoa thanh cong phan tu dau danh sach, danh sach sau khi xoa la: " << endl;
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
				cout << "Xoa khong thanh cong, danh sach rong" << endl;
			else
			{
				cout << "Xoa thanh cong phan tu cuoi danh sach, danh sach sau khi xoa la: " << endl;
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach lien ket hien tai la: " << endl;
			Process_list();
			break;
		case 7:
			cout << "Vui long nhap x= ";
			cin >> x;
			p = Search(x);
			if (p == NULL)
			{
				cout << "Khong tim thay x= " << x << "trong danh sach lien ket " << endl;
			}
			else
			{
				cout << "Tim thay x= " << x << "trong danh sach lien ket " << endl;
			}
			break;
		case 8:
			cout << "Vui long nhap x= ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 0)
				cout << "Khong tim thay x= " << x << "trong danh sach lien ket " << endl;
			else
			{
				cout << "Tim thay x= " << x << "trong danh sach lien ket va da xoa hoan tat! " << endl;
				cout << "Danh sach sau khi xoa la: " << endl;
				Process_list();
			}
			break;
		case 9:
			cout << "Ket thuc chuong trinh " << endl;
			break;
		default:
			break;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}