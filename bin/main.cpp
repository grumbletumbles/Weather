//#include <iostream>
//#include <winsock2.h>
//#include <windows.h>
//#include <./lib/console.h>
//#include <ctime>
//#include <stdlib.h>
//
//int main() {
//    // starting menu
//    tabulate::Table menu;
//    menu.add_row({"Weather Forecast"});
//    menu[0].format().font_align(tabulate::FontAlign::center);
//    std::string info = R"(This application shows you the weather in the cities, the list of cities is in the config.json file.
//Controls:
//"+" -- increase the number of days shown. The maximum is 14 days.
//"-" -- decrease the number of days shown. The minimum is 1 day.
//"n" -- change to the next city.
//"p" -- change to the previous city.
//To get started press space.)";
//    menu.add_row({info});
//    menu.column(0).format().width(102);
//    std::cout << menu << std::endl;
//
//    while (true) {
//        if (GetAsyncKeyState(VK_SPACE)) {
//            break;
//        }
//    }
//    // actual program
//    std::ifstream file("..\\config\\config.json");
//    json config = json::parse(file);
//    int total_cities = config["cities"].size();
//    int current_city = 0;
//    int forecast_days = 7;
//    time_t freq = config["update frequency"];
//    time_t start = time(nullptr);
//    while (true) {
//        // esc -- finished
//        if (GetAsyncKeyState(VK_ESCAPE)) {
//            break;
//        }
//        // add more days and update
//        if (GetAsyncKeyState(PLUS)) {
//            ++forecast_days;
//            // cap at 14
//            if (forecast_days > 14) {
//                forecast_days = 14;
//            }
//            system("CLS");
//            try {
//                PrintWeather(current_city, forecast_days);
//            }
//            catch (...) {
//                std::cout << "Something went wrong, please try again later" << std::endl;
//            }
//        }
//        // remove days and update
//        if (GetAsyncKeyState(MINUS)) {
//            --forecast_days;
//            // cap at 14
//            if (forecast_days < 1) {
//                forecast_days = 1;
//            }
//            system("CLS");
//            try {
//                PrintWeather(current_city, forecast_days);
//            }
//            catch (...) {
//                std::cout << "Something went wrong, please try again later" << std::endl;
//            }
//        }
//
//        // move to the next city
//        if (GetAsyncKeyState(N)) {
//            ++current_city;
//            if (current_city >= total_cities) {
//                current_city -= total_cities;
//            }
//            system("CLS");
//            try {
//                PrintWeather(current_city, forecast_days);
//            }
//            catch (...) {
//                std::cout << "Something went wrong, please try again later" << std::endl;
//            }
//        }
//
//        // move to the previous city
//        if (GetAsyncKeyState(P)) {
//            --current_city;
//            if (current_city < 0) {
//                current_city += total_cities;
//            }
//            system("CLS");
//            try {
//                PrintWeather(current_city, forecast_days);
//            }
//            catch (...) {
//                std::cout << "Something went wrong, please try again later" << std::endl;
//            }
//        }
//
//
//
//        // update the information
//        if (time(nullptr) - start == freq) {
//            system("CLS");
//            try {
//                PrintWeather(current_city, forecast_days);
//            }
//            catch (...) {
//                std::cout << "Something went wrong, please try again later" << std::endl;
//            }
//            start = start + freq;
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <variant>

int main() {
    std::vector<int> vector{1, 2, 3, 239};
    for (int x : vector) {
        std::visit([](int t){std::cout << t << std::endl;}, x);
    }
    return 0;
}