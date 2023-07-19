//
// BasicGUI C++ Library
//
// basicImage.cpp
//
// Author: Ernest Ivanov
//

// https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/4.1.textures/textures.cpp

#include "../include/basicImage.hpp"

//#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

int basic::basicImage::basicBackgroundImage(const char* PATH, int* WIDTH, int* HEIGHT, short BEHAVIOR, short TEXTURE_FILTERING, short MIPMAPS){

    unsigned int texture;
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

    /* set the texture wrapping/filtering options (on the currently bound texture object) */
    switch(BEHAVIOR){
        case 0:
            {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER); // Y position

            float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f }; // transparent
            glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
            break;
            }
        case 1:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Y position
            break;
        case 2:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); // Y position
            break;
        case 3:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Y position
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }

    switch(TEXTURE_FILTERING){
        case 0:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // SCALING UP IMAGE
            break;
        case 1:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // SCALING DOWN IMAGE
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }

    switch(MIPMAPS){
        case 0:
            /* takes the nearest mipmap to match the pixel size and uses nearest neighbor interpolation for texture sampling. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            break;
        case 1:
            /* takes the nearest mipmap level and samples that level using linear interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;
        case 2:
            /*  linearly interpolates between the two mipmaps that most closely match the size of a pixel and samples the interpolated level via nearest neighbor interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            break;
        case 3:
            /* linearly interpolates between the two closest mipmaps and samples the interpolated level via linear interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }

    int nrChannels;

    unsigned char *data = stbi_load(PATH, WIDTH, HEIGHT, &nrChannels, 0);

    if (data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int64_t)WIDTH, (int64_t)HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        std::cout << "Failed to load texture\n";
    }

    stbi_image_free(data); /* Freeing the image memory */

    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
       -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);



    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


}

int basic::basicImage::basicSetImage(const char* PATH, int WIDTH, int HEIGHT, short BEHAVIOR, short TEXTURE_FILTERING, short MIPMAPS){

    unsigned int texture;
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

    /* set the texture wrapping/filtering options (on the currently bound texture object) */
    switch(BEHAVIOR){
        case 0:
            {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER); // Y position

            float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f }; // transparent
            glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);  
            break;
            }
        case 1:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Y position
            break;
        case 2:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); // Y position
            break;
        case 3:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // X position
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Y position
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }

    switch(TEXTURE_FILTERING){
        case 0:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // SCALING UP IMAGE
            break;
        case 1:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // SCALING DOWN IMAGE
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }

    switch(MIPMAPS){
        case 0:
            /* takes the nearest mipmap to match the pixel size and uses nearest neighbor interpolation for texture sampling. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            break;
        case 1:
            /* takes the nearest mipmap level and samples that level using linear interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;
        case 2:
            /*  linearly interpolates between the two mipmaps that most closely match the size of a pixel and samples the interpolated level via nearest neighbor interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            break;
        case 3:
            /* linearly interpolates between the two closest mipmaps and samples the interpolated level via linear interpolation. */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        default:
            std::cout << "Invalid basicBackgroundImage parameter!\nCheck documentation.\n";
            glfwTerminate();
            return -1;
    }


}