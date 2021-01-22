//
//  Ocean.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#include "RenderTools.hpp"


void generateCurvedPlane(Coordinate3D startPoint, Coordinate3D cp1, Coordinate3D cp2,Coordinate3D endPoint, float width = 50, float stripNum = 100){
    
    Coordinate3D startPointLeft;
    startPointLeft.x = startPoint.x;
    startPointLeft.y = startPoint.y;
    startPointLeft.z = startPoint.z;
    Coordinate3D startPointRight;
    startPointRight.x = startPoint.x+width;
    startPointRight.y = startPoint.y;
    startPointRight.z = startPoint.z;
    Coordinate3D endPointLeft;
    endPointLeft.x = endPoint.x;
    endPointLeft.y = endPoint.y;
    endPointLeft.z = endPoint.z;
    Coordinate3D endPointRight;
    endPointRight.x = endPoint.x+width;
    endPointRight.y = endPoint.y;
    endPointRight.z = endPoint.z;
    Coordinate3D cp1Left;
    cp1Left.x = cp1.x;
    cp1Left.y = cp1.y;
    cp1Left.z = cp1.z;
    Coordinate3D cp2Left;
    cp2Left.x = cp2.x;
    cp2Left.y = cp2.y;
    cp2Left.z = cp2.z;
    Coordinate3D cp1Right;
    cp1Right.x = cp1.x + width;
    cp1Right.y = cp1.y;
    cp1Right.z = cp1.z;
    Coordinate3D cp2Right;
    cp2Right.x = cp2.x + width;
    cp2Right.y = cp2.y;
    cp2Right.z = cp2.z;
    Coordinate3D Left;
    Coordinate3D Right;
    Coordinate3D tempLeft = bezier3D(startPointLeft, cp1Left, cp2Left, endPointLeft, 0);
    Coordinate3D tempRight = bezier3D(startPointRight, cp1Right, cp2Right, endPointRight, 0);
    
    glBegin(GL_QUADS);
    
    for (int i = 1; i <= stripNum; i++) {
        double t = (1.0f*i)/stripNum;
        glVertex3f(tempLeft.x, tempLeft.y, tempLeft.z);
        glVertex3f(tempRight.x, tempRight.y, tempRight.z);
        Left = bezier3D(startPointLeft, cp1Left, cp2Left, endPointLeft, t);
        Right = bezier3D(startPointRight, cp1Right, cp2Right, endPointRight, t);
        glVertex3f(Right.x, Right.y, Right.z);
        glVertex3f(Left.x, Left.y, Left.z);
        tempLeft = Left;
        tempRight = Right;
    }
    glEnd();
}



void Bezier12cpPlane(Coordinate3D start,
                Coordinate3D cp1, Coordinate3D cp2, Coordinate3D cp3,
                Coordinate3D cp4, Coordinate3D cp5, Coordinate3D cp6,
                Coordinate3D cp7, Coordinate3D cp8, Coordinate3D cp9,
                Coordinate3D cp10, Coordinate3D cp11, Coordinate3D cp12,
                Coordinate3D end){
    Coordinate3D mid1;
    Coordinate3D mid2;
    Coordinate3D mid3;
    Coordinate3D mid4;
    Coordinate3D mid5;
    mid1 = BezierMiddlePoint(cp2, cp3);
    mid2 = BezierMiddlePoint(cp4, cp5);
    mid3 = BezierMiddlePoint(cp6, cp7);
    mid4 = BezierMiddlePoint(cp8, cp9);
    mid5 = BezierMiddlePoint(cp10, cp11);
    generateCurvedPlane(start, cp1, cp2, mid1);
    generateCurvedPlane(mid1, cp3, cp4, mid2);
    generateCurvedPlane(mid2, cp5, cp6, mid3);
    generateCurvedPlane(mid3, cp7, cp8, mid4);
    generateCurvedPlane(mid4, cp9, cp10, mid5);
    generateCurvedPlane(mid5, cp11, cp12, end);
    
}

