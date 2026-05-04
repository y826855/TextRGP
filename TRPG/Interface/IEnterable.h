#pragma once

class IEnterable
{
public:
    virtual ~IEnterable() = default;
    
    virtual void Enter() = 0;
    virtual void Quit() = 0;
};
