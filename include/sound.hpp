#include <irrKlang/irrKlang.h>
#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include <assert.h>
#include <chrono>

class Sound
{
private:
    irrklang::ISoundEngine* engine;
    std::map<const char*, irrklang::ISound*> tracksSounds;
    double eventMaster;
    double musicMaster;
public:
    Sound(std::vector<const char*> tracks, std::vector<const char*> events);
    ~Sound();
    bool fadeTracks(const char* trackFilename1, const char* trackFilename2, const double fadeTime);
    void playEvent(const char* eventFilename, double volume = -1);
    void pauseTrack(const char* trackFilename);
    void playTrack(const char* trackFilename, double volume = -1);
    void setMusicMaster(double volume);
    void setEventMaster(double volume);
    int getMusicMaster();
    int getEventMaster();
    void setTrackMaster(const char* trackFilename, double volume);
    void rollback(const char* trackFilename, const double rbTime);
    bool freeze(const char* trackFilename, const double pauseTime);
};