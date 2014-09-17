
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp=a;
	a=b;
	b=temp;
}

const char *cards[]={"A", "1", "2", "3", "4", "5",
					"6", "7", "8", "9", "10", "J", "Q", "K"};
const char *flower[]={"Plum", "Box", "Red", "Black"};

class CardDeck
{
public:
	CardDeck(void);
	void Shuffle(void);
	int GetCard(void);
	void PrintCard(int c);
private:
	int card[52];
	int currentCard;
};

CardDeck::CardDeck(void)
{
	int i;
	for(i=0; i<52; i++)
		card[i]=i;
	// shuffle card
	for(i=0; i<52; i++)
		swap(card[rand()%(52-i)+i], card[i]);
	currentCard=0;
}

void CardDeck::Shuffle(void)
{
	int i;
	for(i=0; i<52; i++)
		swap(card[rand()%(52-i)+i], card[i]);
	currentCard=0;
}

int CardDeck::GetCard(void)
{
	if(currentCard>=52)
	{
		std::cout<<"shuffle card";
		Shuffle();
		currentCard=0;
		return -1;
	}
	int temp=card[currentCard];
	currentCard++;
	return temp;
}

void CardDeck::PrintCard(int c)
{
	cout<<flower[c/13]<<"-"<<cards[c%13]<<std::endl;
}

int main(int argc, char *argv[])
{
	CardDeck card;
	card.Shuffle();
	int temp;
	int successCount=0;
	char arr[5];
	int i;
	for(i=0; i<5; i++)
		arr[i]=card.GetCard();
	for(i=0; i<5; i++)
		card.PrintCard(arr[i]);
	std::cout<<std::endl;				 
	for(i=0; i<5; i++)
	{
		temp=card.GetCard();
		if(arr[i]%13==temp%13)
		{
			if(arr[i]/13>temp/13)
				successCount++;
		}
		if(arr[i]%13>temp%13)
		{
			if(arr[i]%13==0)
				successCount++;
			else
				successCount++;
		}
		card.PrintCard(temp);
	}
	std::cout<<"Success Count: "<<successCount<<std::endl;
	std::system("pause");
	return 0;
}
