//
//  Camera.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/20/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#include "Camera.hpp"


    
Camera::Camera(float eyePosX, float eyePosY, float eyePosZ, float lookAtX, float lookAtY, float lookAtZ, float rotationalRate, float translateRate){
    this -> eyePosX = eyePosX ;
    this -> eyePosY = eyePosY ;
    this -> eyePosZ = eyePosZ ;
    this -> lookAtX = lookAtX ;
    this -> lookAtY = lookAtY ;
    this -> lookAtZ = lookAtZ ;
    CameraFlipCheck();
    VAngle = (asin((lookAtY - eyePosY)/radius))/(M_PI/180);
    VAngleAdjRotate = cos(VAngle*M_PI/180)*radius;
    HAngle = (acos((lookAtX-eyePosX)/VAngleAdjRotate))/(M_PI/180);
    translateRate =  this -> translateRate ;
    rotationalRate = this -> rotationalRate;    
}

void Camera::CalculateHorizontalPlate(){
    double ops;
    double adj;
    ops = std::sin(HAngle*M_PI/180)*VAngleAdjRotate;
    adj = std::cos(HAngle*M_PI/180)*VAngleAdjRotate;
    lookAtZ = (float)(eyePosZ-ops);
    lookAtX = (float)(eyePosX+adj);
}

void Camera::CalculateVerticalPlate(){
    double ops;
    ops = sin(VAngle*M_PI/180)*radius;
    VAngleAdjRotate = cos(VAngle*M_PI/180)*radius;
    lookAtY = eyePosY+ops;
}

void Camera::CameraFlipCheck(){
    if(abs(VAngle) > 90 && abs(VAngle) <= 270 && !flipToggle){
        upY = -1;
        flipToggle = !flipToggle;
    }else if((abs(VAngle) < 90 || abs(VAngle) >= 270) && flipToggle){
        upY = 1;
        flipToggle = !flipToggle;
    }
}
void Camera::Rotate(){
    CameraFlipCheck();
    AngleValueCorrection(HAngle);
    AngleValueCorrection(VAngle);
    CalculateVerticalPlate();
    CalculateHorizontalPlate();
}

//rotate vertically
void Camera::RotateUp(){
    VAngle += rotationalRate;
    Rotate();
}

void Camera::RotateDown(){
    VAngle -= rotationalRate;
    Rotate();
}

void Camera::RotateLeft(){
    HAngle += rotationalRate;
    Rotate();
}

void Camera::RotateRight(){
    HAngle -= rotationalRate;
    Rotate();
}

void Camera::TranslateFront(){
    VAngleAdj = cos(VAngle*M_PI/180)*translateRate;
    YStraight = sin(VAngle*M_PI/180)*translateRate;
    XStraight = cos(HAngle*M_PI/180)*VAngleAdj;
    ZStraight = sin(HAngle*M_PI/180)*VAngleAdj;
    eyePosX += XStraight;
    eyePosY += YStraight;
    eyePosZ -= ZStraight;
}

void Camera::TranslateBack(){
    VAngleAdj = cos(VAngle*M_PI/180)*translateRate;
    YStraight = sin(VAngle*M_PI/180)*translateRate;
    XStraight = cos(HAngle*M_PI/180)*VAngleAdj;
    ZStraight = sin(HAngle*M_PI/180)*VAngleAdj;
    eyePosX -= XStraight;
    eyePosY -= YStraight;
    eyePosZ += ZStraight;
}

void Camera::TranslateLeft(){
    XSideways = cos((HAngle+90)*M_PI/180)*translateRate;
    ZSideways = sin((HAngle+90)*M_PI/180)*translateRate;
    eyePosX += XSideways;
    eyePosZ -= ZSideways;
}

void Camera::TranslateRight(){
    XSideways = cos((HAngle-90)*M_PI/180)*translateRate;
    ZSideways = sin((HAngle-90)*M_PI/180)*translateRate;
    eyePosX += XSideways;
    eyePosZ -= ZSideways;
}

void Camera::PrintCameraInfo(){
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout<<"VAngle:"<<VAngle<<std::endl;
    std::cout<<"HAngle:"<<HAngle<<std::endl;
    std::cout<<"lookAtX:"<<lookAtX<<std::endl;
    std::cout<<"lookAtY"<<lookAtY<<std::endl;
    std::cout<<"lookAtZ"<<lookAtZ<<std::endl;
    std::cout<<"eyePosX"<<eyePosX<<std::endl;
    std::cout<<"eyePosY"<<eyePosY<<std::endl;
    std::cout<<"eyePosZ"<<eyePosZ<<std::endl;
//    std::cout<<""<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}


