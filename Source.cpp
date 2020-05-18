#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    while (true)
    {
        setlocale(LC_ALL, "ukr");
        cout << "Показати данi - натиснiть 1" << endl;
        cout << "Записати данi - натиснiть 2" << endl;
        cout << "Вихiд - натиснiть 3" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string name;
            string address;
            int cost;
            int year;
            ifstream infile;
            infile.open("File.txt");
            if (!infile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            cout << setw(9) << "Iмя" << setw(10) << "Адреса" << setw(13) << "Вартiсть" << setw(8) << "Рiк" << endl;
            while (!infile.eof())
            {
                infile >> name;
                infile >> address;
                infile >> cost;
                infile >> year;

                if (!infile.eof())
                {
                    cout.width(9);
                    cout << name;
                    cout.width(10);
                    cout << address;
                    cout.width(12);
                    cout << cost;
                    cout.width(9);
                    cout << year;
                    cout << endl;
                }
            }
            infile.close();
        }
        if (choice == 2)
        {

            string name;
            string address;
            int cost;
            int year;
            cout << "Iмя: ";
            cin >> name;
            cout << "Адреса: ";
            cin >> address;
            cout << "Вартiсть: ";
            cin >> cost;
            cout << "Рiк: ";
            cin >> year;

            fstream outfile("File.txt", ios::app);
            if (!outfile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            outfile.setf(ios::left);
            outfile.width(9);
            outfile << name << ' ';
            outfile.width(9);
            outfile << address << ' ';
            outfile.width(9);
            outfile << cost << ' ';
            outfile.width(9);
            outfile << year << endl;
            outfile.close();
        }

        if (choice == 3)
        {
            break;
        }
    }
    system("pause");
}
