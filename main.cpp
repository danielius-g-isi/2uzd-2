#include "fun.h"

int main()
{
	srand(time(NULL));
	int choice;
	grade table;
	generate g;
	std::cout << "1 file; 2 manual input; 3 for random generation" << '\n';
	std::cin >> choice;
	while (choice < 1 || choice > 3)
	{
		std::cin >> choice;
	}
	if (choice == 1)
	{
		auto t1 = std::chrono::high_resolution_clock::now();
		table.file_input();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Studentu nuskaitymas ir surusiavimas uztruko " << duration << " milisekundziu" << '\n';
	}
	if (choice == 2)
	{
		table.input();
		table.output();
	}
	if (choice == 3)
	{
		//g.gen(1000);
		//g.out();
		//g.gen(10000);
		//g.out();
		//g.gen(100000);
		//g.out();
		//g.gen(1000000);
		//g.out();
		//g.gen(10000000);
		//g.out();
	}
}