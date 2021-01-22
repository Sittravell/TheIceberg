//
//  Ocean.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#ifndef RenderTools_hpp
#define RenderTools_hpp
#include <stdio.h>
#include "DataTypes.hpp"
#include "Bezier.hpp"

void generateCurvedPlane(Coordinate3D startPoint, Coordinate3D cp1, Coordinate3D cp2,Coordinate3D endPoint, float width, float stripNum);

void Bezier12cpPlane(Coordinate3D start,
                     Coordinate3D cp1, Coordinate3D cp2, Coordinate3D cp3,
                     Coordinate3D cp4, Coordinate3D cp5, Coordinate3D cp6,
                     Coordinate3D cp7, Coordinate3D cp8, Coordinate3D cp9,
                     Coordinate3D cp10, Coordinate3D cp11, Coordinate3D cp12,
                     Coordinate3D end);

#endif /* Ocean_hpp */
