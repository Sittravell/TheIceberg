//
//  OBJLoader.cpp
//  CGProject
//
//  Created by Sittravell Sivanthi on 5/22/19.
//  Copyright © 2019 Sittravell Sivanthi. All rights reserved.
//
#include "OBJLoader.hpp"

Model tinyLoader(const tinyobj::attrib_t& attrib,const std::vector<tinyobj::shape_t>& shapes,const std::vector<tinyobj::material_t>& materials, float scale){
    Model model;
    int vertices_count = 1;
    int cur_material_id = -1;
    for (size_t i = 0; i < shapes.size(); i++) {
        Meshes meshes;
        std::vector< Coordinate3D > vertices;
        std::vector< Coordinate2D > uvs;
        std::vector< Coordinate3D > normals;
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[i].mesh.num_face_vertices.size(); f++) {
            size_t fnum = shapes[i].mesh.num_face_vertices[f];
            for (size_t v = 0; v < fnum; v++) {
                Coordinate3D vertex;
                Coordinate3D normal;
                Coordinate2D uv;
                if(shapes[i].mesh.material_ids[f] != cur_material_id){
                    cur_material_id = shapes[i].mesh.material_ids[f];
                    model.material_id_order.push_back(cur_material_id);
                    model.material_start_vertices[cur_material_id] = vertices_count;
                }
                tinyobj::index_t idx = shapes[i].mesh.indices[index_offset + v];
                vertex.x= attrib.vertices[3*idx.vertex_index+0]*scale;
                vertex.y= attrib.vertices[3*idx.vertex_index+1]*scale;
                vertex.z= attrib.vertices[3*idx.vertex_index+2]*scale;
                vertices.push_back(vertex);
                if(attrib.normals.size()>0){
                    normal.x= attrib.normals[3*idx.normal_index+0];
                    normal.y= attrib.normals[3*idx.normal_index+1];
                    normal.z= attrib.normals[3*idx.normal_index+2];
                    normals.push_back(normal);
                }
                if(attrib.texcoords.size()>0){
                    uv.x=attrib.texcoords[2*idx.texcoord_index+0];
                    uv.y=attrib.texcoords[2*idx.texcoord_index+1];
                    uvs.push_back(uv);
                }
                vertices_count++;
            }
            index_offset += fnum;
            //            std::cout << "material_ids: " << shapes[i].mesh.material_ids[f] << std::endl;
        }
        meshes.vertices = vertices;
        meshes.normals = normals;
        meshes.uvs = uvs;
        model.Meshes.push_back(meshes);
        
    }
    
    for (int i = 0; i < materials.size(); i++) {
        Material curMat;
        curMat.Ka.push_back(materials[i].ambient[0]);
        curMat.Ka.push_back(materials[i].ambient[1]);
        curMat.Ka.push_back(materials[i].ambient[2]);
        
        curMat.Kd.push_back(materials[i].diffuse[0]);
        curMat.Kd.push_back(materials[i].diffuse[1]);
        curMat.Kd.push_back(materials[i].diffuse[2]);
        
        curMat.Ks.push_back(materials[i].specular[0]);
        curMat.Ks.push_back(materials[i].specular[1]);
        curMat.Ks.push_back(materials[i].specular[2]);
        
        curMat.Ni = materials[i].ior;
        curMat.Ns = materials[i].shininess;
        curMat.d = materials[i].dissolve;
        curMat.illum = materials[i].illum;
        model.modelMaterials.push_back(curMat);
    }
    return model;
}
Model AdvanceOBJLoader(const char* filename = NULL, const char* basepath = NULL, float scale = 1.0f, bool triangulate = true){
    std::cout << "Loading " << filename << std::endl;
    
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename,
                                basepath, triangulate);
    
    if (!warn.empty()) {
        std::cout << "WARN: " << warn << std::endl;
    }
    
    if (!err.empty()) {
        std::cerr << "ERR: " << err << std::endl;
    }
    
    if (!ret) {
        printf("Failed to load/parse .obj.\n");
    }
    Model model = tinyLoader(attrib, shapes, materials, scale);
    return model;
    
}

