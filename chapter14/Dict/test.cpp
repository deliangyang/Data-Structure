

#include <iostream>
#include <string>

using namespace std;

int * Array(int * arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		arr[i]+=n;
	return arr;
}

int Test(int (* a)[3], int n)
{
	std::cout<<a[0][0]<<std::endl;
}

int main(int argc, char *argv[])
{
	int *p;
	int a=19;
	p=&a;
	std::cout<<*p<<std::endl;
	
	int b=10;
	// it's means give the value another name
	int &ra=a;			// typename &(ref name) = val
	std::cout<<ra<<std::endl;
	ra=b;
	std::cout<<b<<std::endl;

	const int &ref=ra;
	std::cout<<"ref: "<<ref<<std::endl;
	//ref=b;
	a=20;
	std::cout<<"ref(b): "<<ref<<std::endl;

	int * arr;
	int array[]={1, 3 , 4, 5};
	arr=array;
	int i;
	for(i=0; i<4; i++)
		std::cout<<(*arr++)<<" ";  // (*arr) mean get arr val, * < ++
	std::cout<<std::endl;

	arr=Array(array, 4);
	for(i=0; i<4; i++)
		std::cout<<(*arr++)<<" ";  // (*arr) mean get arr val, * < ++
	std::cout<<std::endl;

	int test[3][3]={{1, 2, 3}, {3, 4, 3}, {3, 4, 3}};
	Test(test, 3);
	int m=4; 
	int n=3;
	int j;
	int **t;
	t=(int **)malloc(sizeof(int **)*m);
	for(i=0; i<m; i++)
		t[i]=(int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			t[i][j]=i+j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			std::cout<<t[i][j]<<" ";
		std::cout<<std::endl;
	}

	for(i=0; i<m; i++)
		free(t[i]);
	free(t);
	i=5;
	int te;
	int tp;
	while(i--)		// if get error it will break
	{
		std::cout<<"hello world"<<std::endl;
		cin>>te>>tp;	
		std::cout<<"te, tp"<<te<<", "<<tp<<std::endl;
	}
	std::system("pause");
	return 0;
}
