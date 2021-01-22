//
//  main.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/8/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#include <cmath>
#include "DataTypes.hpp"
#define TINYOBJLOADER_IMPLEMENTATION
#include "Keyboard.hpp"
#include "Correction.hpp"
#include "OBJLoader.hpp"
#include "RenderModel.hpp"
#include "Initializations.h"


void init() {
    initializeCamera(51.3279, -0.102969, -11.3107, -48.4704, -1.84821, -5.20679);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    Model model = AdvanceOBJLoader("myiceberg/myiceberg.obj","myiceberg",1.0f, true);
    Models.push_back(model);
    std::cout<< "Model(s) loaded!" << std::endl;
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getCamera().getEyePosX(), getCamera().getEyePosY(), getCamera().getEyePosZ(), getCamera().getLookAtX(), getCamera().getLookAtY(), getCamera().getLookAtZ(), 0, getCamera().getUpY(), 0);
    renderOBJModels(Models);
    renderOcean(oceanStartX, oceanStartY, oceanStartZ, oceanLength, oceanWidth, oceanWaveAmp);
    glutSwapBuffers();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutIdleFunc(idleFunc);
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutKeyboardFunc(myKeyboard);
    glutKeyboardUpFunc(myKeyboardReleased);
    glutIgnoreKeyRepeat(true);
    init();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
