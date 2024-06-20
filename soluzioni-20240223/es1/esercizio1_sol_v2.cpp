#include <iostream>
#include <fstream>

using namespace std;

double Percentuale(int, int);

int main(int argc, char *argv[])
{

        if (argc != 3)
        {
                cout << "Il numero di parametri inserito non e' corretto!" << endl;
                exit(0);
        }

        fstream fin1, fin2;
        fin1.open(argv[1], ios::in);
        fin2.open(argv[2], ios::in);

        if (!fin1 || !fin2)
        {
                cout << "Attenzione! Non e' stato possibile aprire i file" << endl;
                exit(0);
        }

        double t1, t2;
        int count = 0, tot = 0;

        fin1 >> t1;
        fin2 >> t2;

        while (!fin1.eof())
        {
                if (t1 < t2)
                        count++;
                tot++;
                fin1 >> t1;
                fin2 >> t2;
        }

        if (tot > 0)
                cout << "La percentuale di misurazioni in cui la temperatura del motore1"
                     << endl
                     << "ha superato quella del motore2 e' del "
                     << Percentuale(count, tot) << "%." << endl;
        else
                cout << "Il numero delle misurazioni e' uguale a zero, "
                     << endl
                     << "per cui non posso calcolare la percentuale" << endl;

        fin1.close();
        fin2.close();

        return 0;
}

double Percentuale(int n_volte, int n_misure)
{
        double perc = 0.0;
        perc = (double(n_volte) / double(n_misure)) * 100.0;
        return perc;
}