#include <iostream>
#include <fstream>
#include <map>

#include "nlohmann_json/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

void Values(json& tests, map<int, string>& valueId, string att = "values"){
    for(auto& [key, value] : tests.find(att).value().items()){
        if(value.contains("value"))
            value.find("value").value() = valueId[value.find("id").value()];
        if(value.contains("values"))
            Values(value, valueId);
    }
}

int main(){
    ifstream out("values.json");
    json values = json::parse(out);
    out.close();

    map<int, string> valueId;
    for(auto& [key, value] : values.find("values").value().items()){
        valueId[value.find("id").value()] = value.find("value").value();
    }
    
    out.open("tests.json");
    json tests = json::parse(out);
    out.close();

    Values(tests, valueId, "tests");

    std::ofstream file("report.json");
    json report = tests;
    file << report;
    return 0;
}