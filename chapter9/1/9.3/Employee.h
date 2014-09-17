

#define NAME 20

struct Employee
{
	char name[NAME];
	int idnumber;
	float hourlyper;

	friend std::ostream& operator<<(std::ostream& os, Employee employee);
	friend std::istream& operator>>(std::istream& is, Employee employee);
};

