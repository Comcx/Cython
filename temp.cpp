
#include "stdafx.h"
#include "lainlib.h"
#include "NeuroLayer.h"


array_(2, 1) log_simoid(array_(2, 1) z) {
	return 1 / (1 + (-z).exp());
}

Int main(Int argc, Char *argv[]) {	// main function: the entrance of the program

	Bool lain = true; while (lain) {	// main loop to ensure you can run this again

		Function<Int(Int, Int)> add = [=](Int a, Int b) { return a + b; };
		cout << add(7, 1);

		cout << "\nContinue__1，Exit__0\n" << endl;
		cin.clear();
		(cin >> lain).get();
	}
	system("pause");
	return 0;
}

//===============================================================================================
//Function Blocks