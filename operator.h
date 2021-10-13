
#ifndef COMMON_INCLUDE_OPERATOR
#define COMMON_INCLUDE_OPERATOR

#include <cstring>
#include <ctime>
#include <string>

time_t str_to_time_t(const std::string &time_str,
                     const std::string &format = "%d-%02d-%02d %02d:%02d:%02d");

std::string
time_t_to_str(const time_t &time,
              const std::string &format = "%d-%02d-%02d %02d:%02d:%02d");

time_t now_time();

std::string
now_time_to_str(const std::string &format = "%d-%02d-%02d %02d:%02d:%02d");

std::string change_time_format(
    const std::string &ori_time,
    const std::string &ori_format = "%d-%02d-%02d %02d:%02d:%02d",
    const std::string &target_format = "%d-%02d-%02d %02d:%02d:%02d");

bool is_illegal_time(const time_t &need_comp_time, const time_t &basic_time);
bool is_illegal_time(const std::string &need_comp_time,
                     const std::string &basic_time,
                     const std::string &format = "%d-%02d-%02d %02d:%02d:%02d");
#endif