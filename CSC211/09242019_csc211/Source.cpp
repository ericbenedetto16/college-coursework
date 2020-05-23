#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Player {
	private: 
		string name, team;
		double ba;
		int id, hr, rbi;

	public:
		void print();
		string print_string();

		// Helper Functions
		void setId(int id);
		void setName(string name);
		void setTeam(string team);
		void setBa(double ba);
		void setHr(int hr);
		void setRbi(int rbi);
		int getId();
		string getName();
		string getTeam();
		double getBa();
		int getHr();
		int getRbi();
};

void Player::setId(int id) {this->id = id;}
void Player::setName(string name) {this->name = name;}
void Player::setTeam(string team) {this->team = team;}
void Player::setBa(double ba) {this->ba = ba;}
void Player::setHr(int hr) {this->hr = hr;}
void Player::setRbi(int rbi) {this->rbi = rbi;}
int Player::getId() {return this->id;}
string Player::getName() {return this->name;}
string Player::getTeam() {return this->team;}
double Player::getBa() {return this->ba;}
int Player::getHr() {return this->hr;}
int Player::getRbi() {return this->rbi;}
void Player::print() {cout << "Player ID: " << this->id << "\nPlayer: " << this->name << "\nTeam: " << this->team << "\nHomeruns: " << this->hr << "\nBatting Average: " << this->ba << "\nRBI (Runs Batted In): " << this->rbi << "\n\n";}
string Player::print_string() { return "Player ID: " + to_string(this->id) + "\nPlayer: " + this->name + "\nTeam: " + this->team + "\nHomeruns: " + to_string(this->hr) + "\nBatting Average: " + to_string(this->ba) + "\nRBI (Runs Batted In): " + to_string(this->rbi) + "\n\n"; }


