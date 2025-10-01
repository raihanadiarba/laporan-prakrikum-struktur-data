#include <iostream>

using namespace std;

void kuadrat(int &ongko)
{
    ongko = ongko * ongko;
}

int main()
{
    int nilai = 5;
    cout << "Nilai awal: " << nilai << endl;
    kuadrat(nilai);
    cout << "Nilai setelah dikuadratkan: " << nilai << endl;

    return 0;
}