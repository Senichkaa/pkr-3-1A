#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum class Spec { IK, IT, EF, PE, CT };
string Specs[] = { "IK", "IT", "EF", "PE", "CT" };
struct Student
{
	string surname;
	int course;
	Spec spec;
	int inf;
	int phys;
	int math;
};

void Create(Student* arr, const int size);
void Display(Student* arr, const int size);
double PercentOfStudents(Student* arr, const int size);
double GoodStudent(Student* arr, const int size);

int main()
{
	int size;
	cout << "how much students; n = "; cin >> size;
	Student* arr = new Student[size];

	Create(arr, size);
	Display(arr, size);

	cout << "\npercent of students: "<< PercentOfStudents(arr, size);

	double goodstudent = GoodStudent(arr, size);
	delete[] arr;
	return 0;
}

void Create(Student* arr, const int size)
{
	int spec;
	for (int i = 0; i < size; i++)
	{
		cout << "Student No. " << i + 1 << " :\n";

		cin.get();
		cin.sync();

		cout << "	Surname: "; getline(cin, arr[i].surname);
		cout << "	Course: "; cin >> arr[i].course;
		cout << "	Speciality (0 - Computer Science, 1 - Informatics,\n";
		cout << "   2 - Psychology, 3 - Mathematics, 4 - Physics):";
		cin >> spec;
		arr[i].spec = (Spec)spec;
		cout << "	Physics grade: "; cin >> arr[i].phys;
		cout << "	Mathematics grade: "; cin >> arr[i].math;
		cout << "	Informatics grade: "; cin >> arr[i].inf;
		cout << endl;
	}
}

void Display(Student* arr, const int size)
{
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "| No |      Surname      | Course |         Speciality         | Physics | Maths | Informatics |\n";
	cout << "------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << setw(4) << right << i + 1 << "|" << setw(19) << 
			left << arr[i].surname << "|" << setw(8) << right << arr[i].course;
		switch (arr[i].spec)
		{
		case Spec::IK:
			cout << "|" << setw(28) << left << "IK" << "|";
			break;
		case Spec::IT:
			cout << "|" << setw(28) << left << "IT" << "|";
			break;
		case Spec::EF:
			cout << "|" << setw(28) << left << "EF" << "|";
			break;
		case Spec::PE:
			cout << "|" << setw(28) << left << "PE" << "|";
			break;
		case Spec::CT:
			cout << "|" << setw(28) << left << "CT" << "|";
			break;
		}
		cout << setw(9) << right << arr[i].phys << "|" << setw(7) << right << arr[i].math << "|"
			<< setw(13) << right << arr[i].inf << "|\n";
	}
	cout << "------------------------------------------------------------------------------------------------\n\n\n";
}

double PercentOfStudents(Student* arr, const int size)
{
	int found = 0;
	cout << "------------\n";
	cout << "|  percent |\n";
	cout << "------------\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i].phys > 3 && arr[i].math > 3 && arr[i].inf > 3)
		{
			found++;
			cout << "|" << setw(10) << left << arr[i].surname << "|\n";
		}			
	}
	cout << "------------\n";
	return found * 100. / size;
}

		/*cout << "|" << setw(19) << left << list[i].surname << "|" << setw(10)
			<< right << floor(100 * (list[i].informatics + list[i].mathematics + list[i].physics) / 3.) / 100 << "|\n";
			cout << "------------\n";
			cout << "|  percent |\n";
			cout << "------------\n";
			"|" << setw(19) << left
			*/

double GoodStudent(Student* arr, const int size)
{
	int good = 0;
	cout << "\n";
	cout << "\n";
	cout << "\nStudents which have 4 or 5 in Physics:\n";
	cout << "---------------------\n";
	cout << "|      Surname      |\n";
	cout << "---------------------\n";

	for (int i = 0; i < size; i++)
	{
		if (arr[i].phys == 4 || arr[i].phys == 5)
		{
			good++;
			cout << "|" << setw(19) << left << arr[i].surname << "|\n";
		}
	}
	cout << "---------------------\n";
	return good * 100 /size;
}