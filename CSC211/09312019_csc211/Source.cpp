#include <iostream>
#include <string>

using namespace std;

class secretType {
	private:
		string name;
		int age, weight;
		double height;

	public:
		secretType() {
			cout << "Enter Your First Name: ";
			cin >> name;

			cout << "Enter Your Age: ";
			cin >> age;

			cout << "Enter Your Weight (To The Nearest Pound): ";
			cin >> weight;

			cout << "Enter Your Height (In Inches): ";
			cin >> height;

			cout << '\n';
		}

		secretType(string name, int age, int weight, double height) {
			this->name = name;
			this->age = age;
			this->weight = weight;
			this->height = height;
		}

		string weightStatus(bool print) {
			const double bmi = (weight * 703) / pow(height, 2);
			string stat;

			if (bmi < 18.5) {
				stat = "Underweight";
			}
			else if (bmi >= 18.5 && bmi < 25.0) {
				stat = "Normal";
			}
			else if (bmi >= 25 && bmi < 30) {
				stat = "Overweight";
			}
			else if(bmi > 30) {
				stat = "Obese";
			}
			else {
				stat = "Error";
			}
			if (!print) {
				return "You are: " + stat;
			}
			else if (print) {
				return stat;
			}
			else {
				return "Error";
			}
		}

		void print() {
			cout << "Name: " << this->name << '\n' << "Age: " << this->age << '\n' << "Height: " << this->height << "in" << '\n' << "Weight: " << this->weight << "lbs" << '\n' << "Weight Status: " << this->weightStatus(true) << "\n\n";
		}

		// Helper Functions
		string getName() {
			return this->name;
		}
		int getAge() {
			return this->age;
		}
		double getWeight() {
			return this->weight;
		}

};

int main() {
	secretType personOne("Eric", 19, 169, 75);
	secretType personTwo, personThree;

	personOne.print();
	personTwo.print();
	personThree.print();

	system("pause");
	return 0;
}