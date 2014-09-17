
#include <iostream>
#include <iomanip>


#include "Student.h"


int main(int argc, char *argv[])
{
	int choice;
	SeqLink<Test> Submitted(30);
	SeqLink<Test> Borrowed(30);
	std::cout<<"1:交卷"<<std::setw(10)<<"2:学生查卷"<<std::endl;
	std::cout<<"3:交回借出的试卷"<<std::setw(5)<<"4:退出"<<std::endl;

	std::cout<<"Enter your choice: ";
	std::cin>>choice;
	while(choice!=0)
	{
		switch(choice)
		{
		case 1:
			PutPapper(Submitted);
			break;
		case 2:
			BorrowPapper(Submitted, Borrowed);
			break;
		case 3:
			BackPapper(Submitted, Borrowed);
			break;
		case 4:
			ExitPaper(Submitted, Borrowed);
			break;
		default:
			break;
		}
		std::cout<<"Enter your choice: ";
		std::cin>>choice;
	}

	std::system("pause");
	return 0;
}