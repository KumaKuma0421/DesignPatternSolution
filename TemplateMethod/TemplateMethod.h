//
// Template.h
//

#pragma once

namespace GoF_TempateMethod
{
    class Template
    {
    public:
        bool Action();

    protected:
        virtual bool Init() = 0;
        virtual bool Start() = 0;
        virtual bool Stop() = 0;
        virtual bool Exit() = 0;
    };

    class TemplateAction : public Template
    {
    protected:
        bool Init();
        bool Start();
        bool Stop();
        bool Exit();
    };
}