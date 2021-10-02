#include <irrKlang.h>
#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include <assert.h>

class Sound
{
private:
    irrklang::ISoundEngine* engine;
    std::map<const char*, irrklang::ISound*> tracksSounds;
public:
    Sound(std::vector<const char*> tracks, std::vector<const char*> events);
    ~Sound();
    void playEvent(const char* eventFilename);
    void pauseTrack(const char* trackFilename);
    void playTrack(const char* trackFilename, double volume = 1);
    void setTrackMaster(const char* trackFilename, double volume = 1);
    void rollback(const char* trackFilename, const double rbTime);
    bool freeze(const char* trackFilename, const double pauseTime);
};