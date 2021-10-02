#include "settings.hpp"


settings loadSettings() {
    YAML::Node config = YAML::LoadFile("settings.yml");
    settings Sets;
    if (config["window_height"]) { Sets.window_height = config["window_height"].as<int>();}
    if (config["window_width"]) { Sets.window_width = config["window_width"].as<int>();}
    if (config["antialiasing"]) { Sets.antialiasing = config["antialiasing"].as<int>();}
    return Sets;
}
