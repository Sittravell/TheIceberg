//
//  DataTypes.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/22/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#pragma once
#ifndef DataTypes_hpp
#define DataTypes_hpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <GLUT/GLUT.h>


struct Coordinate4D{
    float x;
    float y;
    float z;
    float w;
};

struct Coordinate3D{
    float x;
    float y;
    float z;
};
struct Coordinate2D{
    float x;
    float y;
};
struct Meshes{
    std::vector<Coordinate3D> vertices;
    std::vector<Coordinate3D> normals;
    std::vector<Coordinate2D> uvs;
};
struct Material{
    GLfloat Ns;
    std::vector<float> Ka;
    std::vector<float> Kd;
    std::vector<float> Ks;
    GLfloat Ni;
    GLfloat d;
    GLint illum;
};

struct Model{
    std::vector<Meshes> Meshes;
    std::vector<int> material_id_order;
    int material_start_vertices[100];
    std::vector<Material> modelMaterials;
    float position[3] = {0.0,0.0,-7.0};
    float orientation[4] = {0.0, 0.0, 0.0, 0.0};
};


#endif /* DataTypes_hpp */
