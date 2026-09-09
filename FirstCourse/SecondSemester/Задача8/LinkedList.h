#include "PointSet.h"

class LinkedList
{
public:
    PointSet *head;

    LinkedList();

    ~LinkedList();
    
    int add_point(Point point);
    
};

