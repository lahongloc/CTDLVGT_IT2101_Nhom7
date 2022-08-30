/*Bài 3: Quản lý một danh sách có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int. (Dùng cấu trúc danh sách liên kết đơn)*/

#include<iostream>
using namespace std;
// 3.1. Khai báo cấu trúc danh sách
struct Node
{
	int info;
	Node* next;
};
Node* createNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
// 3.2. Viết thủ tục khởi tạo danh sách rỗng
void init(Node*&first)
{
	first = NULL;
}
// 3.3. Viết thủ tục xuất các phần tử trong danh sách.
void output(Node* first)
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}
// 3.4. Viết thủ tục tìm một phần tử trong danh sách.
Node* Search(int x, Node*&first)
{
	Node* p = first;
	while ((p != NULL) && (p->info != x))
		p = p->next;
	return p;
}
// 3.5. Viết thủ tục thêm một phần tử vào đầu danh sách
void Insert_first(int x, Node*& first)
{
	Node* p = createNode(x);
	p->next = first;
	p->info = x;
	first = p;
}
// 3.6. Viết thủ tục xóa một phần tử dầu danh sách.
void Delete_first(Node*& first)
{
	if (first != NULL)
	{
		Node* p = first;
		first = p->next;
		p->next = NULL;
		delete p;
	}
}
// 3.7. Viết thủ tục thêm một phần tử vào cuối danh sách
void Insert_last(int x, Node* &first)
{
	Node* p = createNode(x);
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node* last = first;
		while (last->next != NULL)
			last = last->next;
		last->next = p;
	}
}
// 3.8. Viết thủ tục xóa một phần tử cuối danh sách.
void Delete_last(Node *& first)
{
	if (first != NULL)
	{
		Node* last = first;
		Node* prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		if (prev == NULL)
		{
			Delete_first(first);
		}
		else
		{
			prev->next = NULL;
			delete(last);
		}
	}

}
// 3.9. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, hãy xóa phần tử này
void Delete_x(int x, Node* first)
{
	if (first != NULL)
	{
		Node* p = first;
		Node* prev = NULL;
		while (p != NULL && p->info != x)
		{
			prev = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (prev == NULL)
			{
				Delete_first(first);
			}
			else
			{
				prev->next = p->next;
				p->next = NULL;
				delete p;
			}
		}
		else
		{
			cout << "Khong tim thay phan tu can xoa" << endl;
		}
	}
}

void menu()
{
	char choose;
	int x;
	Node* first;
	init(first);
	while (true)
	{
		cout << "==========MENU==========" << endl
			<< "1. Xuat phan tu trong danh sach" << endl
			<< "2. Tim 1 phan tu trong danh sach" << endl
			<< "3. Them 1 phan tu vao dau danh sach" << endl
			<< "4. Xoa 1 phan tu dau danh sach" << endl
			<< "5. Them 1 phan tu vao cuoi danh sach" << endl
			<< "6. Xoa 1 phan tu cuoi danh sach" << endl
			<< "7. Tim 1 phan tu trong danh sach. Neu co thi xoa phan tu do" << endl
			<< "8. Chuyen thanh danh sach co thu tu" << endl
			<< "9. Thoat" << endl
			<< "====================" << endl
			<< "Nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == '1')
		{
			output(first);
			cout << endl;
		}
		else if (choose == '2')
		{
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if (Search(x, first) != NULL)
				cout << "Co phan tu " << x << " trong danh sach" << endl;
			cout << "Khong tim thay phan tu "<<x<<" trong danh sach" << endl;
		}
		else if (choose == '3')
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_first(x, first);
			cout << endl;
		}
		else if (choose == '4')
		{
			Delete_first(first);
		}
		else if (choose == '5')
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_last(x, first);
			cout << endl;
		}
		else if (choose == '6')
		{
			Delete_last(first);
		}
		else if (choose == '7')
		{
			cout << "Nhap phan tu can tim va xoa: ";
			cin >> x;
			Delete_x(x, first);
			cout << endl;
		}

		else if (choose == '9')
		{
			cout << "=====GOOD BYE=====" << endl;
			return;
		}
		else cout << "Ban da nhap sai, vui long nhap tu 1 - 8" << endl;
		system("pause");
		system("cls");
	}
}
int main()
{
	menu();
	return 0;
}