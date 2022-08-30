#include<iostream>
using namespace std;
//=============================
struct soHang{
    int soMu;
    float heSo;
    struct soHang *next;
};
//=============================
void nhapDuLieu(struct soHang *sh)
{
    float temp;
    struct soHang* tg;
    tg = (struct soHang*)malloc(sizeof(struct soHang));
 
    printf("\n Nhap vao so mu : "); scanf("%d",&tg->soMu); 
    printf("\n Nhap vao he so :");  scanf("%f",&temp);
    tg->heSo = temp;
 
    tg->next = NULL;
 
    *sh = *tg;
}
//=============================
soHang* insertToHead(soHang *first,int soMu,float heSo){
    soHang* newNode = (soHang*)malloc(sizeof(soHang));
 
    newNode->soMu = soMu;
    newNode->heSo = heSo;
 
    newNode->next = first;
    first = newNode;
 
    return first;
}
//=============================
soHang* insertToMiddle(soHang* current,int soMu, float heSo){
    soHang* newNode = (soHang*)malloc(sizeof(soHang));
   
    newNode->soMu = soMu;
    newNode->heSo = heSo;
 
    newNode->next = current->next;
    current->next = newNode;
 
    return newNode;
}
//=============================
soHang* insertToLast(soHang *first,int soMu,float heSo){
    soHang* newNode = (soHang*)malloc(sizeof(soHang));
    soHang* current = first;
 
    newNode->soMu = soMu;
    newNode->heSo = heSo;
 
    // Duyet danh sach den cuoi danh sach
    while(current != NULL){
        current = current->next;
    }
 
    current->next = newNode;
 
    return first;
   
}
//=============================
void hienThi(soHang* first){
    soHang* tempNode = first;
   
    while(tempNode != NULL){
        if (tempNode->heSo > 0)
        {
            printf(" +%4.0fX^%d",tempNode->heSo,tempNode->soMu);
        }
        else{
            printf(" -%4.0fX^%d",tempNode->heSo,tempNode->soMu);
        }
       
        tempNode = tempNode->next;
    }
 
}
//=============================
int main()
{
	int chon;
	int soMu;
    float heSo;
    soHang *tempNode,*first = NULL;
    struct soHang* current1 = NULL; 
    struct soHang* list = NULL,*dlist = NULL;
    struct soHang* head = NULL;
	system("cls");
	cout << "===========BAI TAP 14 _ CHUONG 2==========" << endl;
	cout << "14.1 Khai bao cau truc danh sach" << endl;
	cout << "14.2 Nhap vao da thuc" << endl;
	cout << "14.3 Xuat da thuc" << endl;
	cout << "14.4 Cong hai da thuc" << endl;
	cout << "14.5 Tru hai da thuc" << endl;
	cout << "14.6 Nhan hai da thuc" << endl;
	cout << "14.7 Chia hai da thuc" << endl;

	cout << "0.Thoat" << endl;
	do
	{
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout<<"Khai bao cau truc danh sach thanh cong!"<<endl;
			break;
		case 2:
			cout<<"\n Nhap vao He So :"; cin>>heSo;
            cout<<"\n Nhap vao so mu :"; cin>>soMu;
 
            if (list == NULL)
            {
                first = inSertToHead(first,soMu,heSo);
                break;
            }
           
            list = first;
            
            insertToList();
            break;
			break;
		case 3:
			calculateValue();
			break;
		case 4:
			tinhDaoHam();
			break;
		case 5:
			hienThi();
			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");
    
    return 0;
}
