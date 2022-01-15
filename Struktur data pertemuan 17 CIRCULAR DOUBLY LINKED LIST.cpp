#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct SIMPUL{
	char NAMA[30];
	char NIM[15];
	char GENDER[30];
	int NILAI;
	struct SIMPUL*LINK;
	};
SIMPUL *P,*Q,*FRONT,*REAR;
void PEMBUATAN_SIMPUL(void);
void TAMPILAN (void);
void INSERT(void);
void DELETE(void);
void PRINTLAYAR(void);
void FREE_MEMORY(void);
int PIL;
char PILIHAN[1],HURUF;
using namespace std;
int main(void)
	{
	TAMPILAN();
	do
	{
		system("cls");
               cout<<" ============================"<<endl;
		cout<<"  CIRCULAR DOUBLY LINKED LIST    "<<endl;
		cout<<" ============================"<<endl;
		cout<<" 1.Insert Data"<<endl;
		cout<<" 2.Hapus Data"<<endl;
		cout<<" 3.Print data"<<endl;
		cout<<" 4.Exit"<<endl;
		cout<<" PILIHAN(1-4)\t: ";cin>>PILIHAN;
		PIL=atoi(PILIHAN);
		switch (PIL)
	{
		case 1:
		INSERT();
		break;

		case 2:
		DELETE();
		break;

		case 3:
		PRINTLAYAR();
		break;

		default:
		cout<<endl<<" Terimakasih"<<endl<<endl;
		FREE_MEMORY();
		break;
	}
		}while(PIL<4);
		}
		void PEMBUATAN_SIMPUL(void)
		{
		P=(SIMPUL*)malloc(sizeof(SIMPUL));
	if (P!=NULL)
	{
		cout<<" -------------------"<<endl;
		cout<<" Nama \t\t: ";cin>>P->NAMA;
		cout<<" NIM \t\t: ";cin>>P->NIM;
		cout<<" Gender \t: ";cin>>P->GENDER;
		cout<<" Nilai \t\t: ";cin>>P->NILAI;
	}
	else
		{
		cout<<" Pembuatan Simpul Gagal Bos"<<endl;
		getchar();
		exit(1);
	}
		}
		void TAMPILAN(void)
	{
		FRONT=NULL;
		REAR=NULL;
	}
		void INSERT(void)
	{
		PEMBUATAN_SIMPUL();
		if(FRONT==NULL)
	{
		FRONT=P;
		REAR=P;
		REAR->LINK=NULL;
	}
	else
	{
		REAR->LINK=P;
		REAR=P;
		REAR->LINK=NULL;
	}
	}
		void DELETE(void)
	{
	if(FRONT==NULL)
	{
		cout<<" Datanya belum ada"<<endl;
		getchar();
	}
	else
	{
		Q=FRONT->LINK;
		free(FRONT);
		FRONT=Q;
		if(FRONT==NULL)
	TAMPILAN();
		cout<<" Data Terakhir Dihapus"<<endl;
		getch();
	}

	}
		void PRINTLAYAR(void)
	{
		int i=1;
		if(FRONT!=NULL)
	{
		Q=FRONT;
		while(Q!=NULL)
	{
		cout<<"\n Data ke - \t: "<<i++<<endl;
		cout<<" Nama \t\t: "<<Q->NAMA<<endl;
		cout<<" NIM \t\t: "<<Q->NIM<<endl;
		cout<<" Gender \t: "<<Q->GENDER<<endl;
		cout<<" Nilai \t\t: "<<Q->NILAI<<endl;
		Q=Q->LINK;
		cout<<endl;
	}
	}
	else
		cout<<"Datanya kosong/tidak ada"<<endl;
		getch();
	}
		void FREE_MEMORY(void)
	{
		while(FRONT!=NULL)
	{
		Q=FRONT->LINK;
		free(FRONT);
		FRONT=Q;
	}
	}
