/**@file */
#ifndef FILETESTER_H
#define FILETESTER_H
/**
 * Функция, которая открывает файл (.csv), считывает оттуда данные и тестирует функцию quad_solve
 * \param filename {Имя файла для открытия.}
 */
int filetester(const char* filename);
#define GREEN "\033[92m"
#define RED "\033[91m"
#define STANDART "\033[39m"
#endif
