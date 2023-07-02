#include "console.h"

using json = nlohmann::json;

// accepts id of city in config file
void PrintWeather(size_t city_id, size_t forecast_days) {
    std::ifstream file("..\\config\\config.json");
    json config = json::parse(file);

    std::string city = config["cities"][std::to_string(city_id)];

    json Forecast = GetForecast(city_id);

    std::cout << "Weather Forecast for " << city << std::endl;
    size_t weathercode = Forecast["current_weather"]["weathercode"];
    std::string weather = Weathercode(weathercode);
    std::cout << GetPicture(weather) << std::endl;

    std::cout << weather << std::endl;
    std::cout << "temperature " << Forecast["current_weather"]["temperature"] << " C" << std::endl;
    std::cout << "wind speed " << Forecast["current_weather"]["windspeed"] << " m/s" << std::endl;

    for (int i = 0; i < forecast_days; ++i) {
        tabulate::Table table;
        std::string raw_day = Forecast["hourly"]["time"][HOURS_IN_DAY * i];
        std::string day = raw_day.substr(8, 2);
        std::string raw_month = raw_day.substr(5, 2);
        std::string month = GetMonth(std::stoi(raw_month));
        table.add_row({day + " " + month + " night", day + " " + month + " morning", day + " " + month + " noon", day + " " + month + " evening"});
        table.row(0).format().font_align(tabulate::FontAlign::center);
        table.add_row({"temp", "temp", "temp", "temp"});
        for (int ind = 0; ind < 4; ++ind) {
            table.column(ind).format().width(CELL_WIDTH);
        }

        for (int j = 0; j < 4; ++j) {
            std::string current_weather;
            std::string wc = Weathercode(Forecast["hourly"]["weathercode"][HOURS_IN_DAY * i + 6 * j]);
            current_weather += GetPicture(wc) + "\n";
            current_weather += wc + "\n";
            double temperature = Forecast["hourly"]["temperature_2m"][HOURS_IN_DAY * i + DAY_SPLIT * j];
            current_weather += "temperature " + std::to_string(temperature).substr(0,4) + " C\n";
            double windspeed = Forecast["hourly"]["windspeed_10m"][HOURS_IN_DAY * i + DAY_SPLIT * j];
            current_weather += "wind speed " + std::to_string(windspeed).substr(0,4) + " m/s\n";
            table[1][j].set_text(current_weather);
        }
        std::cout << table << std::endl;
    }
}