﻿#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
using namespace simple_numbers;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	if (!ifst) {
		cout << "No input file found!" << endl;
		return 0;
	}

	char ch; //проверка файла на пустоту
	FILE* f = fopen(argv[1], "r");
	if (fscanf(f, "%c", &ch) == EOF) {
		cout << "Input file is Empty" << endl;

		return 1;
	}
	fclose(f);

	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	ofst << "\n\nSorted container. " << endl;
	c.Sort();
	c.Out(ofst);
	ofst << "\n\nFiltered container. " << endl;
	c.OutComplex(ofst);
	ofst << "\n" << endl;
	c.Multimethod(ofst);
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
	return 0;
}