<img src="logo/basicsmall.png">

<img src="https://img.shields.io/badge/license-MIT-green.svg">
<h1>[!] Underdevelopment [!]</h1>

 <h1>About</h1>

 <p><b>basicGUI - Basic C++ Library for Graphical User Interface</b></p>
 <p>The purpose of this <a href="https://github.com/ivanov364/basicGUI/">library</a> was to know better OpenGL and understand how the GUI works.</p>

<h1>Documentation</h1>

Click here to see <a href="#">documentation</a>

<h2>Code snippet</h2>
<p><b>Only concept</b></p>

from examples folder

```C++
#include "../basic.hpp"

int main(){
    /* Initializing GLFW, setting windowsHints and checking for errors */
    basic::basicWindow::basicInfoSet();

    /* Creating window, initialazing glad and checking for errors */
    basic::basicWindow::windowCreate(800, 600, "Hello, World!");

    /* Changing background color and gl clearing color buffer*/
    /* float red, float green, float blue, float alpha */
    /* https://pemavirtualhub.wordpress.com/2016/06/20/opengl-color-codes/ */
    basic::basicBackground::windowSetBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);

    /* Starting loop */
    basic::basicRender::run();

    return 0;
}
```

 <h1>How to install</h1>

 ```
git clone https://github.com/ivanov364/basicGUI.git
cd basicGUI
cmake .
make
 ```

 <h2>Requirements</h2>

 <ul>
    <li>cmake</li>
    <li>makefile</li>
    <li>gcc</li>
    <li>Gnu/Linux</li>
    <li>conan</li>
        <ul>
            <li>GLFW</li>
            <li>openGL</li>
        </ul>
    <li>glad | by default included</li>
 </ul>

 <h1>Credits</h1>

 <p>Thanks to <a href="https://learnopengl.com">https://learnopengl.com</a></p>

 <h2>Additional information/links</h2>

<p>Guide to setup openGL: <a href="https://medium.com/geekculture/a-beginners-guide-to-setup-opengl-in-linux-debian-2bfe02ccd1e">https://medium.com/geekculture/a-beginners-guide-to-setup-opengl-in-linux-debian-2bfe02ccd1e</a>.</p>

<p>openGL documentation: <a href="https://docs.gl/">https://docs.gl/</a>.</p>
