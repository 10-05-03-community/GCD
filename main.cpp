// Copyright 2020 Spardoks

#include <iostream>
#include <limits>

int get_number(char name);
int GCD(int a, int b);
void extendedGCD(int a, int b);

/// MAIN ///

int main() {

    int a = 0;
    int b = 0;

    a = get_number('a');
    b = get_number('b');

    std::cout << "GCD(" << a << ", " << b << ") = " << GCD(std::abs(a), std::abs(b));
    std::cout << std::endl;

    std::cout << "ExtendedGCD: " << std::endl;
    extendedGCD(std::abs(a), std::abs(b));

    // pause
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}

/// END_MAIN ///

int get_number(char name) {

    int number = 0;
    bool good_input = false;

    while (!good_input) {
        std::cout << "Input " << name << ": ";
        std::cin >> number;
        if (std::cin.fail() || (std::cin.peek() != '\n')) {
            std::cin.clear();
            good_input = false;
            std::cout << "Bad_value. It should be integer. Try again!" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            good_input = true;
        }
    }
    return number;
}

int GCD(int a, int b) {
    if (a * b == 0) {
        return a + b;
    } else {
        return GCD(b, a % b);
    }
}

void extendedGCD(int a, int b) {

    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    std::cout << "i\t x\t y\t r\t q\t" << std::endl;
    std::cout << "0\t 1\t 0\t " << a << "\t ---" << std::endl;

    if (b == 0) {
        std::cout << "1\t 0\t 1\t " << b << std::endl;
        return;
    } else {
        std::cout << "1\t 0\t 1\t " << b << "\t " << (a / b) << std::endl;
    }

    int step = 2;
    int last_x = 1;
    int last_y = 0;
    int x = 0;
    int y = 1;
    int q = a / b;
    int r = b;

    do {

        int new_x = last_x - q * x;
        int new_y = last_y - q * y;
        r = a % b; // a - q * b

        std::cout << step << "\t " << new_x << "\t " << new_y << "\t " << r;

        if (r != 0) {
            q = b / r;
            std::cout << "\t " << q << std::endl;
            ++step;
            last_x = x;
            last_y = y;
            x = new_x;
            y = new_y;
            a = b;
            b = r;
        } else {
            break; // r == 0
        }
    } while (true);

    std::cout << std::endl;
}
