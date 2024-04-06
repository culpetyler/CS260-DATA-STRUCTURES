
# Assignment 2 (Design)

### **Queue**

Given the dynamic nature of queues, the creation of a queue will require a way to store and connect values in the queue with a pointer connecting the values linearly together. The main queue object (which will have methods that interact with the referenced values, and some values such as size of the queue) will need to store a pointer to the first value in the queue, and the last value depending on the type of queue.

The methods required would need to add a value to the queue, search for a value in the queue, and remove a value from the queue. Depending on complexity, some other methods may be required as well. A queue is FIFO (First In First Out), so a remove method should start from the first value in the queue, not the last value added. One such basic implementation could look like the following:

#### **Queue Object**

**Variables**
- type \* first
- type \* last
- uint32_t size

**Methods**
- insert(type) // connects the last value to the new value then sets **last** to the pointer of the new value
- remove() // removes the value at first then sets **first** to the next value in the queue

### **Linked List**

A linked list is likewise dynamic and thus requires the use of pointers to find where values are stored in memory. Linked lists are similar to queues, but unlike a queue, a linked list is *not* FIFO. Instead, a linked list can insert and remove values *anywhere* in the list. This means that a linked list can be constructed in the same manner, but with some additions to allow the additional functionality required of it. This could look like:

**Variables**
- type \* first
- type \* last
- uint32_t size

**Methods** 
- insert(type, index) // iterates the list linearly until the index and sets previous value to point to new value
- remove(index) // iterates the list linearly until the index and sets previous value to point to next value after index

Both of these list types will also need an object which stores a value and pointer in order to point to the next value in these lists. The last value in any of these lists will need to point to a **null pointer** and be handled to stop upon reaching such a value.