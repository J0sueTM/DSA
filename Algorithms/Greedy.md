
# Greedy algorithm

Greedy is an algorithmic paradigm that uses the best **local** suitable solution. It does not care about past data, just the current and next data incoming
Greedy is simple, fast and easy to implement. However, since it **always** return the local optimum solution, it **must** be used only if:

- **Don't need to reconsider choices:** If you have a bunch of coins and want to give n dollars for a friend, then just implement greedy with the fractional knapsack problem. However, if you want to use at least x coins (or any other conditional that forces you to keep past information), then greedy will not work
- **There's just one final solution:** Even though there's more than one feasible solution, greedy must return the most optimal. Using the same example as above, the optimal would be the smaller number

## Implementation

Greedy can be implemented with both iteration and recursion, you can find more about on the implementation directory:

- activity selection problem

- huggman coding

- job sequencing problem

- prim's minimum spanning tree

If you want to solve some by your own, [here you go](https://a2oj.com/category?ID=56)
