#include "powernode.h"

PowerNode::PowerNode() {
    voltage = nullptr;
    totalPower = nullptr;
}

PowerNode::PowerNode(QLCDNumber* voltage, QLCDNumber* totalPower): voltage{voltage}, totalPower{totalPower}
{
    if(voltage->intValue() < 0){
        voltage->display(100);
    }
    if(totalPower->intValue() < 0){
        voltage->display(100);
    }
}
