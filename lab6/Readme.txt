lab 6 Readme file for exercise 2
Name: Brian Dizon
SID: 861140364
Date: May 12, 2015

a) My selectionsort function is stable. At the end of the outer loop, where
we make the comparison "if(it != temp)", this will swap the two items, only if
the items do not have the same contents. This reduces the amount of swaps needed
and makes sure it keeps the selectionsort stable. If my function was not stable,
there would be more moves than stated in the lab specs. However, my algorithm
actually uses less moves, so it isn't making unnecessary swaps that would make 
it unstable.

b) To test the stability of my function, I can use a container that contains
only items with the same contents. For example, I would declare
    vector<int> v1 = {1,1,1,1,1,1};
and then call selectionsort on it. If the number of moves == 0, then I know that
the function maintains stability.