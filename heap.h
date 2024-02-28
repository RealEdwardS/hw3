#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 

// Swap function
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp(const T& item, int index); 
  void trickleDown(const T& item, int index); 
  void printList(); 

private:
  // Add whatever helper functions and data members you need below
  std::vector<T> container; 

  // Type of tree
  int ary; 

  // The comparator for comparison
  PComparator comparator;
};

// Add implementation of member functions here

// Ctor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary(m), comparator(c)
{
}

// Dtor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}

// Reminder:
// Default, establish a min heap
// A min heap is where a parent node is always smaller than child node

// NOTE: Replace 2 with ary
// Parent(i) = (i+1)/(ary)
// Left child(i) = (ary)i + 1
// Right child(i) = (ary)i + 2

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  // Add new item to bottom of tree via pushback
  this->container.push_back(item);

  // Get index of item
  int index = container.size() - 1; 

  // Trickle up recursively
  trickleUp(item, index);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(const T& item, int index){
  // If the index is at 0, i.e. at the very top
  if (index == 0){
    return; 
  }

  // If parent node exists (parent index is within the length of container)
  // and parent node is greater than current (child) node, swap 
  if ((index-1)/(this->ary) >= 0){

    // Reference to currNode
    T& currNode = this->container.at(index); 

    // Reference to parentNode
    T& parentNode = this->container.at((index-1)/(this->ary));

    // Compare
    if ((this->comparator(currNode, parentNode))){

      // If comparison passes, swap
      std::swap(currNode, parentNode); 

      // Call trickle up with value of current node at the parentNode's index
      trickleUp(parentNode, (index-1)/(this->ary)); 
    }
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return this->container.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }

  // Plan of action:
  // Swap last item in vector w/ top and then pop back
  // Then recursively sort it

  // If there is only one item in the heap
  if (this->container.size() <= 1){
    this->container.pop_back(); 
    return; 
  }

  // Get the last item:
  // T lastItem = this->container.at(container.size()-1); 

  // Swap the last item with the top item, popback, and then trickle down
  std::swap(this->container.at(0), this->container.at(container.size()-1));
  this->container.pop_back(); 

  trickleDown(this->container.at(0), 0);
}


// Parent(i) = (i+1)/(ary)
// Left child(i) = (ary)i + 1
// Right child(i) = (ary)i + 2

// A ternary tree has a left, middle, and right child
// An ary tree - every parent node can have an ary amount of children 
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(const T& item, int index){
  #ifdef ORIGINAL-trickleDown
  // If left child exists. NOTE: Right child cannot exist if left doesn't exist
  if ( ((index * this->ary) + 1) < this->container.size()){
    // IF LEFT CHILD EXISTS, compare it with left child
    T& currItem = this->container.at(index); 
    T& leftChild = this->container.at((index * this->ary) + 1);

    // If the comparison fails (opposite that of the trickleUp comparison)
    if (this->comparator(currItem, leftChild) == false){
      // Swap these 2 values
      std::swap(currItem, leftChild); 

      // Call trickle down on value of current node at the leftChild's index
      trickleDown(leftChild, ((index * this->ary) + 1));
    }

    // If the comparison passes (LEFT CHILD FAILS), check the right child's existance
    if ( ((index * this->ary) + 2) < this->container.size()){
      // IF RIGHT CHILD EXISTS, compare it with right child
      T& rightChild = this->container.at((index * this->ary) + 2); 
      
      // If the comparison fails (opposite that of the trickleUp comparison)
      if (comparator(currItem, rightChild) == false){
        // Swap these 2 values
        std::swap(currItem, rightChild);

        // Call trickle down on value of current node at the rightChild's index
        trickleDown(rightChild, ((index * this->ary) + 2));
      }
    }
  }
  #endif

  // #ifdef TEST12
  // Loop through each child
  for (int i = 1; i <= this->ary; ++i){
    // If the ith child exists
    if ( ((index * this->ary) + i) < this->container.size() ){
      // If ith child exists, compare currItem with ith child
      T& currItem = this->container.at(index);
      T& currChild = this->container.at((index * this->ary) + i);

      // If the comparison fails (opposite that of trickleUp comparison)
      if (this->comparator(currItem, currChild) == false){
        // Swap these 2 values
        std::swap(currItem, currChild);

        // Call trickle down on value of current node at the currChild's index
        trickleDown(currChild, ((index * this->ary) + i)); 
      }

      // If comparison passes (currChild fails), continue to next child
      else{
        continue;
      }

    }

    else if ( ((index * this->ary) + i) >= this->container.size() ){
      break; 
    }
  }
  // #endif

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if (this->container.size() == 0){
    return true;
  }

  return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return this->container.size(); 
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::printList(){
  // for (int i = 0; i < this->container.size(); ++i){
  //   std::cout << this->container.at(i) << " "; 
  // }
}



#endif

/*
  // If left child exists
  if ((this->ary) * index + 1 < this->container.size()){
    T& currNode = this->container.at(index); 
    T& leftChild = this->container.at((this->ary) * index + 1); 

    // If currNode > leftChild, swap
    if (this->comparator(currNode, leftChild) == false){
      std::swap(currNode, leftChild); 
      trickleDown(leftChild, (this->ary) * index + 1);
    }

    // If currNode < leftChild, then check right child
    else if (this->comparator(currNode, leftChild) == true){
      // If right child exists
      if ((this->ary) * index + 2 < this->container.size()){
        T& rightChild = this->container.at((this->ary) * index + 2);

         // If currNode > rightChild, swap
        if (this->comparator(currNode, rightChild) == false){
          std::swap(currNode, leftChild); 
          trickleDown(rightChild, (this->ary) * index + 2); 
        }
      }
    }
  }
*/