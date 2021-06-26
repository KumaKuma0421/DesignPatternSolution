//
// Watcher.h
//

#pragma once

namespace GoF_FactoryMethod
{
    class Observer
    {
    public:
        void Update();
    };

    class Watcher
    {
    public:
        Watcher();
        virtual ~Watcher();

        void Update();
    };
}