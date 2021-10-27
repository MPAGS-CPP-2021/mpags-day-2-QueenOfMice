#ifndef PROC_CMDLINE_HPP
#define PROC_CMDLINE_HPP

#include <assert.h>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>


std::tuple<bool, bool, std::string, std::string> processCommandLine(const std::vector<std::string> &args);
void provideHelp();
void provideVersion();

#endif 