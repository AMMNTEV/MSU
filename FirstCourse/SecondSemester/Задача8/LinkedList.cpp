#include "LinkedList.h"
#include <cstdlib>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList(){
    PointSet *current = head;
    while (current != nullptr){
        PointSet *next = current->next;
        free(current->points);
        delete current;
        current = next;
    }
}

int LinkedList::add_point(Point point)
{
    PointSet *newSet = new PointSet();
    newSet->points = (Point *)malloc(sizeof(Point));
    if (!newSet->points){
        return -1;
    }
    newSet->points[0] = point;
    newSet->size = 1;
    newSet->next = head;
    head = newSet;

    PointSet *current = head->next;
    PointSet *prev = head;

    while (current != nullptr)
    {
        bool Match = false;

        for (int i = 0; i < current->size; i++)
        {
            if ((abs(point.x - current->points[i].x) <= 1 &&
                 abs(point.y - current->points[i].y) <= 1))
            {
                Match = true;
                break;
            }
        }

        if (Match)
        {
            newSet->points = (Point *)realloc(newSet->points,
                                              (newSet->size + current->size) * sizeof(Point));
            if(!newSet->points){
                return -1;
            }

            for (int i = 0; i < current->size; i++)
            {
                newSet->points[newSet->size + i] = current->points[i];
            }
            newSet->size += current->size;

            prev->next = current->next;

            free(current->points);
            delete current;

            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}
