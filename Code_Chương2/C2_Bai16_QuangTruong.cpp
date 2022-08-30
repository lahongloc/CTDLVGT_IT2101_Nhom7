
#include<iostream>
using namespace std;


struct Node {
	int info;
	Node* link;
};

Node* front, * rear;


void init() {
	front = rear = NULL;
}


int isEmpty() {
	if (front == NULL)
		return 1;
	return 0;
}


int Push(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}
	return 1;
}


int Pop(int& x) {

	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = p->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}


int main() {

	int choice, kt, x;
	system("cls");
	cout << "=== Bai tap 11 - Chuong 2 - QUEUE voi DSLK don ===\n";
	cout << "1. Khoi tao QUEUE rong\n";
	cout << "2. Kiem tra QUEUE co rong hay khong?\n";
	cout << "3. Them phan tu vao QUEUE\n";
	cout << "4. Lay phan tu ra khoi QUEUE\n";
	cout << "5. Thoat\n";

	do {
		cout << "Vui long chon so: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "\nKhoi tao thanh cong\n";
			break;
		case 2:
			kt = isEmpty();
			if (kt == 1) cout << "Rong\n";
			else cout << "Khong rong\n";
			break;
		case 3:
			cout << "Moi nhap X: ";
			cin >> x;
			Push(x);
			break;
		case 4:
			Pop(x);
			cout << "Phan tu X duoc lay ra: " << x << endl;
			break;
		default:
			break;
		}
	} while (choice != 5);

	system("pause");
	return 0;
}