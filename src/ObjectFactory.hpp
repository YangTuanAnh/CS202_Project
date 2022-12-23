#pragma once

#include <functional>
#include <map>
#include <memory>
#include <iostream>
#include <string>

#include "ResourceIdentifiers.hpp"
#include "Object.h"

template <typename T, typename ... Ts>
class ObjectFactory {
public:
    template <typename TDerived>
    void registerType(Objects::ID type) {
        _createFuncs[type] = &createFunc<TDerived>;
    }    
    std::unique_ptr<T> create(Objects::ID type, Ts... args) {
        auto it = _createFuncs.find(type);
        if (it != _createFuncs.end()) {
            return it->second(args...);
        }
        std::cerr << "Could not find type " << type << std::endl;
        return nullptr;
    }    
private:
    template <typename TDerived>
    static std::unique_ptr<T> createFunc(Ts... args) {
        auto ret = std::make_unique<TDerived>(args...);
        return std::move(ret);
    }
    std::map<Objects::ID, std::function<std::unique_ptr<T>(Ts...)>> _createFuncs;
};