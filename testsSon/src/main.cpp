#include <vector>
#include <map>
#include <ctime>
#include "sound.hpp"

int main() {
  std::vector<const char*> events;
  std::vector<const char*> track;
  track.push_back("son.mp3");
  track.push_back("son2.mp3");
  events.push_back("son3.mp3");
  Sound son(track, events);
  son.playTrack("son.mp3");
  std::time_t start = std::time(nullptr);
  while (std::time(nullptr)-start < 15) { continue; }
  son.rollback("son.mp3", 3000);
  son.setTrackMaster("son.mp3", 0.2);
  start = std::time(nullptr);
  while (std::time(nullptr)-start < 5) { continue; }
  son.freeze("son.mp3", 2);
  son.playEvent("son3.mp3");
  start = std::time(nullptr);
  while (std::time(nullptr)-start < 3) { continue; }
  return 0;
}
