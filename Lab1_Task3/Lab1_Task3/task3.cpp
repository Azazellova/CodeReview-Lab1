//К-ичные числа. Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько 
//имеется чисел из N (1<N<20, K+N<26) разрядов таких, что в их записи не содержится два и 
//более подряд идущих нулей. Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <vector>
//FIX_ME: отсутствует библиотека для setlocale
#include <clocale> 

//FIX_ME: отсутствует библиотека <limits> для проверки входных данных
#include <limits>

//FIX_ME: запрещено глобальное использование using namespace std;
//using namespace std;


int main() {
    int K, N;

    setlocale(LC_ALL, "rus");

    std::cout << "Введите основание K (2 <= K <= 10): ";
    std::cin >> K;

    //FIX_ME: отсутствует проверка на ввод символов
    /*if (K < 2 || K > 10) {
        std::cout << "Некорректные входные данные." << std::endl;
        return 1;
    }*/
    while (true)
    {
        std::cout << "Введите основание K (2 <= K <= 10): ";

        if (!(std::cin >> K))
        {
            std::cout << "Ошибка: введено не число.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if (K < 2 || K > 10)
        {
            std::cout << "Ошибка: K должно быть в диапазоне 2..10\n";
            continue;
        }

        break;
    }

    std::cout << "Введите количество разрядов N (1 < N < 20): ";
    std::cin >> N;

    //FIX_ME: отсутствует проверка на ввод символов
    /*if (K + N >= 26)
    {
        std::cout << "Некорректные входные данные." << std::endl;
        return 1;
    }
    if (N <= 1 || N >= 20)
    {
        std::cout << "Некорректные входные данные." << std::endl;
        return 1;
    }*/

    while (true)
    {
        std::cout << "Введите количество разрядов N (1 < N < 20): ";

        if (!(std::cin >> N))
        {
            std::cout << "Ошибка: введено не число.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if (N <= 1 || N >= 20)
        {
            std::cout << "Ошибка: N должно быть в диапазоне 2..19\n";
            continue;
        }

        if (K + N >= 26)
        {
            std::cout << "Ошибка: должно выполняться условие K + N < 26\n";
            continue;
        }

        break;
    }

    //FIX_ME: неинформативные названия переменных nz, oz, tz
    //int nz, oz, tz, _tz, _oz, _nz;

    int previousTwoZero, previousOneZero, previousNonZero;

    int nonZeroEndingCount = K - 1;
    int oneZeroEndingCount = 1;
    int twoZeroEndingCount = 0;

    //FIX_ME: неправильное использование инкремента в цикле
    //for (int i = 2; i <= N; i++)
    for (int i = 2; i <= N; ++i)
    {
        previousNonZero = nonZeroEndingCount;
        previousOneZero = oneZeroEndingCount;
        previousTwoZero = twoZeroEndingCount;

        nonZeroEndingCount = previousNonZero * (K - 1) + previousOneZero * (K - 1);

        oneZeroEndingCount = previousNonZero;

        twoZeroEndingCount = previousTwoZero * K + previousOneZero;
    }

	//FIX_ME: неинформативное название переменной s
	//double s = nonZeroEndingCount + oneZeroEndingCount;

	//FIX_ME: ответ должен быть явно приводится к нужному типу
    double result = static_cast<double>(nonZeroEndingCount + oneZeroEndingCount);


    std::cout << "Количество подходящих K-ичных чисел: " << result << std::endl;

	//FIX_ME: отсуствует возврат из функции main
	return 0;
}

