#include "log.hpp"
#include <iostream>

string_view LOG::level_to_str(LEVEL l){
    switch (l) {
        case HIGH:
            return "HIGH";
        case MEDIUM:
            return "MEDIUM";
        case LOW:
            return "LOW";
        case ERROR:
            return "ERROR";
    }
}
LOG::PRINT::PRINT(const char *m, LEVEL w) : messages(m), warning(w){
    switch(w){
        case HIGH:
            cerr << S_BOLD_RED <<"[" <<level_to_str(warning) << "]" << RESET << ": " << messages << endl;
            break;
        case MEDIUM:
            cout << S_YELLOW <<"[" <<level_to_str(warning) << "]" << RESET << ": " << messages << endl;
            break;
        case LOW:
            cout << S_GREEN <<"[" <<level_to_str(warning) << "]" << RESET << ": " << messages << endl;
            break;
        case ERROR:
            cerr << S_RED <<"[" <<level_to_str(warning) << "]" << RESET << ": " << messages << endl;
            break;
    }
}
