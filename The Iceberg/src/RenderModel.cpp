//
//  RenderObjects.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/23/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//

#include "RenderModel.hpp"

void renderOcean(float startX, float startY, float startZ, float length = 200, float width = 50, float waveAmp = 5){
    GLfloat diffuse[4] = {0.417064, 0.640000, 0.640000, 0.0};
    GLfloat specular[4] = {0.290737, 0.500000, 0.500000, 0.0};
    GLfloat ambient[4] = {1.000000, 1.000000, 1.000000, 0.0};
    GLfloat Ns = 96.078431;
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &Ns);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glDisable(GL_CULL_FACE);
    
    Coordinate3D startPoint;
    startPoint.x = startX;
    startPoint.y = startY;
    startPoint.z = startZ;
    
    Coordinate3D endPoint;
    endPoint.x = startX;
    endPoint.y = startY;
    endPoint.z = startZ-length;
    
    Coordinate3D cp1;
    cp1.x = startX;
    cp1.y = startY + waveAmp;
    cp1.z = startZ + (endPoint.z - startPoint.z)*(1.0f/12);
    
    Coordinate3D cp2;
    cp2.x = startX;
    cp2.y = startY - waveAmp;
    cp2.z = startZ + (endPoint.z - startPoint.z)*(2.0f/12);
    
    Coordinate3D cp3;
    cp3.x = startX;
    cp3.y = startY + waveAmp;
    cp3.z = startZ + (endPoint.z - startPoint.z)*(3.0f/12);
    
    Coordinate3D cp4;
    cp4.x = startX;
    cp4.y = startY - waveAmp;
    cp4.z = startZ + (endPoint.z - startPoint.z)*(4.0f/12);
    
    Coordinate3D cp5;
    cp5.x = startX;
    cp5.y = startY + waveAmp;
    cp5.z = startZ + (endPoint.z - startPoint.z)*(5.0f/12);
    
    Coordinate3D cp6;
    cp6.x = startX;
    cp6.y = startY - waveAmp;
    cp6.z = startZ + (endPoint.z - startPoint.z)*(6.0f/12);
    
    Coordinate3D cp7;
    cp7.x = startX;
    cp7.y = startY + waveAmp;
    cp7.z = startZ + (endPoint.z - startPoint.z)*(7.0f/12);
    
    Coordinate3D cp8;
    cp8.x = startX;
    cp8.y = startY - waveAmp;
    cp8.z = startZ + (endPoint.z - startPoint.z)*(8.0f/12);
    
    Coordinate3D cp9;
    cp9.x = startX;
    cp9.y = startY + waveAmp;
    cp9.z = startZ + (endPoint.z - startPoint.z)*(9.0f/12);
    
    Coordinate3D cp10;
    cp10.x = startX;
    cp10.y = startY - waveAmp;
    cp10.z = startZ + (endPoint.z - startPoint.z)*(10.0f/12);
    
    Coordinate3D cp11;
    cp11.x = startX;
    cp11.y = startY + waveAmp;
    cp11.z = startZ + (endPoint.z - startPoint.z)*(11.0f/12);
    
    Coordinate3D cp12;
    cp12.x = startX;
    cp12.y = startY - waveAmp;
    cp12.z = startZ + (endPoint.z - startPoint.z)*(12.0f/12);
    
    glPushMatrix();
    Bezier12cpPlane(startPoint,
                    cp1, cp2, cp3,
                    cp4, cp5, cp6,
                    cp7, cp8, cp9,
                    cp10, cp11, cp12,
                    endPoint);
    glPopMatrix();
    
    glEnable(GL_CULL_FACE);
    
    
}

void renderOBJModels(std::vector<Model> Models){
    int curMaterialID = NULL;
    GLfloat mat_ambient[4] = {0.0,0.0,0.0,0.0};
    GLfloat mat_diffuse[4] = {0.0,0.0,0.0,0.0};
    GLfloat mat_specular[4] = {0.0,0.0,0.0,0.0};
    GLfloat mat_Ns = 0;
    GLfloat mat_Ni = 0;
    GLfloat mat_d = 0;
    GLint mat_illum = 0;
    for (int k = 0; k < Models.size(); k++) {
        glPushMatrix();
        glTranslatef(Models.at(k).position[0], Models.at(k).position[1], Models.at(k).position[2]);
        glRotatef(Models.at(k).orientation[0],Models.at(k).orientation[1], Models.at(k).orientation[2], Models.at(k).orientation[3]);
        if(Models.at(k).material_id_order.size() > 0){
            curMaterialID = Models.at(k).material_id_order.at(0);
            for (int i = 0; i < 3; i++) {
                mat_diffuse[i] = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).Kd.at(i);
            }
            for (int i = 0; i < 3; i++) {
                mat_specular[i] = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).Ks.at(i);
            }
            for (int i = 0; i < 3; i++) {
                mat_ambient[i] = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).Ka.at(i);
            }
            mat_d = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).d;
            mat_illum = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).d;
            mat_Ni = Models.at(k).modelMaterials.at(Models.at(k).material_id_order.at(0)).d;
            
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_Ns);
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
            
        }
        glBegin(GL_TRIANGLES);
        Color(255, 255, 255);
        int vertex_count = 1;
        int material_count = 1;
        for(int i = 0; i < Models.at(k).Meshes.size(); i++){
            Meshes curMesh = Models.at(k).Meshes.at(i);
            for (int j=0; j < curMesh.vertices.size(); j++) {
                if(material_count < Models.at(k).material_id_order.size()&&vertex_count >= Models.at(k).material_start_vertices[Models.at(k).material_id_order.at(material_count)]){
                    curMaterialID = Models.at(k).material_id_order.at(material_count);
                    for (int i = 0; i < 3; i++) {
                        mat_diffuse[i] = Models.at(k).modelMaterials.at(curMaterialID).Kd.at(i);
                    }
                    for (int i = 0; i < 3; i++) {
                        mat_specular[i] = Models.at(k).modelMaterials.at(curMaterialID).Ks.at(i);
                    }
                    for (int i = 0; i < 3; i++) {
                        mat_ambient[i] = Models.at(k).modelMaterials.at(curMaterialID).Ka.at(i);
                    }
                    mat_d = Models.at(k).modelMaterials.at(curMaterialID).d;
                    mat_illum = Models.at(k).modelMaterials.at(curMaterialID).d;
                    mat_Ni = Models.at(k).modelMaterials.at(curMaterialID).d;
                    
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_Ns);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
                    material_count++;
                }
                glNormal3f(curMesh.normals.at(j).x, curMesh.normals.at(j).y, curMesh.normals.at(j).z);
                glVertex3f(curMesh.vertices.at(j).x,curMesh.vertices.at(j).y,curMesh.vertices.at(j).z);
                vertex_count++;
            }
        }
        glEnd();
        glPopMatrix();
    }
}
