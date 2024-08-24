/**@file */
#ifndef FLAG_H
#define FLAG_H
/**
 * функция, которая анализирует аргументы командной строки
 * в ней считается, что аргумент - это строка из двух символов, первый из которых - '-'
 * \param flag {обрабатываемые аргумент командной строки (arg_v[i]).}
 * \param all_flags {строка содержащая все возможные флаги (например, "hf" для функции с флагами -h и -f).}
 * \param size {длина строки all_flags.}
 */
int analyse_flag(const char* flag, const char* opts, size_t size);
#endif
