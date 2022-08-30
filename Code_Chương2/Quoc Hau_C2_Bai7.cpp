//#include<cstdio>
//#include<iostream>
//using namespace std;
//
//#define Max 100
////7.2 Khoi tao QUEUE rong
//void init(int a[], int& front, int& rear)
//{
//	front = -1;
//	rear = -1;
//}
//// 7.3 Ktra	QUEUE rong
//int isEmty(int a[], int front, int rear)
//{
//	if (rear == front)
//		return 1;
//	return 0;
//}
////7.4 kiểm tra QUEUE đầy.
//int isFull(int a[], int front, int rear)
//{
//	if (front == 00 && rear == Max - 1 || (front - rear == 1))
//		return 1;
//	return 0;
//}
//// 7.5 Thêm một phần tử vào QUEUE
//int Push(int a[], int& front, int& rear, int x)
//{
//	if (rear - front == Max - 1)
//		return 0;
//	else
//	{
//		if (front == -1)
//			front = 0;
//		if (rear == Max - 1)
//		{
//			for (int i = front; i <= rear; i++)
//				a[i - front] = a[i];
//			rear = Max - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//}
////7.6 Lay ra một phần tử tu QUEUE
//int Pop(int a[], int& front, int& rear, int& x)
//{
//	if (front != -1)
//		return 0;
//	else
//	{
//		x = a[front++];
//		if (front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//}
//// Xuat QUEUE
//void process_queue(int a[], int f, int r)
//{
//	cout << "front= " << f << "\t rear= " << r << endl;
//	if (f < r && f != -1)
//	{
//		cout << " <-- ";
//		for (int i = f; i < r + 1; i++)
//			cout << a[i];
//		cout << " <-- \n";
//	}
//	cout << endl;
//}
//int main()
//{
//	int a[Max];
//	int choice, f, r, x, i;
//	system("cls");
//	cout << "=======Bai tap 7 chuong 2 - QUEUE voi DS dac ======" << endl;
//	cout << "1. Khởi tạo QUEUE rỗng\n";
//	cout << "2.Kiem tra QUEUE rong\n";
//	cout << "3.Kiem tra QUEUE day\n";
//	cout << "4.Them 1 phan tu vao QUEUE\n";
//	cout << "5. Lay 1 phan tu trong QUEUE\n";
//	cout << "6.XUAT QUEUE\n";
//	cout << "7.THOAT\n";
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, f, r);
//			cout << "Khoi tao queue thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap phan tu can them x= ";
//			cin >> x;
//			i = Push(a, f, r, x);
//			if (i == 1)
//			{
//				cout << "Them x= " << x << " vao queue Thanh cong!" << endl;
//				cout << "QUEUE sau khi can them lai " << endl;
//				process_queue(a, f, r);
//			}
//			break;
//		case 3:
//			i = Pop(a, f, r, x);
//			if (i == 1)
//			{
//				cout << "Lay ra phan tu QUEUE thanh cong, gia tri lay ra la: x = " << x << endl;
//				cout << "QUEUE sau khi lay ra 1 phan tu la: " << endl;
//				process_queue(a, f, r);
//			}
//			else
//				cout << "Lay ra khong thanh cong\n";
//			break;
//		case 4:
//			i = isEmty(a, f, r);
//			if (i == 1)
//				cout << "QUEUE dang rong\n";
//			else
//				cout << "QUEUE khong rong\n";
//			break;
//		case 5:
//			i = isFull(a, f, r);
//			if (i == 1)
//				cout << "QUEUE dang day\n";
//			else
//				cout << "QUEUE khong day\n";
//			break;
//		case 6:
//			process_queue(a, f, r);
//			break;
//		case 7:
//			cout << "GOODBYE\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 7);
//	system("pause");
//	return 0;
//}
