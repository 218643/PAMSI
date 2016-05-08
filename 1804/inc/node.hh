#pragma once
#include <string>
#include "element.hh"

/*!
*\brief Definicja klasy node
*
* Klasa ta tworzy wezly. Kazdy wezel ma wskaznik na lewego i prawego syna i ojca.
* Oprocz infrastruktury drzewa klasa ta przechowuje rowniez element.
* Zaprzyjazniona jest z klasa tree.
*
*/


class node
{
    element el;
    node *left;
    node *right;
    node *up;
    int black;//0-czerwony, 1-czarny
    friend class tree;
public:
    node(){el.value=0;el.key=0;black=0;}
    element getel()
    {
        return el;
    }
};


