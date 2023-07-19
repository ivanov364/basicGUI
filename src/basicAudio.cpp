//
// BasicGUI C++ Library
//
// basicAudio.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicAudio.hpp"

// Also, we tell the compiler to use the namespaces 'irrklang'.
// All classes and functions of irrKlang can be found in the namespace 'irrklang'.
// If you want to use a class of the engine,
// you'll have to type an irrklang:: before the name of the class.
// For example, to use the ISoundEngine, write: irrklang::ISoundEngine. To avoid having
// to put irrklang:: before of the name of every class, we tell the compiler that
// we use that namespaces here.
//using namespace irrklang;

// To be able to use the irrKlang.dll file, we need to link with the irrKlang.lib.
// We could set this option in the project settings, but to make it easy we use
// a pragma comment:
//#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll*/

//static int basic::basicAudio::playAudio(const char PATH, short autoLoop){

	/* https://www.ambiera.com/irrklang/features.html
	 *
	 * Supported File Formats:
	 *
     * RIFF WAVE (*.wav)
	 * Ogg Vorbis (*.ogg)
	 * MPEG-1 Audio Layer 3 (*.mp3)
	 * Free Lossless Audio Codec (*.flac)
	 * Amiga Modules (*.mod)
	 * Impulse Tracker (*.it)
	 * Scream Tracker 3 (*.s3d)
	 * Fast Tracker 2 (*.xm)
	*/

	/* Initializing */
	/*ISoundEngine *SoundEngine = createIrrKlangDevice();

	switch(audioLoop){
		case 0:
			SoundEngine->play2D(PATH, false); // audio loop off
		case 1:
			SoundEngine->play2D(PATH, true); // audio loop on
		default:
			std::cout << "Invalid playAudio parameter!\nCheck documentation.\n";
			glfwTerminate();
			return -1;
	}

	//SoundEngine->drop(); /* deletes SoundEngine from memory 
}*/