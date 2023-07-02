#include "info.h"

std::string Weathercode(size_t weathercode) {
    switch (weathercode) {
        case 0:
        case 1:
            return "clear";
        case 2:
        case 3:
        case 45:
        case 48:
            return "cloudy"; // or fog
        case 51:
        case 53:
        case 56:
        case 61:
        case 63:
        case 66:
        case 80:
        case 81:
            return "drizzle"; // or slight rain or something like that
        case 55:
        case 57:
        case 65:
        case 67:
        case 82:
            return "heavy rain";
        case 71:
        case 73:
        case 85:
            return "slight snow";
        case 75:
        case 77:
        case 86:
            return "heavy snow";
        case 95:
        case 96:
        case 99:
            return "thunderstorm";
        default:
            return "clear";
    }
}

std::string GetPicture(const std::string& condition) {
    if (condition == "clear") {
        return clear;
    }
    if (condition == "cloudy") {
        return cloudy;
    }
    if (condition == "drizzle") {
        return drizzle;
    }
    if (condition == "heavy rain") {
        return rain;
    }
    if (condition == "slight snow") {
        return slight_snow;
    }
    if (condition == "snow") {
        return snow;
    }
    if (condition == "thunderstorm") {
        return thunderstorm;
    }
    return "none";
}

std::string GetMonth(size_t index) {
    switch (index) {
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
        default:
            return "None";
    }
}
