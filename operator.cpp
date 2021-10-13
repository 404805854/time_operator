#include "operator.h"

time_t str_to_time_t(const std::string &time_str, const std::string &format) {
  struct tm temp;
  time_t res;
  try {
    if (sscanf(time_str.c_str(), format.c_str(), &(temp.tm_year),
               &(temp.tm_mon), &(temp.tm_mday), &(temp.tm_hour), &(temp.tm_min),
               &(temp.tm_sec), &(temp.tm_wday), &(temp.tm_yday)) <= 0) {
      return 0;
    }
    if (temp.tm_mon < 0 || temp.tm_mon > 11) {
      return 0;
    } else if (temp.tm_mday < 1 || temp.tm_mday > 31) {
      return 0;
    } else if (temp.tm_hour < 0 || temp.tm_hour > 23) {
      return 0;
    } else if (temp.tm_min < 0 || temp.tm_min > 59) {
      return 0;
    } else if (temp.tm_sec < 0 || temp.tm_sec > 59) {
      return 0;
    }

    temp.tm_year -= 1900;
    --temp.tm_mon;
    res = mktime(&temp);
    return res;
  } catch (...) {
    return 0;
  }
}

std::string time_t_to_str(const time_t &time, const std::string &format) {
  char *c_res = new char[format.length() + 5 * 4 + 10];
  struct tm *p;
  try {
    p = std::localtime(&time);
    p->tm_year += 1900;
    p->tm_mon += 1;
    if (sprintf(c_res, format.c_str(), p->tm_year, p->tm_mon, p->tm_mday,
                p->tm_hour, p->tm_min, p->tm_sec) <= 0) {
      return "";
    }
    std::string res = c_res;
    delete[] c_res;
    return res;
  } catch (...) {
    delete[] c_res;
    return "";
  }
}

time_t now_time() {
  time_t t_Now = time(0);
  return mktime(std::localtime(&t_Now));
}

std::string now_time_to_str(const std::string &format) {
  return time_t_to_str(now_time(), format);
}

std::string change_time_format(const std::string &ori_time,
                               const std::string &ori_format,
                               const std::string &target_format) {
  time_t temp = str_to_time_t(ori_time, ori_format);
  if (0 == temp) {
    return "";
  }
  return time_t_to_str(temp, target_format);
}

bool is_illegal_time(const time_t &need_comp_time, const time_t &basic_time) {
  return (need_comp_time >= basic_time);
}

bool is_illegal_time(const std::string &need_comp_time,
                     const std::string &basic_time, const std::string &format) {
  time_t need_comp = str_to_time_t(need_comp_time, format);
  time_t basic = str_to_time_t(basic_time, format);
  if (0 == need_comp || 0 == basic) {
    return true;
  }
  return is_illegal_time(need_comp, basic);
}