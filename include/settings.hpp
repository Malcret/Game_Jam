#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <yaml-cpp/yaml.h>
#include <fstream>

typedef struct {
    unsigned int window_width;
    unsigned int window_height;
    unsigned int antialiasing;
} settings;

settings loadSettings();
void saveSettings(settings sets);

#endif // SETTINGS_HPP
