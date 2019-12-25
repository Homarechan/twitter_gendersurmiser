#ifndef GETDATA_H_
#define GETDATA_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

enum Gender { Male, Female, Other };

typedef struct {
    std::string email;
    std::string twitter_id;
    enum Gender biological_sex;
    enum Gender psychological_gender;
    bool        is_publishable;
} FormData;

std::vector<std::string> split(std::string &input, char delimiter) {
    std::istringstream       stream(input);
    std::string              field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) { result.push_back(field); }
    return result;
}

Gender string_to_gender(std::string gender_str) {
    if (gender_str.compare("男性")) {
        return Male;
    }
    if (gender_str.compare("女性")) {
        return Female;
    }
    return Other;
}

bool srting_to_ispublishable(std::string ispublishable_str) {
    if (ispublishable_str.compare("公開しても良い")) {
        return true;
    }
    return false;
}


std::vector<FormData> parse_csv(std::string filename) {
    std::ifstream            file_stream(filename.c_str());
    std::string              line;
    std::vector<FormData>    result;
    std::vector<std::string> splited_string;

    getline(file_stream, line);  // Ignore first line

    while (std::getline(file_stream, line)) {
        splited_string = split(line, ',');
        result.push_back(
          FormData{splited_string.at(0),
                   splited_string.at(1),
                   string_to_gender(splited_string.at(2)),
                   string_to_gender(splited_string.at(3)),
                   srting_to_ispublishable(splited_string.at(4))});
    }
    return result;
}


#endif  // GETDATA_H_
