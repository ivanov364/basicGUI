# Documentation

<img src="../logo/basicsmall.png">
 
Welcome to the BasicGUI documentation. **BasicGUI is C++ library for Graphical User Interface**. <p>basicGUI let's developers to create <b>fast</b>, <b>easy</b> and <b>light</b> applications.</p>

# Content
> version 0.3

- [About](#About)

- [Install](#Install)

- [How to create window | Example](#How-to-create-window)

- [Window functions](#Window)

- [Background functions](#Background)

- [Input functions](#Input)

- [Text functions](#Text)

- [Image functions](#Image)

- [Audio functions](#Audio)

- [Log system](#Log)

- [Mirrors](#Mirrors)

- [License](#License)

- [Credits](#Credits)

# About
<div id="#About"></div>

**BasicGUI is C++ library for Graphical User Interface**. 

> Newest version - 0.3

# Install
<div id="#Install"></div>
Download repository from [Codeberg](https://codeberg.org/ivanov364/basicGUI) or [Github](https://github.com/ivanov364/basicGUI)

> You can download repository manual in website or with terminal using **git clone** command.

### Automatic installation:
- Open folder using your terminal and execute install.sh . 
	> cd basicGUI
	> chmod +x install.sh
	> ./install.sh

### Manual installation:
- Open folder using your terminal and install dependencies using **conanfile.txt**.
- Execute **CMakeLists.txt**.
	> cd basicGUI
	> conan profile detect --force
	> conan install . --output-folder=build --build=missing
	>  cd build
	> cmake ..
	> sudo make install &&  export LD_LIBRARY_PATH=/usr/local/lib && sudo ldconfig

# Example
<div id="#How-to-create-window"></div>

This example is already in 'examples' folder.

```c++
#include <basic.hpp>
using namespace basic;

int main(){
	basic_INFO("Initiliazing...");
	
	/* Initializing GLFW, setting windowsHints and checking for errors */
    basicWindow::basicSet();

    basic_INFO("Creating window");
    /* Creating window, initialazing glad and checking for errors */
    basicWindow::basicCreate(800, 600, "basicGUI | Example", 0, 1);

    /* Starting loop */
    basic_INFO("Starting loop");

    while(basicWindow::basicRun()){

        /* kill key - ESC*/
        basicWindow::basicInput();

        /* Changing background color */
        /* RED, GREEN, BLUE, ALPHA*/
        basicBackground::basicBackgroundColor("gray");

        basicText::basicRText("basicGUI C++ Library", 48, 180.0f, 300.0f, 1.0f, "black", "freesans", 800, 600);
        basicText::basicRText("Hello, World!", 24, 270.0f, 200.0f, 1.0f, "white", "freesans", 800, 600);

        /* check and call events and swap the buffers */
        basicWindow::basicEvent();
    }
    basic_INFO("Ending loop");

    basicWindow::basicTerminate();
	return 0;
}
```

# Install FreeType2

https://www.linuxfromscratch.org/blfs/view/svn/general/freetype2.html

# Window functions
<div id="#Window"></div>
Window function list:

> non alphabetic order

- [basicSet()](#windowSet)
- [basicCreate()](#window-Create)
- [basicSetMinimumSize()](#window-set-minimum-size)
- [basicSetMaximumSize()](#window-set-maximum-size)
- [basicSetPosition()](#window-set-position)
- [basicSetIcon()](#window-set-icon)
- [basicVisibility()](#window-visibility)
- [basicFocus()](#window-focus)
- [basicEvent()](#callEvent)
- [basicTerminate()](#windowTerminate)
- [windowRun()](#windowRun)

## basicSet()
<div id="#windowSet"></div>
Integer type function to initialize GLFW instructions, windowsHints and check for errors.

> must be included in the first code line, otherwise entire program won't work!

> Look for example in the 'examples' folder.

```c++

    basic::basicWindow::basicSet();

```

### Example:

```c++

    /* Initializing GLFW, setting windowsHints and checking for errors */
    basicSet();

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicCreate()
<div id="#window-Create"></div>
Integer type function to create window, initialize glad and check for errors.

> must be included after **basicSet();** function, otherwise entire program won't work!

```c++

    basic::basicWindow::basicCreate(WIDTH, HEIGHT, TITLE, FULLSCREEN, VSYNC);

```

> FULLSCREEN. 0 -> OFF, 1 -> ON
> [!] FULLSCREEN is experimental. Use at your own risk. [!]

> VSYNC. 0 -> OFF, 1 -> ON

### Example:

```c++

    /* code goes here ... */

    /* Creating window, initialazing glad and checking for errors */
    basicCreate(800, 600, "Hello, World!", 0, 1);

    /* code goes here ... */

    /* Starting loop */
    while(basicRun()){
        /* code goes here ... */
    }

```

## basicSetMinimumSize()
<div id="#window-set-minimum-size"></div>
Void type function to set minimum window size.

```c++

    basic::basicWindow::basicSetMinimumSize(WIDTH, HEIGHT);

```

### Example:

```c++

    /* Set minimum window size */
    basicSetMinimumSize(800, 600);

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicSetMaximumSize()
<div id="#window-set-maximum-size"></div>
Void type function to set maximum window size.

```c++

    basic::basicWindow::basicSetMaximumSize(WIDTH, HEIGHT);

```

### Example:

```c++

    /* Set maximum window size */
    basicSetMaximumSize(1920, 1080);

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicSetPosition()
<div id="#window-set-position"></div>
Void type function to set window position on screen.

> experimental function

```c++

    basic::basicWindow::basicSetPosition(POSITION_X, POSITION_Y);

```

### Example:

```c++

    /* Set window position */
    basicSetPosition(500,500);

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicSetIcon()
<div id="#window-set-icon"></div>
Void type function to set window icon.

> experimental function

```c++

    basic::basicWindow::basicSetIcon(icon_path);

```

### Example:

```c++

    /* Set window icon */
    basicSetIcon(icon_path);

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicVisibility()
<div id="#window-visibility"></div>
Integer type function to set window visibility.

> experimental function

```c++

    basic::basicWindow::basicVisibility(STATUS);

```

> STATUS. 0 - VISIBLE
> STATUS. 1 - HIDDEN

### Example:

```c++

    /* Set window visibility */
    basicVisibility(1);

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicFocus()
<div id="#window-focus"></div>
Void type function to set window focus.

> experimental function

```c++

    basic::basicWindow::basicFocus();

```

### Example:

```c++

    /* Set window focus */
    basicFocus();

    /* code ... */

    /* Starting loop */
    while(basicRun()){
        /* code ...*/
    }

```

## basicEvent()
<div id="#callEvent"></div>
Void type function to call window events.

```c++

    basic::basicWindow::callEvent();

```

### Example:

```c++

    /* code ... */

    /* Starting loop */
    while(basicRun()){

        /* code ...*/

       basicEvent();
    }

```

## basicTerminate()
<div id="#windowTerminate"></div>
Void type function to kill window.

```c++

    basic::basicWindow::basicTerminate();

```

### Example:

```c++

    /* code ... */

    /* Starting loop */
    while(basicRun()){

        /* code ...*/

        basicEvent();
    }
    basicTerminate(); // kill window after loop ends.

```

## windowRun()
<div id="#windowRun"></div>
Boolean type function to check for closed window event.

> must be included in the code, otherwise entire program won't run!

```c++

    basic::basicWindow::windowRun();

```

### Example:

```c++
    /* while windowRun is true, run window. Else terminate it*/
    while(windowRun()){

        /* code runs here */

    }

```

# Background functions
<div id="#Background"></div>
Background function list:

> non alphabetic order

- [basicSetBackgroundColorFloat()](#background-set-color-float)
- [basicSetBackgroundColor()](#background-set-color)

## windowSetBackgroundColorFloat()
<div id="#background-set-color-float"></div>
Void type function to set background color using float values.

```c++

    basic::basicBackground::basicSetBackgroundColorFloat(RED, GREEN, BLUE, ALPHA);

```

### Example:

```c++

     while(basicRun()){

        /* Red color */
        basicSetBackgroundColorFloat(255.0f, 0.0f, 0.0f, 1.0f); 

        /* code goes here */
    }

```

## windowSetBackgroundColor)
<div id="#background-set-color"></div>
Int type function to set background color using string.

```c++

    basic::basicBackground::basicSetBackgroundColor(COLOR);

```

### Example:

```c++

     while(basicRun()){

        /* Gray color */
        basicSetBackgroundColor("gray");

        /* code goes here */
    }

```

# Input functions
<div id="#Input"></div>
Input function list:

> non alphabetic order

- [basicInput()](#input-process)
- [inputCursorMode()](#input-cursor-mode)

## basicInput()
<div id="#input-process"></div>
Integer type function to get keys and kill if "ESC" pressed.

> by default kill key - ESC

```c++

    basic::basicWindow::basicInput();

```

### Example:

```c++

     while(basicRun()){

        /* kill key - ESC*/
        basicInput();

        /* code goes here */
    }

```

## inputCursorMode()
<div id="#input-cursor-mode"></div>
Integer type function to enable mouse cursor.

> not implemented yet.

```c++

    basic::basicInput::inputCursorMode();

```

### Example:

```c++

     while(basicRun()){

        inputCursorMode()

        /* code goes here */
    }

```

# Text functions
<div id="#Text"></div>
Text function list:

> non alphabetic order

- [basicRText()](#basicRTEXT)

## basicRText()
<div id="#basicRTEXT"></div>
Integer type function to render text.

```c++

    basic::basicText::basicRText(TEXT, TEXT_SIZE, x, y, SCALE, COLOR, FONT, WIDTH, HEIGHT);

```

### Example:

```c++

     while(basicRun()){

        basicRText("Hello, World!", 24, 270.0f, 200.0f, 1.0f, "white", "freesans", 800, 600);

        /* code goes here */
    }

```

# Image functions
<div id="#Image"></div>
Image function list:

> non alphabetic order

- [basicBackgroundImage()](#basicBackgroundImage)
- [basicSetImage()](#basicSetImage)

## basicBackgroundImage()
<div id="#basicBackgroundImage"></div>
Integer type function to get set background image.

```c++

    basic::basicImage::basicBackgroundImage(PATH, WIDTH, HEIGHT, BEHAVIOR, TEXTURE_FILTERING, MIPMAPS);

```

### Example:

```c++

     while(basicRun()){

       basicBackgroundImage();

        /* code goes here */
    }

```

## basicSetImage()
<div id="#basicSetImage"></div>
Integer type function to get set image.

```c++

    basic::basicImage::basicSetImage(PATH, WIDTH, HEIGHT, BEHAVIOR, TEXTURE_FILTERING, MIPMAPS);

```

### Example:

```c++

     while(basicRun()){

       basicSetImage();

        /* code goes here */
    }

```

# Audio functions
<div id="#Audio"></div>
Audio function list:

> non alphabetic order

- [basicPlayAudio()](#play-audio)

## basicPlayAudio()
<div id="#play-audio"></div>
Integer type function to play audio.

```c++

    basic::basicAudio::basicPlayAudio(PATH, autoLoop);

```

> autoLoop:  0 - OFF | 1 - ON


### Example:

```c++

     while(basicRun()){

        basicPlayAudio("/home/user/Downloads/music.mp3", 0);

        /* code goes here */
    }

```

# Log system
<div id="#Log"></div>

To enable **logs** in your project include **enableLog()** function.

> include in main function

Log function list:

- [basic_INFO()](#basic_info)
- [basic_WARN()](#basic_warn)
- [basic_ERROR()](#basic_error)
- [basic_TRACE()](#basic_trace)
- [basic_INFO_BOLD()](#basic_bold_info)
- [basic_WARN_BOLD()](#basic_bold_warn)
- [basic_ERROR_BOLD()](#basic_bold_error)
- [basic_TRACE_BOLD()](#basic_bold_trace)


Short example:

```c++
#include "../basic.hpp"

int main(){

    basic_INFO("Project: version 0.1"); /* <------- */

    /* Setting windows info */
    basic::basicWindow::basicSet();

    /* Creating window */
    /* WIDTH, HEIGHT, TITLE, FULLSCREEN, VSYNC */
    basic::basicWindow::basicCreate(800, 600, "Hello, World!", 0, 1);

    /* Changing background color */
    /* RED, GREEN, BLUE, ALPHA*/
    basic::basicBackground::basicSetBackgroundColorFloat(0.2f, 0.3f, 0.3f, 1.0f);

    /* Starting loop */
    basic::basicWindow::basicRun();
    
    return 0;
}
```


# Mirrors
<div id="#Mirrors"></div>

### Main project hosting:
-  [Codeberg](https://codeberg.org/ivanov364/basicGUI).

### Mirrors:
-  [Github](https://github.com/ivanov364/basicGUI).

# License
<div id="#License"></div>

basicGUI library is licensed under **MIT** license.


# Credits
<div id="#Credits"></div>

Thanks to [learnopengl.com](https://learnopengl.com/).