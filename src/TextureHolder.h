#pragma once

#include <map>
#include <string>

#include "../include/raygui.h"
#include "ResourceIdentifiers.hpp"

class TextureHolder {
private:
    std::map<Textures::ID, Texture> mTextureMap;
public:
    void load(Textures::ID id, const std::string& filename);
    Texture& get(Textures::ID id);
    const Texture& get(Textures::ID id) const;
};