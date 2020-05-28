#include "fun.h"

void grade::input()
{
	for (int i = 0; i < N; i++)
	{
		std::cout << "Name? (\"stop\" to stop)" << '\n'; std::cin >> name[i];
		if (name[i] == "stop") break;
		std::cout << "Surname?" << '\n'; std::cin >> surname[i];
		std::cout << "Homework grades? (\"11\" to stop, \"12\" for random)" << '\n'; std::cin >> temp;
		while (temp < 1 || temp > 12)
		{
			std::cout << "Grades must be from 1 to 10" << '\n';
			std::cin >> temp;
		}
		if (temp == 11) hmavg = 0;
		else
		{
			while (temp != 11 && temp != 12)
			{
				hm.push_back(temp);
				std::cin >> temp;
				while (temp < 1 || temp > 12)
				{
					std::cout << "Grades must be from 1 to 10" << '\n';
					std::cin >> temp;
				}
			}
			if (temp == 12)
			{
				int rng = rand() % 10 + 1;
				for (int j = 0; j < rng; j++) hm.push_back(rand() % 10 + 1);
			}
			hmavg = std::accumulate(hm.begin(), hm.end(), 0) / hm.size();
		}
		std::cout << "Exam grade? (\"12\" for random)" << '\n'; std::cin >> egz;
		while (egz < 0 || egz > 12 || egz == 11)
		{
			std::cout << "Grades must be from 1 to 10" << '\n';
			std::cin >> egz;
		}
		if (egz == 12) egz = rand() % 10 + 1;
		avg[i] = hmavg * 0.4 + egz * 0.6;
		std::sort(hm.begin(), hm.end());
		if (hm.size() % 2 != 0) med[i] = hm[hm.size() / 2];
		else med[i] = (hm[(hm.size() / 2) - 1] + hm[hm.size() / 2]) / 2;
		while (hm.size() > 0) hm.pop_back();
		total++;
	}
	std::cout << "1 for average, 0 for median" << '\n'; std::cin >> average;
}
void grade::output()
{
	if (average)
	{
		std::cout << std::left << std::setw(15) << "Name" << std::left << std::setw(15) << "Surname" << std::left << std::setw(15) << "Average" << '\n';
		for (int i = 0; i < total; i++)
		{
			std::cout << std::left << std::setw(15) << name[i] << std::left << std::setw(15) << surname[i] << std::left << std::setw(15) << std::setprecision(2) << avg[i] << '\n';
		}
	}
	else
	{
		std::cout << std::left << std::setw(15) << "Name" << std::left << std::setw(15) << "Surname" << std::left << std::setw(15) << "Median" << '\n';
		for (int i = 0; i < total; i++)
		{
			std::cout << std::left << std::setw(15) << name[i] << std::left << std::setw(15) << surname[i] << std::left << std::setw(15) << std::setprecision(2) << med[i] << '\n';
		}
	}
}
void grade::file_input()
{
	std::string name, surname;
	std::vector<int> gr;
	std::vector<double> average_p, average_np, median_p, median_np;
	std::vector<std::string> name_p, surname_p, name_np, surname_np;
	int temp, egz;
	double avg, med, hmavg = 0;
	std::ifstream fd("stud.txt");
	if (fd.fail())
	{
		std::cout << "Read from file failed";
	}
	fd.ignore(256, '\n');
	while (!fd.eof())
	{
		fd >> name >> surname;
		while (fd.get() != '\n' && fd.get() != -1)
		{
			fd >> temp;
			gr.push_back(temp);
		}
		egz = gr[gr.size() - 1];
		gr.pop_back();
		hmavg = std::accumulate(gr.begin(), gr.end(), 0) / gr.size();
		std::sort(gr.begin(), gr.end());
		if (gr.size() % 2 != 0) med = gr[gr.size() / 2];
		else med = (gr[(gr.size() / 2) - 1] + gr[gr.size() / 2]) / 2;
		avg = hmavg * 0.4 + egz * 0.6;
		if (avg >= 5) {
			name_p.push_back(name);
			surname_p.push_back(surname);
			average_p.push_back(average);
			median_p.push_back(med);
		}
		else {
			name_np.push_back(name);
			surname_np.push_back(surname);
			average_np.push_back(average);
			median_np.push_back(med);
		}
		while (gr.size() > 0) gr.pop_back();
	}
}

void generate::gen(int a)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < a; i++) {
		num = rand() % 10000;
		temp_n = "name" + std::to_string(num);
		num = rand() % 10000;
		temp_s = "surname" + std::to_string(num);
		name.push_back(temp_n);
		surname.push_back(temp_s);
		for (int j = 0; j < 15; j++) {
			temp = rand() % 10;
			grade.push_back(temp);
		}
		eg = rand() % 10;
		hmavg = std::accumulate(grade.begin(), grade.end(), 0) / grade.size();
		temp = hmavg * 0.4 + eg * 0.6;
		average.push_back(temp);
		std::sort(grade.begin(), grade.end());
		if (grade.size() % 2 != 0) temp = grade[grade.size() / 2];
		else temp = (grade[(grade.size() / 2) - 1] + grade[grade.size() / 2]) / 2;
		median.push_back(temp);
		if (average[i] >= 5) {
			name_p.push_back(name[i]);
			surname_p.push_back(surname[i]);
			average_p.push_back(average[i]);
			median_p.push_back(median[i]);
		}
		else {
			name_np.push_back(name[i]);
			surname_np.push_back(surname[i]);
			average_np.push_back(average[i]);
			median_np.push_back(median[i]);
		}
		while (grade.size() > 0) grade.pop_back();
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << a << " studentu sukurimas ir rusiavimas uztruko " << duration << " milisekundziu" << '\n';
}

void generate::out() {
	std::ofstream o("pass.txt");
	std::ofstream u("nopass.txt");
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < name_p.size(); i++) {
		o << std::left << std::setw(15) << name_p[i] << std::left << std::setw(15) << surname_p[i] << std::left << std::setw(15) << std::setprecision(2) << average_p[i] << std::left << std::setw(15) << std::setprecision(2) << median_p[i] << '\n';
	}
	for (int i = 0; i < name_np.size(); i++) {
		u << std::left << std::setw(15) << name_np[i] << std::left << std::setw(15) << surname_np[i] << std::left << std::setw(15) << std::setprecision(2) << average_np[i] << std::left << std::setw(15) << std::setprecision(2) << median_np[i] << '\n';
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "Studentu irasymas i faila uztruko " << duration << " milisekundziu" << '\n';
}