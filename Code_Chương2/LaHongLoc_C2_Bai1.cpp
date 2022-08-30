#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void Input(int a[], int& n)
{
	cout << "Nhap vao so luong phan tu cua DS" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	{
		if (i == n)
			return -1;
	}
	return i;
}
//Độ phức tạp của hàm Search O(n)
int Insert_last(int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
int Delete_last(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;
}
int Delete(int a[], int& n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
			n--;
			return 1;
		}
		return 0;
	}
}
//Độ phức tạp của hàm Delete là O(n)
int Search_Delete(int a[], int& n, int i)
{
	cout << "Nhap phan tu ban muon tim va xoa" << endl;
	cin >> i;
	for (int j = 0; j < n; j++)
	{
		if (a[j] == i)
		{
			Delete(a, n, i);
			return 1;
		}
		else
			cout << "Khong tim thay phan tu trong danh sach" << endl;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << "-------BAI TAP 1 CHUONG 2 DANH SACH DAC-------" << endl;
	cout << "1.Nhap danh sach" << endl;
	cout << "2.Xuat danh sach" << endl;
	cout << "3.Tao phan tu co gia tri x trong danh sach" << endl;
	cout << "4.Them phan tu vao cuoi danh sach" << endl;
	cout << "5.Xoa phan tu vao cuoi danh sach" << endl;
	cout << "6.Xoa phan tu tai vi tri i" << endl;
	cout << "7.Tim va xoa phan tu neu co" << endl;
	cout << "8.Ket thuc chuong trinh" << endl;
	do {
		cout << "Vui long chon so de thuc hien lenh" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Input(a, n);
			cout << "Nhap danh sach thanh cong" << endl;
			break;
		case 3:
			cout << "Vui long nhap gia tri can tim x" << endl;
			cin >> x;
			i = Search(a, n, x);
			if (i == -1)
				cout << "Tim khong thay x" << x << "trong do" << endl;
			else
				cout << "Tim thay x" << x << " tai vi tri i" << i << endl;
			break;
		case 4:
			cout << "Vui long nhap x can them cuoi danh sach" << endl;
			cin >> x;
			i = Insert_last(a, n, x);
			if (i == 0)
				cout << " DS da day, khong the them" << endl;
			else
			{
				cout << " Da them thanh cong x= " << x << " vao cuoi ds " << endl;
				cout << " Danh sach sau them la " << endl;
				Output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a, n);
			if (i < 0)
			{
				cout << "Xoa phan tu cuoi thanh cong" << endl;
				cout << "Danh sach sau khi xoa la " << endl;
				Output(a, n);
			}
			break;
		case 6:
			i = Delete(a, n, i);
			if (i < 0)
			{
				cout << "Xoa phan tu tai vi tri i thanh cong" << endl;
				cout << "Danh sach sau khi xoa la " << endl;
				Output(a, n);
			}
		case 7:
			cout << "Vui long nhap x can tim duoc xoa" << endl;
			cin >> x;
			i = Search_Delete(a, n, i);
			if (i == 1)
			{
				cout << "Moi phan tu x" << x << "thanh cong!" << endl;
				cout << "Danh sach sau khi xoa la" << endl;
				Output(a, n);
			}
			else
				cout << "Khong co phan tu de xoa!" << endl;
			break;
		case 8:
			cout << "Chuong Trinh Ket Thuc\n";
			return 0;
		}
	} while (choice != 8);
	system("pause");
	return 0;

}