#include "TextureHolder.h"

#include <cassert>
#include <memory>

#include <raylib.h>

TextureHolder::~TextureHolder() {
    for (auto& pair : mTextureMap)
        UnloadTexture(pair.second);
}

void TextureHolder::load(Textures::ID id, const std::string& filename) {
    std::unique_ptr<Texture> texture(new Texture());
    *texture = LoadTexture(filename.c_str());
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(*texture)));
    assert(inserted.second);
}

Texture2D& TextureHolder::get(Textures::ID id) {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return found->second;
}

const Texture2D& TextureHolder::get(Textures::ID id) const {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return found->second;
}