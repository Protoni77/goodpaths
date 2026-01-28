# goodpaths

https://www.optil.io/optilion/problem/3225

Here are a few pieces of information about the second project and the Good Paths problem.

1. The project will be extended by a few days (at least three). I will fix the new deadline by Friday/Saturday and let you know.

2. I strongly encourage you to use local search approach to tackle the problem, just as mentioned and discussed during labs.

3. I encourage using data reduction rules (particularly path compression, perhaps some other lossy rules like leaf-trimming might work for some instances as well), but it is not neccessary. Baseline solutions do not use any data reduction rules (but using it might make it easier to beat the baselines, but probably more difficult to implement algorithms).

4. Take care to implement zero-cost moves for local search (such as, e.g., tail reversal, tail replacement or single-edge/single-node swaps), for without those your solutions are likely to be much more susceptible to getting stuck early in a local optimum.

5. Perhaps a DFS (maybe with backtracking? and fixed small maximum depth?) might be useful after all. If you use DFS, make sure that you can 'mask out' neccessary information (e.g. visited nodes) and reverse applied changes efficiently (by resetting only those values that could have been changed, that were 'touched' during the algorithm execution).

6. I was informed that there might be issues with running a deep DFS on optil.io due to the stack size limit set by default to (probably) 8MB. You can try to increase the stack size during runtime (easily google'able how to do it) if you need that, although I do not guarantee that it will work. DFS calls with bounded depth (e.g. not deeper than 10000) should work without any changes.

7. If you did not read assessment criteria, it might be a good idea to read it before the semester ends :) (e.g. how many points for the result quality will a submission obtain, if it scored 84 points on optilo and baselines scored: swats-82, foxy-95)?

8. The 'swats' baseline solution is a greedy or an almost greedy algorithm. It uses a greedy algorithm to find the initial solution and perhaps two basic moves, from which one is zero-cost move (I do not remember if this version/baseline uses any moves at all, but if it uses any, it uses not more than the two basic ones (they were discussed during labs). Judging by the total execution time, it is very likely that it is a purely greedy algorithm, without any local search moves).
Baseline solutions for the short and long track are identical, except for the time limit (that is why the foxy baseline produces noticeably better results for long track - it was simply given more time).

9. Should you have any questions regarding the project (any at all!), do not hesitate to ask! (most preferably during labs, because in that time we will surely have enough time to discuss it, but you can also write an email/message).
