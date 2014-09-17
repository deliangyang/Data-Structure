

struct IntEntry
{
	int value;			// element
	int count;			// the element show times
};

void PrintIntEntry(Node<IntEntry> * list)
{
	Node<IntEntry> * ptrCurrent=list;
	while(ptrCurrent!=NULL)
	{
		std::cout<<ptrCurrent->data.value<<": "<<ptrCurrent->data.count<<std::endl;
		ptrCurrent=ptrCurrent->NextNode();
	}
}


int operator==(IntEntry& a, IntEntry& b)
{
	return a.value==b.value;
}

int operator>(IntEntry& a, IntEntry& b)
{
	return a.value>b.value;
}

