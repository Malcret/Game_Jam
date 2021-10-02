#include <vector>
#include <map>
#include <ctime>
#include "sound.hpp"

int main() {
  std::vector<const char*> events;
  std::vector<const char*> track;
  track.push_back("son.mp3");
  //track.push_back("son2.mp3");
  //events.push_back("son3.mp3");
  Sound son(track, events);
  son.playTrack("son.mp3");
  std::time_t start = std::time(nullptr);
  while (std::time(nullptr)-start < 15) { continue; }
  /*std::time_t start = std::time(nullptr);
  while (std::time(nullptr)-start < 5) { continue; }
  son.pauseTrack("son.mp3");
  while (std::time(nullptr)-start < 5) { continue; }
  son.pauseTrack("son.mp3");
  while (std::time(nullptr)-start < 5) { continue; }
  son.playEvent("son3.mp3");*/
  std::map<const char*, irrklang::ISound*> tracksSounds;
  return 0;
}