#include <iostream>
#include "dominios.h"

using namespace std;

int main() {
    int MESES[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Data data("01/01/00");
    int incr = 0;
    int dias = 0;
    for (int i = 0; i <= 99; i++) {
        for (int j = 1; j < 13; j++) {
            if (j == 2)
                incr = Data::isLeapYear(2000 + i);
            else
                incr = 0;
            for (int k = 1; k <= MESES[j - 1] + incr; k++) {
                dias++;
                try {
                    data.setData(k, j, i);
                }
                catch (invalid_argument e) {
                    cout << "ERRO NA DATA: " << Dominio::formatarInt(k, 2) + "/" + Dominio::formatarInt(j, 2) + "/" + Dominio::formatarInt(i, 2) << " | MENSAGEM DE ERRO: " << e.what();
                    exit(1);
                }
            }
        }
    }

    cout << "Done! (Days passed: " << dias << ")";
    return 0;
}
