> python playground.py
DEBUG: Debugging mode on: level 1
DEBUG: Found settings:
DEBUG:   input: examples/example.c
DEBUG:   function: ltmp0
DEBUG:   k_widening: 5
DEBUG:   decreasing_chain: 5
DEBUG:   repeat: 1
DEBUG:   interactive: False
DEBUG:   debug: 1
DEBUG:   output: None
DEBUG:   timeout: 0
DEBUG:   dev_no_exception_traceback: False
DEBUG:   dev_stop_at_first_exception: False
DEBUG:   COUNTER_VARIABLE_NAME: symbolic_counter
DEBUG:   INPUT_STREAM_VARIABLE_PREFIX: input_stream_
DEBUG:   INPUT_STREAM_COUNTER_VARIABLE_PREFIX: input_stream_counter_
DEBUG:   INPUT_STREAM_COUNTER_LENGTH_VARIABLE_PREFIX: input_stream_counter_length_
DEBUG:   CINCLUDE_PATH: include
DEBUG:   RANDOM_FUNCTION_NAME: __VERIFIER_nondet_int
DEBUG:   SYMBOLIC_VARIABLE_NAME: symbolic_goal
DEBUG: Preprocessing: gcc -Iinclude -E examples/example.c
DEBUG: Points-to analysis:
DEBUG: function ltmp0 (x |,| ):
symbolic_counter = 0; // deps={symbolic_goal, symbolic_counter, x}
skip; // not relevant
while (x >= 0) do // relevant
  x = (x - 1); // deps={symbolic_goal, symbolic_counter, x}
  symbolic_counter = (symbolic_counter + 1); // deps={symbolic_goal, symbolic_counter, x}
done;
assume (symbolic_counter == symbolic_goal); // deps={symbolic_goal, symbolic_counter}

DEBUG: (May) Used Variables: symbolic_goal, x
DEBUG: Invariant: 1·symbolic_goal - 1·x - 1 >= 0 ∧ 1·symbolic_goal + 0 >= 0

