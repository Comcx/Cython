
#include "lainlib.h"
#include "cython.h"



int main(int argc, char *argv[]) {	// main function: the entrance of the program

	string raw_name(""), out_name("");
	if (argc == 1) {
		raw_name = "test.py";
		out_name = "out.py";

		ifstream raw(raw_name);
		ofstream out(out_name);

		out << arrange_by_end(raw);
		raw.close();
		out.close();

		system("python out.py");

	} else {
		for (int i = 1; i < argc; i++) {
			raw_name = argv[i];
			ifstream raw(raw_name);
			ofstream out("out" + num2str(i) + ".py");

			out << arrange_by_end(raw);
			raw.close();
			out.close();
		}
	}
		
	cout << "-> cython finished" << endl;

	system("pause");
	return 0;
}

