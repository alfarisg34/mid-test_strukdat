/*	Nama program	: Soal1
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 23 04 2019
	Deskripsi		: List Sepak Bola
********************************************************************/
#include<iostream>
using namespace std;
struct data{
    int urutanDaftar;
    char namaTim[20];
    char asalDaerah[20];
    int gol;
    data*next;
};
typedef data*pointer;
typedef pointer List;
void createList(List& first)
{ 
    first=NULL;
}
void createElm(pointer&pBaru)
{
    pBaru=new data;
    cout<<"Urutan daftar : ";cin>>pBaru->urutanDaftar;
    cout<<"Nama Tim : ";cin>>pBaru->namaTim;
    cout<<"Asal Daerah: ";cin>>pBaru->asalDaerah;
    pBaru->gol=0;
    pBaru->next=NULL;
}
void insertLast(List& First, pointer pBaru)
{
    pointer last; 
    cout<<"Insert Last"<<endl;
    if (First==NULL)
    { 
        First=pBaru;
    }
    else 
    { 
        last=First; 
        while (last->next!=NULL)
        {
            last=last->next;
        }
    last->next=pBaru; 
    }
}
void traversal(List first)
{
    pointer pBantu;
    pBantu=first;
    cout<<"No Daftar\tTim\tAsal Daerah"<<endl;
    while(pBantu!=NULL){
        cout<<pBantu->urutanDaftar<<"\t\t";
        cout<<pBantu->namaTim<<"\t";
        cout<<pBantu->asalDaerah<<"\t"<<endl;
        pBantu=pBantu->next;
    }
    cout<<endl;
}
void update(List first){
    pointer pBantu;
    pBantu=first;
    while(pBantu!=NULL){
        cout<<pBantu->namaTim<<endl;
        cout<<"Jumlah gol : ";cin>>pBantu->gol;
        pBantu=pBantu->next;
    }
    cout<<endl;
    pBantu=first;
    cout<<"No Daftar\tTim\tAsal Daerah\tGol"<<endl;
    while(pBantu!=NULL){
        cout<<pBantu->urutanDaftar<<"\t\t";
        cout<<pBantu->namaTim<<"\t";
        cout<<pBantu->asalDaerah<<"\t\t";
        cout<<pBantu->gol<<endl;
        pBantu=pBantu->next;
    }
    cout<<endl;
    cout<<"Decending berdasarkan gol"<<endl;
    cout<<"No Daftar\tTim\tAsal Daerah\tGol"<<endl;
    for(int i=3;i>=0;i--){
        pBantu=first;
        for(int j=0;j<7;j++){
           if(pBantu->gol==i){
            cout<<pBantu->urutanDaftar<<"\t\t";
            cout<<pBantu->namaTim<<"\t";
            cout<<pBantu->asalDaerah<<"\t\t";
            cout<<pBantu->gol<<endl;
           }
           pBantu=pBantu->next;
           if(pBantu==NULL){
               break;
           }
        }
    }
}
int main()
{
    pointer p;
    List m;
    createList(m);

    for(int i=0;i<6;i++)
    {
        createElm(p);
        insertLast(m,p);
        traversal(m);
    }
    update(m);
}