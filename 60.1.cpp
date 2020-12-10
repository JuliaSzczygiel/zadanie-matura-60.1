#include <iostream>
#include <fstream>

using namespace std;

class files {
   ifstream fileIn;
   ofstream fileOut;
   int ostatnia, przedostatnia, licznik=0, liczba;
  public:
   files(); //otwarcie plików obu
   ~files();
   void loop();
};

files::files()
{
   fileIn.open("c:\\liczby.txt");
   fileOut.open("c:\\wynik.txt");

    if (!fileIn.good())
     cerr << "Error fileIn not exists!!!!\n";
    if (!fileOut.good())
     cerr << "Error cannot create fileOut!!!\n";
}

files::~files()
{
   fileIn.close();
   fileOut.close();
}

void files::loop()
{

        for(int i=0; i<200; i++)
        {
            fileIn >> liczba;
            if (liczba<1000)
            {   
                przedostatnia = ostatnia;
                ostatnia = liczba;
                licznik++;
            }
        }

    cout << "Mniejszych od 1000: " << licznik << \n;
    cout << "Dwie ostatnie: " << przedostatnia << " " << ostatnia << \n;
}

main()
{
  files dane;
  dane.loop();
  return 1;
}