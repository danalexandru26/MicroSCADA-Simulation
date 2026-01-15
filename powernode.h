#ifndef POWERNODE_H
#define POWERNODE_H

#include<QLCDNumber>

class PowerNode
{
public:
    PowerNode();
    PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower);
    ~PowerNode();

private:
    QLCDNumber* voltage;
    QLCDNumber* totalPower;
};

#endif // POWERNODE_H
