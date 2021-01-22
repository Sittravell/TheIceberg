//
//  Correction.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/21/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#include "Correction.hpp"

void AngleValueCorrection(float Angle){
    if(Angle > 359){
        Angle -= 360;
    }else if(Angle < 0){
        Angle += 360;
    }
}

void Color(float r, float g, float b){
    glColor3f(r/255,g/255,b/255);
}

