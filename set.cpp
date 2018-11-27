#include "set.hpp"

// Default constructor
Set::Set() 
{
	head = new Node(NULL, nullptr);
    // Add code
    // implement before HA session week 46
}	

// Constructor for creating a set from an int
Set::Set(int v)
{
	// Add code
	// implement before HA session week 46

	head = new Node(NULL, nullptr);
	head->next = new Node(v, nullptr);
	
}

// Constructor creating a set
// a non-sorted array of n intgers
Set::Set(const int a[], int n) 
{
	// Add code
	// implement before HA session week 46
	// Sort array before we ad it in list?
	
	head = new Node(NULL, nullptr);
	for (int i = 0; i < n; i++) {
		*this = *this + a[i];
	}

	
}

// copy constructor
Set::Set(const Set& source) 
{
	// Add code
	// implement before HA session week 46

	head = new Node(NULL, nullptr);
	Node *sourceptr = source.head;
	Node *tmp = head;
	
	while (sourceptr->next) {
		sourceptr = sourceptr->next;
		tmp->next = new Node(sourceptr->value, nullptr);
		tmp = tmp->next;
	}
	

}

// Destructor: deallocate all nodes
Set::~Set() 
{
	// Add code
	// implement before HA session week 46

	Node *n = head;
	Node *tmp;
	while (n) {
		tmp = n;
		n = n->next;
		delete tmp;
	}

}

// Test if set is empty
bool Set::empty() const 
{

    // Add code
    // implement before HA session week 46

    return !head->next;  // to be deleted
}

// Return number of elements in the set
int Set::cardinality() const 
{
    // Add code
    // implement before HA session week 46

	int i = 0;
	Node *tmp = head;

	while (tmp->next) {
		tmp=tmp->next;
		i++;
	}

    return i; // to be deleted
}

// Test if x is an element of the set
bool Set::member(int x) const 
{
    // Add code
    // implement before HA session week 46

	Node *tmp = head;

	while (tmp->next) {
		tmp = tmp->next;
		if (x == tmp->value) {
			return true;
		}
		
	}

    return false; //to be deleted
}

// Assignment operator
Set& Set::operator=(const Set& s)
{

	if (this != &s) {

		Set _copy{ s };

		std::swap(head, _copy.head);

	}

	// Add code
	return *this;  // to be deleted
}

bool Set::operator<=(const Set& b) const 
{
	Node *aptr = head;

	while (aptr->next) {
		aptr = aptr->next;
		if (!b.member(aptr->value)) return false;
	}
    // Add code
    return true;  // to be deleted
}

bool Set::operator==(const Set& b) const 
{
    // Add code
    return (*this <= b) && (this->cardinality()==b.cardinality());  // to be deleted
}

bool Set::operator!=(const Set& b) const 
{
    // Add code
    return !(*this == b);  // to be deleted
}

bool Set::operator<(const Set& b) const 
{
    // Add code
    return (*this <= b) && (this->cardinality() < b.cardinality());;  // to be deleted
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const 
{
    // Add code
    // implement before HA session week 45
	Set newSet = Set(*this);
	Node *aptr = newSet.head;
	Node *bptr = b.head;
	while (bptr->next) {
		if(aptr->next) {
			if (aptr->next->value > bptr->next->value) {
				aptr->next = new Node(bptr->next->value, aptr->next);
			}
			else if (aptr->next->value < bptr->next->value) {
				aptr = aptr->next;
			}
			else {
				bptr = bptr->next;
			}
		}
		else
			aptr->next = new Node(bptr->next->value, nullptr);
	}

    return newSet;  // to be deleted
}

// Set intersection
Set Set::operator*(const Set& b) const 
{
	Set newSet;
	Node *tmp = b.head;

	while (tmp->next) {
		tmp = tmp->next;
		if (this->member(tmp->value)) {
			newSet = newSet + tmp->value;
		}

	}

    // Add code
    return newSet;  // to be deleted
}

// Set difference
Set Set::operator-(const Set& b) const 
{
	Set newSet;
	Node *tmp = head;

	while (tmp->next) {
		tmp = tmp->next;
		if (!b.member(tmp->value)) {
			newSet = newSet + tmp->value;
		}
	}

	// Add code
	return newSet;  // to be deleted
}

// Set union with set {x}
Set Set::operator+(int x) const 
{
    // Add code
    return *this + Set(x);  // to be deleted
}

// Set difference with set {x}
Set Set::operator-(int x) const 
{
    // Add code
    return *this - Set(x);  // to be deleted
}



std::ostream& operator<<(std::ostream& os, const Set& theSet) 
{
	if (theSet.empty())
	{
		os << "Set is empty!";
	}
    else
	{
        Set::Node* temp = theSet.head->next;
        os << "{ ";

        while (temp)
		{
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }

    return os;
}
