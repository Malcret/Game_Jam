#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <yaml-cpp/yaml.h>
#include <fstream>

typedef struct Settings {
    unsigned int window_width;
    unsigned int window_height;
    unsigned int antialiasing;
};

Settings loadSettings();
void saveSettings(Settings sets);

#endif // SETTINGS_HPP
