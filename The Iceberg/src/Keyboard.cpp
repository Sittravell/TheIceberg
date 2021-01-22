//
//  Keyboard.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/20/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#include "Keyboard.hpp"

Camera camera;
bool keys[8] = {false, false, false, false,
    false, false, false, false,};

void initializeCamera(float eyePosX, float eyePosY, float eyePosZ, float lookAtX, float lookAtY, float lookAtZ, float rotationalRate, float translateRate){
    camera = Camera(eyePosX, eyePosY, eyePosZ, lookAtX, lookAtY, lookAtZ, rotationalRate, translateRate);
}

Camera getCamera(){
    return camera;
}

void idleFunc(){
    if(keys[0]){
        camera.TranslateFront();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[1]){
        camera.TranslateBack();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[2]){
        camera.TranslateRight();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[3]){
        camera.TranslateLeft();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[4]){
        camera.RotateUp();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[5]){
        camera.RotateDown();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[6]){
        camera.RotateRight();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
    if(keys[7]){
        camera.RotateLeft();
//        camera.PrintCameraInfo();
        glutPostRedisplay();
    }
}

void myKeyboardReleased(unsigned char theKey, int mouseX, int mouseY){
    switch (theKey) {
        case 'w':
            keys[0] = false;
            break;
        case 's':
            keys[1] = false;
            break;
        case 'd':
            keys[2] = false;
            break;
        case 'a':
            keys[3] = false;
            break;
        case 'i':
            keys[4] = false;
            break;
        case 'k':
            keys[5] = false;
            break;
        case 'l':
            keys[6] = false;
            break;
        case 'j':
            keys[7] = false;
            break;
        default:
            break;
    }
}
void myKeyboard(unsigned char theKey, int mouseX, int mouseY){
    switch (theKey) {
        case 'w':
            keys[0] = true;
            break;
        case 's':
            keys[1] = true;
            break;
        case 'd':
            keys[2] = true;
            break;
        case 'a':
            keys[3] = true;
            break;
        case 'i':
            keys[4] = true;
            break;
        case 'k':
            keys[5] = true;
            break;
        case 'l':
            keys[6] = true;
            break;
        case 'j':
            keys[7] = true;
            break;
        default:
            break;
    }
}


