/*
condition on last element of sequence
-if last element is ):
    
every prefix sum before
*/


/*
let ( = 1, ) = -1

The parenthesis combination is valid iff prefix sum >= 0



dp, conditioning on last element of sequence
- if i is 1, then every possible subsequence ending in index i is valid
- if i is -1, then every previous valid subsequence that


observation:
Let i be an element of the subsequence
for k in [i,j), the prefix sum [0,k] = original[0,k] + last - i




c1: for any interval that ends in -1, every k in [i,j) that starts with a[i]=1 must have 
prefix[0,k] >= 2 

there are two dependencies: i and j

observation:
let's say we are at index j, and we want to find all the satisfying subsequences ending at j
the satisfying subsequences are:
- adding a[j] to previous satisfying subsequences that ended in -1
- adding a[j] to previous satisfying subsequences that ended in 1 for i > most recent prefix <= 1

let count_{x} be running counters that actively tracks the conditions above
- count_{-1} is the number of satisfying subsequences that end in -1
- count{1} is the number of satisfying subsequences that end in 1 and have i > most recent prefix <= 1



given # valid subsequences that end in {-1,1} at index [0,i-1] and the index p of the most recent prefix <=1,
we can get the # valid subsequences that end in {-1,1} at index i by:
    - if a[i] = -1, count_{a[i]} += count_{-1} + count_{1}
    - if a[i] = 1, if prefix[i] <= 1, count_{1} = 0
    - 

we can update the count for [0,i] that satisfies the condition:
    - if a[i]=-1, count_-1 += ()
    - if a[i]=1, count


*/