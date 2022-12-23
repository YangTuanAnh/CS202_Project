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

void TextureHolder::loadFromImage(Textures::ID id, Image& image) {
    std::unique_ptr<Texture> texture(new Texture());
    *texture = LoadTextureFromImage(image);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(*texture)));
    assert(inserted.second);
}

void TextureHolder::load(Textures::ID id, const std::string& filename, int width, int height) {
    std::unique_ptr<Texture> texture(new Texture());
    Image img = LoadImage(filename.c_str());
    ImageResize(&img, width, height);
    *texture = LoadTextureFromImage(img);
    UnloadImage(img);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(*texture)));
    assert(inserted.second);
}

void TextureHolder::loadFromImage(Textures::ID id, Image& image, int width, int height) {
    std::unique_ptr<Texture> texture(new Texture());
    ImageResize(&image, width, height);
    *texture = LoadTextureFromImage(image);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(*texture)));
    assert(inserted.second);
}

Texture2D& TextureHolder::get(Textures::ID id) {
    auto found = mTextureMap.find(id);
    if (found != mTextureMap.end()) {
       return found->second;
    }
    return mTextureMap[Textures::ID::None];
}

const Texture2D& TextureHolder::get(Textures::ID id) const {
    auto found = mTextureMap.find(id);
    if (found != mTextureMap.end()) {
       return found->second;
    }
    return mTextureMap.at(Textures::ID::None);
}