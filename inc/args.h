#pragma once

namespace args {
    static constexpr char kArgValueSeparator = '=';
    static constexpr size_t kArgStartsFromIdx = 0;

    char *get_arg_or_null(int argc, char *argv[], const char *arg);
    char *get_argvalue_or_null(int argc, char *argv[], const char *arg);
    char *get_argvalue(char *arg);
}