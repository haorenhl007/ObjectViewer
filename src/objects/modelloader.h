#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "abstractmodel.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include <vector>
#include <memory>

using namespace std;

class ModelLoader
{

public:
    ModelLoader();
    ~ModelLoader();

    vector<shared_ptr<ModelData>> loadModel(const string& filename);
    vector<shared_ptr<ModelData>> loadModel(const string& name, const string& filename);

private:
    MeshData loadMesh(const string& name,
                      const string& filename,
                      unsigned int index,
                      const aiMesh* mesh);

    MaterialData loadMaterial(const string& name,
                              const string& filename,
                              unsigned int index,
                              const aiMaterial* material);

    TextureData loadTexture(const string& name,
                            const string& filename,
                            unsigned int index,
                            const aiMaterial* material);

};

#endif // MODELLOADER_H