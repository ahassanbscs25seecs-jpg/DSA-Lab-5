# DSA-Lab-5

- **Name:** Agha Waleed Hassan
- **CMS ID:** 540711
- **Section:** BSCS-15-D

### Task 3
Since the list is circular, the next node of the last node will
not be nullptr, it will be head. This means that no nodes in the
node will have nullptr as a next pointer and loops with the
nullptr check will be infinite

### Task 6
LIFO stands for 'last in first out.' This means that the last element that was pushed onto the stack will be the first one to be popped

The array stack uses an array. The elements are continguous
and only one allocation is required to allocate the entire stack. The array stack is fast but it fixed size

The linked list stack changes size dynamically so every push causes an allocation to be done. This can be slow in the long run since allocation on the heap is a slow process.

Array stack is better if you want to prioritize speed over dynamic size.
