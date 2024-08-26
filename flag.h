/**@file */
#ifndef FLAG_H
#define FLAG_H
/**
 *
 */
int analyze_flag(const struct flag_struct all_flags[], size_t flag_count, const char* argv);

struct flag_struct
{
    char short_flag;
    const char* long_flag;
};
#endif
