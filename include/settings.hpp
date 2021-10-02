#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <yaml-cpp/yaml.h>

typedef struct {
    unsigned int window_width;
    unsigned int window_height;
    unsigned int antialiasing;
} settings;

settings loadSettings();

#endif // SETTINGS_HPP
