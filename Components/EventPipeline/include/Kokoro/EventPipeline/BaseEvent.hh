#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// https://stackoverflow.com/a/11176265/9943479
namespace Kokoro
{
    struct BaseEvent
    {
        virtual ~BaseEvent() = default;

        using create_f = std::unique_ptr<BaseEvent>();

        static void registrate(std::string const& sName, create_f* fp)
        {
            registry()[sName] = fp;
        }

        static std::unique_ptr<BaseEvent> instantiate(std::string const& sName)
        {
            auto it = registry().find(sName);
            return it == registry().end() ? nullptr : (it->second)();
        }

        virtual void Execute(std::vector<void*> pData) { }

        template<typename D>
        struct Registrar
        {
            explicit Registrar(std::string const& sName)
            {
                BaseEvent::registrate(sName, &D::create);
            }
        };

    protected:
        template<int I, typename T>
        T GetDataValue(std::vector<void*> pData)
        {
            return (T) pData[I];
        }

    private:
        static std::unordered_map<std::string, create_f*>& registry()
        {
            static std::unordered_map<std::string, BaseEvent::create_f*> impl;

            return impl;
        }
    };
}  // namespace Kokoro
