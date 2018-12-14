[![Build Status](https://travis-ci.com/joaomlneto/anafind.svg?token=QsVQsaqyQNrgjyTyzV4W&branch=master)](https://travis-ci.com/joaomlneto/anafind)

# anafind
C++ library to find anagrams in a dictionary.

This solution is optimized for a high query ratio (number of queries / size of the dictionary).

# Complexity Analysis

Some definitions:
- `N` denotes the *number of words in a dictionary*
- `L` denotes the *length of a word*

We assume `N` >> `L`.

We have to take into account the time it takes to
1. Load (and preprocess) the dictionary and
  - Worst case: `O(N^2)`
  - Average case: `O(N*log(N))`
2. Lookup the anagram of a given word.
  - Worst case: `O(N)`
  - Average case: `O(1)`

An alternative implementation is to swap the HashMap for a TreeMap, causing both worst cases and average cases to be `O(N*log(N)^2)` for insertion and `O(log(N))` for lookups.

Below is a slightly more verbose discussion on these results.

## Loading the Dictionary

For each word we:
1. Compute its index key (words share same key iff they are anagrams)
2. Look up the corresponding set of anagrams for that word in the hash map
3. Insert the word in that set

##### Computing Index Key
Computing the index key is linear in the length of the word. We have a constant bound on the number of operations when processing each character.

While lookups in an ordered map are `O(log N)`, the size of the map is bounded to `26` (number of characters in the english alphabet), hence the `O(1)` claim to process each character.

##### Looking up the Corresponding Set

Lookups in a hash-map are `O(1)`. However, it will trigger an insertion if such set doesn't exist.

Insertions are `O(1)` on average, but may take linear time in the number of elements in the map in a few cases.

I'm not too familiar about hashmaps and the STL implementation but I believe the reasons for a linear time insert are:
- If there is a hashing collision;
- Buckets being badly balanced;
- Hashmap becoming "full", requiring a resize and rehash procedure.

We could use a tree to improve the worst-case, at the expense of the average-case -- a tradeoff between raw performance and predictability, I guess.

##### Inserting the word in the set

Insertions, since they are ordered, can take `O(log N)` -- logarithmic time with the size of the container.

### Putting Everything Together

**Inserting a word in the dictionary takes `O(L+log(N))` on average**.

**Worst case will be `O(L+N)`** -- if it triggers a *bad insert* in the hashmap. If it is an insert, insertion in the sorted set will be `O(1)` due to it being empty.

Therefore, **processing the dictionary is `O(N*(L+log(N)))` at worst and `O(N^2+LN)` on average**. Since it's fairly safe to assume `N >> L`, worst case can simply be stated as `O(N^2)`.

We can improve the worst-case scenario by replacing the hashmap with a tree (`O(N*log(N))`)

## Looking up an anagram

We just look up the corresponding set of anagrams in the hashmap. **Usually `O(1)` but can take up to `O(N)` if it is badly balanced.**

Afterwards we just return the first element in an already-sorted set, which is `O(1)`.
