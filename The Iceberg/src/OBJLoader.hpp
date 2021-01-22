//
//  OBJLoader.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/22/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#pragma once
#ifndef OBJLoader_hpp
#define OBJLoader_hpp
#include "tiny_obj_loader.h"
#include "DataTypes.hpp"
#include "Correction.hpp"
Model AdvanceOBJLoader(const char* filename, const char* basepath, float scale,bool triangulate);
#endif /* OBJLoader_hpp */
