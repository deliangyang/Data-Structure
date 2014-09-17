
#include <iostream>

using namespace std;

struct Student
{
	int filed1;
	double filed2;
};



template<class T>
void Copy(T a[], T b[], int n)
{
	int i;
	for(i=0; i<n; i++)
		a[i]=b[i];
}

void PrintArray(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void PrintStu(Student stu[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<"{"<<stu[i].filed1<<", "<<stu[i].filed2<<"}"<<std::endl;
}

int main(int argc, char *argv[])
{
	int AInt[6], BInt[6]={1, 3, 5, 7, 9};
	Student Astudnet[3];
	Student Bstudent[3]={{1, 3}, {3, 0}, {5, 5}};
	Copy(AInt, BInt, 6);
	Copy(Astudnet, Bstudent, 3);
	PrintArray(AInt, 6);
	PrintStu(Astudnet, 3);

	std::system("pause");
	return 0;
}
