#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int info;
	Node* next, * previous;
};
Node* first, * last;
void init()
{
	first = NULL;
	last = NULL;
}
// Xuat danh sach
void Process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->next;
	}
	cout << endl;
}
// Tim kiem 
Node* Search(int x)
{
	Node* p;
	p = first;
	while (p != NULL && p->info != x)
	{
		p = p->next;
	}
	return p;
}
// Them phan tu vao dau danh sach
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
	{
		first->previous = p;
	}
	else // Danh sach rong
	{
		last = p;
	}
	first = p;
}
// Xoa phan tu vao dau danh sach
int Delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
		{
			first->previous = NULL;
		}
		else
		{
			last = NULL;
		}
		return 1;
	}
	return 0;
}
// Them phan tu vao cuoi danh sach
void Insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
	{
		last->next = p;
	}
	else
	{
		first = p;
	}
	last = p;
}
// Xoa phan tu vao cuoi danh sach
int Delete_last()
{
	if (last != NULL)
	{
		Node* p = last;
		last = last->previous;
		if (last != NULL)
			last->next = NULL;
		else
		{
			first = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
// Tim va xoa phan tu duoc tim thay
void SearchAndDelete(int x) {
	//Tim kiem theo du lieu x va gan vao node p
	Node* p = Search(x);
	//Neu tim thay ket qua
	if (p != NULL) {
		//Neu p->prev == NULL thuc hien xoa dau
		if (p->previous == NULL) {
			Delete_first();
			return;
		}
		//Neu p->next == NULL thuc hien xoa cuoi
		if (p->next == NULL) {
			Delete_last();
			return;
		}
		//Thay doi lai lien ket cua phan tu co x can xoa
		p->previous->next = p->next;
		p->next->previous = p->previous;
		//Gan con tro prev va next cua phan tu co x can xoa ve null
		p->previous = NULL;
		p->next = NULL;
		//Xoa node p co phan tu la x
		delete p;
	}
}
int main()
{
	int x, choice;
	Node* p;
	system("cls");
	cout << "------------------BAI TAP 3A CHUONG 2 DSLK DOI-----------------" << endl;
	cout << "1. Khoi tao danh sach rong " << endl;
	cout << "2. Xuat cac phan tu trong danh sach " << endl;
	cout << "3. Tim mot phan tu trong danh sach " << endl;
	cout << "4. Them mot phan tu vao dau danh sach " << endl;
	cout << "5. Xoa phan tu dau danh sach " << endl;
	cout << "6. Them mot phan tu vao cuoi danh sach " << endl;
	cout << "7. Xoa phan tu cuoi danh sach " << endl;
	cout << "8. Tim va xoa phan tu trong danh sach " << endl;
	cout << "9. Thoat khoi chuong trinh! " << endl;
	do
	{
		cout << "Moi ban chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao danh sach rong thanh cong! " << endl;
			break;
		case 2:
			cout << "Danh sach: ";
			Process_list();
			break;
		case 3:
			cout << "Vui long nhap x: ";
			cin >> x;
			p = Search(x);
			if (p == NULL)
			{
				cout << "Khong tim thay x trong danh sach! " << endl;
			}
			else
				cout << "Tim thay x trong danh sach! " << endl;
			break;
		case 4:
			cout << "Nhap phan tu ma ban muon them vao: ";
			cin >> x;
			Insert_first(x);
			Process_list();
			break;
		case 5:
			Delete_first();
			cout << "Danh sach sau khi xoa phan tu dau: ";
			Process_list();
			break;
		case 6:
			cout << "Nhap phan tu ma ban muon them vao: ";
			cin >> x;
			Insert_last(x);
			Process_list();
			break;
		case 7:
			Delete_last();
			cout << "Danh sach sau khi xoa phan tu cuoi: ";
			Process_list();
			break;
		case 8:
			cout << "Vui long nhap x ma ban muon tim de xoa: ";
			cin >> x;
			SearchAndDelete(x);
			Process_list();
			break;
		case 9:
			cout << "Ket thuc chuong trinh! " << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}