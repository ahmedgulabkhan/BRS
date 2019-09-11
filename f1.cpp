#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

int p = 0;
class Bus{
	public:
		int bno;
		string barr, bdep, from, to, res;
}b[10];

//showAll function
void showAll(Bus b[]){
	for(int i=0;i<10;i++){
		cout<<b[i].bno<<"\t"<<b[i].barr<<"\t"<<b[i].bdep<<"\t"<<b[i].from<<"\t"<<b[i].to<<"\t"<<b[i].res<<endl;
	}
}

//showOne function
void showOne(Bus b[]){
	int x;
	cout<<"Enter the bus number of the bus that you want the details of\n";
	cin>>x;
	for(int i=0;i<10;i++){
		if(b[i].bno==x){
			cout<<b[i].bno<<"\t"<<b[i].barr<<"\t"<<b[i].bdep<<"\t"<<b[i].from<<"\t"<<b[i].to<<"\t"<<b[i].res<<endl;
			return;
		}
	}
	cout<<"Enter a valid bus number\n";
	return;
}

//reserve function
void reserve(Bus b[]){
	int x, flag = 0, y;
	cout<<"Enter the bus number in which you want to make a reservation in\n";
	cin>>x;
	int i;
	for(i=0;i<10;i++){
		if(b[i].bno==x){
			flag++;
			break;
		}
	}
	if(flag==0){
		cout<<"Enter a valid bus number\n";
		return;
	}
	
	cout<<"Enter the seat number you want to reserve\n";
	cin>>y;
	if(y>30){
		cout<<"Enter a valid seat number\n";
		return;
	}
	
	if(b[i].res[y-1]=='1'){
		cout<<"Bus is already reserved\n";
		return;
	}
	else{
		b[i].res[y-1] = '1';
		cout<<"Seat number successfully reserved\n";
		ofstream fout;
		fout.open("db.txt", ios::out);
		int k = 0;
		while(k<10){
			fout<<b[k].bno<<"\t"<<b[k].barr<<"\t"<<b[k].bdep<<"\t"<<b[k].from<<"\t"<<b[k].to<<"\t"<<b[k].res<<endl;
			k++;
		}
		fout.close();
	}
}

//menu function
int menu(){
	int choice;
	
	cout<<"Select the choice\n";
	cout<<"1. Show details of all the buses\n";
	cout<<"2. Show details of a specific bus\n";
	cout<<"3. Make a reservation\n";
	cout<<"4. Exit\n";
	cin>>choice;
	
	return choice;
}

//main function
int main(){
	ifstream fin;
	fin.open("db.txt", ios::in);
	while(fin>>b[p].bno>>b[p].barr>>b[p].bdep>>b[p].from>>b[p].to>>b[p].res){
		p++;
	}
	fin.close();
	
	while(1){
		switch(menu()){
			case 1: 
				showAll(b);
				break;
			case 2:
				showOne(b);
				break;
			case 3:
				reserve(b);
				break;
			case 4:
				cout<<"You have chosen to exit\n";
				exit(0);
				break;
			default:
				cout<<"Enter a valid chocie\n";
				break;
		}
	}
	
	return 0;
}
