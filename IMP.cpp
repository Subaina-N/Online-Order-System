#include "Node.h"
#include "GList.cpp"
#include "User.h"
#include "Item.h"

template class Node<user>;
template class GList<user>;

template class Node<Item>;
template class GList<Item>;