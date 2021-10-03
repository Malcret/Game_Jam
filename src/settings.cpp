#include "settings.hpp"

Settings loadSettings() {
    YAML::Node config = YAML::LoadFile("settings.yml");
    Settings Sets;
    if (config["window_height"]) { Sets.window_height = config["window_height"].as<int>();}
    if (config["window_width"]) { Sets.window_width = config["window_width"].as<int>();}
    if (config["antialiasing"]) { Sets.antialiasing = config["antialiasing"].as<int>();}
    return Sets;
}

void saveSettings(Settings sets) {
    YAML::Node setsFile = YAML::LoadFile("settings.yml");
    std::ofstream outFile("settings.yml");
    setsFile["window_height"] = sets.window_height;
    setsFile["window_width"] = sets.window_width;
    setsFile["antialiasing"] = sets.antialiasing;
    outFile << setsFile;
    outFile.close();
}
