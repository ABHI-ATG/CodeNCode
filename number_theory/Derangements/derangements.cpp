/*
Derangements : Set of permutations in which in each of the permutation, no element is at present at its position (or say index)
mathematically i!=a[i] for all i 1 to n

how to calculate?
Derangements - n! - (E1 U E2 U E3 U .. En)
where E1 is all permutation in which only 1 elements is at its position

E1 U E2 U .. En = (-1)^i * (number of permutaion with i fixed point);

Why minus?
bcs some permutaion will overlap
this is simple inclusion ans exclusion

how to calculate Ei?
Ei- nCi * (n-i)!
Ei- n!/i!


Now,
Solution is n! * ( i:0 to n E (-1)^i / i!)


*/