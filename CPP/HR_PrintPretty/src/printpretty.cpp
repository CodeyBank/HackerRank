/*****************************************************************//**
 * \file   printpretty.cpp
 * \brief  Print pretty challenge
 * 
 * \author HP
 * \date   September 2023
 *********************************************************************/


#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;


        int T{}; // Number of test cases
        cin >> T;

        double number[3];
        for (size_t i{}; i < T; i++)
        {
            cin >> number[0] >> number[1] >> number[2];

            // A: strip out decimal and convert first  to hex
            std::cout << std::hex << (int)number[0] << std::endl;

            // B: 2 Decimal places, preceeded with a +/- right justified, left padded  with underscores
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << std::setfill('_') << std::setw(15) << number[1] << std::endl;

            // C: Exactly nine decimal places in scientific notation
            std::cout << std::setprecision(9) << std::scientific << number[2] << std::endl;
        }
    }
    return 0;
}
