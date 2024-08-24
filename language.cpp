#include "language.h"
extern const struct print_data phrases[2] =
{
    {
        .pr_fl_err = "Ошибка: неопознанный флаг\n",
        .pr_numb = "Введите число\n",
        .pr_menu = "Для решения уравнения вида ax^2+bx+c=0 введите коэффициенты a, b и c:\n"
                   "Для завершения введите EOF\n",
        .pr_no_roots = "Нет корней\n\n",
        .pr_one_root = "Уравнение имеет один корень:\n",
        .pr_two_roots = "Уравнение имеет два корня:\n",
        .pr_inf_roots = "Любое число является решением\n\n",
        .pr_filename = "Введите имя файла с данными для тестирования,"
                       "EOF для выхода из программы или # для перехода к квадратке:\n",
        .pr_help = "Добро пожаловать в квадратку!\n"
                   "Введите ./a.out для запуска программы.\n"
                   "Также доступны следующие флаги:\n"
                   "-h: помощь;\n"
                   "-f: тестирование по данным из файла (нужен файл *.csv для работы).\n"
                   "-e: to switch to english\n\n",
        .pr_file_nopen = "Не удалось открыть файл:",
        .pr_read_err = "Ошибка чтения из файла в строке",
        .pr_test_pass = "Все тесты успешно пройдены!\n\n",
        .pr_test_err = "Ошибка в тесте",
        .pr_exp = "Ожидаемые значения:",
        .pr_res = "Полученные значения:",
        .locale_name = "ru_RU.utf8",
        .inf_or_nan = "Ошибка: при вычислениях возникли INF или NaN"
    },
    {
        .pr_fl_err = "Error: unidentifined flag\n",
        .pr_numb = "Enter a number\n",
        .pr_menu = "To solve the equation of the form ax^2+bx+c=0 enter coefficients a, b и c:\n"
                   "To escape print EOF\n",
        .pr_no_roots = "No roots\n\n",
        .pr_one_root = "The equation has one root:\n",
        .pr_two_roots = "The equation has two roots:\n",
        .pr_inf_roots = "Any number is a root\n\n",
        .pr_filename = "Enter name of the file for testing, EOF to quit or # to go to quadratka\n",
        .pr_help = "Welcome to quadratic equation solver (aka quadratka)!\n"
                   "Enter ./a.out to start the program.\n"
                   "There are also available some flags:\n"
                   "-h: help;\n"
                   "-f: testing using data from the file (requiares a *.csv file).\n"
                   "-e: to switch to english\n\n",
        .pr_file_nopen = "Failed to open the file:",
        .pr_read_err = "Read error in file in line",
        .pr_test_pass = "All tests were succesfully passed!\n\n",
        .pr_test_err = "Error in test",
        .pr_exp = "Expected:",
        .pr_res = "Get:",
        .locale_name = "C",
        .inf_or_nan = "Error: INF or NaN appeared in calculations"
    }
};
