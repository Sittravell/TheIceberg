//
//  Keyboard.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/20/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#pragma once
#include "Camera.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <GLUT/GLUT.h>

void initializeCamera(float eyePosX, float eyePosY, float eyePosZ, float lookAtX, float lookAtY, float lookAtZ, float rotationalRate = 0.5, float translateRate = 0.1);
Camera getCamera();
void idleFunc();
void myKeyboardReleased(unsigned char theKey, int mouseX, int mouseY);
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);
