#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	int x = 15, y = 15; // Explorer’s coordinates
	int x1, y1; // Treasure’s coordinates
	int steps = 0;
	char direction;
	float distance;
	bool treasure = false;

	srand(time(0)); // secretly seed the rand function !
	x1 = rand() % 30 + 1; // set X1 to random between 1 and 30
	y1 = rand() % 30 + 1; // set y1 to random between 1and 30
	distance = sqrt(static_cast<double>((x - x1)*(x - x1) + (y - y1)*(y - y1)));
	cout << "Distance From Treasure: " << distance << endl;

	do {
		cout << "Enter a direction: N S E W\n";
		cin >> direction;
		switch (direction)
		{
		case 'N':
		case 'n':
			y++;
			break;
		case 'S':
		case 's':
			y--;
			break;
		case 'E':
		case 'e':
			x++;
			break;
		case 'W':
		case 'w':
			x--;
			break;
		default:
			cout << "Invalid/Unrecognized Character, Please Try Again.\n";
			break;
		}
		steps++;
		distance = sqrt(static_cast<double>((x - x1)*(x - x1) + (y - y1)*(y - y1)));
		if (distance == 0) {
			treasure = true;
		}

		cout << "Distance From Treasure: " << distance << endl;
	} while (!treasure);

	cout << "Congratulations! You have found the treasure in " << steps << " steps!\n";



	system("pause");
	return 0;
}