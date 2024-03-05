# QuantIt

## Assumptions on bignum sourcecode

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


## Missing

[ ] caching ast operations for faster analysis, problem freezing lists

## benchmarks:

- bignum:
