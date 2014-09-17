
#include <iostream>

#include <fstream>
#include <cstdlib>
#include <iomanip>

#include <string>

using namespace std;

#include "SeqLink.h"
#include "Film.h"

int main(int argc, char *argv[])
{
	int j=0;
	int arr[5]={1, 2, 3, 4, 5};

	SeqLink<FilmData> inventoryList(30), customerList(30);
	FilmData fd;
	GetFilmInfo(inventoryList);
	PrintFilmInfo(inventoryList);
	char customer[STRINGLEN];
	
	for(int i=0; i<4; i++)
	{
		cout<<"Enter customer's name: ";
		cin>>customer;
		cout<<"Enter the film' name: ";
		cin>>fd.filename;
		if(inventoryList.Find(fd))
		{
			strcpy(fd.customername, customer);
			customerList.Insert(fd);
			inventoryList.Delete(fd);
		}
		else
			cout<<"sorry this film isn't exist or has been borrowed"<<endl;
	}
	/*for(int i=0; i<4; i++)
	{
		cout<<"Enter customer's name: ";
		cin.getline(customer, 32, '\n');
		cout<<"Enter the film' name: ";
		cin.getline(fd.filename, 32, '\n');
		if(inventoryList.Find(fd))
		{
			strcpy(fd.customername, customer);
			customerList.Insert(fd);
			inventoryList.Delete(fd);
		}
		else
			cout<<"sorry this film isn't exist or has been borrowed"<<endl;
		cout<<endl;
	}*/
	cout<<"Print Customer's info: "<<endl;
	PrintCustomerList(customerList);
	cout<<"Print Inventory List: "<<endl;
	PrintFilmInfo(inventoryList);
	
	system("pause");
	return 0;
}
