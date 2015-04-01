#include "Library.h"
int main(){
	Library library;
	library.AddBook("Software Engineering");
	//library.AddBook("The Book2");
	library.AddBook("Chemistry");
	library.AddBook("Slave to the Pointer");
	//library.AddBook("The Book");

	library.AddEmployee("Adam");
	library.AddEmployee("Sam");
	library.AddEmployee("Ann");

	//before circulate order --> adam, sam , ann

	library.CirculateBook("Chemistry", Date("1-1-2012", DateFormat::US)); //adam gets book 
	library.PassOn("Chemistry", Date("1-2-2012", DateFormat::US)); //sam gets book
	library.PassOn("Chemistry", Date("1-3-2012", DateFormat::US)); //Ann gets book
	library.PassOn("Chemistry", Date("1-6-2012", DateFormat::US)); //Ann returns book

	//after chem order should be --> ann, sam, adam

	library.CirculateBook("Slave to the Pointer", Date("1-7-2012", DateFormat::US)); //ann gets book 
	library.PassOn("Slave to the Pointer", Date("1-9-2012", DateFormat::US)); //sam gets book
	library.PassOn("Slave to the Pointer", Date("1-12-2012", DateFormat::US)); //Adam gets book
	library.PassOn("Slave to the Pointer", Date("1-16-2012", DateFormat::US)); //Adam returns book



	system("pause");

}

//adam wait time should be 0 and retain time should be 1 month
//sam wait time should be 1 month and retain should be 1 month
//ann wait time should be 2 month as well at this point and retain 0