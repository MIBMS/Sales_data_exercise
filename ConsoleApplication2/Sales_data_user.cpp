#include "stdafx.h"
#include <iostream>
#include <string>

#include "Sales_data.h"

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::string;
using std::cerr;
using std::cin;

int main() {
	Sales_data total; // variable to hold the running sum
	if (read(cin, total)) { // read the first transaction
		cout << "Processing next transaction" << endl;
		Sales_data trans; // variable to hold data for the next transaction
		while (read(cin, trans)) { // read the remaining transactions
			if (total.isbn() == trans.isbn()) // check the isbns
				total.combine(trans); // update the running total
			else {
				cout << total.isbn() << " done:" << endl;
				print(cout, total) << endl; // print the results
				total = trans; // process the next book
			}
			cout << "Processing next transaction" << endl;
		}
		print(cout, total) << endl; // print the last transaction
	}
	else { // there was no input
		cerr << "No data?!" << endl; // notify the user
	}
}



