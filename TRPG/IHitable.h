#pragma once

class IHitable
{
public:
    virtual ~IHitable() = default;
    virtual void OnHit(int damage) = 0;
};
