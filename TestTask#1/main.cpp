#include <iostream>

#include "Projectile.h"

int main() {

	std::cout << "Select an action \n1. Start calculation with default parameters \n2. Change default parameters\n";
	int selectedAction;
	std::cin >> selectedAction;
	Projectile projectile;
	switch (selectedAction) {
	case 1:
		projectile.calculate();
		projectile.exportToXls();
		break;
	case 2:
		break;

	default:
		break;
	}
	
	return 0;

}