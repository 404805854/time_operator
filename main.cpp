#include "operator.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string now = time_t_to_str(now_time());
  std::vector<std::string> compare_times = {"2021-10-12",
                                            "2021-10-12 15:50:20",
                                            "2021-10-12 5:50:20",
                                            "2021-10-12 55:50:20",
                                            "2021/10/12 05:50:20",
                                            "2021/10/12 15:50:20",
                                            "2021-10-12-05:50:20",
                                            "2021-10-12-15:50:20",
                                            "2021-10-12T05:50:20",
                                            "2021-10-12T15:50:20",
                                            "2021-10-12 05:50:20.000",
                                            "2021-10-12 15:50:20.000",
                                            "2021-10-12T05:50:20.000",
                                            "2021-10-12T15:50:20.000",
                                            "2021-10-12 05:50:20.000+07",
                                            "2021-10-12 15:50:20.000+07",
                                            "2021-10-12T05:50:20.000+07",
                                            "2021-10-12T15:50:20.000+07"};
  for (size_t i = 0; i < compare_times.size(); ++i) {
    std::cout << "compare now(" << now << ") with " << compare_times[i]
              << std::endl;
    std::cout << "result is : " << is_illegal_time(now, compare_times[i])
              << std::endl;
  }

  std::cout << "now to string : " << now_time_to_str() << std::endl;
  std::cout << "change 2021-09-29T14:33:08.68001161+08:00 format : "
            << change_time_format("2021-09-29T14:33:08.68001161+08:00",
                                  "%d-%d-%dT%d:%d:%d")
            << std::endl;

  return 0;
}