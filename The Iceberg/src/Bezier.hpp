//
//  Bezier.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#ifndef Bezier_hpp
#define Bezier_hpp

#include <stdio.h>
#include "DataTypes.hpp"

Coordinate2D bezier2D(Coordinate2D A,  // Start value
                      Coordinate2D B,  // First control value
                      Coordinate2D C,  // Second control value
                      Coordinate2D D,  // Ending value
                      double t);

Coordinate3D bezier3D(Coordinate3D A,  // Start value
                      Coordinate3D B,  // First control value
                      Coordinate3D C,  // Second control value
                      Coordinate3D D,  // Ending value
                      double t);  // Parameter 0 <= t <= 1

Coordinate3D BezierMiddlePoint(Coordinate3D A2, Coordinate3D B1);
#endif /* Bezier_hpp */
