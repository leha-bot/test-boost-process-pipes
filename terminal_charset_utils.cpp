/// @file terminal_character_utils.cpp Contains misc utils for adjusting 
///       terminalcharacter set.
#include <codecvt>
#include <iostream>

#include <clocale>

namespace utils {
#ifdef _WIN32
void adjust_terminal_charset()
{
	std::locale loc;
	loc.combine < std::codecvt<char, char, mbstate_t>>(std::locale::classic());
	setlocale(LC_CTYPE, ""); // seems that this call affects to ConsoleCP in Windows MSVC2017

	// Imbuing locales helps with char conventions
	std::cout.imbue(loc);
	std::cerr.imbue(loc);
};
#else
void adjust_terminal_charset() {} // no-op on POSIX.
#endif
}

