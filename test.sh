#!/bin/bash

test() {
    if [ "$("$1" "$3")" != "$2" ]; then
        echo "wrong answer on $3"
    fi
}

# test_neg() {
#     a=$("$1" "$2")
#     ret=$?
#     if [ "$ret" == 0 ] || [ "$a" == "Segmentation fault" ] ; then 
#         echo "return success or segfault on $2"
#     fi
# }

# позитивные тесты
test ./calculator 12 "10 + 5 - 3"
test ./calculator -4 "(5 + 4) / 3 - 7"
test ./calculator 6  "round(4.5) + 2 - 1"
test ./calculator 2  "floor(3.7) + 1 - 2"
test ./calculator -9 "((8 + 2) / 2) - (3 + 7) - (round(3.3) + floor(1.6))"
test ./calculator 6  "20 / 5 + 2"
test ./calculator 8  "10 + (-5) - (-3)"
test ./calculator 6  "(10 + -5) - (-3) - 2"
test ./calculator 6  "floor(round(4.6)) + round(floor(1.4))"
test ./calculator 3  "round 3.6 + 1 - 2"
test ./calculator 8  "round((5 + 2) + (floor(3.8) + 2)) - (floor(10/3) + 1)"
test ./calculator 6  "floor(round(4.6) + floor(round(3.4))) - round(floor(2.5))"
test ./calculator -3 "floor(5 - (8 + floor(1.2) - 2)) - floor(10/4) / (6 - 4)"
test ./calculator 2  "2"
test ./calculator -2 "-2"
test ./calculator 2  "(2)"
test ./calculator -2 "(-2)"
test ./calculator 3.2 "32e5 / 1e6"


# негативные тесты
./calculator ""
./calculator "()"
./calculator "("
./calculator ")"
./calculator "-"
./calculator "/"
./calculator "round"
./calculator "2 * 2"
