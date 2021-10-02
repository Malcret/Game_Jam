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
    if (volume > 1 or volume < 0) {volume = 1;}
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
    tracksSounds[trackFilename]->setPlayPosition(tracksSounds[trackFilename]->getPlayPosition()-rbTime);
}

Sound::~Sound() {
    engine->drop();
    for (std::map<const char*, irrklang::ISound*>::iterator iter = tracksSounds.begin(); iter != tracksSounds.end(); iter++) {
        delete iter->second;
    }
}