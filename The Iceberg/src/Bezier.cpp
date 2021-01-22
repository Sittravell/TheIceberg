//
//  Bezier.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#include "Bezier.hpp"

Coordinate2D bezier2D(Coordinate2D A,  // Start value
                      Coordinate2D B,  // First control value
                      Coordinate2D C,  // Second control value
                      Coordinate2D D,  // Ending value
                      double t)  // Parameter 0 <= t <= 1
{
    Coordinate2D VertexFinal;
    double s = 1 - t;
    VertexFinal.x=(int)(((A.x*s + B.x*t)*s+
                         (B.x*s + C.x*t)*t)*s+
                        ((B.x*s + C.x*t)*s+
                         (C.x*s + D.x*t)*t)*t+0.5);
    VertexFinal.y=(int)(((A.y*s + B.y*t)*s+
                         (B.y*s + C.y*t)*t)*s+
                        ((B.y*s + C.y*t)*s+
                         (C.y*s + D.y*t)*t)*t+0.5);
    return VertexFinal;
}

Coordinate3D bezier3D(Coordinate3D A,  // Start value
                      Coordinate3D B,  // First control value
                      Coordinate3D C,  // Second control value
                      Coordinate3D D,  // Ending value
                      double t)  // Parameter 0 <= t <= 1
{
    Coordinate3D VertexFinal;
    double s = 1 - t;
    VertexFinal.x=(float)(((A.x*s + B.x*t)*s+
                           (B.x*s + C.x*t)*t)*s+
                          ((B.x*s + C.x*t)*s+
                           (C.x*s + D.x*t)*t)*t+0.5);
    VertexFinal.y=(float)(((A.y*s + B.y*t)*s+
                           (B.y*s + C.y*t)*t)*s+
                          ((B.y*s + C.y*t)*s+
                           (C.y*s + D.y*t)*t)*t+0.5);
    VertexFinal.z=(float)(((A.z*s + B.z*t)*s+
                           (B.z*s + C.z*t)*t)*s+
                          ((B.z*s + C.z*t)*s+
                           (C.z*s + D.z*t)*t)*t+0.5);
    return VertexFinal;
}

Coordinate3D BezierMiddlePoint(Coordinate3D A2, Coordinate3D B1){
    Coordinate3D middlePoint;
    middlePoint.x = (A2.x + B1.x)/2;
    middlePoint.y = (A2.y + B1.y)/2;
    middlePoint.z = (A2.z + B1.z)/2;
    return middlePoint;
}
