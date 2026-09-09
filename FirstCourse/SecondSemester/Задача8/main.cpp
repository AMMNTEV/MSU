#include "LinkedList.h"
#include <cstdio>
#include <cstdlib>

void show(LinkedList &list)
{
    PointSet *current = list.head;
    int setNumber = 1;

    while (current != nullptr)
    {
        printf("PointSet %d (size=%d): ", setNumber, current->size);
        for (int i = 0; i < current->size; i++)
        {
            printf("(%d,%d) ", current->points[i].x, current->points[i].y);
        }
        printf("\n");

        current = current->next;
        setNumber++;
    }
}

int main()
{
    LinkedList list;
    /*FILE *file = fopen("input.txt", "r");

    int x, y;

    while (fscanf(file, "%d %d", &x, &y) == 2)
    {
        Point newPoint;
        newPoint.x = x;
        newPoint.y = y;
        list.add_point(newPoint);
    }

    fclose(file);

    show(list);
    */

    int x, y;

    while (scanf("%d %d", &x, &y) == 2)
    {
        Point newPoint;
        newPoint.x = x;
        newPoint.y = y;
        list.add_point(newPoint);
        show(list);
    }


    return 0;
}