int main() {
	Player a, b, c, d, e, f, g, h, i, j;
	string filename = "data.txt";
	bool output;
	char out;
	bool invalid = true;
	
	do {
		cout << "Would You Like to Save Your Data to an Output File? (Y/N) ";
		cin >> out;
		if (out == 'Y' ^ out == 'y') {
			output = true;
			invalid = false;
		}
		else if (out == 'N' ^ out == 'n') {
			output = false;
			invalid = false;
		}
	} while (invalid);

	string line;
	ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open()) {
		int iterator = 0;
		char cur = 'a';
		while (getline(inFile, line)) {
			switch (cur) {
			case 'a':
				switch (iterator) {
				case 0:
					a.setId(stoi(line));
					break;
				case 1:
					a.setName(line);
					break;
				case 2:
					a.setTeam(line);
					break;
				case 3:
					a.setBa(stod(line));
					break;
				case 4:
					a.setHr(stoi(line));
					break;
				case 5:
					a.setRbi(stoi(line));
					break;
				}
				break;
			case 'b':
				switch (iterator) {
				case 0:
					b.setId(stoi(line));
					break;
				case 1:
					b.setName(line);
					break;
				case 2:
					b.setTeam(line);
					break;
				case 3:
					b.setBa(stod(line));
					break;
				case 4:
					b.setHr(stoi(line));
					break;
				case 5:
					b.setRbi(stoi(line));
					break;
				}
				break;
			case 'c':
				switch (iterator) {
				case 0:
					c.setId(stoi(line));
					break;
				case 1:
					c.setName(line);
					break;
				case 2:
					c.setTeam(line);
					break;
				case 3:
					c.setBa(stod(line));
					break;
				case 4:
					c.setHr(stoi(line));
					break;
				case 5:
					c.setRbi(stoi(line));
					break;
				}
				break;
			case 'd':
				switch (iterator) {
				case 0:
					d.setId(stoi(line));
					break;
				case 1:
					d.setName(line);
					break;
				case 2:
					d.setTeam(line);
					break;
				case 3:
					d.setBa(stod(line));
					break;
				case 4:
					d.setHr(stoi(line));
					break;
				case 5:
					d.setRbi(stoi(line));
					break;
				}
				break;
			case 'e':
				switch (iterator) {
				case 0:
					e.setId(stoi(line));
					break;
				case 1:
					e.setName(line);
					break;
				case 2:
					e.setTeam(line);
					break;
				case 3:
					e.setBa(stod(line));
					break;
				case 4:
					e.setHr(stoi(line));
					break;
				case 5:
					e.setRbi(stoi(line));
					break;
				}
				break;
			case 'f':
				switch (iterator) {
				case 0:
					f.setId(stoi(line));
					break;
				case 1:
					f.setName(line);
					break;
				case 2:
					f.setTeam(line);
					break;
				case 3:
					f.setBa(stod(line));
					break;
				case 4:
					f.setHr(stoi(line));
					break;
				case 5:
					f.setRbi(stoi(line));
					break;
				}
				break;
			case 'g':
				switch (iterator) {
				case 0:
					g.setId(stoi(line));
					break;
				case 1:
					g.setName(line);
					break;
				case 2:
					g.setTeam(line);
					break;
				case 3:
					g.setBa(stod(line));
					break;
				case 4:
					g.setHr(stoi(line));
					break;
				case 5:
					g.setRbi(stoi(line));
					break;
				}
				break;
			case 'h':
				switch (iterator) {
				case 0:
					h.setId(stoi(line));
					break;
				case 1:
					h.setName(line);
					break;
				case 2:
					h.setTeam(line);
					break;
				case 3:
					h.setBa(stod(line));
					break;
				case 4:
					h.setHr(stoi(line));
					break;
				case 5:
					h.setRbi(stoi(line));
					break;
				}
				break;
			case 'i':
				switch (iterator) {
				case 0:
					i.setId(stoi(line));
					break;
				case 1:
					i.setName(line);
					break;
				case 2:
					i.setTeam(line);
					break;
				case 3:
					i.setBa(stod(line));
					break;
				case 4:
					i.setHr(stoi(line));
					break;
				case 5:
					i.setRbi(stoi(line));
					break;
				}
				break;
			case 'j':
				switch (iterator) {
				case 0:
					j.setId(stoi(line));
					break;
				case 1:
					j.setName(line);
					break;
				case 2:
					j.setTeam(line);
					break;
				case 3:
					j.setBa(stod(line));
					break;
				case 4:
					j.setHr(stoi(line));
					break;
				case 5:
					j.setRbi(stoi(line));
					break;
				}
				break;
			}

			if (iterator == 5) {
				cur++;
				iterator = 0;
			}
			else if (iterator < 5) {
				iterator++;
			}
			else {
				cout << "Error " << cur << " " << iterator << '\n';
			}
		}
		inFile.close();
	}
	else {
		cout << "Unable to open file\n";
	}

	bool running = true;
	do {
		system("cls");
		string ui;
		cout << "Enter the Number of the Player Below to See Their Statistics\n0: " << a.getName() << "\n1: " << b.getName() << "\n2: " << c.getName() << "\n3: " << d.getName() << "\n4: " << e.getName() << "\n5: " << f.getName() << "\n6: " << g.getName() << "\n7: " << h.getName() << "\n8: " << i.getName() << "\n9: " << j.getName() << "\n10 : All Players\n11 : Pick a Team\n12 : Update Statistics\nEnter Q to Exit the Program\n";
		cin >> ui;

		try {
			int input = stoi(ui);
			switch (input) {
				case 0:
					a.print();
					system("pause");
					break;
				case 1:
					b.print();
					system("pause");
					break;
				case 2:
					c.print();
					system("pause");
					break;
				case 3:
					d.print();
					system("pause");
					break;
				case 4:
					e.print();
					system("pause");
					break;
				case 5:
					f.print();
					system("pause");
					break;
				case 6:
					g.print();
					system("pause");
					break;
				case 7:
					h.print();
					system("pause");
					break;
				case 8:
					i.print();
					system("pause");
					break;
				case 9:
					j.print();
					system("pause");
					break;
				case 10:
					a.print();
					b.print();
					c.print();
					d.print();
					e.print();
					f.print();
					g.print();
					h.print();
					i.print();
					j.print();
					system("pause");
					break;
				case 11:
					bool invalid;
					do {
						invalid = true;
						string in;
						cout << "Enter a Team Name (Mets, Yankees, Brewers, Diamondbacks, Pirates, Rockies, Astros)\n";
						cin >> in;

						if (in == "Mets") {
							invalid = false;
							a.print();
							g.print();
							system("pause");
						}
						else if (in == "Yankees") {
							b.print();
							invalid = false;
							system("pause");
						}
						else if (in == "Brewers") {
							c.print();
							invalid = false;
							system("pause");
						}
						else if (in == "Diamondbacks") {
							d.print();
							invalid = false;
							system("pause");
						}
						else if (in == "Pirates") {
							e.print();
							j.print();
							invalid = false;
							system("pause");
						}
						else if (in == "Rockies") {
							f.print();
							h.print();
							invalid = false;
							system("pause");
						}
						else if (in == "Astros") {
							i.print();
							invalid = false;
							system("pause");
						}
						else {
							cout << "Error Team Not Found\n";
						}
					} while (invalid);
					break;
				case 12:
					int num;
					cout << "Select a Player's Statistics to Update\n";
					cin >> num;

					
					if (num == 0) {
						int choice;
						a.print();
						cout << "Select a Statistic to Update\n0: Player Name\n1: Player Team\n2: Batting Average\n3: Homeruns\n4: RBI (Runs Batted In)\n";
						cin >> choice;

						if (choice == 0) {
							string name;
							cout << "Enter the Updated Name Value (user underscores for spaces): ";
							cin >> name;
							a.setName(name);
						}
						else if (choice == 1) {
							string team;
							cout << "Enter the Updated Team Value (use underscores for spaces): ";
							cin >> team;
							a.setTeam(team);
						}
						else if (choice == 2) {
							double ba;
							cout << "Enter the Updated Batting Average Value: ";
							cin >> ba;
							a.setBa(ba);
						}
						else if (choice == 3) {
							int hr;
							cout << "Enter the Updated Homerun Value: ";
							cin >> hr;
							a.setHr(hr);
						}
						else if (choice == 4) {
							int rbi;
							cout << "Enter the Updated RBI Value: ";
							cin >> rbi;
							a.setRbi(rbi);
						}
					}
					else if (num == 1) {
						b.print();
						system("pause");
					}
					else if (num == 2) {
						c.print();
						system("pause");
					}
					else if (num == 3) {
						d.print();
						system("pause");
					}
					else if (num == 4) {
						e.print();
						system("pause");
					}
					else if (num == 5) {
						f.print();
						system("pause");
					}
					else if (num == 6) {
						g.print();
						system("pause");
					}
					else if (num == 7) {
						h.print();
						system("pause");
					}
					else if (num == 8) {
						i.print();
						system("pause");
					}else if(num == 9) {
						j.print();
						system("pause");
					}
					system("pause");
					break;
			}
		}
		catch (exception) {
			if (ui == "q" ^ ui == "Q") {
				string fin;
				cout << "Are you sure you would like to exit? (Y/N)";
				cin >> fin;

				if (fin == "Y" || fin == "y") {
					if (output) {
						string outfilename = "out.txt";
						ofstream outfile;
						outfile.open(outfilename);
						outfile << a.print_string() << '\n' << b.print_string() << '\n' << c.print_string() << '\n' << d.print_string() << '\n' << e.print_string() << '\n' << f.print_string() << '\n' << g.print_string() << '\n' << h.print_string() << '\n' << i.print_string() << '\n' << j.print_string() << '\n';
					}
					running = false;
				}
			}
		}
	} while (running);

	return 0;
}
