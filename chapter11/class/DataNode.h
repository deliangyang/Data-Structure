

template<class T>
class DataNode
{
public:
	T data;
	int index;
	int active;

	friend int operator<=(const DataNode<T>& x, const DataNode<T>& y);	
};

template<class T>
void TournameSort(T a[], int n)
{
	DataNode<T> * tree;
	DataNode<T> item;

	int bottomRowSize;
	int treesize;
	int loadindex;
	int i, j;
	// get last line's node numbers
	bottomRowSize=PowerOfTwo(n);
	treesize=2*bottomRowSize-1;
	loadindex=bottomRowSize-1;
	tree=new DataNode<T>[treesize];
	j=0;
	for(i=loadindex; i<treesize; i++)
	{
		
	}
}