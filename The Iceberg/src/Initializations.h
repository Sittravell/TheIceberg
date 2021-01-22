//
//  Initializations.h
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#ifndef Initializations_h
#define Initializations_h
#include <CoreGraphics/CoreGraphics.h>
CGRect mainMonitor = CGDisplayBounds(CGMainDisplayID());
CGFloat monitorHeight = CGRectGetHeight(mainMonitor);
CGFloat monitorWidth = CGRectGetWidth(mainMonitor);
#include "DataTypes.hpp"
float oceanWidth = 50;
float oceanLength = 200;
float oceanStartX = -25;
float oceanStartY = -5;
float oceanStartZ = 105;
float oceanWaveAmp = 5;
int StripNum = 100;
int stripNumber = 100;
char title[] = "The Iceberg";
GLfloat lightPos[4] = {100.0,100.0,100.0,0.0};
std::vector<Model> Models;

#endif /* Initializations_h */
