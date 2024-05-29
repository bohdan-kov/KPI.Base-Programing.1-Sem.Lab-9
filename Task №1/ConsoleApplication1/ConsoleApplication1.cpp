#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;


void writeF() {
    ofstream fout;


    fout.open("F.txt", ofstream::app);

    if (!fout.is_open())
        cout << "Помилка відкриття файлу!" << endl;
    else
    {
        fout << "\nEtiam ut consequat dui, a tincidunt purus. ";
    }

    fout.close();
}

void readwriteF() {
    ifstream fin;
    ofstream fout;

    fin.open("F.txt");
    fout.open("G.txt", ofstream::app);

    int coutline = 0;

    if (!fin.is_open() || !fout.is_open())
        cout << "Помилка відкриття файлу";
    else
    {
        cout << "Файл відкритий!" << endl << endl;
        string strline, inpline;
        int coutline = 0;

        cout << "Введіть рядок для пошуку в файлі: ";
        cin >> inpline;

        cout << "Знайдено рядки:" << endl << endl;

        while (!fin.eof())
        {
            strline = "";
            getline(fin, strline);

            size_t pos = strline.find(inpline);
            if (pos != string::npos) {
                fout << "\n" << strline;
                cout << strline << endl;
                coutline++;
            }
        }

        fout << "\n\nКількість знайдених рядків: " <<  coutline;
    }

    fin.close();
    fout.close();
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    readwriteF();

    return 0;
}
