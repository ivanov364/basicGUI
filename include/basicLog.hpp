//
// BasicGUI C++ Library
//
// basicLog.hpp
//
// Author: Ernest Ivanov
//

#ifndef basicLog_hpp
#define basicLog_hpp

    #include <stdio.h>
    #include <iostream>

    #include <chrono>
    #include <ctime>
    #include <iomanip>
    #include <format>

    /*
        https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
    */
    #define GCC_VERSION (__GNUC__ * 10000 \
                     + __GNUC_MINOR__ * 100 \
                     + __GNUC_PATCHLEVEL__)
    

    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    const auto timeDate = std::put_time(std::localtime(&t_c), "[%T] ");

    const auto YELLOW = "\e[0;33m";        // std::string
    const auto YELLOW_BOLD = "\e[1;33m";   // std::string

    const auto RED = "\e[0;31m";           // std::string
    const auto RED_BOLD = "\e[1;31m";      // std::string

    const auto GREEN = "\e[0;32m";         // std::string
    const auto GREEN_BOLD = "\e[1;32m";    // std::string

    const auto BLUE = "\e[0;34m";          // std::string
    const auto BLUE_BOLD = "\e[1;34m";     // std::string

    const auto CLEAR = "\e[0m";            // std::string


    /*
        Checking C++ version.
        Checking GCC compiler version.

        If it's higher than 13.0.0 we use C++20 approach.
        If it's lower or we use different compiler we use old approach.
    */

    #if __cplusplus >= 202002L
        #if GCC_VERSION >= 130000
            #define basic_INFO(...)                std::cout << timeDate << std::format("{} {} {}\n", GREEN, __VA_ARGS__, CLEAR);
            #define basic_WARN(...)                std::cout << timeDate << std::format("{} {} {}\n", YELLOW, __VA_ARGS__, CLEAR);
            #define basic_ERROR(...)               std::cout << timeDate << std::format("{} {} {}\n", RED,  __VA_ARGS__, CLEAR);
            #define basic_TRACE(...)               std::cout << timeDate << std::format("{} {} {}\n", BLUE, __VA_ARGS__, CLEAR);

            #define basic_INFO_BOLD(...)           std::cout << timeDate << std::format("{} {} {}\n", GREEN_BOLD, __VA_ARGS__, CLEAR);
            #define basic_WARN_BOLD(...)           std::cout << timeDate << std::format("{} {} {}\n", YELLOW_BOLD, __VA_ARGS__, CLEAR);
            #define basic_ERROR_BOLD(...)          std::cout << timeDate << std::format("{} {} {}\n", RED_BOLD, __VA_ARGS__, CLEAR);
            #define basic_TRACE_BOLD(...)          std::cout << timeDate << std::format("{} {} {}\n", BLUE_BOLD, __VA_ARGS__, CLEAR);
        #else
            #error Error with GCC_VERSION macro
        #endif
    #else
        #define basic_INFO(...)                std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << GREEN << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_WARN(...)                std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << YELLOW << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_ERROR(...)               std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << RED << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_TRACE(...)               std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << BLUE << (__VA_ARGS__) << CLEAR << std::endl;

        #define basic_INFO_BOLD(...)           std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << GREEN_BOLD << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_WARN_BOLD(...)           std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << YELLOW_BOLD << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_ERROR_BOLD(...)          std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << RED_BOLD << (__VA_ARGS__) << CLEAR << std::endl;
        #define basic_TRACE_BOLD(...)          std::cout << std::put_time(std::localtime(&t_c), "[%T] ") << BLUE_BOLD << (__VA_ARGS__) << CLEAR << std::endl;
    #endif
#endif // basicLog_hpp