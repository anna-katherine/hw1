#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERED

void ULListStr::push_back(const std::string& val)
{
    if (empty()) //if empty list, create a new Item n and set val, first, last. 
								 //then, set head_ to n.
    {
      Item* n = new Item();
			n->val[0] = val;
			n->first = 0;
			n->last = 1;
			head_ = n;
			tail_ = head_;
			
    }
		else if (tail_->last != ARRSIZE) //if there is space in tail Item
		{
			tail_->val[tail_->last] = val;
			tail_->last++;
		}
		else //adding new Item m as tail by swapping the values of tail and m
		{
			 Item* m = new Item();
			 m->next = NULL; //since it will be the new tail (point to NULL)
			 tail_->next = m;
		 	 m->prev = tail_;
			 m->val[0] = val;
			 m->first = 0;
			 m->last = 1;
			 tail_ = m;
		}
	  size_++;
}

void ULListStr::push_front(const std::string& val)
{
		if (empty()) //if empty list, create a new Item n and set val, first, last. 
								 //then, set head_ to n. same as push_back!
    {
      Item* n = new Item();
			n->val[0] = val;
			n->first = 0;
			n->last = 1;
			head_ = n;
			tail_ = head_;
    }
		else if (head_->first != 0) //if there is space in the head
		{
			head_->val[head_->first-1] = val;
			head_->first--;
		}
		else //create new head Item if existing one is full
		{
				Item* m = new Item();
				m->prev = NULL;
				head_->prev = m;
				m->next = head_;
				m->val[ARRSIZE-1] = val;
				m->first = ARRSIZE-1;
				m->last = ARRSIZE;
				head_ = m;
		}
		size_++;
}

void ULListStr::pop_back()
{
		if (empty())
			return; // in case there's nothing in da list
		if (size_ == 1) // if there is only ONE value in entire linked list, delete both head_ and tail_
		{

			delete tail_;
			tail_ = NULL;
			head_ = NULL;

		}
		else if (tail_->last - tail_->first != 1) // if there's at least 2 values in tail_'s array
		{
				tail_->last--;
		}
		else // there's only 1 value, so I only delete the current tail_ Item
		{
			tail_ = tail_->prev;
			delete tail_->next;
			tail_->next = NULL;
		}
		size_--;
}

void ULListStr::pop_front()
{
		if (empty())
			return; // in case there's nothing in da list
		if (size_ == 1) // if there is only ONE value in entire linked list, delete both head_ and tail_
		{
			delete head_;
			tail_ = NULL;
			head_ = NULL;
		}
		else if (head_->last - head_->first != 1) // if there's at least 2 values in head_'s array
		{
				head_->first++;
		}
		else // there's only 1 value, so I only delete the current head_ Item
		{
			head_ = head_->next;
			delete head_->prev;
			head_->prev = NULL;
		}
		size_--;
}

std::string const & ULListStr::back() const{
	
	return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const//must be O(n)
{
	Item* copy = head_;
	if (loc > size_ || size_ == 0)
			return NULL;
	else
	{
		while (loc >= copy->last - copy->first)
		{
				loc -= copy->last - copy->first;
				if (copy->next == NULL)
						return NULL;
				copy = copy->next;
		}
	}
	return &copy->val[copy->first+loc];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
