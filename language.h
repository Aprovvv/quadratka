/** @file */
#ifndef LANDUAGE_H
#define LANGUAGE_H
/**
 * Структура, которая может содержать все фразы для вывода
 */
struct print_data{
    const char *pr_fl_err;
    const char *pr_numb;
    const char *pr_menu;
    const char *pr_no_roots;
    const char *pr_one_root;
    const char *pr_two_roots;
    const char *pr_inf_roots;
    const char *pr_filename;
    const char *pr_help;
    const char *pr_file_nopen;
    const char *pr_read_err;
    const char *pr_test_pass;
    const char *pr_test_err;
    const char *pr_exp;
    const char *pr_res;
    const char *locale_name;
    const char *inf_or_nan;
};
#endif
