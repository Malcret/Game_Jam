#include "settings.hpp"

Settings loadSettings() {
    YAML::Node config = YAML::LoadFile("settings.yml");
    Settings Sets;
    if (config["window_height"]) { Sets.window_height = config["window_height"].as<int>();}
    if (config["window_width"]) { Sets.window_width = config["window_width"].as<int>();}
    if (config["antialiasing"]) { Sets.antialiasing = config["antialiasing"].as<int>();}
    if (config["eventMaster"]) { Sets.antialiasing = config["eventMaster"].as<int>();}
    if (config["musicMaster"]) { Sets.antialiasing = config["musicMaster"].as<int>();}
    return Sets;
}

void saveSettings(Settings sets) {
    YAML::Node setsFile = YAML::LoadFile("settings.yml");
    std::ofstream outFile("settings.yml");
    setsFile["window_height"] = sets.window_height;
    setsFile["window_width"] = sets.window_width;
    setsFile["antialiasing"] = sets.antialiasing;
    setsFile["eventMaster"] = sets.eventMaster;
    setsFile["musicMaster"] = sets.musicMaster;
    outFile << setsFile;
    outFile.close();
}
