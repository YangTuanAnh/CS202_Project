#pragma once

#include <map>
#include <string>

#include <raygui.h>
#include "ResourceIdentifiers.hpp"

class TextureHolder {
private:
    std::map<Textures::ID, Texture> mTextureMap;
public:
    ~TextureHolder();
    void load(Textures::ID id, const std::string& filename);
    void load(Textures::ID id, const std::string& filename, int width, int height);
    void loadFromImage(Textures::ID id, Image& image);
    void loadFromImage(Textures::ID id, Image& image, int width, int height);
    Texture2D& get(Textures::ID id);
    const Texture2D& get(Textures::ID id) const;
};
