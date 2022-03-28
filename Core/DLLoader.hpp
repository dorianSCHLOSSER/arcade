/*
** EPITECH PROJECT, 2021
** Boostrap_Arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include <dlfcn.h>
#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class DLLoader 
{
    public:
        DLLoader(std::string const &path)
        : _instance(nullptr)
        {
            _handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!_handle) {
                std::cerr << dlerror() << std::endl;
                exit(84);
            }
            dlerror();
            loadInstance();
        }
        ~DLLoader() 
        {
            if (_handle != nullptr) {
                if (_instance) _instance = nullptr;
                dlclose(_handle);
            }
        }

        T *getInstance() const 
        {
            if (!_instance) {
                std::cerr << dlerror() << std::endl;
                exit(84);
            }
            return (_instance);
        }

        T *loadInstance(std::string symName="entryPoint")
        {
            auto sym = dlsym(_handle, symName.c_str());
            if (!sym) {
                std::cerr << dlerror() << std::endl;
                exit(84);
            }
            auto fct = reinterpret_cast<void *(*)()>(sym);
            _instance = reinterpret_cast<T*>(fct());
            return (_instance);
        }

    protected:
    private:
        T *_instance;
        void *_handle;
};

#endif /* !DLLOADER_HPP_ */
