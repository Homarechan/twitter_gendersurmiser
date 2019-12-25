#include "getdata.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main(int argc, char const *argv[]) {
    std::vector<FormData> result = parse_csv("../form.csv");
    for (FormData data: result) {
        std::cout << data.email << std::endl
                  << data.twitter_id << std::endl
                  << data.biological_sex << std::endl
                  << data.psychological_gender << std::endl
                  << data.is_publishable << std::endl;
    }
    return 0;
}
