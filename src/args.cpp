#include <algorithm>

#include "args.h"

namespace args {
    
    char *get_argvalue_or_null(int argc, char *argv[], const char *arg) {
        char *a = get_arg_or_null(argc, argv, arg);
        return a ? get_argvalue(a) : nullptr;
    }

    char *get_argvalue(char *arg) {
        char *value = nullptr;

        for ( ; *arg; arg++) {
            if (*arg == kArgValueSeparator) {
                value = arg + 1;
                break;
            }
        }

        return value;
    }

    char *get_arg_or_null(int argc, char *argv[], const char *arg) {
        std::string current_arg;
        char *return_arg = nullptr;

        for (int i = 0; i < argc; i++) {
            current_arg = argv[i];
            if (current_arg.find(arg) == kArgStartsFromIdx) {
                return_arg = argv[i];
                break;
            }
        }
        
        return return_arg;
    }

}
