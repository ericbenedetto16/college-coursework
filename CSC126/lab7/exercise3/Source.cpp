#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void gatherInventory();
void totalValue(string tool, double quantity, double price);

int items;

ifstream inputFile;
ofstream outputFile;

int main() {
	inputFile.open("hardware.dat");
	outputFile.open("hardware.out");

	gatherInventory();
	
	inputFile.close();
	outputFile.close();

	system("pause");
	return 0;
}

void gatherInventory() {
	cout << "Gathering Inventory";
	string str;
	string tool;
	int quantity;
	double price;
	vector<string> tools;
	vector<double> stock;
	vector<double> prices;

	int i = 0;
	while (getline(inputFile, str)) {
		inputFile >> tool >> quantity >> price;
		cout << "Item found " << tool << quantity << price << endl;
		i++;
		tools.resize(i);
		stock.resize(i);
		prices.resize(i);
		tools[i-1] = tool;
		stock[i-1] = quantity;
		prices[i-1] = price;
	}

	outputFile << "MY HARDWARE STORE\n---------------------\nTOOL\tQUANTITY\tPRICE\n";
	for (int index = 0; index < i-1; index++) {

		outputFile << tools[index] << "\t" << stock[index] << "\t\t" << prices[index] << endl;
	}

	outputFile << "\n\n";

	for (int j = 0; j < i-1; j++) {
		totalValue(tools[j], stock[j], prices[j]);
	}

}

void totalValue(string tool, double stock, double price) {
	cout << "totalling";
	outputFile << "Value of all " << tool << " in stock:\t" << "$ " << price * stock << endl;
}