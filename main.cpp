#include <iostream>
#include <math.h>
#include "Dominios.h"

using namespace std;

int main()
{
    Texto a;
    a.setValor("1234567890- ? ! ");
    cout << a.getValor();

    Codigo m = Codigo();
    m.setValor("12016112273");
    cout << m.getValor();

        // Data::calendario(2, 17);
    Data * data = new Data(23, 04, 03);
    cout << data-> getValor() << endl << endl;
    int MESES[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;
    int incr = 0;
    for (int i = 1; i < 2100; i++) {
        for (int j = 1; j < 13; j++) {
            if (j == 2)
                incr = Data::isLeapYear(i);
            else
                incr = 0;
            for (int k = 1; k <= MESES[j - 1] + incr; k++) {
                dias++;
            }
        }
    }

    int dias_teste = round(365.242189 * 2099);
    cout << "Dias reais: " << dias << endl << "Dias teste: " << dias_teste;
    cout << endl << 365.242189 * 2099;
    return 0;
}
