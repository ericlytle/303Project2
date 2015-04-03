#include "Library.h"

int main(){
	Library library;
	
	library.AddBook("Software Engineering");
	library.AddBook("Chemistry");
	library.AddBook("Slave to the Pointer");
	

	library.AddEmployee("Adam");
	library.AddEmployee("Sam");
	library.AddEmployee("Ann");

	
	library.CirculateBook("Chemistry", Date("1-1-2012", DateFormat::US)); 
	library.PassOn("Chemistry", Date("1-2-2012", DateFormat::US)); 
	library.PassOn("Chemistry", Date("1-3-2012", DateFormat::US)); 
	library.PassOn("Chemistry", Date("1-6-2012", DateFormat::US)); 
	
	library.AddEmployee("Zinzi");

	library.CirculateBook("Slave to the Pointer", Date("1-7-2012", DateFormat::US));  
	library.PassOn("Slave to the Pointer", Date("1-9-2012", DateFormat::US)); 
	library.PassOn("Slave to the Pointer", Date("1-12-2012", DateFormat::US)); 
	library.PassOn("Slave to the Pointer", Date("1-16-2012", DateFormat::US)); 
	library.PassOn("Slave to the Pointer", Date("1-23-2012", DateFormat::US));

	library.CirculateBook("Software Engineering", Date("1-17-2012", DateFormat::US));

	library.AddBook("The Art of Computer Programming");

	system("pause");
	return 0;
}