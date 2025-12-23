# push_swap roadmap

## Current snapshot
- Core helpers exist in `mandatory/` for linked lists (`listools.c`), moves (`moves.c`), string parsing (`ft_split.c`, `utils.c`, `utils2.c`), and the `t_list` struct in `push_swap.h`.
- Missing pieces: entrypoint (`main`), argument validation/normalization, index assignment, complete move set wrappers (e.g., `ss`, `rrr`), and the actual sorting strategies.

## What to build next (no coding steps, just plan)
1. **Argument handling & validation**
   - Accept both space-separated single argument and multiple arguments.
   - Reject non-numeric input, overflows beyond `INT_MIN/INT_MAX`, duplicates, and empty input; clean up allocated memory on failure.
   - Convert to longs/ints and keep original order for stack A.

2. **Stack construction & indexing**
   - Populate stack A as a singly linked list; keep stack B empty.
   - Create an array copy to sort and assign each node its compressed index (ranking) to make radix/chunk sorting easier.

3. **Complete operations layer**
   - Ensure safeguards on `swap` for <2 nodes.
   - Add missing combined ops (`ss`, `rrr`) and follow the existing `rr` pattern (silent single-stack calls then one combined print) so each combined move is logged only once.
   - Keep outputs exactly as required (`sa`, `pb`, etc.) with newline.

4. **Small input strategies**
   - Size 2–3: minimal deterministic swaps/rotations.
   - Size 4–5: push smallest elements to B, sort remaining 3 in A, then push back.

5. **General sorting approach**
   - Prefer binary radix on indices for all sizes (simple and within move limits up to 500); consider chunk-based pushes only if you later optimize move counts for medium inputs (e.g., 100–500).
   - Determine max bit-length from the highest index to bound loops.

6. **Error handling & exit**
   - Centralize error printing (`Error\n`), free both stacks, and return the correct exit status.

7. **Cleanup & leaks**
   - Free all allocated strings from `ft_split`, temporary arrays, and both stacks on normal exit and on errors.

8. **Testing & verification**
   - Add quick scripts to generate random inputs; compare `./push_swap` output count against expected move limits for small sizes.
   - If you build a checker later, reuse list parsing/validation to avoid duplication.

9. **Style & portability**
   - Conform to project norm (headers, includes, no forbidden functions), add missing includes (`stdlib.h`, `unistd.h`) where required, and keep functions below line limits.
