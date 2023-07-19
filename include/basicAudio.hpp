//
// BasicGUI C++ Library
//
// basicAudio.hpp
//
// Author: Ernest Ivanov
//

/*
 *  --- https://www.ambiera.com/irrklang/downloads.html
 *
*/ 

#ifndef basicAudio_hpp
#define basicAudio_hpp

    #include <iostream>
    #include <stdio.h>

    //#include <irrKlang.h>
    //#include "irrKlang.h"

    // include console I/O methods (conio.h for windows, our wrapper in linux)
    #if defined(WIN32)
        #include <conio.h>
    #else
        #include "conio.h"
    #endif

    namespace basic{
        class basicAudio{
            public:
                /*static int basicPlayAudio(const char PATH, short autoLoop);

                ~playAudio(){
                    SoundEngine->drop(); /* deletes SoundEngine from memory 
                };*/
        };
    }

#endif // basicAudio_hpp