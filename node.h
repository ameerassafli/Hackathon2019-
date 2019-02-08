#ifndef MAIN_SAVITCH_NODE2_H
#define MAIN_SAVITCH_NODE2_H
#include <cstdlib> // Provides NULL and size_t
#include <iterator> // Will be used for the node_iterator in Section 6.5
#include <cassert> // Provides assert
//namespace main_savitch_6B

template <class Item>
class node
{
public:
// TYPEDEF
typedef Item value_type;
// CONSTRUCTOR
node(const Item& init_data=Item( ), node* init_link=NULL)
{ data_field = init_data; link_field = init_link; }
// MODIFICATION MEMBER FUNCTIONS
Item& data( ) { return data_field; }
node* link( ) { return link_field; }
void set_data(const Item& new_data) { data_field = new_data; }
void set_link(node* new_link) { link_field = new_link; }
// CONST MEMBER FUNCTIONS
const Item& data( ) const { return data_field; }
const node* link( ) const { return link_field; }
private:
Item data_field;
node *link_field;
};
template <class Item>
void list_clear(node<Item>*& head_ptr)
	// Library facilities used: cstdlib
 {
while (head_ptr != NULL)
 list_head_remove(head_ptr);
 }
template <class Item>
void list_copy
(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
// Library facilities used: cstdlib
 {
head_ptr = NULL;
tail_ptr = NULL;
// Handle the case of the empty list.
if (source_ptr == NULL)
return;
// Make the head node for the newly created list, and put data in it.
list_head_insert(head_ptr, source_ptr->data( ));
tail_ptr = head_ptr;
// Copy the rest of the nodes one at a time, adding at the tail of new list.
source_ptr = source_ptr->link( );
while (source_ptr != NULL)
{
 list_insert(tail_ptr, source_ptr->data( ));
 tail_ptr = tail_ptr->link( );
source_ptr = source_ptr->link( );
}
 }
template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry)
	{
head_ptr = new node<Item>(entry, head_ptr);
}
template <class Item>
void list_head_remove(node<Item>*& head_ptr)
	{
node<Item> *remove_ptr;
remove_ptr = head_ptr;
head_ptr = head_ptr->link( );
delete remove_ptr;
 }
template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry)
	{
node<Item> *insert_ptr;
insert_ptr = new node<Item>(entry, previous_ptr->link( ));
previous_ptr->set_link(insert_ptr);
 }
template <class Item>
int list_length(const node<Item>* head_ptr)
	{
const node<Item> *cursor;
int answer;
answer = 0;
for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
 ++answer;
return answer;
 }
template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position)
	// Library facilities used: cassert, cstdlib
 {
NodePtr cursor;
std::size_t i;
assert(0 < position);
cursor = head_ptr;
for (i = 1; (i < position) && (cursor != NULL); ++i)
 cursor = cursor->link( );
return cursor;
 }
template <class Item>
void list_remove(node<Item>* previous_ptr)
	{
node<Item> *remove_ptr;
remove_ptr = previous_ptr->link( );
previous_ptr->set_link(remove_ptr->link( ));
delete remove_ptr;
 }
template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target)
	// Library facilities used: cstdlib
 {
NodePtr cursor;
for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
if (target == cursor->data( ))
return cursor;
return NULL;
 }
template <class Item>
void reverse_traverse ( node<Item>* head_ptr ){
	if(head_ptr != NULL ){
		reverse_traverse ( head_ptr->link() );
		cout<<head_ptr->data()<<endl;
	}
}
template <class Item>
void reverse_traverse_2 ( node<Item>* head_ptr ){
	node <Item>* previous_ptr = NULL;
	for( node<Item>* next_ptr ; head_ptr !=NULL ; head_ptr = next_ptr ){
		next_ptr = head_ptr->link();
		head_ptr->set_link(previous_ptr);
		previous_ptr = head_ptr;
	}
	node<Item>* temp_ptr = previous_ptr;
	previous_ptr = head_ptr;
	head_ptr = temp_ptr;
	for( node<Item>* next_ptr ; head_ptr !=NULL ; head_ptr = next_ptr ){
		cout<<head_ptr->data()<<endl;
		next_ptr = head_ptr->link();
		head_ptr->set_link(previous_ptr);
		previous_ptr = head_ptr;
	}
}
#endif
