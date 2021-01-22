//
//  Camera.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/20/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#pragma once
#include "Correction.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>
class Camera{
private:
    float eyePosX = 0;
    float eyePosY = 0;
    float eyePosZ = 20;
    float lookAtX = 0;
    float lookAtY = 0;
    float lookAtZ = -100;
    float upY = 1;
    double radius = 100;
    float HAngle = 90;
    float VAngle = 0;
    float translateRate = 0.1;
    float rotationalRate = 0.5;
    bool flipToggle = false;
    double VAngleAdj = cos(VAngle*M_PI/180)*translateRate;
    double YStraight;
    double XStraight;
    double ZStraight;
    double XSideways;
    double ZSideways;
    double VAngleAdjRotate = cos(VAngle*M_PI/180)*radius;
    
    public:
    Camera(){}
    
    Camera(float eyePosX, float eyePosY, float eyePosZ, float lookAtX, float lookAtY, float lookAtZ, float rotationalRate, float translateRate);
    
    void setEyePosX(float eyePosX){this -> eyePosX = eyePosX;}
    
    float getEyePosX(){return eyePosX;}
    
    void setEyePosY(float eyePosY){this -> eyePosY = eyePosY;}
    
    float getEyePosY(){return eyePosY;}
    
    void setEyePosZ(float eyePosZ){this -> eyePosZ = eyePosZ;}
    
    float getEyePosZ(){return eyePosZ;}
    
    float getLookAtX(){return lookAtX;}
    
    void setLookAtX(float lookAtX){this -> lookAtX = lookAtX;}

    void setLookAtY(float lookAtY){this -> lookAtY = lookAtY;}
    
    float getLookAtY(){return lookAtY;}
    
    void setLookAtZ(float lookAtZ){this -> lookAtZ = lookAtZ;}
    
    float getLookAtZ(){return lookAtZ;}
    
    float getUpY(){return upY;}
    
    void setUpY(float upY){this -> upY = upY;}
    
    float getRadius(){return radius;}
    
    void setRadius(float radius){this -> radius = radius;}
    
    float getVAngle(){return VAngle;}

    void setVAngle(float VAngle){this -> VAngle = VAngle;}
    
    float getHAngle(){return HAngle;}
    
    void setHAngle(float HAngle){this -> HAngle = HAngle;}
    
    void CalculateHorizontalPlate();
    
    void CalculateVerticalPlate();
    
    void CameraFlipCheck();
    
    void Rotate();
        
    void RotateUp();
    
    void RotateDown();

    void RotateLeft();

    void RotateRight();
    
    void TranslateFront();
    
    void TranslateBack();
    
    void TranslateLeft();
    
    void TranslateRight();
    
    void PrintCameraInfo();
};
