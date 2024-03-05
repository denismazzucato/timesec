# TODO

[ ] Support for general numeric domains from apron
[ ] Better architecture. Modules should take only what needed, not more.
[ ] cfg should rename after optimizations
[ ] timeout
[ ] json output for outsourced impact analysis
[ ] add doc
[ ] int vs real variables?
[ ] Labels equality checks
[ ] CFG generator to pick symbolic variable

# Bugs

[ ] abstract1.__del__ raises an error
[ ] equality sometimes is not bad when used in assertions

# impact

[ ] pass input bounds
[ ] pass buckets
[ ] initial analysis for input partitioning

# assumptions

- no return, exit at the end of the function
- no break, one loop rewritten in bignum_add
- no goto, four loops rewritten in bignum_amontredc, bignum_coprime, bignum_montredc
- smashed returns in bignum_ge, bignum_add, bignum_gt, bignum_le, bignum_lt
- add helper for types (defined in include/bignum_types.h)
- ltmp0 returns void only
- resolved expr list in bignum_cmul, bignum_cmadd, bignum_cmnegadd, bignum_coprime, bignum_copy_row_from_table_8n_neon, bignum_copy_row_from_table, bignum_modinv, bignum_shi_small, bignum_shr_small
- resolved boolean variable in bignum_shr_small, bignum_modifier, word_divstep59, bignum_modinv, bignum_ge, bignum_coprime, bignum_lt, bignum_le, bignum_gt, bignum_eq, bignum_amontifier, and others...
- array dereferencing rewriting in bignum_madd, bignum_modinv, bignum_coprime
- removed bignum_modexp


# Missing

[ ] type annotations and point-to analysis to solve array dependencies
[ ] multiple pop-push for generic cfgs, a program point depends on the unresolved conditions
[ ] boolean variables
[ ] typing inference for pointers, act like pointer -> be pointre

There are no pointer-of operations (&) and a few cases of pointer assignment, it should be easy

whenever we encounter a join point, we should check how many split points we are gathering from, and each one of them correspond to a push, (cannot be more than one pop every split). Assuming out(n) <= 2.
