#pragma once
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <fstream>

using json = nlohmann::json;

struct Coordinates {
    Coordinates(double lat, double lon)
    : latitude(lat)
    , longitude(lon) {}

    double latitude;
    double longitude;
};

Coordinates GetCoordinates(std::string city_name);

json GetForecast(size_t city);