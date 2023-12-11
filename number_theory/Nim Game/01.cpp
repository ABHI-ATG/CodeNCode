// Initially two cases could exist. Case 1: Initial Nim Sum is zero As we know, in this case if played optimally B wins, which means B would always prefer to have Nim sum of zero for A‘s turn. So, as the Nim Sum is initially zero, whatever number of items A removes the new Nim Sum would be non-zero (as mentioned above). Also, as B would prefer Nim sum of zero for A‘s turn, he would then play a move so as to make the Nim Sum zero again (which is always possible, as mentioned above). The game will run as long as there are items in any of the piles and in each of their respective turns A would make Nim sum non-zero and B would make it zero again and eventually there will be no elements left and B being the one to pick the last wins the game. It is evident by above explanation that the optimal strategy for each player is to make the Nim Sum for his opponent zero in each of their turn, which will not be possible if it’s already zero. Case 2: Initial Nim Sum is non-zero Now going by the optimal approach A would make the Nim Sum to be zero now (which is possible as the initial Nim sum is non-zero, as mentioned above). Now, in B‘s turn as the nim sum is already zero whatever number B picks, the nim sum would be non-zero and A can pick a number to make the nim sum zero again. This will go as long as there are items available in any pile. And A will be the one to pick the last item. So, as discussed in the above cases, it should be obvious now that Optimal strategy for any player is to make the nim sum zero if it’s non-zero and if it is already zero then whatever moves the player makes now, it can be countered.


// Proof of the winning formula
// The soundness of the optimal strategy described above was demonstrated by C. Bouton.

// Theorem. In a normal nim game, the player making the first move has a winning strategy if and only if the nim-sum of the sizes of the heaps is not zero. Otherwise, the second player has a winning strategy.

// Proof: Notice that the nim-sum (⊕) obeys the usual associative and commutative laws of addition (+) and also satisfies an additional property, x ⊕ x = 0.

// Let x1, ..., xn be the sizes of the heaps before a move, and y1, ..., yn the corresponding sizes after a move. Let s = x1 ⊕ ... ⊕ xn and t = y1 ⊕ ... ⊕ yn. If the move was in heap k, we have xi = yi for all i ≠ k, and xk > yk. By the properties of ⊕ mentioned above, we have

//     t = 0 ⊕ t
//       = s ⊕ s ⊕ t
//       = s ⊕ (x1 ⊕ ... ⊕ xn) ⊕ (y1 ⊕ ... ⊕ yn)
//       = s ⊕ (x1 ⊕ y1) ⊕ ... ⊕ (xn ⊕ yn)
//       = s ⊕ 0 ⊕ ... ⊕ 0 ⊕ (xk ⊕ yk) ⊕ 0 ⊕ ... ⊕ 0
//       = s ⊕ xk ⊕ yk
 
// (*) t = s ⊕ xk ⊕ yk.
// The theorem follows by induction on the length of the game from these two lemmas.

// Lemma 1. If s = 0, then t ≠ 0 no matter what move is made.

// Proof: If there is no possible move, then the lemma is vacuously true (and the first player loses the normal play game by definition). Otherwise, any move in heap k will produce t = xk ⊕ yk from (*). This number is nonzero, since xk ≠ yk.

// Lemma 2. If s ≠ 0, it is possible to make a move so that t = 0.

// Proof: Let d be the position of the leftmost (most significant) nonzero bit in the binary representation of s, and choose k such that the dth bit of xk is also nonzero. (Such a k must exist, since otherwise the dth bit of s would be 0.) Then letting yk = s ⊕ xk, we claim that yk < xk: all bits to the left of d are the same in xk and yk, bit d decreases from 1 to 0 (decreasing the value by 2d), and any change in the remaining bits will amount to at most 2d−1. The first player can thus make a move by taking xk − yk objects from heap k, then












// 
// Variations
// The subtraction game

// Interactive subtraction game: Players take turns removing 1, 2 or 3 objects from an initial pool of 21 objects. The player taking the last object wins.
// In another game which is commonly known as nim (but is better called the subtraction game), an upper bound is imposed on the number of objects that can be removed in a turn. Instead of removing arbitrarily many objects, a player can only remove 1 or 2 or ... or k at a time. This game is commonly played in practice with only one heap.

// Bouton's analysis carries over easily to the general multiple-heap version of this game. The only difference is that as a first step, before computing the nim-sums we must reduce the sizes of the heaps modulo k + 1. If this makes all the heaps of size zero (in misère play), the winning move is to take k objects from one of the heaps. In particular, in ideal play from a single heap of n objects, the second player can win if and only if

// 0 = n (mod k + 1) (in normal play), or
// 1 = n (mod k + 1) (in misère play).