#include "api.h"

Coordinates GetCoordinates(std::string city_name) {
    size_t pos;
    while ((pos = city_name.find(' ')) != std::string::npos) {
        city_name = city_name.substr(0, pos) + "%20" + city_name.substr(pos + 1);
    }
    cpr::Response response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city?name=" + city_name}
                                    , cpr::Header{{"X-Api-Key", "pdTRmz92xIDsb6q3bNiqfQ==S63SBt8d43h2Enck"}});
    if (response.status_code != 200) {
        throw std::runtime_error("Incorrect city name");
    }
    json res = json::parse(response.text);


    double lat = res[0]["latitude"];
    double lon = res[0]["longitude"];

    return {lat, lon};
}


json GetForecast(size_t city) {
    std::ifstream config_path("..\\config\\config.json");
    json config = json::parse(config_path);
    Coordinates coordinates = GetCoordinates(config["cities"][std::to_string(city)]);

    std::string api_url = "https://api.open-meteo.com/v1/forecast?";
    api_url += "latitude=" + std::to_string(coordinates.latitude);
    api_url += "&longitude=" + std::to_string(coordinates.longitude);
    api_url += "&timezone=auto";
    api_url += "&current_weather=true";
    api_url += "&hourly=temperature_2m,weathercode,rain,snowfall,windspeed_10m&forecast_days=16";

    cpr::Response response = cpr::Get(cpr::Url{api_url});
    if (response.status_code != 200) {
        throw std::runtime_error("cannot get the weather");
    }
    json weather = json::parse(response.text);
    return weather;
}
