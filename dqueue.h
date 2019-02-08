#ifndef MAIN_SAVITCH_QUEUE1_H
#define MAIN_SAVITCH_QUEUE1_H
#include <cstdlib> // Provides size_t
#include "node.h" // Node template class
#include <cassert>
template <class Item>
class dqueue
{
public:
// TYPEDEFS
typedef std::size_t size_type;
typedef Item value_type;
// CONSTRUCTORS and DESTRUCTOR
dqueue( );
dqueue(const dqueue<Item>& source);
~dqueue( );
// MODIFICATION MEMBER FUNCTIONS
Item del( );
void ins(const Item& entry);
void operator =(const dqueue<Item>& source);
// CONSTANT MEMBER FUNCTIONS
bool empty( ) const { return (count == 0); }
bool empty_next( ) const { return (count == 1); }
Item front( ) const;
size_type size( ) const { return count; }
private:
node<Item> *front_ptr;
node<Item> *rear_ptr;
size_type count; // Total number of items in the dqueue
};
template <class Item>
dqueue<Item>::dqueue( )
	{
count = 0;
front_ptr = NULL;
}
template <class Item>
dqueue<Item>::dqueue(const dqueue<Item>& source)
	// Library facilities used: node2.h
{
count = source.count;
list_copy(source.front_ptr, front_ptr, rear_ptr);
}
template <class Item>
dqueue<Item>::~dqueue( )
	// Library facilities used: node2.h
{
list_clear(front_ptr);
}
template <class Item>
void dqueue<Item>::operator =(const dqueue<Item>& source)
	// Library facilities used: node2.h
{
if (this == &source) // Handle self-assignment
return;
list_clear(front_ptr);
list_copy(source.front_ptr, front_ptr, rear_ptr);
count = source.count;
}
template <class Item>
Item dqueue<Item>::front( ) const
// Library facilities used: cassert
{
assert(!empty( ));
return front_ptr->data( );
}
template <class Item>
Item dqueue<Item>::del( )
	// Library facilities used: cassert, node2.h
{
assert(!empty( ));
Item temp = front_ptr->data();
list_head_remove(front_ptr);
--count;
return temp;
}
template <class Item>
void dqueue<Item>::ins(const Item& entry)// Library facilities used: node2.h
{
if (empty( ))
{ // Insert the first entry.
list_head_insert(front_ptr, entry);
rear_ptr = front_ptr;
}
else
{ // Insert an entry that is not the first.
list_insert(rear_ptr, entry);
rear_ptr = rear_ptr->link( );
}
++count;
}

#endif
