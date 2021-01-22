//
//  RenderObjects.hpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#ifndef RenderModel_hpp
#define RenderModel_hpp

#include <stdio.h>
#include "RenderTools.hpp"
#include "Correction.hpp"
void renderOcean(float startX, float startY, float startZ, float length, float width, float waveAmp);
void renderOBJModels(std::vector<Model> Models);

#endif /* RenderObjects_hpp */
