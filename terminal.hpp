#ifndef UTILS_TERMINAL_H_
#define UTILS_TERMINAL_H_


namespace utils {

/// @brief Setup terminal charset on some OSes to avoid "crocozyabres"
///        in terminal window.
void adjust_terminal_charset();
}

#endif