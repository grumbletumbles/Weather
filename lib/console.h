#pragma once
#include <cctype>
#include <tabulate/table.hpp>
#include "api.h"
#include "info.h"
#include "pictures.h"

using json = nlohmann::json;

// accepts id of city in config file
void PrintWeather(size_t city_id, size_t forecast_days);

