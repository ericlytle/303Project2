#include "Library.h"
int main(){
	Library library;
	library.AddBook("Software Engineering");
	library.AddBook("Chemistry");

	library.AddEmployee("Adam");
	library.AddEmployee("Sam");
	library.AddEmployee("Ann");

	library.CirculateBook("Chemistry", Date(2015, 3, 1, DateFormat::US));
	library.PassOn("Chemistry", Date(2015, 3, 5, DateFormat::US));
	system("pause");

}