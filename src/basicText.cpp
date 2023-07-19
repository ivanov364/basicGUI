//
// BasicGUI C++ Library
//
// basicText.cpp
//
// Author: Ernest Ivanov
//

#include "../include/basicText.hpp"

#include "../include/shader.h"

#include <freetype/freetype.h>
#include <ft2build.h>
#include FT_FREETYPE_H

/* Initializing global variable */
static const char* globalFont;

/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2   Size;      // Size of glyph
    glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Horizontal offset to advance to next glyph
};

std::map<GLchar, Character> Characters;
unsigned int VAO, VBO;

// X_TEXT_POSITION, Y_TEXT_POSITION
int basic::basicText::basicRText(std::string TEXT, short TEXT_SIZE, float x, float y, float SCALE, std::string COLOR, std::string FONT, int WIDTH, int HEIGHT){
    //
    //          usr/local/include/text.fs
    static Shader shader("/usr/local/include/text.vs", "/usr/local/include/text.fs");

    // activate corresponding render state
    shader.use();

    std::transform(FONT.begin(), FONT.end(), FONT.begin(), ::tolower);
	if(FONT == "freesansbold"){
        globalFont = "/usr/share/fonts/gnu-free/FreeSansBold.otf";
    }else if(FONT == "freesans"){
        globalFont = "/usr/share/fonts/gnu-free/FreeSans.otf";
    }else if(FONT == "freemono"){
        globalFont = "/usr/share/fonts/gnu-free/FreeMono.otf";
    }else if(FONT == "freeserif"){
        globalFont = "/usr/share/fonts/gnu-free/FreeSerif.otf";
    }else{
        std::cout << "Invalid windowSetFont parameter!\nCheck documentation.\n";
		glfwTerminate();
		return -1;
    }

	// OpenGL state
    // ------------
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // compile and setup the shader
    // ----------------------------
    //Shader shader("text.vs", "text.fs");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(WIDTH), 0.0f, static_cast<float>(HEIGHT));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    /* Freetype */
	FT_Library ft;

	// All functions return a value different than 0 whenever an error occurred
	if (FT_Init_FreeType(&ft))
	{
	    std::cout << "ERROR::FREETYPE: Could not init FreeType Library\n";
	    return -1;
	}

	/* Loads font as face*/
	FT_Face face;
	if (FT_New_Face(ft, globalFont, 0, &face))
	{
	    std::cout << "ERROR::FREETYPE: Failed to load font\n";
	    return -1;
	} else {
        // set size to load glyphs as
        FT_Set_Pixel_Sizes(face, 0, TEXT_SIZE);

        // disable byte-alignment restriction
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        // load first 128 characters of ASCII set
        unsigned char c = 0;
        for (; c < 128; c++)
        {
            // Load character glyph 
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }
            // generate texture
            unsigned int texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );
            // set texture options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // now store character for later use
            Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
            };
            Characters.insert(std::pair<char, Character>(c, character));
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    }

 	// destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
    // configure VAO/VBO for texture quads
    // -----------------------------------
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);   

    std::transform(COLOR.begin(), COLOR.end(), COLOR.begin(), ::tolower);
    if(COLOR == "white"){
        glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 1.0f, 1.0f, 1.0f);
    }else if(COLOR == "black"){
        glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 0.0f, 0.0f, 0.0f);
    }else if(COLOR == "gray"){
	    glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 0.502f, 0.502f, 0.502f);
    }else if(COLOR == "red"){
        glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 1.0f, 0.0f, 0.0f);
    }else if(COLOR == "green"){
        glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 0.0f, 1.0f, 0.0f);
    }else if(COLOR == "blue"){
        glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 0.0f, 0.0f, 1.0f);
    }else{
        std::cout << "Invalid basicRText parameter!\nCheck documentation.\n";
	    glfwTerminate();
	    return -1;
    }

    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    // iterate through all characters
    std::string::const_iterator c;
    for (c = TEXT.begin(); c != TEXT.end(); c++) 
    {
        Character ch = Characters[*c];

        float xpos = x + ch.Bearing.x * SCALE;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * SCALE;

        float w = ch.Size.x * SCALE;
        float h = ch.Size.y * SCALE;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * SCALE; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    return 0;
}