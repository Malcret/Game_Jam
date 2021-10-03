#include "sound.hpp"

Sound::Sound(std::vector<const char*> tracks, std::vector<const char*> events) {
    engine = irrklang::createIrrKlangDevice();
    if (!engine) {
        throw "Erreur: impossible d'initaliser IrrKlang";
    }
    for (int i{0}; i<events.size(); i++) { engine->addSoundSourceFromFile(events[i]);}
    for (int i{0}; i<tracks.size(); i++) {
        engine->addSoundSourceFromFile(tracks[i]);
        tracksSounds[tracks[i]] = engine->play2D(engine->getSoundSource(tracks[i]), false, true, true);
        tracksSounds[tracks[i]]->setIsPaused(true);
    }
}

void Sound::playEvent(const char* eventFilename) {
    engine->play2D(engine->getSoundSource(eventFilename), false);
}

void Sound::playTrack(const char* trackFilename, double volume) {
    if (volume > 1 or volume < 0) {volume = 1;}
    assert(tracksSounds[trackFilename]!=nullptr);
    assert(tracksSounds[trackFilename]!=NULL);
    tracksSounds[trackFilename]->setVolume(volume);
    tracksSounds[trackFilename]->setIsPaused(false);
}

void Sound::pauseTrack(const char* trackFilename) {
    tracksSounds[trackFilename]->setIsPaused(!tracksSounds[trackFilename]->getIsPaused());
}

void Sound::setTrackMaster(const char* trackFilename, double volume) {
    if (volume > 1) {volume = 1;}
    if (volume < 0) {volume = 0;}
    tracksSounds[trackFilename]->setVolume(volume);
}

bool Sound::freeze(const char* trackFilename, const double pauseTime) {
    if (pauseTime <= 0) { return false; }
    std::time_t start = std::time(nullptr);
    pauseTrack(trackFilename);
    while (std::time(nullptr)-start < pauseTime) { continue; }
    pauseTrack(trackFilename);
    return true;
}

void Sound::rollback(const char* trackFilename, const double rbTime) {
    tracksSounds[trackFilename]->setPlayPosition(tracksSounds[trackFilename]->getPlayPosition()-rbTime*1000);
}

bool Sound::fadeTracks(const char* trackFilename1, const char* trackFilename2, const double fadeTime) {
    if (fadeTime <= 0) { return false; }
    tracksSounds[trackFilename2]->setVolume(0);
    tracksSounds[trackFilename2]->setPlayPosition(tracksSounds[trackFilename1]->getPlayPosition());
    tracksSounds[trackFilename2]->setIsPaused(false);
    std::chrono::milliseconds ms;
    for (int i{1}; i <= 100; i++) {
        std::cout << i << std::endl;
        tracksSounds[trackFilename2]->setVolume(i/100);
        tracksSounds[trackFilename1]->setVolume(1-(i/100));

        ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        while ( std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) < ms + std::chrono::milliseconds(int(fadeTime*10))) { continue; }
    }
    tracksSounds[trackFilename1]->setIsPaused(true);
    return true;
}


Sound::~Sound() {
    engine->drop();
    for (std::map<const char*, irrklang::ISound*>::iterator iter = tracksSounds.begin(); iter != tracksSounds.end(); iter++) {
        delete iter->second;
    }
}