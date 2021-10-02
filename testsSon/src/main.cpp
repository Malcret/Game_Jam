#include <irrKlang.h>
#include <iostream>

int main() {
      // start the sound engine with default parameters
  irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

  if (!engine) { return -1; }; // error starting up the engine
  // play some sound stream, looped
  engine->play2D("son.mp3", true);

  char i = 0;
  std::cin >> i; // wait for user to press some key
  engine->drop(); // delete engine
  return 0;
}