Analysis Results: (parse: 0.30s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.02s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  x           Input   May Used  ∞         Possibly Dangerous

1 /72 Analyzing: bignum_shr_small.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.09s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar2       Local   Unused    0         Definitely Safe
 6  lVar4       Local   Unused    0         Definitely Safe
 7  uVar1       Local   Unused    0         Definitely Safe
 8  uVar3       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe
10  uVar6       Local   Unused    0         Definitely Safe

2 /72 Analyzing: bignum_montifier.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 1.07s, fixpoint_iterator: 5.67s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar10     Local   Unused    0         Definitely Safe
 5  auVar11     Local   Unused    0         Definitely Safe
 6  auVar12     Local   Unused    0         Definitely Safe
 7  auVar13     Local   Unused    0         Definitely Safe
 8  auVar2      Local   Unused    0         Definitely Safe
 9  auVar3      Local   Unused    0         Definitely Safe
10  auVar4      Local   Unused    0         Definitely Safe
11  auVar5      Local   Unused    0         Definitely Safe
12  auVar6      Local   Unused    0         Definitely Safe
13  auVar7      Local   Unused    0         Definitely Safe
14  auVar8      Local   Unused    0         Definitely Safe
15  auVar9      Local   Unused    0         Definitely Safe
16  bVar1       Local   Unused    0         Definitely Safe
17  bVar14      Local   Unused    0         Definitely Safe
18  bVar15      Local   Unused    0         Definitely Safe
19  bVar16      Local   Unused    0         Definitely Safe
20  lVar18      Local   Unused    0         Definitely Safe
21  lVar21      Local   Unused    0         Definitely Safe
22  lVar25      Local   Unused    0         Definitely Safe
23  uVar17      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar20      Local   Unused    0         Definitely Safe
26  uVar22      Local   Unused    0         Definitely Safe
27  uVar23      Local   Unused    0         Definitely Safe
28  uVar24      Local   Unused    0         Definitely Safe
29  uVar26      Local   Unused    0         Definitely Safe

3 /72 Analyzing: bignum_montsqr.c

Analysis Results: (parse: 0.06s, points_to_analysis: 0.00s, dependency_analysis: 0.45s, fixpoint_iterator: 2.51s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar2      Local   Unused    0         Definitely Safe
 5  auVar3      Local   Unused    0         Definitely Safe
 6  auVar4      Local   Unused    0         Definitely Safe
 7  auVar5      Local   Unused    0         Definitely Safe
 8  auVar6      Local   Unused    0         Definitely Safe
 9  auVar7      Local   Unused    0         Definitely Safe
10  bVar1       Local   Unused    0         Definitely Safe
11  bVar8       Local   Unused    0         Definitely Safe
12  bVar9       Local   Unused    0         Definitely Safe
13  lVar11      Local   Unused    0         Definitely Safe
14  lVar12      Local   Unused    0         Definitely Safe
15  lVar14      Local   Unused    0         Definitely Safe
16  uVar10      Local   Unused    0         Definitely Safe
17  uVar13      Local   Unused    0         Definitely Safe
18  uVar15      Local   Unused    0         Definitely Safe
19  uVar16      Local   Unused    0         Definitely Safe
20  uVar17      Local   Unused    0         Definitely Safe
21  uVar18      Local   Unused    0         Definitely Safe
22  uVar19      Local   Unused    0         Definitely Safe
23  uVar20      Local   Unused    0         Definitely Safe
24  uVar21      Local   Unused    0         Definitely Safe
25  uVar22      Local   Unused    0         Definitely Safe

4 /72 Analyzing: bignum_modifier.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 1.05s, fixpoint_iterator: 6.01s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar10     Local   Unused    0         Definitely Safe
 5  auVar11     Local   Unused    0         Definitely Safe
 6  auVar12     Local   Unused    0         Definitely Safe
 7  auVar13     Local   Unused    0         Definitely Safe
 8  auVar2      Local   Unused    0         Definitely Safe
 9  auVar3      Local   Unused    0         Definitely Safe
10  auVar4      Local   Unused    0         Definitely Safe
11  auVar5      Local   Unused    0         Definitely Safe
12  auVar6      Local   Unused    0         Definitely Safe
13  auVar7      Local   Unused    0         Definitely Safe
14  auVar8      Local   Unused    0         Definitely Safe
15  auVar9      Local   Unused    0         Definitely Safe
16  bVar1       Local   Unused    0         Definitely Safe
17  bVar14      Local   Unused    0         Definitely Safe
18  bVar15      Local   Unused    0         Definitely Safe
19  bVar16      Local   Unused    0         Definitely Safe
20  lVar18      Local   Unused    0         Definitely Safe
21  lVar22      Local   Unused    0         Definitely Safe
22  lVar26      Local   Unused    0         Definitely Safe
23  uVar17      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar20      Local   Unused    0         Definitely Safe
26  uVar21      Local   Unused    0         Definitely Safe
27  uVar23      Local   Unused    0         Definitely Safe
28  uVar24      Local   Unused    0         Definitely Safe
29  uVar25      Local   Unused    0         Definitely Safe

5 /72 Analyzing: bignum_digit.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.05s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  uVar1       Local   Unused    0         Definitely Safe
 4  uVar2       Local   Unused    0         Definitely Safe
 5  uVar3       Local   Unused    0         Definitely Safe

6 /72 Analyzing: bignum_madd.c
WARNING: Potentially unsound array expression from sum: param_6 + (((uVar9 - uVar1) * 8) + (lVar10 * 8))

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.25s, fixpoint_iterator: 1.96s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  ∞         Possibly Dangerous
 5  param_6     Input   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  bVar5       Local   Unused    0         Definitely Safe
10  lVar10      Local   Unused    0         Definitely Safe
11  puVar14     Local   Unused    0         Definitely Safe
12  uVar1       Local   Unused    0         Definitely Safe
13  uVar11      Local   Unused    0         Definitely Safe
14  uVar12      Local   Unused    0         Definitely Safe
15  uVar13      Local   Unused    0         Definitely Safe
16  uVar6       Local   Unused    0         Definitely Safe
17  uVar7       Local   Unused    0         Definitely Safe
18  uVar8       Local   Unused    0         Definitely Safe
19  uVar9       Local   Unused    0         Definitely Safe

7 /72 Analyzing: bignum_sub.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.08s, fixpoint_iterator: 0.35s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  0         Definitely Safe
 5  param_6     Input   Unused    0         Definitely Safe
 6  bVar1       Local   Unused    0         Definitely Safe
 7  bVar2       Local   Unused    0         Definitely Safe
 8  lVar3       Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar7       Local   Unused    0         Definitely Safe
11  lVar9       Local   Unused    0         Definitely Safe
12  uVar10      Local   Unused    0         Definitely Safe
13  uVar5       Local   Unused    0         Definitely Safe
14  uVar6       Local   Unused    0         Definitely Safe
15  uVar8       Local   Unused    0         Definitely Safe

8 /72 Analyzing: bignum_optneg.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.06s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar1       Local   Unused    0         Definitely Safe
 5  bVar2       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe

9 /72 Analyzing: bignum_add.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.07s, fixpoint_iterator: 0.31s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  0         Definitely Safe
 5  param_6     Input   Unused    0         Definitely Safe
 6  bVar1       Local   Unused    0         Definitely Safe
 7  bVar2       Local   Unused    0         Definitely Safe
 8  lVar3       Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  uVar5       Local   Unused    0         Definitely Safe
12  uVar7       Local   Unused    0         Definitely Safe
13  uVar8       Local   Unused    0         Definitely Safe

10/72 Analyzing: bignum_digitsize.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe

11/72 Analyzing: bignum_cmul.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.07s, fixpoint_iterator: 0.25s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   May Used  2         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  bVar6       Local   Unused    0         Definitely Safe
10  bVar7       Local   Unused    0         Definitely Safe
11  lVar1       Local   Unused    0         Definitely Safe
12  lVar10      Local   Unused    0         Definitely Safe
13  lVar8       Local   Unused    0         Definitely Safe
14  lVar9       Local   Unused    0         Definitely Safe
15  uVar11      Local   Unused    0         Definitely Safe
16  uVar12      Local   Unused    0         Definitely Safe

12/72 Analyzing: bignum_modadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.06s, fixpoint_iterator: 0.21s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  bVar3       Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  bVar5       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  lVar7       Local   Unused    0         Definitely Safe
12  uVar10      Local   Unused    0         Definitely Safe
13  uVar8       Local   Unused    0         Definitely Safe
14  uVar9       Local   Unused    0         Definitely Safe

13/72 Analyzing: bignum_cdiv_exact.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.10s, fixpoint_iterator: 0.18s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  lVar5       Local   Unused    0         Definitely Safe
 8  lVar6       Local   Unused    0         Definitely Safe
 9  lVar7       Local   Unused    0         Definitely Safe
10  puVar3      Local   Unused    0         Definitely Safe
11  uVar10      Local   Unused    0         Definitely Safe
12  uVar11      Local   Unused    0         Definitely Safe
13  uVar12      Local   Unused    0         Definitely Safe
14  uVar13      Local   Unused    0         Definitely Safe
15  uVar14      Local   Unused    0         Definitely Safe
16  uVar4       Local   Unused    0         Definitely Safe
17  uVar8       Local   Unused    0         Definitely Safe
18  uVar9       Local   Unused    0         Definitely Safe

14/72 Analyzing: bignum_ctz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  uVar3       Local   Unused    0         Definitely Safe
 5  uVar4       Local   Unused    0         Definitely Safe

15/72 Analyzing: bignum_clz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.05s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe

16/72 Analyzing: bignum_modsub.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.04s, fixpoint_iterator: 0.13s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  bVar3       Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  lVar5       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  uVar7       Local   Unused    0         Definitely Safe
12  uVar8       Local   Unused    0         Definitely Safe

17/72 Analyzing: bignum_bitfield.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.04s, fixpoint_iterator: 0.08s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  uVar1       Local   Unused    0         Definitely Safe
 6  uVar2       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe
10  uVar6       Local   Unused    0         Definitely Safe

18/72 Analyzing: word_ctz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe

19/72 Analyzing: word_clz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe

20/72 Analyzing: bignum_copy_row_from_table_8n_neon.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.13s, fixpoint_iterator: 1.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   May Used  ∞         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  auVar8      Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  lVar7       Local   Unused    0         Definitely Safe
12  pauVar5     Local   Unused    0         Definitely Safe

21/72 Analyzing: bignum_cmod.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.28s, fixpoint_iterator: 0.14s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  auVar10     Local   Unused    0         Definitely Safe
 4  auVar11     Local   Unused    0         Definitely Safe
 5  auVar12     Local   Unused    0         Definitely Safe
 6  auVar13     Local   Unused    0         Definitely Safe
 7  auVar14     Local   Unused    0         Definitely Safe
 8  auVar3      Local   Unused    0         Definitely Safe
 9  auVar4      Local   Unused    0         Definitely Safe
10  auVar5      Local   Unused    0         Definitely Safe
11  auVar6      Local   Unused    0         Definitely Safe
12  auVar7      Local   Unused    0         Definitely Safe
13  auVar8      Local   Unused    0         Definitely Safe
14  auVar9      Local   Unused    0         Definitely Safe
15  bVar15      Local   Unused    0         Definitely Safe
16  lVar1       Local   Unused    0         Definitely Safe
17  lVar2       Local   Unused    0         Definitely Safe
18  uVar16      Local   Unused    0         Definitely Safe
19  uVar17      Local   Unused    0         Definitely Safe
20  uVar18      Local   Unused    0         Definitely Safe
21  uVar19      Local   Unused    0         Definitely Safe
22  uVar20      Local   Unused    0         Definitely Safe
23  uVar21      Local   Unused    0         Definitely Safe
24  uVar22      Local   Unused    0         Definitely Safe
25  uVar23      Local   Unused    0         Definitely Safe

22/72 Analyzing: word_min.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe

23/72 Analyzing: word_divstep59.c
^Z
[7]  + 50635 suspended  python playground.py
> python playground.py
DEBUG: Debugging mode on: level 1
DEBUG: Found settings:
DEBUG:   input: examples/example.c
DEBUG:   function: ltmp0
DEBUG:   k_widening: 5
DEBUG:   decreasing_chain: 5
DEBUG:   repeat: 1
DEBUG:   interactive: False
DEBUG:   debug: 1
DEBUG:   output: None
DEBUG:   timeout: 0
DEBUG:   dev_no_exception_traceback: False
DEBUG:   dev_stop_at_first_exception: False
DEBUG:   COUNTER_VARIABLE_NAME: symbolic_counter
DEBUG:   INPUT_STREAM_VARIABLE_PREFIX: input_stream_
DEBUG:   INPUT_STREAM_COUNTER_VARIABLE_PREFIX: input_stream_counter_
DEBUG:   INPUT_STREAM_COUNTER_LENGTH_VARIABLE_PREFIX: input_stream_counter_length_
DEBUG:   CINCLUDE_PATH: include
DEBUG:   RANDOM_FUNCTION_NAME: __VERIFIER_nondet_int
DEBUG:   SYMBOLIC_VARIABLE_NAME: symbolic_goal
DEBUG: Preprocessing: gcc -Iinclude -E examples/example.c
DEBUG: Points-to analysis:
DEBUG: function ltmp0 (x |,| ):
symbolic_counter = 0; // deps={x, symbolic_goal, symbolic_counter}
skip; // not relevant
while (x >= 0) do // relevant
  x = (x - 1); // deps={x, symbolic_goal, symbolic_counter}
  symbolic_counter = (symbolic_counter + 1); // deps={x, symbolic_goal, symbolic_counter}
done;
assume (symbolic_counter == symbolic_goal); // deps={symbolic_goal, symbolic_counter}

DEBUG: (May) Used Variables: symbolic_goal, x
DEBUG: Invariant: 1·symbolic_goal - 1·x - 1 >= 0 ∧ 1·symbolic_goal + 0 >= 0

Analysis Results: (parse: 0.07s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.02s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  x           Input   May Used  ∞         Possibly Dangerous

1 /72 Analyzing: bignum_shr_small.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.09s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar2       Local   Unused    0         Definitely Safe
 6  lVar4       Local   Unused    0         Definitely Safe
 7  uVar1       Local   Unused    0         Definitely Safe
 8  uVar3       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe
10  uVar6       Local   Unused    0         Definitely Safe

2 /72 Analyzing: bignum_montifier.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 1.02s, fixpoint_iterator: 5.68s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar10     Local   Unused    0         Definitely Safe
 5  auVar11     Local   Unused    0         Definitely Safe
 6  auVar12     Local   Unused    0         Definitely Safe
 7  auVar13     Local   Unused    0         Definitely Safe
 8  auVar2      Local   Unused    0         Definitely Safe
 9  auVar3      Local   Unused    0         Definitely Safe
10  auVar4      Local   Unused    0         Definitely Safe
11  auVar5      Local   Unused    0         Definitely Safe
12  auVar6      Local   Unused    0         Definitely Safe
13  auVar7      Local   Unused    0         Definitely Safe
14  auVar8      Local   Unused    0         Definitely Safe
15  auVar9      Local   Unused    0         Definitely Safe
16  bVar1       Local   Unused    0         Definitely Safe
17  bVar14      Local   Unused    0         Definitely Safe
18  bVar15      Local   Unused    0         Definitely Safe
19  bVar16      Local   Unused    0         Definitely Safe
20  lVar18      Local   Unused    0         Definitely Safe
21  lVar21      Local   Unused    0         Definitely Safe
22  lVar25      Local   Unused    0         Definitely Safe
23  uVar17      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar20      Local   Unused    0         Definitely Safe
26  uVar22      Local   Unused    0         Definitely Safe
27  uVar23      Local   Unused    0         Definitely Safe
28  uVar24      Local   Unused    0         Definitely Safe
29  uVar26      Local   Unused    0         Definitely Safe

3 /72 Analyzing: bignum_montsqr.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.43s, fixpoint_iterator: 2.45s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar2      Local   Unused    0         Definitely Safe
 5  auVar3      Local   Unused    0         Definitely Safe
 6  auVar4      Local   Unused    0         Definitely Safe
 7  auVar5      Local   Unused    0         Definitely Safe
 8  auVar6      Local   Unused    0         Definitely Safe
 9  auVar7      Local   Unused    0         Definitely Safe
10  bVar1       Local   Unused    0         Definitely Safe
11  bVar8       Local   Unused    0         Definitely Safe
12  bVar9       Local   Unused    0         Definitely Safe
13  lVar11      Local   Unused    0         Definitely Safe
14  lVar12      Local   Unused    0         Definitely Safe
15  lVar14      Local   Unused    0         Definitely Safe
16  uVar10      Local   Unused    0         Definitely Safe
17  uVar13      Local   Unused    0         Definitely Safe
18  uVar15      Local   Unused    0         Definitely Safe
19  uVar16      Local   Unused    0         Definitely Safe
20  uVar17      Local   Unused    0         Definitely Safe
21  uVar18      Local   Unused    0         Definitely Safe
22  uVar19      Local   Unused    0         Definitely Safe
23  uVar20      Local   Unused    0         Definitely Safe
24  uVar21      Local   Unused    0         Definitely Safe
25  uVar22      Local   Unused    0         Definitely Safe

4 /72 Analyzing: bignum_modifier.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 1.02s, fixpoint_iterator: 5.86s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar10     Local   Unused    0         Definitely Safe
 5  auVar11     Local   Unused    0         Definitely Safe
 6  auVar12     Local   Unused    0         Definitely Safe
 7  auVar13     Local   Unused    0         Definitely Safe
 8  auVar2      Local   Unused    0         Definitely Safe
 9  auVar3      Local   Unused    0         Definitely Safe
10  auVar4      Local   Unused    0         Definitely Safe
11  auVar5      Local   Unused    0         Definitely Safe
12  auVar6      Local   Unused    0         Definitely Safe
13  auVar7      Local   Unused    0         Definitely Safe
14  auVar8      Local   Unused    0         Definitely Safe
15  auVar9      Local   Unused    0         Definitely Safe
16  bVar1       Local   Unused    0         Definitely Safe
17  bVar14      Local   Unused    0         Definitely Safe
18  bVar15      Local   Unused    0         Definitely Safe
19  bVar16      Local   Unused    0         Definitely Safe
20  lVar18      Local   Unused    0         Definitely Safe
21  lVar22      Local   Unused    0         Definitely Safe
22  lVar26      Local   Unused    0         Definitely Safe
23  uVar17      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar20      Local   Unused    0         Definitely Safe
26  uVar21      Local   Unused    0         Definitely Safe
27  uVar23      Local   Unused    0         Definitely Safe
28  uVar24      Local   Unused    0         Definitely Safe
29  uVar25      Local   Unused    0         Definitely Safe

5 /72 Analyzing: bignum_digit.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.05s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  uVar1       Local   Unused    0         Definitely Safe
 4  uVar2       Local   Unused    0         Definitely Safe
 5  uVar3       Local   Unused    0         Definitely Safe

6 /72 Analyzing: bignum_madd.c
WARNING: Potentially unsound array expression from sum: param_6 + (((uVar9 - uVar1) * 8) + (lVar10 * 8))

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.25s, fixpoint_iterator: 2.00s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  ∞         Possibly Dangerous
 5  param_6     Input   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  bVar5       Local   Unused    0         Definitely Safe
10  lVar10      Local   Unused    0         Definitely Safe
11  puVar14     Local   Unused    0         Definitely Safe
12  uVar1       Local   Unused    0         Definitely Safe
13  uVar11      Local   Unused    0         Definitely Safe
14  uVar12      Local   Unused    0         Definitely Safe
15  uVar13      Local   Unused    0         Definitely Safe
16  uVar6       Local   Unused    0         Definitely Safe
17  uVar7       Local   Unused    0         Definitely Safe
18  uVar8       Local   Unused    0         Definitely Safe
19  uVar9       Local   Unused    0         Definitely Safe

7 /72 Analyzing: bignum_sub.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.08s, fixpoint_iterator: 0.35s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  0         Definitely Safe
 5  param_6     Input   Unused    0         Definitely Safe
 6  bVar1       Local   Unused    0         Definitely Safe
 7  bVar2       Local   Unused    0         Definitely Safe
 8  lVar3       Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar7       Local   Unused    0         Definitely Safe
11  lVar9       Local   Unused    0         Definitely Safe
12  uVar10      Local   Unused    0         Definitely Safe
13  uVar5       Local   Unused    0         Definitely Safe
14  uVar6       Local   Unused    0         Definitely Safe
15  uVar8       Local   Unused    0         Definitely Safe

8 /72 Analyzing: bignum_optneg.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.06s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar1       Local   Unused    0         Definitely Safe
 5  bVar2       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe

9 /72 Analyzing: bignum_add.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.07s, fixpoint_iterator: 0.30s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  0         Definitely Safe
 5  param_6     Input   Unused    0         Definitely Safe
 6  bVar1       Local   Unused    0         Definitely Safe
 7  bVar2       Local   Unused    0         Definitely Safe
 8  lVar3       Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  uVar5       Local   Unused    0         Definitely Safe
12  uVar7       Local   Unused    0         Definitely Safe
13  uVar8       Local   Unused    0         Definitely Safe

10/72 Analyzing: bignum_digitsize.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe

11/72 Analyzing: bignum_cmul.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.07s, fixpoint_iterator: 0.25s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   May Used  2         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  bVar6       Local   Unused    0         Definitely Safe
10  bVar7       Local   Unused    0         Definitely Safe
11  lVar1       Local   Unused    0         Definitely Safe
12  lVar10      Local   Unused    0         Definitely Safe
13  lVar8       Local   Unused    0         Definitely Safe
14  lVar9       Local   Unused    0         Definitely Safe
15  uVar11      Local   Unused    0         Definitely Safe
16  uVar12      Local   Unused    0         Definitely Safe

12/72 Analyzing: bignum_modadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.06s, fixpoint_iterator: 0.20s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  bVar3       Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  bVar5       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  lVar7       Local   Unused    0         Definitely Safe
12  uVar10      Local   Unused    0         Definitely Safe
13  uVar8       Local   Unused    0         Definitely Safe
14  uVar9       Local   Unused    0         Definitely Safe

13/72 Analyzing: bignum_cdiv_exact.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.10s, fixpoint_iterator: 0.17s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  lVar5       Local   Unused    0         Definitely Safe
 8  lVar6       Local   Unused    0         Definitely Safe
 9  lVar7       Local   Unused    0         Definitely Safe
10  puVar3      Local   Unused    0         Definitely Safe
11  uVar10      Local   Unused    0         Definitely Safe
12  uVar11      Local   Unused    0         Definitely Safe
13  uVar12      Local   Unused    0         Definitely Safe
14  uVar13      Local   Unused    0         Definitely Safe
15  uVar14      Local   Unused    0         Definitely Safe
16  uVar4       Local   Unused    0         Definitely Safe
17  uVar8       Local   Unused    0         Definitely Safe
18  uVar9       Local   Unused    0         Definitely Safe

14/72 Analyzing: bignum_ctz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  uVar3       Local   Unused    0         Definitely Safe
 5  uVar4       Local   Unused    0         Definitely Safe

15/72 Analyzing: bignum_clz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe

16/72 Analyzing: bignum_modsub.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.04s, fixpoint_iterator: 0.13s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  bVar3       Local   Unused    0         Definitely Safe
 8  bVar4       Local   Unused    0         Definitely Safe
 9  lVar5       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  uVar7       Local   Unused    0         Definitely Safe
12  uVar8       Local   Unused    0         Definitely Safe

17/72 Analyzing: bignum_bitfield.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.04s, fixpoint_iterator: 0.07s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  uVar1       Local   Unused    0         Definitely Safe
 6  uVar2       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe
10  uVar6       Local   Unused    0         Definitely Safe

18/72 Analyzing: word_ctz.c

Analysis Results: (parse: 0.02s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe

19/72 Analyzing: word_clz.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe

20/72 Analyzing: bignum_copy_row_from_table_8n_neon.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.13s, fixpoint_iterator: 1.00s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   May Used  ∞         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  auVar8      Local   Unused    0         Definitely Safe
 9  lVar4       Local   Unused    0         Definitely Safe
10  lVar6       Local   Unused    0         Definitely Safe
11  lVar7       Local   Unused    0         Definitely Safe
12  pauVar5     Local   Unused    0         Definitely Safe

21/72 Analyzing: bignum_cmod.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.29s, fixpoint_iterator: 0.15s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  auVar10     Local   Unused    0         Definitely Safe
 4  auVar11     Local   Unused    0         Definitely Safe
 5  auVar12     Local   Unused    0         Definitely Safe
 6  auVar13     Local   Unused    0         Definitely Safe
 7  auVar14     Local   Unused    0         Definitely Safe
 8  auVar3      Local   Unused    0         Definitely Safe
 9  auVar4      Local   Unused    0         Definitely Safe
10  auVar5      Local   Unused    0         Definitely Safe
11  auVar6      Local   Unused    0         Definitely Safe
12  auVar7      Local   Unused    0         Definitely Safe
13  auVar8      Local   Unused    0         Definitely Safe
14  auVar9      Local   Unused    0         Definitely Safe
15  bVar15      Local   Unused    0         Definitely Safe
16  lVar1       Local   Unused    0         Definitely Safe
17  lVar2       Local   Unused    0         Definitely Safe
18  uVar16      Local   Unused    0         Definitely Safe
19  uVar17      Local   Unused    0         Definitely Safe
20  uVar18      Local   Unused    0         Definitely Safe
21  uVar19      Local   Unused    0         Definitely Safe
22  uVar20      Local   Unused    0         Definitely Safe
23  uVar21      Local   Unused    0         Definitely Safe
24  uVar22      Local   Unused    0         Definitely Safe
25  uVar23      Local   Unused    0         Definitely Safe

22/72 Analyzing: word_min.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe

23/72 Analyzing: word_divstep59.c

Analysis Results: (parse: 0.08s, points_to_analysis: 0.00s, dependency_analysis: 34.46s, fixpoint_iterator: 0.02s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe
 2  param_3     Input   Unused          0  Definitely Safe
 3  param_4     Input   Unused          0  Definitely Safe
 4  bVar4       Local   Unused          0  Definitely Safe
 5  lVar1       Local   Unused          0  Definitely Safe
 6  lVar10      Local   Unused          0  Definitely Safe
 7  lVar11      Local   Unused          0  Definitely Safe
 8  lVar12      Local   Unused          0  Definitely Safe
 9  lVar13      Local   Unused          0  Definitely Safe
10  lVar14      Local   Unused          0  Definitely Safe
11  lVar15      Local   Unused          0  Definitely Safe
12  lVar16      Local   Unused          0  Definitely Safe
13  lVar17      Local   Unused          0  Definitely Safe
14  lVar18      Local   Unused          0  Definitely Safe
15  uVar2       Local   Unused          0  Definitely Safe
16  uVar3       Local   Unused          0  Definitely Safe
17  uVar5       Local   Unused          0  Definitely Safe
18  uVar6       Local   Unused          0  Definitely Safe
19  uVar7       Local   Unused          0  Definitely Safe
20  uVar8       Local   Unused          0  Definitely Safe
21  uVar9       Local   Unused          0  Definitely Safe

24/72 Analyzing: bignum_amontredc.c
WARNING: Potentially unsound array expression from sum: param_4 + ((uVar12 + uVar10) * 8)

Analysis Results: (parse: 0.23s, points_to_analysis: 0.00s, dependency_analysis: 0.34s, fixpoint_iterator: 1.35s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  param_6     Input   May Used  ∞         Possibly Dangerous
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  auVar4      Local   Unused    0         Definitely Safe
 9  auVar5      Local   Unused    0         Definitely Safe
10  bVar1       Local   Unused    0         Definitely Safe
11  bVar6       Local   Unused    0         Definitely Safe
12  lVar11      Local   Unused    0         Definitely Safe
13  lVar8       Local   Unused    0         Definitely Safe
14  lVar9       Local   Unused    0         Definitely Safe
15  uVar10      Local   Unused    0         Definitely Safe
16  uVar12      Local   Unused    0         Definitely Safe
17  uVar13      Local   Unused    0         Definitely Safe
18  uVar14      Local   Unused    0         Definitely Safe
19  uVar15      Local   Unused    0         Definitely Safe
20  uVar16      Local   Unused    0         Definitely Safe
21  uVar17      Local   Unused    0         Definitely Safe
22  uVar7       Local   Unused    0         Definitely Safe

25/72 Analyzing: bignum_copy.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.08s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  uVar1       Local   Unused    0         Definitely Safe
 5  uVar2       Local   Unused    0         Definitely Safe

26/72 Analyzing: bignum_cdiv.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.54s, fixpoint_iterator: 0.46s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar10     Local   Unused    0         Definitely Safe
 7  auVar11     Local   Unused    0         Definitely Safe
 8  auVar12     Local   Unused    0         Definitely Safe
 9  auVar13     Local   Unused    0         Definitely Safe
10  auVar14     Local   Unused    0         Definitely Safe
11  auVar2      Local   Unused    0         Definitely Safe
12  auVar3      Local   Unused    0         Definitely Safe
13  auVar4      Local   Unused    0         Definitely Safe
14  auVar5      Local   Unused    0         Definitely Safe
15  auVar6      Local   Unused    0         Definitely Safe
16  auVar7      Local   Unused    0         Definitely Safe
17  auVar8      Local   Unused    0         Definitely Safe
18  auVar9      Local   Unused    0         Definitely Safe
19  bVar15      Local   Unused    0         Definitely Safe
20  lVar19      Local   Unused    0         Definitely Safe
21  lVar20      Local   Unused    0         Definitely Safe
22  lVar21      Local   Unused    0         Definitely Safe
23  puVar16     Local   Unused    0         Definitely Safe
24  uVar17      Local   Unused    0         Definitely Safe
25  uVar18      Local   Unused    0         Definitely Safe
26  uVar22      Local   Unused    0         Definitely Safe
27  uVar23      Local   Unused    0         Definitely Safe
28  uVar24      Local   Unused    0         Definitely Safe
29  uVar25      Local   Unused    0         Definitely Safe
30  uVar26      Local   Unused    0         Definitely Safe
31  uVar27      Local   Unused    0         Definitely Safe
32  uVar28      Local   Unused    0         Definitely Safe

27/72 Analyzing: bignum_montmul.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.47s, fixpoint_iterator: 2.55s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  auVar6      Local   Unused    0         Definitely Safe
10  auVar7      Local   Unused    0         Definitely Safe
11  bVar1       Local   Unused    0         Definitely Safe
12  bVar8       Local   Unused    0         Definitely Safe
13  bVar9       Local   Unused    0         Definitely Safe
14  lVar11      Local   Unused    0         Definitely Safe
15  lVar12      Local   Unused    0         Definitely Safe
16  lVar14      Local   Unused    0         Definitely Safe
17  uVar10      Local   Unused    0         Definitely Safe
18  uVar13      Local   Unused    0         Definitely Safe
19  uVar15      Local   Unused    0         Definitely Safe
20  uVar16      Local   Unused    0         Definitely Safe
21  uVar17      Local   Unused    0         Definitely Safe
22  uVar18      Local   Unused    0         Definitely Safe
23  uVar19      Local   Unused    0         Definitely Safe
24  uVar20      Local   Unused    0         Definitely Safe
25  uVar21      Local   Unused    0         Definitely Safe
26  uVar22      Local   Unused    0         Definitely Safe

28/72 Analyzing: bignum_copy_row_from_table_32_neon.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.54s, fixpoint_iterator: 0.64s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar1      Local   Unused    0         Definitely Safe
 5  auVar10     Local   Unused    0         Definitely Safe
 6  auVar11     Local   Unused    0         Definitely Safe
 7  auVar12     Local   Unused    0         Definitely Safe
 8  auVar13     Local   Unused    0         Definitely Safe
 9  auVar14     Local   Unused    0         Definitely Safe
10  auVar15     Local   Unused    0         Definitely Safe
11  auVar16     Local   Unused    0         Definitely Safe
12  auVar19     Local   Unused    0         Definitely Safe
13  auVar2      Local   Unused    0         Definitely Safe
14  auVar20     Local   Unused    0         Definitely Safe
15  auVar21     Local   Unused    0         Definitely Safe
16  auVar22     Local   Unused    0         Definitely Safe
17  auVar23     Local   Unused    0         Definitely Safe
18  auVar24     Local   Unused    0         Definitely Safe
19  auVar25     Local   Unused    0         Definitely Safe
20  auVar26     Local   Unused    0         Definitely Safe
21  auVar27     Local   Unused    0         Definitely Safe
22  auVar28     Local   Unused    0         Definitely Safe
23  auVar29     Local   Unused    0         Definitely Safe
24  auVar3      Local   Unused    0         Definitely Safe
25  auVar30     Local   Unused    0         Definitely Safe
26  auVar31     Local   Unused    0         Definitely Safe
27  auVar32     Local   Unused    0         Definitely Safe
28  auVar33     Local   Unused    0         Definitely Safe
29  auVar34     Local   Unused    0         Definitely Safe
30  auVar4      Local   Unused    0         Definitely Safe
31  auVar5      Local   Unused    0         Definitely Safe
32  auVar6      Local   Unused    0         Definitely Safe
33  auVar7      Local   Unused    0         Definitely Safe
34  auVar8      Local   Unused    0         Definitely Safe
35  auVar9      Local   Unused    0         Definitely Safe
36  lVar17      Local   Unused    0         Definitely Safe
37  lVar18      Local   Unused    0         Definitely Safe

29/72 Analyzing: bignum_copy_row_from_table_16_neon.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.16s, fixpoint_iterator: 0.24s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar1      Local   Unused    0         Definitely Safe
 5  auVar11     Local   Unused    0         Definitely Safe
 6  auVar12     Local   Unused    0         Definitely Safe
 7  auVar13     Local   Unused    0         Definitely Safe
 8  auVar14     Local   Unused    0         Definitely Safe
 9  auVar15     Local   Unused    0         Definitely Safe
10  auVar16     Local   Unused    0         Definitely Safe
11  auVar17     Local   Unused    0         Definitely Safe
12  auVar18     Local   Unused    0         Definitely Safe
13  auVar2      Local   Unused    0         Definitely Safe
14  auVar3      Local   Unused    0         Definitely Safe
15  auVar4      Local   Unused    0         Definitely Safe
16  auVar5      Local   Unused    0         Definitely Safe
17  auVar6      Local   Unused    0         Definitely Safe
18  auVar7      Local   Unused    0         Definitely Safe
19  auVar8      Local   Unused    0         Definitely Safe
20  lVar10      Local   Unused    0         Definitely Safe
21  lVar9       Local   Unused    0         Definitely Safe

30/72 Analyzing: bignum_mux.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   May Used  ∞         Possibly Dangerous
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  uVar1       Local   Unused    0         Definitely Safe

31/72 Analyzing: bignum_shl_small.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.13s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  2         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  uVar1       Local   Unused    0         Definitely Safe
 6  uVar2       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe

32/72 Analyzing: bignum_optadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.06s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  lVar5       Local   Unused    0         Definitely Safe
 8  uVar3       Local   Unused    0         Definitely Safe
 9  uVar4       Local   Unused    0         Definitely Safe

33/72 Analyzing: bignum_copy_row_from_table.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.03s, fixpoint_iterator: 0.35s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   Unused    0         Definitely Safe
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   May Used  ∞         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  lVar1       Local   Unused    0         Definitely Safe
 6  lVar3       Local   Unused    0         Definitely Safe
 7  puVar2      Local   Unused    0         Definitely Safe

34/72 Analyzing: bignum_modinv.c
WARNING: Potentially unsound array expression from sum: puVar1 + (lVar34 + 8)
WARNING: Potentially unsound array expression from sum: puVar2 + (lVar34 + 8)
x
Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 4.69s, fixpoint_iterator: 26.15s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar10     Local   Unused    0         Definitely Safe
 6  auVar11     Local   Unused    0         Definitely Safe
 7  auVar12     Local   Unused    0         Definitely Safe
 8  auVar13     Local   Unused    0         Definitely Safe
 9  auVar14     Local   Unused    0         Definitely Safe
10  auVar15     Local   Unused    0         Definitely Safe
11  auVar16     Local   Unused    0         Definitely Safe
12  auVar17     Local   Unused    0         Definitely Safe
13  auVar18     Local   Unused    0         Definitely Safe
14  auVar19     Local   Unused    0         Definitely Safe
15  auVar20     Local   Unused    0         Definitely Safe
16  auVar21     Local   Unused    0         Definitely Safe
17  auVar22     Local   Unused    0         Definitely Safe
18  auVar23     Local   Unused    0         Definitely Safe
19  auVar24     Local   Unused    0         Definitely Safe
20  auVar25     Local   Unused    0         Definitely Safe
21  auVar26     Local   Unused    0         Definitely Safe
22  auVar27     Local   Unused    0         Definitely Safe
23  auVar4      Local   Unused    0         Definitely Safe
24  auVar5      Local   Unused    0         Definitely Safe
25  auVar6      Local   Unused    0         Definitely Safe
26  auVar7      Local   Unused    0         Definitely Safe
27  auVar8      Local   Unused    0         Definitely Safe
28  auVar9      Local   Unused    0         Definitely Safe
29  bVar28      Local   Unused    0         Definitely Safe
30  bVar28_1    Local   Unused    0         Definitely Safe
31  bVar28_2    Local   Unused    0         Definitely Safe
32  bVar29      Local   Unused    0         Definitely Safe
33  bVar3       Local   Unused    0         Definitely Safe
34  lVar34      Local   Unused    0         Definitely Safe
35  lVar38      Local   Unused    0         Definitely Safe
36  lVar49      Local   Unused    0         Definitely Safe
37  puVar1      Local   Unused    0         Definitely Safe
38  puVar2      Local   Unused    0         Definitely Safe
39  uVar30      Local   Unused    0         Definitely Safe
40  uVar31      Local   Unused    0         Definitely Safe
41  uVar32      Local   Unused    0         Definitely Safe
42  uVar33      Local   Unused    0         Definitely Safe
43  uVar35      Local   Unused    0         Definitely Safe
44  uVar36      Local   Unused    0         Definitely Safe
45  uVar37      Local   Unused    0         Definitely Safe
46  uVar39      Local   Unused    0         Definitely Safe
47  uVar40      Local   Unused    0         Definitely Safe
48  uVar41      Local   Unused    0         Definitely Safe
49  uVar42      Local   Unused    0         Definitely Safe
50  uVar43      Local   Unused    0         Definitely Safe
51  uVar44      Local   Unused    0         Definitely Safe
52  uVar45      Local   Unused    0         Definitely Safe
53  uVar46      Local   Unused    0         Definitely Safe
54  uVar47      Local   Unused    0         Definitely Safe
55  uVar48      Local   Unused    0         Definitely Safe

35/72 Analyzing: bignum_optsub.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 0.03s, fixpoint_iterator: 0.09s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  bVar3       Local   Unused    0         Definitely Safe
 8  bVar5       Local   Unused    0         Definitely Safe
 9  lVar8       Local   Unused    0         Definitely Safe
10  uVar4       Local   Unused    0         Definitely Safe
11  uVar6       Local   Unused    0         Definitely Safe
12  uVar7       Local   Unused    0         Definitely Safe

36/72 Analyzing: bignum_mux16.c

Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 0.12s, fixpoint_iterator: 0.14s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  uVar1       Local   Unused    0         Definitely Safe
 6  uVar2       Local   Unused    0         Definitely Safe

37/72 Analyzing: word_bytereverse.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  uVar1       Local   Unused          0  Definitely Safe
 2  uVar2       Local   Unused          0  Definitely Safe

38/72 Analyzing: word_recip.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  auVar3      Local   Unused          0  Definitely Safe
 2  auVar4      Local   Unused          0  Definitely Safe
 3  auVar5      Local   Unused          0  Definitely Safe
 4  auVar6      Local   Unused          0  Definitely Safe
 5  lVar1       Local   Unused          0  Definitely Safe
 6  lVar2       Local   Unused          0  Definitely Safe
 7  uVar7       Local   Unused          0  Definitely Safe
 8  uVar8       Local   Unused          0  Definitely Safe

39/72 Analyzing: bignum_cld.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe

40/72 Analyzing: bignum_ctd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe

41/72 Analyzing: bignum_nonzero.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  uVar1       Local   Unused    0         Definitely Safe

42/72 Analyzing: bignum_of_word.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.02s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe

43/72 Analyzing: bignum_sqr.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.30s, fixpoint_iterator: 1.79s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar1      Local   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  bVar5       Local   Unused    0         Definitely Safe
 9  bVar6       Local   Unused    0         Definitely Safe
10  lVar9       Local   Unused    0         Definitely Safe
11  puVar16     Local   Unused    0         Definitely Safe
12  uVar10      Local   Unused    0         Definitely Safe
13  uVar11      Local   Unused    0         Definitely Safe
14  uVar12      Local   Unused    0         Definitely Safe
15  uVar13      Local   Unused    0         Definitely Safe
16  uVar14      Local   Unused    0         Definitely Safe
17  uVar15      Local   Unused    0         Definitely Safe
18  uVar17      Local   Unused    0         Definitely Safe
19  uVar18      Local   Unused    0         Definitely Safe
20  uVar7       Local   Unused    0         Definitely Safe
21  uVar8       Local   Unused    0         Definitely Safe

44/72 Analyzing: bignum_even.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe

45/72 Analyzing: bignum_bitsize.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe

46/72 Analyzing: bignum_ge.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.05s, fixpoint_iterator: 0.22s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar2       Local   Unused    0         Definitely Safe
 5  bVar2_1     Local   Unused    0         Definitely Safe
 6  bVar2_2     Local   Unused    0         Definitely Safe
 7  lVar3       Local   Unused    0         Definitely Safe
 8  lVar5       Local   Unused    0         Definitely Safe
 9  uVar1       Local   Unused    0         Definitely Safe
10  uVar4       Local   Unused    0         Definitely Safe

47/72 Analyzing: bignum_pow2.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  lVar1       Local   Unused    0         Definitely Safe
 4  uVar2       Local   Unused    0         Definitely Safe

48/72 Analyzing: bignum_coprime.c
WARNING: Potentially unsound array expression from sum: param_5 + (lVar21 + 8)
WARNING: Potentially unsound array expression from sum: puVar1 + (lVar21 + 8)

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 2.01s, fixpoint_iterator: 8.95s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar10     Local   Unused    0         Definitely Safe
 6  auVar11     Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  auVar6      Local   Unused    0         Definitely Safe
10  auVar7      Local   Unused    0         Definitely Safe
11  auVar8      Local   Unused    0         Definitely Safe
12  auVar9      Local   Unused    0         Definitely Safe
13  bVar12      Local   Unused    0         Definitely Safe
14  bVar12_1    Local   Unused    0         Definitely Safe
15  bVar12_2    Local   Unused    0         Definitely Safe
16  bVar13      Local   Unused    0         Definitely Safe
17  lVar21      Local   Unused    0         Definitely Safe
18  puVar1      Local   Unused    0         Definitely Safe
19  uVar14      Local   Unused    0         Definitely Safe
20  uVar15      Local   Unused    0         Definitely Safe
21  uVar16      Local   Unused    0         Definitely Safe
22  uVar17      Local   Unused    0         Definitely Safe
23  uVar18      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar2       Local   Unused    0         Definitely Safe
26  uVar20      Local   Unused    0         Definitely Safe
27  uVar22      Local   Unused    0         Definitely Safe
28  uVar23      Local   Unused    0         Definitely Safe
29  uVar24      Local   Unused    0         Definitely Safe
30  uVar25      Local   Unused    0         Definitely Safe
31  uVar26      Local   Unused    0         Definitely Safe
32  uVar27      Local   Unused    0         Definitely Safe
33  uVar28      Local   Unused    0         Definitely Safe
34  uVar29      Local   Unused    0         Definitely Safe
35  uVar3       Local   Unused    0         Definitely Safe
36  uVar30      Local   Unused    0         Definitely Safe
37  uVar31      Local   Unused    0         Definitely Safe
38  uVar32      Local   Unused    0         Definitely Safe

49/72 Analyzing: bignum_demont.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.26s, fixpoint_iterator: 1.24s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar2      Local   Unused    0         Definitely Safe
 5  auVar3      Local   Unused    0         Definitely Safe
 6  auVar4      Local   Unused    0         Definitely Safe
 7  auVar5      Local   Unused    0         Definitely Safe
 8  bVar1       Local   Unused    0         Definitely Safe
 9  bVar6       Local   Unused    0         Definitely Safe
10  bVar7       Local   Unused    0         Definitely Safe
11  lVar10      Local   Unused    0         Definitely Safe
12  lVar11      Local   Unused    0         Definitely Safe
13  lVar9       Local   Unused    0         Definitely Safe
14  uVar12      Local   Unused    0         Definitely Safe
15  uVar13      Local   Unused    0         Definitely Safe
16  uVar14      Local   Unused    0         Definitely Safe
17  uVar15      Local   Unused    0         Definitely Safe
18  uVar16      Local   Unused    0         Definitely Safe
19  uVar17      Local   Unused    0         Definitely Safe
20  uVar8       Local   Unused    0         Definitely Safe

50/72 Analyzing: bignum_lt.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.05s, fixpoint_iterator: 0.22s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar2       Local   Unused    0         Definitely Safe
 5  bVar2_1     Local   Unused    0         Definitely Safe
 6  bVar2_2     Local   Unused    0         Definitely Safe
 7  lVar3       Local   Unused    0         Definitely Safe
 8  lVar5       Local   Unused    0         Definitely Safe
 9  uVar1       Local   Unused    0         Definitely Safe
10  uVar4       Local   Unused    0         Definitely Safe

51/72 Analyzing: bignum_amontsqr.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.40s, fixpoint_iterator: 2.34s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar1      Local   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  auVar6      Local   Unused    0         Definitely Safe
10  bVar7       Local   Unused    0         Definitely Safe
11  bVar8       Local   Unused    0         Definitely Safe
12  lVar10      Local   Unused    0         Definitely Safe
13  lVar11      Local   Unused    0         Definitely Safe
14  lVar13      Local   Unused    0         Definitely Safe
15  uVar12      Local   Unused    0         Definitely Safe
16  uVar14      Local   Unused    0         Definitely Safe
17  uVar15      Local   Unused    0         Definitely Safe
18  uVar16      Local   Unused    0         Definitely Safe
19  uVar17      Local   Unused    0         Definitely Safe
20  uVar18      Local   Unused    0         Definitely Safe
21  uVar19      Local   Unused    0         Definitely Safe
22  uVar20      Local   Unused    0         Definitely Safe
23  uVar21      Local   Unused    0         Definitely Safe
24  uVar9       Local   Unused    0         Definitely Safe

52/72 Analyzing: bignum_eq.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.12s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar1       Local   Unused    0         Definitely Safe
 5  bVar1_1     Local   Unused    0         Definitely Safe
 6  bVar1_2     Local   Unused    0         Definitely Safe
 7  uVar2       Local   Unused    0         Definitely Safe

53/72 Analyzing: bignum_normalize.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.08s, fixpoint_iterator: 0.53s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  bVar2       Local   Unused    0         Definitely Safe
 3  lVar1       Local   Unused    0         Definitely Safe
 4  lVar3       Local   Unused    0         Definitely Safe
 5  lVar4       Local   Unused    0         Definitely Safe
 6  lVar5       Local   Unused    0         Definitely Safe
 7  lVar8       Local   Unused    0         Definitely Safe
 8  uVar10      Local   Unused    0         Definitely Safe
 9  uVar11      Local   Unused    0         Definitely Safe
10  uVar12      Local   Unused    0         Definitely Safe
11  uVar6       Local   Unused    0         Definitely Safe
12  uVar7       Local   Unused    0         Definitely Safe
13  uVar9       Local   Unused    0         Definitely Safe

54/72 Analyzing: bignum_amontifier.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.71s, fixpoint_iterator: 3.94s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar2      Local   Unused    0         Definitely Safe
 5  auVar3      Local   Unused    0         Definitely Safe
 6  auVar4      Local   Unused    0         Definitely Safe
 7  auVar5      Local   Unused    0         Definitely Safe
 8  auVar6      Local   Unused    0         Definitely Safe
 9  auVar7      Local   Unused    0         Definitely Safe
10  auVar8      Local   Unused    0         Definitely Safe
11  auVar9      Local   Unused    0         Definitely Safe
12  bVar1       Local   Unused    0         Definitely Safe
13  bVar10      Local   Unused    0         Definitely Safe
14  bVar11      Local   Unused    0         Definitely Safe
15  bVar12      Local   Unused    0         Definitely Safe
16  lVar14      Local   Unused    0         Definitely Safe
17  lVar22      Local   Unused    0         Definitely Safe
18  lVar23      Local   Unused    0         Definitely Safe
19  uVar13      Local   Unused    0         Definitely Safe
20  uVar15      Local   Unused    0         Definitely Safe
21  uVar16      Local   Unused    0         Definitely Safe
22  uVar17      Local   Unused    0         Definitely Safe
23  uVar18      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe
25  uVar20      Local   Unused    0         Definitely Safe
26  uVar21      Local   Unused    0         Definitely Safe

55/72 Analyzing: bignum_modoptneg.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.11s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  uVar2       Local   Unused    0         Definitely Safe
 7  uVar3       Local   Unused    0         Definitely Safe
 8  uVar4       Local   Unused    0         Definitely Safe
 9  uVar5       Local   Unused    0         Definitely Safe

56/72 Analyzing: bignum_gt.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.05s, fixpoint_iterator: 0.21s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar2       Local   Unused    0         Definitely Safe
 5  bVar2_1     Local   Unused    0         Definitely Safe
 6  bVar2_2     Local   Unused    0         Definitely Safe
 7  lVar3       Local   Unused    0         Definitely Safe
 8  lVar5       Local   Unused    0         Definitely Safe
 9  uVar1       Local   Unused    0         Definitely Safe
10  uVar4       Local   Unused    0         Definitely Safe

57/72 Analyzing: bignum_mul.c
WARNING: Potentially unsound array expression from sum: param_6 + (((uVar9 - uVar2) * 8) + (lVar10 * 8))

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.20s, fixpoint_iterator: 1.72s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   May Used  ∞         Possibly Dangerous
 5  param_6     Input   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  bVar1       Local   Unused    0         Definitely Safe
 9  bVar5       Local   Unused    0         Definitely Safe
10  lVar10      Local   Unused    0         Definitely Safe
11  puVar14     Local   Unused    0         Definitely Safe
12  uVar11      Local   Unused    0         Definitely Safe
13  uVar12      Local   Unused    0         Definitely Safe
14  uVar13      Local   Unused    0         Definitely Safe
15  uVar2       Local   Unused    0         Definitely Safe
16  uVar6       Local   Unused    0         Definitely Safe
17  uVar7       Local   Unused    0         Definitely Safe
18  uVar8       Local   Unused    0         Definitely Safe
19  uVar9       Local   Unused    0         Definitely Safe

58/72 Analyzing: bignum_cmadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.08s, fixpoint_iterator: 0.29s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   May Used  ∞         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  bVar1       Local   Unused    0         Definitely Safe
10  bVar6       Local   Unused    0         Definitely Safe
11  lVar7       Local   Unused    0         Definitely Safe
12  lVar8       Local   Unused    0         Definitely Safe
13  uVar10      Local   Unused    0         Definitely Safe
14  uVar11      Local   Unused    0         Definitely Safe
15  uVar12      Local   Unused    0         Definitely Safe
16  uVar13      Local   Unused    0         Definitely Safe
17  uVar9       Local   Unused    0         Definitely Safe

59/72 Analyzing: bignum_moddouble.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.04s, fixpoint_iterator: 0.14s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar1       Local   Unused    0         Definitely Safe
 5  bVar2       Local   Unused    0         Definitely Safe
 6  bVar3       Local   Unused    0         Definitely Safe
 7  bVar4       Local   Unused    0         Definitely Safe
 8  lVar5       Local   Unused    0         Definitely Safe
 9  lVar6       Local   Unused    0         Definitely Safe
10  uVar7       Local   Unused    0         Definitely Safe
11  uVar8       Local   Unused    0         Definitely Safe
12  uVar9       Local   Unused    0         Definitely Safe

60/72 Analyzing: bignum_amontmul.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.43s, fixpoint_iterator: 2.39s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar1      Local   Unused    0         Definitely Safe
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  auVar4      Local   Unused    0         Definitely Safe
 9  auVar5      Local   Unused    0         Definitely Safe
10  auVar6      Local   Unused    0         Definitely Safe
11  bVar7       Local   Unused    0         Definitely Safe
12  bVar8       Local   Unused    0         Definitely Safe
13  lVar10      Local   Unused    0         Definitely Safe
14  lVar11      Local   Unused    0         Definitely Safe
15  lVar13      Local   Unused    0         Definitely Safe
16  uVar12      Local   Unused    0         Definitely Safe
17  uVar14      Local   Unused    0         Definitely Safe
18  uVar15      Local   Unused    0         Definitely Safe
19  uVar16      Local   Unused    0         Definitely Safe
20  uVar17      Local   Unused    0         Definitely Safe
21  uVar18      Local   Unused    0         Definitely Safe
22  uVar19      Local   Unused    0         Definitely Safe
23  uVar20      Local   Unused    0         Definitely Safe
24  uVar21      Local   Unused    0         Definitely Safe
25  uVar9       Local   Unused    0         Definitely Safe

61/72 Analyzing: bignum_muladd10.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.05s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  uVar1       Local   Unused    0         Definitely Safe
 4  uVar2       Local   Unused    0         Definitely Safe

62/72 Analyzing: bignum_le.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.05s, fixpoint_iterator: 0.22s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  bVar2       Local   Unused    0         Definitely Safe
 5  bVar2_1     Local   Unused    0         Definitely Safe
 6  bVar2_2     Local   Unused    0         Definitely Safe
 7  lVar3       Local   Unused    0         Definitely Safe
 8  lVar5       Local   Unused    0         Definitely Safe
 9  uVar1       Local   Unused    0         Definitely Safe
10  uVar4       Local   Unused    0         Definitely Safe

63/72 Analyzing: bignum_divmod10.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.01s, fixpoint_iterator: 0.04s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  lVar1       Local   Unused    0         Definitely Safe
 3  lVar2       Local   Unused    0         Definitely Safe
 4  uVar3       Local   Unused    0         Definitely Safe
 5  uVar4       Local   Unused    0         Definitely Safe

64/72 Analyzing: word_negmodinv.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  lVar1       Local   Unused          0  Definitely Safe
 2  lVar3       Local   Unused          0  Definitely Safe
 3  lVar4       Local   Unused          0  Definitely Safe
 4  uVar2       Local   Unused          0  Definitely Safe

65/72 Analyzing: bignum_negmodinv.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.32s, fixpoint_iterator: 0.60s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  auVar2      Local   Unused    0         Definitely Safe
 4  auVar3      Local   Unused    0         Definitely Safe
 5  auVar4      Local   Unused    0         Definitely Safe
 6  auVar5      Local   Unused    0         Definitely Safe
 7  auVar6      Local   Unused    0         Definitely Safe
 8  auVar7      Local   Unused    0         Definitely Safe
 9  auVar8      Local   Unused    0         Definitely Safe
10  auVar9      Local   Unused    0         Definitely Safe
11  bVar1       Local   Unused    0         Definitely Safe
12  bVar10      Local   Unused    0         Definitely Safe
13  bVar1_1     Local   Unused    0         Definitely Safe
14  bVar1_2     Local   Unused    0         Definitely Safe
15  bVar_2      Local   May Used  ∞         Possibly Dangerous
16  lVar13      Local   Unused    0         Definitely Safe
17  lVar14      Local   Unused    0         Definitely Safe
18  lVar16      Local   Unused    0         Definitely Safe
19  uVar11      Local   Unused    0         Definitely Safe
20  uVar12      Local   Unused    0         Definitely Safe
21  uVar15      Local   Unused    0         Definitely Safe
22  uVar17      Local   Unused    0         Definitely Safe
23  uVar18      Local   Unused    0         Definitely Safe
24  uVar19      Local   Unused    0         Definitely Safe

66/72 Analyzing: bignum_montredc.c
WARNING: Potentially unsound array expression from sum: param_4 + ((uVar13 + uVar11) * 8)

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.34s, fixpoint_iterator: 1.46s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   May Used  ∞         Possibly Dangerous
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  param_6     Input   May Used  ∞         Possibly Dangerous
 6  auVar2      Local   Unused    0         Definitely Safe
 7  auVar3      Local   Unused    0         Definitely Safe
 8  auVar4      Local   Unused    0         Definitely Safe
 9  auVar5      Local   Unused    0         Definitely Safe
10  bVar1       Local   Unused    0         Definitely Safe
11  bVar6       Local   Unused    0         Definitely Safe
12  bVar7       Local   Unused    0         Definitely Safe
13  lVar10      Local   Unused    0         Definitely Safe
14  lVar12      Local   Unused    0         Definitely Safe
15  lVar9       Local   Unused    0         Definitely Safe
16  uVar11      Local   Unused    0         Definitely Safe
17  uVar13      Local   Unused    0         Definitely Safe
18  uVar14      Local   Unused    0         Definitely Safe
19  uVar15      Local   Unused    0         Definitely Safe
20  uVar16      Local   Unused    0         Definitely Safe
21  uVar17      Local   Unused    0         Definitely Safe
22  uVar18      Local   Unused    0         Definitely Safe
23  uVar8       Local   Unused    0         Definitely Safe

67/72 Analyzing: bignum_iszero.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.03s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  uVar1       Local   Unused    0         Definitely Safe

68/72 Analyzing: word_max.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe

69/72 Analyzing: bignum_optsubadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.02s, fixpoint_iterator: 0.07s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  param_5     Input   Unused    0         Definitely Safe
 5  bVar1       Local   Unused    0         Definitely Safe
 6  bVar2       Local   Unused    0         Definitely Safe
 7  lVar6       Local   Unused    0         Definitely Safe
 8  uVar3       Local   Unused    0         Definitely Safe
 9  uVar4       Local   Unused    0         Definitely Safe
10  uVar5       Local   Unused    0         Definitely Safe

70/72 Analyzing: bignum_odd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.00s, impact_analysis: 0.00s)

    Variable    Type    Usage      Impact  Notes
--  ----------  ------  -------  --------  ---------------
 0  param_1     Input   Unused          0  Definitely Safe
 1  param_2     Input   Unused          0  Definitely Safe

71/72 Analyzing: bignum_cmnegadd.c

Analysis Results: (parse: 0.03s, points_to_analysis: 0.00s, dependency_analysis: 0.08s, fixpoint_iterator: 0.28s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   May Used  ∞         Possibly Dangerous
 4  param_5     Input   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  auVar5      Local   Unused    0         Definitely Safe
 9  bVar1       Local   Unused    0         Definitely Safe
10  bVar7       Local   Unused    0         Definitely Safe
11  lVar14      Local   Unused    0         Definitely Safe
12  lVar8       Local   Unused    0         Definitely Safe
13  lVar9       Local   Unused    0         Definitely Safe
14  uVar10      Local   Unused    0         Definitely Safe
15  uVar11      Local   Unused    0         Definitely Safe
16  uVar12      Local   Unused    0         Definitely Safe
17  uVar13      Local   Unused    0         Definitely Safe
18  uVar6       Local   Unused    0         Definitely Safe

72/72 Analyzing: bignum_emontredc.c

Analysis Results: (parse: 0.04s, points_to_analysis: 0.00s, dependency_analysis: 0.14s, fixpoint_iterator: 0.90s, impact_analysis: 0.00s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  param_1     Input   May Used  ∞         Possibly Dangerous
 1  param_2     Input   Unused    0         Definitely Safe
 2  param_3     Input   Unused    0         Definitely Safe
 3  param_4     Input   Unused    0         Definitely Safe
 4  auVar1      Local   Unused    0         Definitely Safe
 5  auVar2      Local   Unused    0         Definitely Safe
 6  auVar3      Local   Unused    0         Definitely Safe
 7  auVar4      Local   Unused    0         Definitely Safe
 8  bVar5       Local   Unused    0         Definitely Safe
 9  uVar10      Local   Unused    0         Definitely Safe
10  uVar11      Local   Unused    0         Definitely Safe
11  uVar12      Local   Unused    0         Definitely Safe
12  uVar13      Local   Unused    0         Definitely Safe
13  uVar6       Local   Unused    0         Definitely Safe
14  uVar7       Local   Unused    0         Definitely Safe
15  uVar8       Local   Unused    0         Definitely Safe
16  uVar9       Local   Unused    0         Definitely Safe


================================================================================

Overall Statistics:  (over 72 programs: 72 succeeded and 0 failed):

  Lines of code:
    - 5984 lines of code in total
    - 83 lines of code on average for 72 analyzed programs
    - 1113 lines of code in the program with the most lines of code
    - 7 lines of code in the program with the least lines of code

  Timings:
    - 132.96 seconds in total for the analysis of 72 programs
    - 2.54 seconds in total for parsing
    - 0.02 seconds in total for the points-to analysis
    - 50.88 seconds in total for the dependency analysis
    - 79.27 seconds in total for the fixpoint iterator
    - 0.25 seconds in total for the impact analysis
    - 1.85 seconds on average for the analysis of 72 programs
    - 34.56 seconds in the program with the longest analysis
    - 0.03 seconds in the program with the shortest analysis
    - 0.04 seconds on average for parsing of 72 programs
    - 0.71 seconds on average for the dependency analysis of 72 programs
    - 1.1 seconds on average for the fixpoint iterator of 72 programs
    - 0.0 seconds on average for the impact analysis of 72 programs

  Input variables:
    - 272 input variables in total
    - 4 input variables on average for 72 analyzed programs
    - 6 input variables in the program with the most input variables
    - 1 input variables in the program with the least input variables

  Local variables:
    - 900 local variables in total
    - 12 local variables on average for 72 analyzed programs
    - 53 local variables in the program with the most local variables
    - 2 local variables in the program with the least local variables

  In total: (with two symbolic variables each program)
    - 1172 variables in total
    - 16 variables on average for 72 analyzed programs
    - 58 variables in the program with the most variables
    - 3 variables in the program with the least variables

  Slicing from dependency analysis:
    - 356 variables in use during the forward-backward analysis (30% of the total variables)
    - 5 variables in use on average for 72 analyzed programs
    - 12 variables in use in the program with the most variables
    - 2 variables in use in the program with the least variables
    - 816 variables removed from the forward-backward analysis (70% of the total variables)
    - 11 variables removed on average for 72 analyzed programs
    - 48 variables removed in the program with the most variables
    - 1 variables removed in the program with the least variables

  Quantitative impact of input variables on the number of iterations:
    - 85 maybe dangerous input variables in total
    - 5 input variables with definitely no impact (discovered by the quantitative analysis)
    - 182 input variables that are definitely not used (discovered by the qualitative analysis)

  Quantitative impact of local variables on the number of iterations:
    - 1 maybe dangerous local variables in total
    - 0 local variables with definitely no impact (discovered by the quantitative analysis)
    - 899 local variables that are definitely not used (discovered by the qualitative analysis)


Usage Composition:
Program                               Function    Dangerous                  Zero Used         Unused                              Original File
------------------------------------  ----------  -------------------------  ----------------  ----------------------------------  ----------------------------------------------------------------------------
bignum_add.c                          ltmp0       param_1                    param_3, param_5  param_2, param_4, param_6           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_add.S
bignum_amontifier.c                   ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_amontifier.S
bignum_amontmul.c                     ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_amontmul.S
bignum_amontredc.c                    ltmp0       param_1, param_3, param_6                    param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_amontredc.S
bignum_amontsqr.c                     ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_amontsqr.S
bignum_bitfield.c                     ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_bitfield.S
bignum_bitsize.c                      ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_bitsize.S
bignum_cdiv.c                         ltmp0       param_1, param_3                             param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cdiv.S
bignum_cdiv_exact.c                   ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cdiv_exact.S
bignum_cld.c                          ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cld.S
bignum_clz.c                          ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_clz.S
bignum_cmadd.c                        ltmp0       param_1, param_4                             param_2, param_3, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cmadd.S
bignum_cmnegadd.c                     ltmp0       param_1, param_4                             param_2, param_3, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cmnegadd.S
bignum_cmod.c                         ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cmod.S
bignum_cmul.c                         ltmp0       param_1, param_4                             param_2, param_3, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_cmul.S
bignum_coprime.c                      ltmp0       param_1, param_3                             param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_coprime.S
bignum_copy.c                         ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_copy.S
bignum_copy_row_from_table.c          ltmp0       param_3, param_4                             param_1, param_2, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_copy_row_from_table.S
bignum_copy_row_from_table_16_neon.c  ltmp0       param_3                                      param_1, param_2, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_copy_row_from_table_16_neon.S
bignum_copy_row_from_table_32_neon.c  ltmp0       param_3                                      param_1, param_2, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_copy_row_from_table_32_neon.S
bignum_copy_row_from_table_8n_neon.c  ltmp0       param_3, param_4                             param_1, param_2, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_copy_row_from_table_8n_neon.S
bignum_ctd.c                          ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_ctd.S
bignum_ctz.c                          ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_ctz.S
bignum_demont.c                       ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_demont.S
bignum_digit.c                        ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_digit.S
bignum_digitsize.c                    ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_digitsize.S
bignum_divmod10.c                     ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_divmod10.S
bignum_emontredc.c                    ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_emontredc.S
bignum_eq.c                           ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_eq.S
bignum_even.c                         ltmp0                                                    param_1, param_2                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_even.S
bignum_ge.c                           ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_ge.S
bignum_gt.c                           ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_gt.S
bignum_iszero.c                       ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_iszero.S
bignum_le.c                           ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_le.S
bignum_lt.c                           ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_lt.S
bignum_madd.c                         ltmp0       param_1, param_3, param_5                    param_2, param_4, param_6           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_madd.S
bignum_modadd.c                       ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_modadd.S
bignum_moddouble.c                    ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_moddouble.S
bignum_modifier.c                     ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_modifier.S
bignum_modinv.c                       ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_modinv.S
bignum_modoptneg.c                    ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_modoptneg.S
bignum_modsub.c                       ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_modsub.S
bignum_montifier.c                    ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_montifier.S
bignum_montmul.c                      ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_montmul.S
bignum_montredc.c                     ltmp0       param_1, param_3, param_6                    param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_montredc.S
bignum_montsqr.c                      ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_montsqr.S
bignum_mul.c                          ltmp0       param_1, param_3, param_5                    param_2, param_4, param_6           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_mul.S
bignum_muladd10.c                     ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_muladd10.S
bignum_mux.c                          ltmp0       param_2                                      param_1, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_mux.S
bignum_mux16.c                        ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_mux16.S
bignum_negmodinv.c                    ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_negmodinv.S
bignum_nonzero.c                      ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_nonzero.S
bignum_normalize.c                    ltmp0       param_1                                      param_2                             /Users/mazzu/src/s2n-bignum/arm/generic/bignum_normalize.S
bignum_odd.c                          ltmp0                                                    param_1, param_2                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_odd.S
bignum_of_word.c                      ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_of_word.S
bignum_optadd.c                       ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_optadd.S
bignum_optneg.c                       ltmp0       param_1                                      param_2, param_3, param_4           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_optneg.S
bignum_optsub.c                       ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_optsub.S
bignum_optsubadd.c                    ltmp0       param_1                                      param_2, param_3, param_4, param_5  /Users/mazzu/src/s2n-bignum/arm/generic/bignum_optsubadd.S
bignum_pow2.c                         ltmp0       param_1                                      param_2, param_3                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_pow2.S
bignum_shl_small.c                    ltmp0       param_1, param_3                             param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_shl_small.S
bignum_shr_small.c                    ltmp0       param_1                    param_3           param_2, param_4, param_5           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_shr_small.S
bignum_sqr.c                          ltmp0       param_1, param_3                             param_2, param_4                    /Users/mazzu/src/s2n-bignum/arm/generic/bignum_sqr.S
bignum_sub.c                          ltmp0       param_1                    param_3, param_5  param_2, param_4, param_6           /Users/mazzu/src/s2n-bignum/arm/generic/bignum_sub.S
word_bytereverse.c                    ltmp0                                                    param_1                             /Users/mazzu/src/s2n-bignum/arm/generic/word_bytereverse.S
word_clz.c                            ltmp0                                                    param_1                             /Users/mazzu/src/s2n-bignum/arm/generic/word_clz.S
word_ctz.c                            ltmp0                                                    param_1                             /Users/mazzu/src/s2n-bignum/arm/generic/word_ctz.S
word_divstep59.c                      ltmp0                                                    param_1, param_2, param_3, param_4  /Users/mazzu/src/s2n-bignum/arm/generic/word_divstep59.S
word_max.c                            ltmp0                                                    param_1, param_2                    /Users/mazzu/src/s2n-bignum/arm/generic/word_max.S
word_min.c                            ltmp0                                                    param_1, param_2                    /Users/mazzu/src/s2n-bignum/arm/generic/word_min.S
word_negmodinv.c                      ltmp0                                                    param_1                             /Users/mazzu/src/s2n-bignum/arm/generic/word_negmodinv.S
word_recip.c                          ltmp0                                                    param_1                             /Users/mazzu/src/s2n-bignum/arm/generic/word_recip.S
WARNING: Error deleting apron abstract1 object: argument 1: TypeError: Don't know how to convert parameter 1
