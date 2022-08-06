//4. Напишите программу под названием multi_input.cpp, которая предлагает пользователю ввести несколько целых восьмеричных, 
//десятичных и шестнадцатеричных чисел в любом сочетании, используя суффиксы О и Ох; правильно интерпретируйте эти числа и преобразуйте
//их в десятичный вид.Ваша программа должна выводить на экран
//примерно такие результаты :
//Ох43  (шестнадцатеричное) превращается в десятичное 67
//0123  (восьмеричное) в 83
//65    (десятичное) в 65

#include <iostream>

int main()
{
    int a;
    std::cout << "To end the program, enter a non-integer number!" << std::endl<< std::endl
        << "Enter numbers in different formats (hexadecimal, octal and decimal):" << std::endl;

    std::cin.unsetf(std::ios::hex);
    std::cin.unsetf(std::ios::oct);
    std::cin.unsetf(std::ios::dec);

    while (std::cin >> a)
        std::cout << "Your number turns into " << a;

    return 0;
}