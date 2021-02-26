#include <iostream>
#include <fstream>
#include <string>

#include "hashTable.h"

using namespace std;

int main() {


	int p = 0, n = 0, k1 = 0; //Declare size of Hash Table p, number of keys n, and search k1
	double alpha = 0.0; // Declare alpha for Linear Hashing
	hashTable *chainedHashTable, *linearHashTable, *doubleHashTable; //Declare Chained Hash Table, Linear Hash Table, and Double Hash Table
	int* keys; // Array of size n for keys.

	/*Open input file*/
	ifstream myReadFile;
	myReadFile.open("input.txt");

	cout<<"Open input file"<<endl; //Display open input file.
	cout<<"Reading input file"<<endl;

	myReadFile >> p; //Read the first number for p.
	myReadFile >> alpha;//Read the second number for alpha.
	myReadFile >> n;//Read the third number for size n.

	/*Read next lines for keys, and put them in array*/
	keys = new int[n];
	for(int i = 0; i < n; i++) {
		myReadFile >> keys[i];
	}

	// Read the last number k1 for searching.
	myReadFile >> k1;

	myReadFile.close();//Close input file.
	cout<<"Input file is close"<<endl;

	// Create Hash Tables
	chainedHashTable = new hashTable(p, alpha);
	linearHashTable = new hashTable(p, alpha);
	doubleHashTable = new hashTable(p, alpha);
	ofstream myWriteFile; //Declare output file.
	string output; //String to print output.

	// Chained Hash Table.
        cout<< "\nOpen Chained-Hash-Output file to write output" <<endl;
	myWriteFile.open("Chained-Hash-Output.txt"); //Open output file to wrtie.

	// Insert keys
	for(int i = 0; i < n; i++){
	    chainedHashTable->chainedHashInsert(keys[i]);
	}

	output = chainedHashTable->print(); //Print Hash Table to output.
        cout<<"Write output to the file"<<endl;
	myWriteFile << output; //Write to output file.

	// Search for element k1
	int searchK1 = chainedHashTable->chainedHashSearch(k1); //Search element k1.
	myWriteFile << searchK1 << endl; //Write to ouput file.

	myWriteFile.close(); //Close current output file.
        cout<<"Chained-Hash-Output.txt is closed"<<endl;

	// Linear Hash Table
	cout<< "\nOpen Linear-Hash-Output file to write output" <<endl;
	myWriteFile.open("Linear-Hash-Output.txt"); //Open output file to write.

	// Insert keys
	for(int i = 0; i < n; i++){
	    linearHashTable->hashInsertLinear(keys[i]);
	}
	output = linearHashTable->print(); //Print Hash Table to output.
	cout<<"Write output to the file"<<endl;
	myWriteFile << output; //Write to output file.

	// Search element k1
	output = linearHashTable->hashSearchLinear(k1); //Search for k1.
	myWriteFile << output << endl;//Write sequence to output file.

	myWriteFile.close(); // Close output file.
        cout<<"Linear-Hash-Output.txt is closed"<<endl;

	// Double Hash Table
	cout<<"\nOpen Double-Hash-Output.txt"<<endl;
	myWriteFile.open("Double-Hash-Output.txt"); //Open output file to write.

	// Insert keys
	for(int i = 0; i < n; i++){
	   doubleHashTable->hashInsertDouble(keys[i]);
	}
	output = doubleHashTable->print(); //Print Hash Table to output.
	cout<<"Write output to the file"<<endl;
	myWriteFile << output; //Write to output file.

	// Search element k1
	output = doubleHashTable->hashSearchDouble(k1); //Search k1.
	myWriteFile << output << endl; //Write sequence to output file.

	myWriteFile.close(); //Close output file.
	cout<<"Double-Hash-Output.txt is closed"<<endl;

	return 0;
}//End of main.

